/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouzalm <tbouzalm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 20:13:35 by tbouzalm          #+#    #+#             */
/*   Updated: 2023/03/23 20:13:40 by tbouzalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	*ft_memset(void *b, int c, int len)
{
	unsigned char	*string;

	string = (unsigned char *)b;
	while (len-- > 0)
		*string++ = (unsigned char)c;
	return (b);
}
