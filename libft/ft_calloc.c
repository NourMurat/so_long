/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: numussan <numussan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 20:07:07 by numussan          #+#    #+#             */
/*   Updated: 2022/09/01 05:15:05 by numussan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_calloc(int count, int size)
{
	int		count_size;
	void	*pointer;
	void	*pp;

	count_size = count * size;
	pointer = (void *)malloc(count_size);
	if (!pointer)
		return (0);
	pp = pointer;
	while (count_size--)
		*(char *)pp++ = '\0';
	return (pointer);
}
