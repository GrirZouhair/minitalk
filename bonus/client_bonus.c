/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zogrir <zogrir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 17:11:40 by zogrir            #+#    #+#             */
/*   Updated: 2025/01/26 13:37:15 by zogrir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

void	signal_handler(int signl)
{
	if (SIGUSR1 == signl)
		ft_putstr_fd("\033[1;32m✅ Message sent successfully!\033[0m\n", 1);
}

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
	int			pid;
	char		*message;

	if (ac != 3)
		return (ft_putstr_fd("\033[1;31m🛑ERROR: ARG Problem\033[0m\n", 2), 0);
	if (av[1][0] == '-')
		return (ft_putstr_fd("\033[1;31m🛑ERROR: pid Problem \033[0m\n", 2), 0);
	signal(SIGUSR1, signal_handler);
	pid = ft_atoi(av[1]);
	message = av[2];
	while (*message != '\0')
	{
		ft_send_message(pid, *message);
		message++;
	}
	ft_send_message(pid, '\0');
}
