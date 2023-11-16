/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkost <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 22:03:08 by rkost             #+#    #+#             */
/*   Updated: 2023/05/29 13:54:46 by rkost            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*cw(char const *s, size_t count, size_t len, unsigned int start)
{
	char	*dst;

	if ((start + len) > ft_strlen(s))
		len = ft_strlen(s) - start;
	dst = (char *)malloc((len + 1) * sizeof(char));
	if (dst == NULL)
		return (NULL);
	while (count < len)
	{
		dst[count] = s[start + count];
		count++;
	}
	dst[count] = '\0';
	return (dst);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dst;
	size_t	count;

	count = 0;
	dst = NULL;
	if (s == NULL)
		return (NULL);
	if (ft_strlen(s) < start)
	{
		dst = (char *)malloc(sizeof(char));
		if (dst == NULL)
			return (NULL);
		dst[0] = '\0';
		return (dst);
	}
	else
	{
		dst = cw(s, count, len, start);
		return (dst);
	}
}
