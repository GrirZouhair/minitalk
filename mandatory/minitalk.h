/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zogrir <zogrir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 12:21:44 by zogrir            #+#    #+#             */
/*   Updated: 2025/01/09 12:19:23 by zogrir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
#define MINITALK_H

#include<signal.h>
#include<unistd.h>
#include<stdio.h>

void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr(int n);
void	ft_putchar(char c);
int		ft_atoi(const char *str);
int		ft_isdigit(int c);


#endif