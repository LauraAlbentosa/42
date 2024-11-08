/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalbento <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 15:16:12 by lalbento          #+#    #+#             */
/*   Updated: 2024/11/08 15:16:14 by lalbento         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

int ft_putptr(void *ptr)
{
    int len;
    unsigned long long    hex_ptr;

    len = 0;
    hex_ptr = (unsigned long long)ptr;
    if (!ptr)
    {
        len = ft_putstr("(nil)");
        return (len);
    }
    len += ft_putstr("0x");
    len += ft_puthex(hex_ptr, 0);
    return(len);
}

/*
int     main(void)
{
    char    *ptr;
    printf("%p\n", ptr);
    ft_putptr(ptr);
    return(0);
}
*/
