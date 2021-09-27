/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayajrhou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 16:47:14 by ayajrhou          #+#    #+#             */
/*   Updated: 2019/10/22 16:47:17 by ayajrhou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_first(char *s1, char *set)
{
	int i;

	i = 0;
	while (s1[i] != '\0' && ft_strchr(set, s1[i]))
	{
		i++;
	}
	return (i);
}

static int		ft_last(char *s1, char *set)
{
	int	len;

	len = ft_strlen(s1);
	while (ft_strchr(set, s1[len - 1]))
	{
		len--;
		if (len == 0)
			return (0);
	}
	return (len);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*p;

	if (!(s1))
		return (NULL);
	if (!(set))
		ft_strdup(s1);
	start = ft_first((char *)s1, (char *)set);
	end = ft_last((char *)s1, (char*)set);
	if (end - start + 1 > 1)
	{
		if (!(p = (char *)malloc(sizeof(char) * (end - start + 1))))
			return (NULL);
		ft_strlcpy(p, s1 + start, end - start + 1);
	}
	else
	{
		if (!(p = (char *)malloc(sizeof(char) * 1)))
		{
			return (NULL);
		}
		p[0] = 0;
	}
	return (p);
}
