/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zogrir <zogrir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 12:21:07 by zogrir            #+#    #+#             */
/*   Updated: 2025/01/08 17:03:49 by zogrir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minitalk.h"

void header(void)
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


void signlHandler(int sg, siginfo_t *info, void *just)
{
	static	int	c;
}

int main(int ac, char **av)
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