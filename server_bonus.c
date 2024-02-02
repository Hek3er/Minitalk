/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azainabi <azainabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 22:57:39 by azainabi          #+#    #+#             */
/*   Updated: 2024/02/02 10:46:31 by azainabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	reset(int *i, int *j)
{
	*i = 0;
	*j = 0;
}

static void	init(t_var *var, pid_t pid)
{
	var->i = 0;
	while (var->i < 4)
		var->s[var->i++] = 0;
	reset(&var->i, &var->count);
	reset(&var->asc, &var->byte);
	var->pid = pid;
}

static void	uni(t_var *var)
{
	if (var->i == 0)
	{
		if (var->asc >= 240)
			var->byte = 4;
		else if (var->asc >= 224)
			var->byte = 3;
		else if (var->asc >= 192)
			var->byte = 2;
	}
	if (var->i < var->byte)
		var->s[var->i++] = var->asc;
	if (var->i == var->byte)
	{
		write(1, &var->s, var->byte);
		while (var->i--)
			var->s[var->i] = 0;
		reset(&var->i, &var->byte);
	}
}

static void	handler(int sig, siginfo_t *info, void *context)
{
	static t_var	var;
	int				signal1;

	(void)context;
	signal1 = 0;
	if (!var.pid)
		var.pid = info->si_pid;
	if (var.pid != info->si_pid)
		init(&var, info->si_pid);
	if (sig == SIGUSR1)
		signal1 = 1;
	var.asc = (var.asc << 1) | signal1;
	if (++var.count == 8)
	{
		if (var.asc == 0)
		{
			write(1, "\n", 1);
			send_sig(var.pid, SIGUSR1);
		}
		else if (var.asc > 127)
			uni(&var);
		else
			ft_putchar(var.asc);
		reset(&var.asc, &var.count);
	}
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
