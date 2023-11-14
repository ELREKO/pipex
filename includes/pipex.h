#ifndef PIPEX_H
# define PIPEX_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

typedef struct s_list{
    char *str_tmp;
    char *str_path;
}   t_list;

char	*ft_strnstr(const char *haystack, const char *needle,  unsigned int len);
char	**ft_split(char const *s, char c);
size_t	ft_strlcpy(char *dest, const char *src, size_t size_dest);
size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *dest, const char *src, size_t size_dest);
char	*ft_strchr(const char *str, int ch);
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_memmove(void *dest, const void *src, size_t n);
char	*ft_strdup(const char *str);

#endif
