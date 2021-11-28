/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadina <dadina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 22:17:58 by dadina            #+#    #+#             */
/*   Updated: 2021/11/28 20:52:12 by dadina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	exit_error_msg(char *str)
{
	ft_putstr_fd(R"\nError!\n"RS, 1);
	ft_putstr_fd(str, 1);
	exit(1);
}

void	convers_dec(char c, int pid)
{
	int	i;
	int	b;

	b = 8;
	i = 0;
	while (i < b)
	{
		if ((c << i) & 128)
		{
			if (kill(pid, SIGUSR1) == -1)
				exit_error_msg(R"SIGUSR1 == -1\n"RS);
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				exit_error_msg(R"SIGUSR2 == -1\n"RS);
		}
		i++;
		usleep(125);
	}
}

int	ascii_to_bin(char *string, int pid)
{
	int	i;
	int	l;

	i = 0;
	l = ft_strlen(string);
	while (i <= l)
	{
		convers_dec(string[i], pid);
		i++;
	}
	return (0);
}

void	signal_sent(int index, siginfo_t *info, void *u)
{
	(void)index;
	(void)info;
	(void)u;
	ft_putstr_fd(G"gotovo blet \n"RS, 1);
	exit(0);
}

int	main(int argc, char **argv)
{
	struct sigaction	talk;

	talk.sa_sigaction = signal_sent;
	if ((sigaction(SIGUSR2, &talk, 0) == -1))
		exit_error_msg(R"\nFailed signing!\n"RS);
	if (argc == 1)
		exit_error_msg(Y"\nNO, PID!\nUse server PID!\n"RS);
	else if (argc == 2)
		exit_error_msg(Y"\nEnter a message to send!\n"RS);
	else if (argc == 3)
		ascii_to_bin(argv[2], ft_atoi(argv[1]));
	else
		exit_error_msg(Y"Many arguments!\nOnly argc == 3!\n"RS);
	while (1)
		pause();
	return (0);	
}
