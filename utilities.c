/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azainabi <azainabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 21:51:54 by azainabi          #+#    #+#             */
/*   Updated: 2024/02/01 02:11:12 by azainabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

void	ft_putchar(int c)
{
	write(1, &c, 1);
}

void	ft_putstr_fd(char *str, int fd)
{
	int	i;

	i = 0;
	if (fd < 0)
		return ;
	if (!str)
		return ;
	while (str[i])
	{
		write(fd, &str[i], 1);
		i++;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	char		nb;
	long long	i;

	i = n;
	if (fd < 0)
		return ;
	if (i < 0)
	{
		write(fd, "-", 1);
		i *= -1;
	}
	if (i <= 9)
	{
		nb = i + 48;
		write(fd, &nb, 1);
	}
	else
	{
		ft_putnbr_fd(i / 10, fd);
		ft_putnbr_fd(i % 10, fd);
	}
}

int	ft_atoi(const char *str)
{
	int				i;
	int				neg;
	unsigned long	ret;

	i = 0;
	neg = 1;
	ret = 0;
	while (str[i] != '\0' && (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13)))
	{
		i++;
	}
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9'))
		ret = ret * 10 + (str[i++] - '0');
	if (ret > 9223372036854775807 && neg == 1)
		return (-1);
	else if (ret > 9223372036854775807)
		return (0);
	return (ret * neg);
}
