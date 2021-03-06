/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadina <dadina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 22:17:47 by dadina            #+#    #+#             */
/*   Updated: 2021/12/16 20:14:26 by dadina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	exit_error_msg(char *str)
{
	ft_putstr_fd(R"Error!\n"RS, 1);
	ft_putstr_fd(str, 1);
	exit(1);
}

void	signal_parse(int index, siginfo_t *info, void *u)
{
	static int	c;
	static int	i;

	(void)u;
	if (index == SIGUSR1)
		c += 1 << (7 - i);
	i++;
	if (i == 8)
	{
		if (c == 0)
		{
			if (kill(info->si_pid, SIGUSR2))
				exit_error_msg(R"\nFailing signing! Durak!"RS);
		}
		ft_putchar_fd(c, 1);
		i = 0;
		c = '\0';
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	t;
	int					i;

	i = 0;
	(void)argv;
	if (argc == 1)
	{
		while (++i < 30)
		{
			ft_putstr_fd(G". "RS, 1);
			usleep(45000);
		}
		ft_putstr_fd(G"\nServer init ✓\n"RS, 1);
		ft_putstr_fd(Y"Server PID:\t"RS, 1);
		ft_putnbr_fd(getpid(), 1);
		ft_putchar_fd('\n', 1);
		t.sa_sigaction = signal_parse;
		if (sigaction(SIGUSR1, &t, 0) == -1 || \
			sigaction(SIGUSR2, &t, 0) == -1)
			exit_error_msg(R"\nFailed signing!"RS);
		while (1)
			pause();
	}
	else
		exit_error_msg(Y"\nMany arguments!\nOnly argc == 1!\n"R);
}
