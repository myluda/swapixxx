/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayajrhou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 15:13:26 by ayajrhou          #+#    #+#             */
/*   Updated: 2019/10/21 03:48:04 by ayajrhou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	int		i;
	int		count;
	char	*dest;

	if (!(dest = malloc(nmemb * size)))
	{
		return (NULL);
	}
	count = nmemb * size;
	i = 0;
	ft_bzero(dest, count);
	return (dest);
}
