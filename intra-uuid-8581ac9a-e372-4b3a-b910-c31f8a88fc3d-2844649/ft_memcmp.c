/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayajrhou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 17:04:07 by ayajrhou          #+#    #+#             */
/*   Updated: 2019/10/17 23:34:24 by ayajrhou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *b, const void *c, size_t len)
{
	unsigned char	*p;
	unsigned char	*q;
	int				i;

	p = (unsigned char *)b;
	q = (unsigned char *)c;
	i = 0;
	while (len > 0)
	{
		if (p[i] != q[i])
		{
			return (p[i] - q[i]);
		}
		len--;
		i++;
	}
	return (0);
}
