/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: numussan <numussan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 18:27:14 by numussan          #+#    #+#             */
/*   Updated: 2022/09/01 05:14:27 by numussan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, int len)
{
	const unsigned char	*temp_src;
	unsigned char		*temp_dst;

	if (!dst && !src)
		return (NULL);
	temp_src = src;
	temp_dst = dst;
	if (dst < src)
	{
		while (len--)
			*temp_dst++ = *temp_src++;
	}
	else
	{
		while (len--)
			*(temp_dst + len) = *(temp_src + len);
	}
	return (dst);
}
