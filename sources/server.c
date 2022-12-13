/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ada-cruz <ada-cruz@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 19:11:23 by ada-cruz          #+#    #+#             */
/*   Updated: 2022/12/12 15:24:52 by ada-cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

t_char	g_char;

void	init_char(void)
{
	g_char.bitshifted_counter = 0;
	g_char.assembled_char = '\0';
}

void	print_pid(void)
{
	ft_putnbr_fd(getpid(), STDOUT_FILENO);
	ft_putchar_fd('\n', STDOUT_FILENO);
}

void	print_character(int signal)
{
	if (signal == SIGUSR1)
		g_char.assembled_char += (0b00000001 << g_char.bitshifted_counter);
	if (g_char.bitshifted_counter == 7)
	{
		ft_putchar_fd(g_char.assembled_char, STDOUT_FILENO);
		init_char();
		return ;
	}
	g_char.bitshifted_counter++;
}

void	send_sinal(void)
{
	signal(SIGUSR1, print_character);
	signal(SIGUSR2, print_character);
	while (1)
		pause();
}

int	main(void)
{
	init_char();
	print_pid();
	send_sinal();
	return (0);
}
