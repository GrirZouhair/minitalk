/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zogrir <zogrir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 12:09:28 by zogrir            #+#    #+#             */
/*   Updated: 2025/01/11 14:33:20 by zogrir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minitalk.h"

void ft_send_message(int PID, char character)
{
	int	i;
	int bit;
	
	i = 7;
	while (i >= 0)
	{
		bit = (character >> i) & 1;
		if (bit == 1)
		{
			kill(PID, SIGUSR1);
		}
		else if (bit == 0)
		{
			kill(PID, SIGUSR2);
		}
		usleep(500);
		i--;
	}
}


int main(int ac, char **av)
{
    int PID;
    char *message;

    if (ac != 3)
    {
        ft_putstr_fd("\033[1;31m🛑ERROR: Argument Problem\033[0m\n", 2);
        return 1;
    }

    if (av[1][0] == '-')
    {
        ft_putstr_fd("\033[1;31m🛑ERROR: PID Problem \033[0m\n", 2);
        return 1;
    }

    PID = ft_atoi(av[1]);
    message = av[2];

    printf("\033[1;34m📤 Sending message to server: \"%s\"\033[0m\n", message);

    while (*message != '\0')
    {
        ft_send_message(PID, *message);
        message++;
    }
    ft_send_message(PID, '\n');

    printf("\033[1;32m✅ Message sent successfully!\033[0m\n");
    return 0;
}
