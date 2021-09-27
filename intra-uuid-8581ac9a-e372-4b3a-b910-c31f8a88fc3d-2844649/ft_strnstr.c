/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayajrhou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 19:42:50 by ayajrhou          #+#    #+#             */
/*   Updated: 2019/10/22 18:18:45 by ayajrhou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	size_t			i;
	size_t			j;
	unsigned char	*str1;
	unsigned char	*to_find1;

	str1 = (unsigned char *)str;
	to_find1 = (unsigned char *)to_find;
	i = 0;
	if (n == 0 && str == 0)
		return (NULL);
	if (to_find1[i] == '\0')
		return ((char *)str1);
	while (str1[i] != '\0' && i < n)
	{
		j = 0;
		while (str1[i + j] == to_find1[j] && i + j < n)
		{
			if (to_find1[j + 1] == '\0')
				return ((char *)(&str1[i]));
			j++;
		}
		i++;
	}
	return (0);
}
