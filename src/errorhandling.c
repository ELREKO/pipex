/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errorhandling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkost <rkost@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 11:02:56 by rkost             #+#    #+#             */
/*   Updated: 2023/11/18 11:07:10 by rkost            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"
#include <errno.h>

void	ft_throw_error(const char *msg, t_arg **arg)
{
	ft_free_struct_arg(arg);
	if (ft_strncmp(strerror(errno), "Success", ft_strlen(strerror(errno))) == 0)
		write(1, msg, ft_strlen(msg));
	else
		perror(msg);
	exit (0);
}

void	ft_free_struct_arg(t_arg **arg)
{
	if (*arg != NULL)
	{
		ft_free_map((*arg)->cmd_1);
		ft_free_map((*arg)->cmd_2);
		ft_free_str((*arg)->inflile);
		ft_free_str((*arg)->outfile);
		ft_free_str((*arg)->path_1);
		ft_free_str((*arg)->path_2);
		free(*arg);
	}
}

void	ft_free_str(char *str)
{
	if (str != 0)
		free(str);
}

void	ft_free_map(char **map)
{
	int	i_count;

	if (map != NULL)
	{
		i_count = 0;
		while (map[i_count] != NULL)
			i_count++;
		while (i_count >= 0)
			free(map[i_count--]);
		free(map);
	}
}
