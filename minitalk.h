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
int			ft_isdigit(int c);
int			ft_atoi(const char *str);
static int	ft_is_space(char ch);

#endif
