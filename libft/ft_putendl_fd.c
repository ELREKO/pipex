/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkost <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 16:56:39 by rkost             #+#    #+#             */
/*   Updated: 2023/05/29 16:58:31 by rkost            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	size_t	count;

	if (s == NULL)
		return ((void) NULL);
	count = 0;
	while (s[count])
	{
		write(fd, &s[count], 1);
		count++;
	}
	write (fd, "\n", 1);
}
