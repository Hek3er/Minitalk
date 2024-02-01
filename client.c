/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azainabi <azainabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 01:02:05 by azainabi          #+#    #+#             */
/*   Updated: 2024/02/01 02:06:25 by azainabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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
	if (ac == 3)
	{
		if (ft_atoi(av[1]) <= 0)
		{
			ft_putstr_fd("Error in PID\n", 2);
			exit(2);
		}
		send_signal(av[1], av[2]);
	}
}
