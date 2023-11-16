/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkost <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 16:20:06 by rkost             #+#    #+#             */
/*   Updated: 2023/05/29 16:21:26 by rkost            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char *str, char sep);
static void	write_word(char *dest, char *from, char sep);
static int	compare(char **split, int *word, int *j);
static void	*write_split(char **split, char *str, char sep);

char	**ft_split(const char *s, char c)
{
	char	**res;
	char	*str;
	int		words;

	if (s == NULL)
		return (NULL);
	str = (char *)s;
	words = count_words(str, c);
	res = (char **)malloc(sizeof(char *) * (words + 1));
	if (res == NULL)
		return (NULL);
	res[words] = NULL;
	if (write_split(res, str, c) == NULL)
		return (NULL);
	return (res);
}

static int	count_words(char *str, char sep)
{
	int	i;
	int	words;

	words = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i + 1] == sep || str[i + 1] == '\0')
			&& (str[i] != sep && str[i] != '\0'))
			words++;
		i++;
	}
	return (words);
}

static void	write_word(char *dest, char *from, char sep)
{
	int	i;

	i = 0;
	while (from[i] != sep && from[i] != '\0')
	{
		dest[i] = from[i];
		i++;
	}
	dest[i] = '\0';
}

static int	compare(char **split, int *word, int *j)
{
	split[*word] = (char *)malloc(sizeof(char) * (*j + 1));
	if (split[*word] == NULL)
	{
		while (*word > 0)
			free(split[*--word]);
		return (0);
	}
	return (1);
}

static void	*write_split(char **split, char *str, char sep)
{
	int		i;
	int		j;
	int		word;

	word = 0;
	i = 0;
	while (str[i] != '\0' )
	{
		if ((str[i] == sep || str[i] == '\0'))
			i++;
		else
		{
			j = 0;
			while (str[i + j] != sep && str[i + j] != '\0')
				j++;
			if (compare(split, &word, &j) == 0)
				return (NULL);
			write_word(split[word], str + i, sep);
			i += j;
			word++;
		}
	}
	return ((void *)1);
}

