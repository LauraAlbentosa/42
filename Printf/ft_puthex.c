/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalbento <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:04:11 by lalbento          #+#    #+#             */
/*   Updated: 2024/11/06 17:04:12 by lalbento         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_puthex(unsigned int hex, int flag)
{
    int i;
    char    *hex_str;

    i = 0;
    hex_str = "0123456789abcdef";
    if (flag)
        hex_str = "0123456789ABCDEF";
    if (hex >= 16)
        i += ft_puthex((hex / 16), flag); 
    write(0, &hex_str[hex % 16], 1);
    i++;
    return(i);
}
/*
int main(void)
{
    int len = ft_puthex(214748368, 0);
    printf("\n%i", len);
    int len2 = printf("\n%x", 214748368);
    printf("\n%i", len2);
    return(0);
}
*/