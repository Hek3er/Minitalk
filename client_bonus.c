/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azainabi <azainabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 22:59:19 by azainabi          #+#    #+#             */
/*   Updated: 2024/02/01 02:06:53 by azainabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int sig)
{
	(void)sig;
	ft_putstr_fd("\033[1;32mMessage Recieved.\033[1;0m\n", 1);
	exit(1);
}

void	send_signal(char *pid, char *str)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (i <= ft_strlen(str))
	{
		j = 7;
		c = str[i];
		while (j >= 0)
		{
			if ((c >> j) & 1)
				kill(ft_atoi(pid), SIGUSR1);
			else
				kill(ft_atoi(pid), SIGUSR2);
			j--;
			usleep(1000);
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	struct sigaction	act;

	if (ac == 3)
	{
		if (ft_atoi(av[1]) <= 0)
		{
			ft_putstr_fd("Error in PID\n", 2);
			exit(2);
		}
		act.sa_flags = SA_RESTART;
		act.sa_handler = handler;
		sigaction(SIGUSR1, &act, NULL);
		send_signal(av[1], av[2]);
		pause();
	}
}
