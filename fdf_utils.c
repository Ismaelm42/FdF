/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoro-sa <imoro-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 13:46:42 by imoro-sa          #+#    #+#             */
/*   Updated: 2023/05/05 13:47:19 by imoro-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fdf.h"

void	error(char *err)
{
	ft_putstr_fd(err, 2);
	exit(EXIT_FAILURE);
}

long int	fdf_atoi(char *str)
{
	long int	i;
	long int	j;
	long int	k;

	i = 0;
	while (str[i] == 32 || str[i] == 12 || str[i] == 10
		|| str[i] == 13 || str[i] == 11 || str[i] == 9)
		i++;
	k = 1;
	if (str[i] == 45 || str[i] == 43)
	{
		if (str[i] == 45)
			k = -1;
		i++;
	}
	j = 0;
	while (str[i] > 47 && str[i] < 58)
	{
		j = j * 10 + str[i] - '0';
		i++;
	}
	return ((k * j));
}
int	hex_to_decimal(char *buffer, int channel)
{
	char	base_low[] = "0123456789abcdef";
	char	base_upper[] = "0123456789ABCDEF";
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (buffer[channel] != base_low[i] && buffer[channel] != base_upper[i])
		i++;
	while (buffer[channel + 1] != base_low[j] && buffer[channel + 1] != base_upper[j])
		j++;
	if (i > 16 || j > 16)
		error(ERR_INPUT);
	printf("channel = %d\n", channel);
	return ((16 * i) + j);
}
