/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ada-cruz <ada-cruz@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 17:17:43 by ada-cruz          #+#    #+#             */
/*   Updated: 2022/12/12 15:27:12 by ada-cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include <unistd.h>

# include "../library/libft/libft.h"

void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
int		ft_atoi(const char *nptr);
size_t	ft_strlen(const char *s);

typedef struct s_char
{
	int		bitshifted_counter;
	char	assembled_char;
}t_char;

#endif