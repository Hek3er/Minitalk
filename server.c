/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azainabi <azainabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 01:00:14 by azainabi          #+#    #+#             */
/*   Updated: 2024/02/01 02:09:19 by azainabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_1(char *c, int *count)
{
	*c = (*c << 1) | 1;
	if (*count == 8)
	{
		if (*c == '\0')
			write(1, "\n", 1);
		write(1, c, 1);
		*count = 0;
		*c = 0;
	}
}

void	handle_2(char *c, int *count)
{
	*c = (*c << 1);
	if (*count == 8)
	{
		if (*c == '\0')
			write(1, "\n", 1);
		write(1, c, 1);
		*count = 0;
		*c = 0;
	}
}

void	handler(int sig, siginfo_t *info, void *context)
{
	static int		count = 0;
	static char		c = 0;
	static pid_t	pid = 0;

	(void)context;
	if (pid == 0)
		pid = info->si_pid;
	if (pid != info->si_pid)
	{
		c = 0;
		count = 0;
		pid = info->si_pid;
	}
	count++;
	if (sig == SIGUSR1)
		handle_1(&c, &count);
	else if (sig == SIGUSR2)
		handle_2(&c, &count);
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	action;

	pid = getpid();
	ft_putstr_fd("\033[1;31mServer PID --> \033[1;0m", 1);
	ft_putnbr_fd(pid, 1);
	ft_putstr_fd("\n", 1);
	action.sa_flags = SA_SIGINFO;
	action.sa_handler = NULL;
	action.sa_sigaction = &handler;
	if (sigaction(SIGUSR1, &action, NULL) == -1)
		ft_putstr_fd("sigaction failed!", 2);
	if (sigaction(SIGUSR2, &action, NULL) == -1)
		ft_putstr_fd("sigaction failed!", 2);
	while (1)
	{
		pause();
	}
}
