/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomes-g <agomes-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 08:02:36 by agomes-g          #+#    #+#             */
/*   Updated: 2023/10/11 09:32:38 by agomes-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nico/includes/minishell.h"

int	digits(char *s)
{
	int	i;

	i = 0;
	if (s[i] == '-')
		i ++;
	while(s[i])
	{
		if (!(ft_isdigit(s[i])))
			return (0);
		i ++;
	}
	return (1);
}

unsigned int my_exit(char **cmd, t_env *env)//, t_cmd *scmd)
{
	unsigned int	nb;

	printf("exit\n");
	if (cmd[1])
	{
		if(cmd[2])
		{
			printf("minishell: exit : Too many arguments\n");
			return (1);
		}
	}
	clear_env(env);
	//clear_cmd(scmd);
	if (!cmd[1])
		exit(0);
	if (digits(cmd[1]) == 0)
	{
		printf("minishell: exit: %s: numeric argument required\n", cmd[1]);
		exit (2);
	}
	else
		exit((unsigned int)ft_atoi(cmd[1]));
	
}

int	main(int argc, char **argv, char **env)
{
	t_env *en;
	en = create_own_env(env);
	printf("%u\n", my_exit(argv, en));
	return (0);
}