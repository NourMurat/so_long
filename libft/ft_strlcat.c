/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: numussan <numussan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 22:01:18 by numussan          #+#    #+#             */
/*   Updated: 2022/09/01 05:12:23 by numussan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strnlen(const char *s, int maxlen)
{
	int	i;

	i = 0;
	while (s[i] && maxlen--)
		i++;
	return (i);
}

int	ft_strlcat(char *dst, const char *src, int dstsize)
{
	int	len;

	len = ft_strnlen(dst, dstsize);
	if (len == dstsize)
		return (len + ft_strlen(src));
	return (len + ft_strlcpy(dst + len, src, dstsize - len));
}
