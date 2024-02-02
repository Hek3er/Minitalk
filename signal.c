/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azainabi <azainabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 08:51:35 by azainabi          #+#    #+#             */
/*   Updated: 2024/02/02 09:03:41 by azainabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_sig(pid_t pid, int sig)
{
	if (kill(pid, sig) == -1)
	{
		ft_putstr_fd("Coudn't send the signal!\n", 2);
		exit(1);
	}
}
