/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayajrhou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 14:00:21 by ayajrhou          #+#    #+#             */
/*   Updated: 2019/10/17 19:12:15 by ayajrhou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *str2, size_t n)
{
	size_t			i;
	char			*cdest;
	char			*cstr2;

	i = 0;
	cdest = (char *)dest;
	cstr2 = (char *)str2;
	if (cdest > cstr2)
	{
		while (n >= 1)
		{
			cdest[n - 1] = cstr2[n - 1];
			n--;
		}
		cdest = (char *)dest;
		return (cdest);
	}
	while (i < n && (cdest || cstr2))
	{
		cdest[i] = cstr2[i];
		i++;
	}
	cdest = (char *)dest;
	return (cdest);
}
