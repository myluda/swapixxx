/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayajrhou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 01:04:53 by ayajrhou          #+#    #+#             */
/*   Updated: 2019/10/22 17:54:40 by ayajrhou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t				f;
	char				*dest;

	f = 0;
	if (!(s))
	{
		return (NULL);
	}
	if (!(dest = malloc(sizeof(char) * (len + 1))))
	{
		return (NULL);
	}
	while ((f < len) && (ft_strlen(s) > start))
	{
		dest[f] = s[start];
		start++;
		f++;
	}
	dest[f] = '\0';
	return (dest);
}
