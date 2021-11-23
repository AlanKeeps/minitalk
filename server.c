/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadina <dadina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 22:17:47 by dadina            #+#    #+#             */
/*   Updated: 2021/11/23 22:21:29 by dadina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

// void	signal_parse(int index, siginfo_t *info, void *u)

int	main(int argc, char **argv)
{
	struct sigaction	talk;
	int					i;

	i = 0;
	(void)argv;
	if (argc == 1)
	{
		while (++i < 17)
		{
			ft_putstr_fd(G". "RS, 1);
			usleep(45000);
		}
		ft_putstr_fd(G"\nServer init ✓\n"RS, 1);
		ft_putstr_fd(Y"Server PID:\t"RS, 1);
		ft_putnbr_fd(getpid(), 1);
		ft_putchar_fd('\n', 1);
		talk.sa_sigaction = signal_parse;
		if (sigaction(SIGUSR1, &talk, 0) == -1 || \
			sigaction(SIGUSR2, &talk, 0) == -1)
			exit_error_msg(R"\nFailed signing!"RS);
		while (1)
			pause();
	}
	else
		exit_error_msg(Y"\nMany arguments!\nOnly argc == 1!\n"R);
}
