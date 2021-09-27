/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayajrhou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 19:41:41 by ayajrhou          #+#    #+#             */
/*   Updated: 2019/10/21 22:02:19 by ayajrhou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	nbr;
	unsigned int	f;

	nbr = n;
	if (n < 0)
	{
		write(fd, "-", 1);
		nbr = -n;
	}
	if (nbr >= 10)
	{
		ft_putnbr_fd(nbr / 10, fd);
		f = nbr % 10 + 48;
		write(fd, &f, 1);
	}
	else
	{
		f = nbr + 48;
		write(fd, &f, 1);
	}
}
