/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcot <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 10:43:45 by gcot              #+#    #+#             */
/*   Updated: 2023/04/24 10:49:51 by gcot             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdio.h>
# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include <stdio.h>

void	ft_print(char *str, int i);
void	*ft_memset(void *s, int c, size_t n);
void	reception(int sig);
char	*ft_realoc_add(char *str, int len, char c);
char	*ft_itoa(int i);
int		ft_atoi(char *str);
int		ft_strlen(char *str);
int		encoding(int c, int pid);
int		ft_error(char *str);

#endif
