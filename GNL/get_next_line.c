/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalbento <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 13:15:54 by lalbento          #+#    #+#             */
/*   Updated: 2024/10/09 13:08:09 by lalbento         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*fill_line(int fd, char *line)
{
	char	*buffer;
	char	*temp;
	ssize_t	b_read;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	b_read = 1;
	while(b_read > 0)
	{
		b_read = read(fd, buffer, BUFFER_SIZE);
		if(b_read < 0)
		{
			free(buffer);
			return (NULL);
		}
		buffer[b_read] = '\0';
		if (!line)
			line = ft_strdup("");
		temp = line;
		line = ft_strjoin(temp, buffer);
		free(temp);
		if (ft_strchr(line, '\n'))
			break;
	}
	free(buffer);
	if (b_read == 0 || !line)
		return (NULL);
	return (line);
}

static char		*line_position(char *line)
{
	char	*line_copy;
	int		i;

	if (!line)
		return (NULL);
	i = 0;
	while(line[i] != '\n' && line[i])
		i++;
	if (!line[i])
	{
		free(line);
		return (NULL);
	}
	line_copy = ft_substr(line, i + 1, ft_strlen(line) - i - 1);
	free(line);
	return (line_copy);
}


char	*get_line_substr(char *line)
{
	char	*final_line;
	int		i;

	if (!line)
		return (NULL);
	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	//final_line = ft_substr(line, 0, (line[i] == '\n') ? i + 1 : i);
	final_line = ft_substr(line, 0, i + 1);
	return (final_line);
}

char	*get_next_line(int fd)
{
	static char		*line;
	char	*final_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = fill_line(fd, line);
	if (!line)
		return (NULL);
	final_line = get_line_substr(line);
	line = line_position(line);
	return (final_line);
}

/*#include "get_next_line.h"

char *fill_line(int fd, char *line) {
    char *buffer;
    char *temp;
    ssize_t b_read;

    buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
    if (!buffer)
        return (NULL);
    
    b_read = 1; // Inicializamos para entrar en el bucle
    while (b_read > 0) {
        b_read = read(fd, buffer, BUFFER_SIZE);
        if (b_read < 0) {
            free(buffer);
            return (NULL);
        }
        buffer[b_read] = '\0'; // Asegúrate de null-terminar el buffer
        
        // Unir el contenido leído con la línea acumulada
        if (line) {
            temp = ft_strjoin(line, buffer);
        } else {
            temp = ft_strdup(buffer);
        }
        free(line);
        line = temp;

        // Salir si encontramos un salto de línea
        if (ft_strchr(line, '\n'))
            break;
    }

    free(buffer);
    
    // Verifica si hemos llegado al final del archivo sin haber leído nada
    if (b_read == 0 && !line) {
        return (NULL);
    }
    
    return (line);
}

static char *line_position(char *line) {
    char *line_copy;
    int i;

    if (!line)
        return (NULL);

    i = 0;
    while (line[i] != '\n' && line[i])
        i++;

    if (!line[i]) {
        free(line);
        return (NULL);
    }
    line_copy = ft_substr(line, i + 1, ft_strlen(line) - i - 1);
    free(line);
    return (line_copy);
}

char *get_line_substr(char *line) {
    char *final_line;
    int i;

    if (!line)
        return (NULL);
    
    i = 0;
    while (line[i] && line[i] != '\n')
        i++;

    final_line = ft_substr(line, 0, i + (line[i] == '\n'));
    return (final_line);
}

char *get_next_line(int fd) {
    static char *line;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);

    line = fill_line(fd, line);
    if (!line)
        return (NULL);

    char *final_line = get_line_substr(line);
    line = line_position(line);
    return (final_line);
}
*/