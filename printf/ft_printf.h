/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenguir <mdenguir@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 12:31:04 by mdenguir          #+#    #+#             */
/*   Updated: 2022/10/26 15:02:50 by mdenguir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *ptr, ...);
int	ft_putstr(char *s);
int	ft_putchar(char c);
int	ft_putnbr(long n);
int	ft_print_hexa(unsigned int n, char *base);
int	ft_print(va_list args, char c);
int	ft_print_address(unsigned long n, char *base);
int	ft_print_unsigned(unsigned int n);

#endif