/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zogrir <zogrir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 12:21:07 by zogrir            #+#    #+#             */
/*   Updated: 2025/01/26 13:35:49 by zogrir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

void	header(void)
{
	ft_putstr_fd("\033[38;2;0;255;0m", 1);
	ft_putstr_fd("\n\n", 1);
	ft_putstr_fd("  ___  ___ _ ____   _____ _ __ \n", 1);
	ft_putstr_fd(" / __|/ _ \\ '__\\ \\ / / _ \\ '__|\n", 1);
	ft_putstr_fd(" \\__ \\  __/ |   \\ V /  __/ |   \n", 1);
	ft_putstr_fd(" |___/\\___|_|    \\_/ \\___|_|   \n", 1);
	ft_putstr_fd("\n", 1);
	ft_putstr_fd("	Process Id (PID) : ", 1);
	ft_putnbr(getpid());
	ft_putchar('\n');
}

void	signal_handler(int sig, siginfo_t *info, void *just)
{
	static int	bit_count = 0;
	static char	received_char = 0;
	static int	pid;

	(void)just;
	pid = info->si_pid;
	if (pid != info->si_pid)
	{
		bit_count = 0;
		received_char = 0;
	}
	if (sig == SIGUSR1)
		received_char = received_char << 1 | 1;
	else
		received_char = received_char << 1 | 0;
	bit_count++;
	while (bit_count == 8)
	{
		if (received_char == 0)
			write(1, "\n", 1);
		else
			write(1, &received_char, 1);
		bit_count = 0;
		received_char = 0;
	}
}

int	main(void)
{
	struct sigaction	sg;

	sg.sa_sigaction = signal_handler;
	sg.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sg, 0) == -1 || sigaction(SIGUSR2, &sg, 0) == -1)
		return (ft_putstr_fd("\033[1;31m🛑ERROR:\033[0m\n", 2), 0);
	header();
	while (1)
		pause();
}
