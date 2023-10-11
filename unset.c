/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomes-g <agomes-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 06:26:17 by agomes-g          #+#    #+#             */
/*   Updated: 2023/10/11 07:16:54 by agomes-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nico/includes/minishell.h"

void	sort_list(t_env *env) //ajouter les changements avec val
{
	char	*name;
	char	*value;
	t_env	*tmp;

	while (env != NULL)
	{
		tmp = env->next;
		while (tmp != NULL)
		{
			if (ft_strncmp(env->name, tmp->name, ft_strlen(env->name)) == 1)
			{
				name = env->name;
				value = env->value;
				env->name = tmp->name;
				env->value = tmp->value;
				tmp->name = name;
				tmp->value = value;
			}
			tmp = tmp->next;
		}
		env = env->next;
	}
}

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


void	delete_element(char *name, t_env *env)
{
	t_env	*tmp;
	t_env	*new;

	tmp = env->next;
	new = env;
	if (!(ft_strncmp(env->name, name, ft_strlen(tmp->name))))
	{
		env = env->next;
		return ;
	}
	while (tmp && (ft_strncmp(tmp->name, name, ft_strlen(tmp->name)) != 0))
	{
		new = tmp;
		tmp = tmp->next;
	}
	if (tmp)
	{
		new->next = tmp->next;
		free(tmp->name);
		if (tmp->value)
			free(tmp->value);
		free(tmp);
	}
}

void	unset(char **cmd, t_env *env)
{
	int		i;
	t_env	*tmp;

	i = 1;
	if (!cmd[1])
		return ;
	if (cmd[i][0] == '-')
	{
		printf("Invalid option\n");
		return ;
	}
	while (cmd[i])
	{
		delete_element(cmd[i], env);
		i ++;
	}
}

int	main(int argc, char **argv, char **env)
{
	(void)argc;
	t_env *en;
	en = create_own_env(env);
	//sort_list(en);
	//printList(en);
	unset(argv, en);
	printf("\n--------------------\n");
	printList(en);
	clear_env(en);
	// 
	// sort_list(en);
	// printf("\n\n");
	// printList(en);
	return (0);
}