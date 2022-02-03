/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 15:33:22 by momeaizi          #+#    #+#             */
/*   Updated: 2022/02/03 11:26:27 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	ft(unsigned char *dst, unsigned char *src, unsigned char c)
{
	int	i;

	i = 0;
	if (src)
	{
		while (src[i])
		{
			dst[i] = src[i];
			i++;
		}
	}
	dst[i++] = c;
	dst[i] = 0;
}

unsigned char	*ft_strjoin(unsigned char c, unsigned char *str)
{
	unsigned char	*msg;
	int				i;

	i = 0;
	if (str)
		while (str[i])
			i++;
	if (!c)
	{
		write(1, str, i);
		return (str);
	}
	msg = (unsigned char *)malloc((i + 2) * sizeof(unsigned char));
	if (!msg)
	{
		free(str);
		write(2, "ERROR!\n", 7);
		return (0);
	}
	ft(msg, str, c);
	if (str)
		free(str);
	return (msg);
}

void	sig_handler(int sig, siginfo_t *info, void *context)
{
	static unsigned char	c = 0;
	static int				i = 0;
	static unsigned char	*msg = NULL;

	(void)context;
	c *= 2;
	if (sig == SIGUSR2)
		c += 1;
	i++;
	if (i == 8)
	{
		msg = ft_strjoin(c, msg);
		if (!c)
		{
			free(msg);
			msg = NULL;
			kill(info->si_pid, SIGUSR1);
		}
		i = 0;
		c = 0;
	}
}

void	ft_putnbr(int pid)
{
	char	c;

	if (pid >= 10)
		ft_putnbr(pid / 10);
	c = pid % 10 + '0';
	write(1, &c, 1);
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	sa;

	sa.sa_sigaction = sig_handler;
	sa.sa_flags = SA_SIGINFO;
	pid = getpid();
	ft_putnbr(pid);
	write(1, "\n", 1);
	if (sigaction(SIGUSR1, &sa, NULL))
		write(2, "ERROR!\n", 7);
	if (sigaction(SIGUSR2, &sa, NULL))
		write(2, "ERROR!\n", 7);
	while (1)
		pause();
}
