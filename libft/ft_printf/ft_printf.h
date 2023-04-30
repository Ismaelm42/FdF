/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoro-sa <imoro-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 12:12:23 by imoro-sa          #+#    #+#             */
/*   Updated: 2023/01/23 12:23:28 by imoro-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <stdarg.h>
# include "../libft/libft.h"

int	ft_printf(char const *str, ...);
int	ft_call(void *arg, char const *print_str);
int	ft_char(void *arg);
int	ft_string(void *arg);
int	ft_pointer(void *arg);
int	ft_decimal(void *arg);
int	ft_integer(void *arg);
int	ft_unsigned(void *arg);
int	ft_lower_case_hex(void *arg);
int	ft_cap_hex(void *arg);

#endif
