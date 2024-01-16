/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serveur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcot <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 09:59:16 by gcot              #+#    #+#             */
/*   Updated: 2023/04/18 09:59:18 by gcot             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_bo = -1;

char	*confirm_2(char *str, int pid, int len, void *context)
{
	if (str)
	{
		str[g_bo - 1] = '\n';
		str[g_bo] = '\0';
		ft_print(str, 0);
		free(str);
		str = NULL;
		g_bo = -1;
		len = 0;
	}
	else
	{
		str = malloc(sizeof(*str) * len + 2);
		g_bo = -g_bo;
	}
	(void)context;
	kill(pid, SIGUSR2);
	return (str);
}

void	confirm(int sig, siginfo_t *info, void *context)
{
	static int	i = 0;
	static int	len = 0;
	static char	c = 0;
	static char	*str = NULL;

	c |= (sig == SIGUSR2);
	if (++i == 8)
	{
		i = 0;
		if (!c)
		{
			str = (confirm_2(str, info->si_pid, len, context));
			return ;
		}
		if (g_bo < 0)
			len = len * 10 + (c - 48);
		else
			str[++g_bo - 2] = c;
		c = 0;
	}
	else
		c <<= 1;
	kill(info->si_pid, SIGUSR1);
}

/*
void	confirm(int sig, siginfo_t *info, void *context)
{
	static int				i = 0;
	static char	c = 0;
	static char	*str = NULL;

	(void)context;
	c |= (sig == SIGUSR2);
	if (++i == 8)
	{
		i = 0;
		if (!c)
		{
			str = ft_realoc_add(str, ft_strlen(str), '\n');
			ft_print(str, 0);
			free(str);
			str = NULL;
			kill(info->si_pid, SIGUSR2);
			return ;
		}
		str = ft_realoc_add(str, ft_strlen(str), c);
		c = 0;
		kill(info->si_pid, SIGUSR1);
	}
	else
		c <<= 1;
}*/

int	main(void)
{
	int					pid;
	struct sigaction	sig;

	ft_memset((void *)&sig.sa_mask, 0, 15 * sizeof(unsigned long));
	pid = getpid();
	printf("pid [%i]\n", pid);
	sig.sa_sigaction = confirm;
	sig.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	while (1)
		pause();
	return (0);
}
