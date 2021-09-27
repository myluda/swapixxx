/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayajrhou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 17:18:01 by ayajrhou          #+#    #+#             */
/*   Updated: 2019/10/22 18:06:03 by ayajrhou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t			i;
	unsigned char	*sstr2;
	unsigned char	*sstr1;

	sstr1 = (unsigned char *)str1;
	sstr2 = (unsigned char *)str2;
	i = 0;
	if (n == 0)
	{
		return (0);
	}
	while (i < n - 1 && str1[i] != '\0')
	{
		if (sstr1[i] != sstr2[i])
		{
			return (sstr1[i] - sstr2[i]);
		}
		i++;
	}
	return (sstr1[i] - sstr2[i]);
}
