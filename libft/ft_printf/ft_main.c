/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoro-sa <imoro-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 12:10:29 by imoro-sa          #+#    #+#             */
/*   Updated: 2023/01/23 16:04:39 by imoro-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	int	a;
	char	str[] = "HOLA GUS!!!!";
	int	*ptr;

	a = 5;
	ptr = &a;
	ft_printf("hola hola%s%p", str, ptr);
	return (0);
}
