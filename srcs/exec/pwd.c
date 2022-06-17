/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocartier <ocartier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 09:01:41 by ocartier          #+#    #+#             */
/*   Updated: 2022/06/17 18:06:54 by ocartier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/*
	Minishell built-in function (pwd)
	Print the PWD from the env if found
*/
int	ft_pwd(t_mem *mem)
{
	char	*pwd;

	pwd = my_getenv(mem->my_env, "PWD");
	if (pwd)
	{
		write(1, pwd, ft_strlen(pwd));
		write(1, "\n", 1);
		mem->exit_statue = 0;
		free(pwd);
		exit(EXIT_SUCCESS);
	}
	else
	{
		ft_printf("\033[91m%s\033[0m\n",
			"minishell: pwd does not work if PWD is unset");
		mem->exit_statue = 1;
		exit(EXIT_FAILURE);
	}
}
