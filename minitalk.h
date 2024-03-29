/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azainabi <azainabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 02:05:45 by azainabi          #+#    #+#             */
/*   Updated: 2024/02/02 09:03:17 by azainabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h> 
# include <stdlib.h>

typedef struct s_var
{
	int		i;
	int		asc;
	int		count;
	int		byte;
	pid_t	pid;
	char	s[4];
}				t_var;

void	ft_putstr_fd(char *str, int fd);
void	ft_putchar(int c);
void	send_sig(pid_t pid, int sig);
void	ft_putnbr_fd(int n, int fd);
int		ft_strlen(char *str);
int		ft_atoi(const char *str);

#endif