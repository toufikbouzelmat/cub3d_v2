/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouzalm <tbouzalm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 20:15:16 by tbouzalm          #+#    #+#             */
/*   Updated: 2023/03/23 20:15:18 by tbouzalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	*ft_substr(char const *s, int start, int len)
{
	char	*string;
	char	*substring;
	int		j;
	int		finish;

	if (s)
	{
		string = (char *)s;
		substring = (char *)ft_calloc((len + 1), sizeof(char));
		if (substring == NULL)
			return (0);
		j = 0;
		finish = len + start;
		if (start <= ft_strlen(string))
		{
			while (start < finish && string[start])
				substring[j++] = string[start++];
		}
		return (substring);
	}
	else
		return (NULL);
}
