/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momeaizi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 13:23:23 by momeaizi          #+#    #+#             */
/*   Updated: 2022/02/02 15:58:11 by momeaizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>

//client
int				ft_atoi(char *str);
void			send(unsigned char *str);
void			sig(unsigned char c, int i);
void			sig_handler(int sig, siginfo_t *info, void *context);
//server
void			ft_putnbr(int pid);
void			sig_handler(int sig, siginfo_t *info, void *context);
unsigned char	*ft_strjoin(unsigned char c, unsigned char *str);
void			ft_strcpy(unsigned char *dst, unsigned char     *src, unsigned char c);

#endif
