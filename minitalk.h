#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>

//							client
int				ft_atoi(char *str);
void			send(unsigned char *str);
void			sig(unsigned char c, int i);
void			sig_handler(int sig, siginfo_t *info, void *context);

//							server
void			ft_putnbr(int pid);
void			sig_handler(int sig, siginfo_t *info, void *context);
unsigned char	*ft_strjoin(unsigned char c, unsigned char *str);
void			ft(unsigned char *dst, unsigned char *src, unsigned char c);

#endif
