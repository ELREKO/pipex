/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkost <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 21:50:25 by rkost             #+#    #+#             */
/*   Updated: 2023/05/29 17:11:44 by rkost            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	*ft_strnstr(const char *haystack, const char *needle, unsigned int len)
{
	 unsigned int	i;
	int		j;

	if (*needle == '\0')
		return ((char *)haystack);
	i = 0;
	while (haystack[i] != '\0' && i < len)
	{
		if (haystack[i] == needle[0])
		{
			j = 0;
			while (needle[j] && haystack[i + j] && i + j < len
				&& haystack[i + j] == needle[j])
				j++;
			if (needle[j] == '\0')
				return ((char *)haystack + i);
		}
		i++;
	}
	return (0);
}

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

size_t	ft_strlen(const char *str)
{
	size_t	count;

	count = 0;
	while (str[count] != '\0')
		count++;
	return (count);
}


char	*ft_strchr(const char *str, int ch)
{
	int	count;

	count = 0;
	while (str[count])
	{
		if (str[count] == (char)ch)
			return ((char *)(str + count));
		count++;
	}
	if (str[count] == (char)ch)
		return ((char *)(str + count));
	return (NULL);
}


char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	count;
	size_t	s1_len;
	size_t	s2_len;
	char	*ret;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	ret = (char *)malloc((s1_len + s2_len + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	ret = ft_memmove(ret, s1, s1_len);
	count = 0;
	while (s2[count] != '\0')
	{
		ret[s1_len + count] = s2[count];
		count++;
	}
	ret[s1_len + count] = '\0';
	return (ret);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t		count;
	char		*mem_dest;
	const char	*mem_src;

	mem_dest = (char *)dest;
	mem_src = (const char *)src;
	count = 0;
	if (n <= 0 || dest == src)
		return (dest);
	if (mem_src < mem_dest)
	{
		while (n--)
			mem_dest[n] = mem_src[n];
		return (dest);
	}
	while (count < n)
	{
		mem_dest[count] = mem_src[count];
		count++;
	}
	return (dest);
}

char	*ft_strdup(const char *str)
{
	char	*ret;
	size_t	size_str;
	size_t	count;

	size_str = ft_strlen(str);
	ret = (char *)malloc((size_str + 1) * sizeof(char));
	if (ret == NULL)
		return (NULL);
	count = 0;
	while (str[count] != '\0')
	{
		ret[count] = str[count];
		count++;
	}
	ret[count] = '\0';
	return (ret);
}