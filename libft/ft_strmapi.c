/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkost <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 17:02:06 by rkost             #+#    #+#             */
/*   Updated: 2023/05/29 17:04:47 by rkost            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*ret;
	size_t	count;

	if (!s || !f)
		return (NULL);
	ret = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (ret == NULL)
		return (NULL);
	count = 0;
	while (s[count] != '\0')
	{
		ret[count] = f(count, s[count]);
		count++;
	}
	ret[count] = '\0';
	return (ret);
}
