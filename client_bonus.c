/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 15:33:07 by momeaizi          #+#    #+#             */
/*   Updated: 2022/02/03 11:53:07 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int	g_pid;

void	sig_handler(int sig, siginfo_t *info, void *context)
{
	(void)context;
	if (sig == SIGUSR1)
		if (info->si_pid == g_pid)
			write(1, "SERVER : message has been received!\n", 36);
}

void	sig(unsigned char c, int i)
{
	int	error;

	error = 0;
	if (i < 7)
		sig(c / 2, i + 1);
	if (!(c % 2))
		error = kill(g_pid, SIGUSR1);
	else
		error = kill(g_pid, SIGUSR2);
	if (error == -1)
	{
		write(2, "Bad pid!\n", 9);
		exit (1);
	}
	usleep (100);
}

void	send(unsigned char *str)
{
	int	i;

	i = 0;
	while (str[i])
		sig(str[i++], 0);
	sig(str[i], 0);
	usleep((i + 1) * 100);
}

int	ft_atoi(char *str)
{
	int		i;
	int		nbr;
	char	sign;

	i = 0;
	nbr = 0;
	sign = 1;
	if (str[i] == '-')
		sign = -(++i);
	while (str[i] >= '0' && str[i] <= '9')
		nbr = (nbr * 10) + str[i++] - '0';
	return (nbr * sign);
}

int	main(int ac, char **av)
{
	struct sigaction	sa;

	if (ac != 3)
		return (0);
	g_pid = ft_atoi(av[1]);
	if (g_pid == -1)
	{
		write(2, "Bad pid!\n", 9);
		exit (1);
	}
	sa.sa_sigaction = &sig_handler;
	sa.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sa, NULL))
		write(2, "ERROR!\n", 7);
	send(((unsigned char *)av[2]));
	return (0);
}
