/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: numussan <numussan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 12:00:04 by numussan          #+#    #+#             */
/*   Updated: 2022/09/01 05:47:58 by numussan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, int len)
{
	int		i;
	char	*result;
	int		temp_start;

	temp_start = start;
	if (!s)
		return (NULL);
	if (temp_start > ft_strlen(s))
		len = 0;
	if (len > ft_strlen(s) - temp_start)
		len = ft_strlen(s) - temp_start;
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (i < len)
	{
		result[i] = s[temp_start];
		i++;
		temp_start++;
	}
	result[i] = '\0';
	return (result);
}
