/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouzalm <tbouzalm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 20:12:51 by tbouzalm          #+#    #+#             */
/*   Updated: 2023/04/01 08:31:42 by tbouzalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	ft_strlen_const(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	negative_atoi(const char *str)
{
	int	i;

	if (ft_strlen_const(str) > 3)
	{
		printf("Error\ninvalid variable(max)\n");
		exit(1);
	}
	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] >= 'a' && str[i] <= 'z') || \
		(str[i] >= 'A' && str[i] <= 'Z'))
		{
			printf("Error\ninvalid variable\n");
			exit(1);
		}
		if ((str[i] >= 33 && str[i] <= 43) || \
		(str[i] >= 45 && str[i] <= 47))
		{
			printf("Error\ninvalid variable\n");
			exit(1);
		}
		i++;
	}
}

int	ft_atoi(const char *str)
{
	int	num;
	int	sign;
	int	i;

	num = 0;
	sign = 1;
	i = 0;
	negative_atoi(str);
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == 45)
		sign *= (-1);
	if (str[i] == 45 || str[i] == 43)
		i++;
	while (ft_isdigit(str[i]))
		num = num * 10 + (str[i++] - 48);
	if (str[i] && !ft_isdigit(str[i]) && ft_isdigit((str[i] + 1)))
		return (-1);
	return (num * sign);
}
