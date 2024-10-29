#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int main(int argc, char **argv)
{
    int fd;
    char *line;

    // Verifica si se ha pasado un archivo como argumento
    if (argc < 2)
    {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return (1);
    }

    // Abre el archivo
    fd = open(argv[1], O_RDONLY);
    if (fd < 0)
    {
        perror("Error opening file");
        return (1);
    }

    // Lee y muestra líneas hasta que no haya más
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);  // Libera la memoria de la línea leída
    }

    // Cierra el archivo
    close(fd);
    return (0);
}
