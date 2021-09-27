/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayajrhou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 21:34:26 by ayajrhou          #+#    #+#             */
/*   Updated: 2019/10/17 18:34:29 by ayajrhou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned int	i;
	unsigned char	*adest1;
	unsigned char	*bsrc2;

	i = 0;
	adest1 = (unsigned char *)dest;
	bsrc2 = (unsigned char *)src;
	while (i < n)
	{
		adest1[i] = bsrc2[i];
		if (bsrc2[i] == (unsigned char)c)
		{
			return (adest1 + 1 + i);
		}
		i++;
	}
	return (NULL);
}
