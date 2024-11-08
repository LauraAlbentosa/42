/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalbento <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:14:02 by lalbento          #+#    #+#             */
/*   Updated: 2024/11/05 15:14:04 by lalbento         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdarg.h>


int ft_putchar(char c);
int ft_putnbr(int n);
int ft_putstr(char *s);
int ft_printf(char const *str, ...);
int ft_puthex(unsigned int hex, int flag);
int ft_putptr(void *ptr);
int ft_putunsigned(unsigned int u_num);

#endif
