/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayajrhou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 17:02:53 by ayajrhou          #+#    #+#             */
/*   Updated: 2019/10/17 21:35:46 by ayajrhou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	int				i;
	unsigned char	*str1;

	i = 0;
	str1 = (unsigned char *)str;
	while (n > 0)
	{
		if (str1[i] == (unsigned char)c)
			return (str1 + i);
		i++;
		n--;
	}
	return (0);
}
