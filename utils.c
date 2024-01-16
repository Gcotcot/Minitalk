/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcot <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 10:36:41 by gcot              #+#    #+#             */
/*   Updated: 2023/04/24 10:43:28 by gcot             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_print(char *str, int i)
{
	if (!str)
		return ;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	ft_strlen(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}
/*
char	*ft_realoc_add(char *str, int len, char c)
{
	char	*new;
	int		i;

	i = 0;
	if (!str)
	{
		new = malloc(sizeof(*new) * 2);
		new[0] = c;
		new[1] = '\0';
		return (new);
	}
	new = malloc(sizeof(*new) * len + 2);
	while (str[i])
	{
		new[i] = str[i];
		i++;
	}
	new[i] = c;
	new[i + 1] = '\0';
	free(str);
	return (new);
}*/

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*(char *)(s + i) = c;
		i++;
	}
	return (s);
}

int	ft_atoi(char *str)
{
	int	i;
	int	pid;

	i = 0;
	pid = 0;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		pid = pid * 10 + str[i] - '0';
		i++;
	}
	return (pid);
}

char	*ft_itoa(int i)
{
	char	*pid;
	int		g;
	int		c;

	g = i;
	c = 0;
	while (i > 0)
	{
		c++;
		i = i / 10;
	}
	pid = malloc(sizeof(*pid) * c + 1);
	pid[c] = '\0';
	c--;
	while (c >= 0)
	{
		if (g >= 10)
			pid[c] = (g % 10) + '0';
		else
			pid[c] = g + '0';
		g = g / 10;
		c--;
	}
	return (pid);
}
