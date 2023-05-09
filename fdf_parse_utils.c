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

int	wrd_counter(char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != '\0' && s[i] != '\n')
	{
		if (s[i] != c
			&& (s[i + 1] == c || s[i + 1] == '\0' || s[i + 1] == '\n'))
		{
			count++;
			i++;
		}
		else
			i++;
	}
	return (count);
}

int	hex_to_decimal(char *buffer, int channel)
{
	char	*base;
	int		i;
	int		j;

	i = 0;
	j = 0;
	base = ft_strdup("0123456789abcdefABCDEF");
	while (buffer[channel] != base[i])
		i++;
	while (buffer[channel + 1] != base[j])
		j++;
	if (i > 21 || j > 21)
		error(ERR_INPUT);
	if (i > 15)
		i = i - 6;
	if (j > 15)
		j = j - 6;
	return (free (base), (16 * i) + j);
}

void	get_altitude(t_point *point, char *buffer)
{
	int		len;

	if (ft_strchr(buffer, ',') == NULL)
		point->z = ft_atoi(buffer);
	else
	{
		len = ft_strlen(buffer) - ft_strlen(ft_strchr(buffer, ','));
		point->z = ft_atoi(ft_substr(buffer, 0, len));
	}
}

void	get_rgb(t_point *point, char *buffer)
{
	if (ft_strchr(buffer, ',') == NULL)
	{
		point->r = 19;
		point->g = 205;
		point->b = 231;
	}
	else
	{
		buffer = ft_strnstr(buffer, "0x", ft_strlen(buffer));
		if (ft_strlen(buffer) >= 4)
			point->r = hex_to_decimal(buffer, 2);
		if (ft_strlen(buffer) >= 6)
			point->g = hex_to_decimal(buffer, 4);
		if (ft_strlen(buffer) == 8)
			point->b = hex_to_decimal(buffer, 6);
	}
}
