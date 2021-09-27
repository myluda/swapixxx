/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayajrhou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 16:08:21 by ayajrhou          #+#    #+#             */
/*   Updated: 2019/10/21 00:17:28 by ayajrhou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	char	*place;
	int		i;
	int		k;

	i = 0;
	place = 0;
	k = ft_strlen(str);
	while (i <= k)
	{
		if (str[i] == c)
		{
			place = ((char *)&str[i]);
			break ;
		}
		i++;
	}
	return (place);
}
