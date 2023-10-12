/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomes-g <agomes-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 07:45:29 by agomes-g          #+#    #+#             */
/*   Updated: 2023/10/12 08:09:39 by agomes-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nico/includes/minishell.h"

void my_env(char **cmd, t_env *env) 
{
    t_env	*lst;

	lst = env;
	if (cmd[1])
	{
		printf("Invalid option/args\n");
		return ;
	}
    while (lst != NULL)
	{
		if (lst->value)
        	printf("%s=%s\n", lst->name, lst->value);
		else if (lst->val)
			printf("%s=\"\"\n", lst->name);
        lst = lst->next;
    }
}

int	main(int argc, char **argv, char **env)
{
	t_env *en;
	en = create_own_env(env);
	my_env(argv, en);
	return (0);
}
