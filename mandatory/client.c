/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zogrir <zogrir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 12:09:28 by zogrir            #+#    #+#             */
/*   Updated: 2025/01/28 14:27:01 by zogrir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

void	ft_send_message(int pid, char character)
{
	int	i;
	int	bit;

	i = 7;
	bit = 0;
	while (i >= 0)
	{
		bit = (character >> i) & 1;
		if (bit == 1)
			kill(pid, SIGUSR1);
		else if (bit == 0)
			kill(pid, SIGUSR2);
		usleep(500);
		i--;
	}
}

int	main(int ac, char **av)
{
	int		pid;
	char	*message;

	if (ac != 3)
		return (ft_putstr_fd("\033[1;31m🛑ERROR:ARG Problem\033[0m\n", 2), 0);
	if (av[1][0] == '-')
		return (ft_putstr_fd("\033[1;31m🛑ERROR:PID Problem\033[0m\n", 2), 0);
	pid = ft_atoi(av[1]);
	if (pid <= 0)
		return (ft_putstr_fd("\033[1;31m🛑ERROR: failed\033[0m\n", 2), 0);
	message = av[2];
	while (*message != '\0')
	{
		ft_send_message(pid, *message);
		message++;
	}
	ft_send_message(pid, '\n');
}
