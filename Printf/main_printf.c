#include <stdio.h>
#include "ft_printf.h"
#include <limits.h>

int   main(void)
{
   char  *ptr;
   char  *nul_str = "\0";
   int   size_printf;
   int   size_ftprintf;

   //Enteros
   size_printf = printf("un entero: %i\n", 23);
   size_ftprintf = ft_printf("un entero: %i\n", 23);

   printf("size printf: %i\n", size_printf);
   printf("size ft_printf: %i\n", size_ftprintf);

   size_printf = printf("un entero negativo: %i\n", -23);
   size_ftprintf = ft_printf("un entero negativo: %i\n", -23);

   printf("size printf: %i\n", size_printf);
   printf("size ft_printf: %i\n", size_ftprintf);

   size_printf = printf("int min: %i\n", INT_MIN);
   size_ftprintf = ft_printf("int min: %i\n", INT_MIN);

   printf("size printf: %i\n", size_printf);
   printf("size ft_printf: %i\n", size_ftprintf);
      
   size_printf = printf("int max: %i\n", INT_MAX);
   size_ftprintf = ft_printf("int max: %i\n", INT_MAX);

   printf("size printf: %i\n", size_printf);
   printf("size ft_printf: %i\n", size_ftprintf);

   //Punteros
   size_printf = printf("un puntero: %p\n", ptr);
   size_ftprintf = ft_printf("un puntero: %p\n", ptr);

   printf("size printf: %i\n", size_printf);
   printf("size ft_printf: %i\n", size_ftprintf);

   size_printf = printf("un puntero null: %p\n", NULL);
   size_ftprintf = ft_printf("un puntero null: %p\n", NULL);

   printf("size printf: %i\n", size_printf);
   printf("size ft_printf: %i\n", size_ftprintf);

   //Strings
   size_printf = printf("una cadena: %s\n","hola que tal prueba");
   size_ftprintf = ft_printf("una cadena: %s\n", "hola que tal prueba");

   printf("size printf: %i\n", size_printf);
   printf("size ft_printf: %i\n", size_ftprintf);

   size_printf = printf("una cadena vacía: %s\n", "");
   size_ftprintf = ft_printf("una cadena vacía: %s\n", "");

   printf("size printf: %i\n", size_printf);
   printf("size ft_printf: %i\n", size_ftprintf);

   size_printf = printf("una cadena con un nul: %s\n",  nul_str);
   size_ftprintf = ft_printf("una cadena con un nul: %s\n", nul_str);

   printf("size printf: %i\n", size_printf);
   printf("size ft_printf: %i\n", size_ftprintf);

   //Char
   size_printf = printf("un char: %c\n",'h');
   size_ftprintf = ft_printf("un char: %c\n", 'h');

   printf("size printf: %i\n", size_printf);
   printf("size ft_printf: %i\n", size_ftprintf);

   //Hexadecimales
   size_printf = printf("un hexadecimal en minusculas: %x\n", 482);
   size_ftprintf = ft_printf("un hexadecimal en minusculas: %x\n", 482);

   printf("size printf: %i\n", size_printf);
   printf("size ft_printf: %i\n", size_ftprintf);

   size_printf = printf("un hexadecimal en mayusculas: %X\n", 482);
   size_ftprintf = ft_printf("un hexadecimal en mayusculas: %X\n", 482);

   printf("size printf: %i\n", size_printf);
   printf("size ft_printf: %i\n", size_ftprintf);

   size_printf = printf("hex max: %x\n", UINT_MAX);
   size_ftprintf = ft_printf("hex max: %x\n", UINT_MAX);

   printf("size printf: %i\n", size_printf);
   printf("size ft_printf: %i\n", size_ftprintf);

   //Varios
   size_printf = printf("varios datos juntos, un int %i, un hexadecimal %x, %% y un puntero %p\n", 45, 478, ptr);
   size_ftprintf = ft_printf("varios datos juntos, un int %i, un hexadecimal %x, %% y un puntero %p\n", 45, 478, ptr);

   printf("size printf: %i\n", size_printf);
   printf("size ft_printf: %i\n", size_ftprintf);
}
