/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadina <dadina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 20:29:15 by dadina            #+#    #+#             */
/*   Updated: 2021/12/08 20:54:15 by dadina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <stdlib.h>
# include <signal.h>

# define R	"\x1b[31m"
# define G	"\x1b[32m"
# define Y	"\x1b[33m"
# define RS	"\x1b[0m"

size_t		ft_strlen(const char *s);
void		ft_putstr_fd(char *s, int fd);
void		ft_putnbr_fd(long long n, int fd);
void		ft_putchar_fd(char c, int fd);
int			ft_isdigit(int c);
int			ft_atoi(const char *str);
int			ft_is_space(int c);

#endif
