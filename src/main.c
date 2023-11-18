/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkost <rkost@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 11:11:58 by rkost             #+#    #+#             */
/*   Updated: 2023/11/18 11:13:39 by rkost            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	main(int ac, char **ag, char **envp)
{
	t_arg	*argument;

	argument = NULL;
	if (ac != 5)
		ft_throw_error("Missing arguments \n", &argument);
	else
		argument = ft_read_arg(ag, envp);
	ft_forking(&argument);
	ft_free_struct_arg(&argument);
}
