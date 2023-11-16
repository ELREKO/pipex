/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkost <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 20:44:37 by rkost             #+#    #+#             */
/*   Updated: 2023/05/16 20:59:36 by rkost            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_isspace(const char c)
{
	if (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

static int	get_isnb(const char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	return (-1);
}

int	ft_atoi(const char *str)
{
	int				count;
	int				puffer;
	unsigned long	ret;
	int				sign;

	ret = 0;
	count = 0;
	sign = 1;
	while (get_isspace(str[count]))
		count++;
	if (str[count] == '+' || str[count] == '-')
		if (str[count++] == '-')
			sign = -1;
	while (get_isnb(str[count]) != -1)
	{
		puffer = get_isnb(str[count]);
		if (sign == 1 && (ret > 2147483647))
			return (-1);
		else if (sign == -1 && (ret > 2147483648))
			return (0);
		ret = ret * 10 + puffer;
		count++;
	}
	return (ret * sign);
}
