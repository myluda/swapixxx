/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayajrhou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 16:23:35 by ayajrhou          #+#    #+#             */
/*   Updated: 2019/10/17 23:27:24 by ayajrhou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *str, int c)
{
	int		i;
	int		len;
	char	*place;
	char	*str1;

	str1 = (char *)str;
	len = ft_strlen(str);
	i = 0;
	place = 0;
	while (len >= 0)
	{
		if (str1[len] == c)
		{
			place = &str1[len];
			break ;
		}
		len--;
	}
	return (place);
}
