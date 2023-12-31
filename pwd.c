/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomes-g <agomes-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 10:02:52 by agomes-g          #+#    #+#             */
/*   Updated: 2023/10/11 07:29:42 by agomes-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nico/includes/minishell.h"

void	pwd(char **cmd)
{
	char	*pwd;
	
	if (cmd[1])
	{
		if (cmd[1][0] == '-')
		{
			printf("Invalid option\n");
			return ;
		}
	}
	pwd = getcwd(NULL, 0);
	if (!pwd)
		perror("Can't get pwd");
	printf("%s\n", pwd);
	free(pwd);
}

int main(int argc, char **argv)
{
	(void)argc;
	pwd(argv);
	return (0);
}