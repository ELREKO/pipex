/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkost <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 21:41:40 by rkost             #+#    #+#             */
/*   Updated: 2023/06/02 18:21:50 by rkost            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size_dest)
{
	size_t	count;
	size_t	src_len;

	src_len = ft_strlen(src);
	if (!size_dest)
		return (src_len);
	count = 0;
	while ((src[count] != '\0') && (count < size_dest - 1))
	{
		dest[count] = src[count];
		count++;
	}
	dest[count] = '\0';
	return (src_len);
}
