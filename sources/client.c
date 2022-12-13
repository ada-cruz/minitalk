/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ada-cruz <ada-cruz@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 22:41:31 by ada-cruz          #+#    #+#             */
/*   Updated: 2022/12/12 15:59:11 by ada-cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	error(char *msg)
{
	ft_putstr_fd(msg, STDERR_FILENO);
	exit(EXIT_FAILURE);
}

void	send(pid_t pid, char *msg)
{
	int	i;
	int	bits_shifted;
	int	kill_status;

	i = 0;
	while (msg[i] != '\0')
	{
		bits_shifted = 0;
		while (bits_shifted < 8)
		{
			if ((msg[i] >> bits_shifted) & 0b00000001)
				kill_status = kill(pid, SIGUSR1);
			else
				kill_status = kill(pid, SIGUSR2);
			if (kill_status == -1)
				error("Kill error\n");
			bits_shifted++;
			usleep(500);
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid;

	if (argc != 3)
		error("invalid arguments.\n");
	if (ft_strlen(argv[1]) > 7)
		error("invalid PID.\n");
	pid = ft_atoi(argv[1]);
	send(pid, argv[2]);
	return (0);
}
