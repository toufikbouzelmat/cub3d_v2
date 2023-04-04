/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouzalm <tbouzalm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 20:15:07 by tbouzalm          #+#    #+#             */
/*   Updated: 2023/03/23 20:15:10 by tbouzalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	ft_strncmp(const char *s1, const char *s2, int n)
{
	int				i;
	int				j;
	unsigned char	*string1;
	unsigned char	*string2;

	string1 = (unsigned char *)s1;
	string2 = (unsigned char *)s2;
	j = 0;
	i = 0;
	while (i < n)
	{
		if (string1[i] != string2[j])
			return (string1[i] - string2[j]);
		if (string1[i] == '\0' && string2[j] == '\0')
			return (0);
		i++;
		j++;
	}
	return (0);
}
