/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomes-g <agomes-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 09:00:36 by agomes-g          #+#    #+#             */
/*   Updated: 2023/10/11 07:39:03 by agomes-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nico/includes/minishell.h"

void printList(t_env *env) 
{
    t_env	*lst;

	lst = env;
    while (lst != NULL)
	{
        printf("export %s", lst->name);
		if (lst->value != NULL)
			printf("=\"%s\"", lst->value);
		else if (lst->val)
			printf("=\"\"");
		printf("\n");
        lst = lst->next;
    }
}

char	*gethome(t_env *env)
{
	t_env	*tmp;

	tmp = env;
	while (tmp && ft_strncmp(tmp->name, "HOME", 4) != 0)
		tmp = tmp->next;
	if (tmp)
		return (tmp->value);
	return (NULL);
}

int	count(char **cmd)
{
	int	i;

	i = 0;
	while (cmd[i + 1])
		i ++;
	return (i);
}

int	cd(char **cmd, t_env *env)
{
	int i;
	char *home;

	i = 1;
	if (count(cmd) > 1)
		return (perror("too many arguments"), 1);
	if (!cmd[i])
	{
		home = gethome(env);
		if (!home)
			return (perror ("Can't access to home"), 1);
		//printf("%s", home);
		if (chdir(home) != 0)
			return (perror ("Bad file"), 1);
	}
	else
	{
		if (chdir(cmd[i]) != 0)
			return (perror(cmd[i]), 1);
	}
	return (0);
}

int main(int argc, char **argv, char **env)
{
	(void)argc;
	t_env *en;
	en = create_own_env(env);
	printList(en);
 	int a = cd(argv, en);
	return (0);
}

