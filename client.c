/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcot <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 09:59:00 by gcot              #+#    #+#             */
/*   Updated: 2023/04/18 09:59:08 by gcot             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_bo = 0;

void	action(int sig)
{
	if (sig == SIGUSR2 && g_bo)
	{
		ft_print("Message received\n", 0);
		exit(0);
	}
	if (sig == SIGUSR1)
		return ;
}

void	mt_kill_int(int pid, int i)
{
	int		j;
	int		x;
	char	c;

	while (i > 0)
	{
		x = 8;
		j = i % 10;
		c = j + 48;
		i = i / 10;
		while (x--)
		{
			if (c >> x & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(100000);
		}
	}
	x = 8;
	while (x--)
	{
		kill(pid, SIGUSR1);
		usleep(100000);
	}
}

void	mt_kill(int pid, char *str)
{
	int		i;
	int		j;
	char	c;

	j = 0;
	while (str[j])
	{
		i = 8;
		c = str[j++];
		while (i--)
		{
			if (c >> i & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(100000);
		}
	}
	i = 8;
	while (i--)
	{
		kill(pid, SIGUSR1);
		usleep(100000);
	}
}

int	main(int argc, char **argv)
{
	if (argc != 3)
		return (ft_error("Error !\nUsage : [pid] [message]\n"));
	signal(SIGUSR1, action);
	signal(SIGUSR2, action);
	if (!ft_atoi(argv[1]))
		return (ft_error("Error : Invalid pid !\n"));
	if (kill(ft_atoi(argv[1]), SIGUSR1) == -1)
		return (ft_error("Error : Wrong pid !\n"));
	mt_kill_int(ft_atoi(argv[1]), ft_strlen(argv[2]));
	g_bo = 1;
	mt_kill(ft_atoi(argv[1]), argv[2]);
	while (1)
		pause();
	return (0);
}
