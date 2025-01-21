/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zogrir <zogrir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 17:11:38 by zogrir            #+#    #+#             */
/*   Updated: 2025/01/13 10:56:58 by zogrir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"



void header(void)
{
    ft_putstr_fd("\033[38;2;0;255;0m", 1); // Set color to green
    ft_putstr_fd("\n\n", 1);
    ft_putstr_fd("  ______ ______________  __ ___________ \n", 1);
    ft_putstr_fd(" /  ___// __ \\_  __ \\  \\/ // __ \\_  __ \\\n", 1);
    ft_putstr_fd(" \\___ \\\\  ___/|  | \\/\\   /\\  ___/|  | \\/\n", 1);
    ft_putstr_fd(" /____  >\\___  >__|    \\_/  \\___  >__|   \n", 1);
    ft_putstr_fd("      \\/     \\/                 \\/       \n", 1);
    ft_putstr_fd("\n", 1);
    ft_putstr_fd("  ___.                                    \n", 1);
    ft_putstr_fd("  \\_ |__   ____   ____  __ __  ______     \n", 1);
    ft_putstr_fd("   | __ \\ /  _ \\ /    \\|  |  \\/  ___/     \n", 1);
    ft_putstr_fd("   | \\_\\ (  <_> )   |  \\  |  /\\___ \\      \n", 1);
    ft_putstr_fd("   |___  /\\____/|___|  /____//____  >     \n", 1);
    ft_putstr_fd("       \\/            \\/           \\/      \n", 1);
    ft_putstr_fd("\n", 1);
    ft_putstr_fd("  Process Id (PID) : ", 1);
    ft_putnbr(getpid());
    ft_putchar('\n');
}



void signlHandler(int sig, siginfo_t *info, void *just)
{
    static int bit_count = 0;
    static char received_char = 0;
    static int pid;

	(void)just;
	pid = info->si_pid;
	if(pid != info->si_pid)
	{
		bit_count = 0;
		received_char = 0;
	}
	if(sig== SIGUSR1)
		received_char = received_char << 1 | 1;
	else
		received_char = received_char << 1 | 0;
	bit_count++;
	while (bit_count == 8)
	{
		if (received_char == 0)
		{
			write(1, "\n", 1);		
		}
		else
			write(1, &received_char, 1);
			
		bit_count = 0;
		received_char = 0;
	}
}

int main()
{
	struct sigaction sg;
	sg.sa_sigaction = signlHandler; 
	sg.sa_flags = SA_SIGINFO;
	if(sigaction(SIGUSR1, &sg, 0) == -1 || sigaction(SIGUSR2, &sg, 0) == -1)
	{
		ft_putstr_fd("error 1", 2);
		_exit(0);
	}
	header();
	while (1)
		pause();
}
