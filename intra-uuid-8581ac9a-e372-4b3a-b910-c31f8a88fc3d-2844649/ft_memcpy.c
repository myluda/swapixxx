/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayajrhou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 19:49:06 by ayajrhou          #+#    #+#             */
/*   Updated: 2019/10/21 00:18:44 by ayajrhou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *str1, const void *str2, size_t n)
{
	unsigned int	i;
	char			*astr1;
	char			*bstr2;

	astr1 = (char *)str1;
	bstr2 = (char *)str2;
	i = 0;
	while (i < n && (astr1 || bstr2))
	{
		astr1[i] = bstr2[i];
		i++;
	}
	return ((void *)str1);
}
