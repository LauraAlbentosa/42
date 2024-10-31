/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalbento <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 13:15:54 by lalbento          #+#    #+#             */
/*   Updated: 2024/10/31 12:31:57 by lalbento         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*fill_line(int fd, char *line, char *buffer)
{
	char	*temp;
	ssize_t	b_read;

	b_read = read(fd, buffer, BUFFER_SIZE);
	while (b_read > 0)
	{
		buffer[b_read] = '\0';
		if (!line)
			line = ft_strdup("");
		temp = line;
		line = ft_strjoin(temp, buffer);
		free(temp);
		if (!line)
			return (NULL);
		if (ft_strchr(line, '\n'))
			break ;
		b_read = read(fd, buffer, BUFFER_SIZE);
	}
	if (b_read < 0)
	{
		free(line);
		return (NULL);
	}
	return (line);
}

static char	*line_position(char *line)
{
	char	*line_copy;
	int		i;

	if (!line)
		return (NULL);
	i = 0;
	while (line[i] != '\n' && line[i])
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

	if (line[0] == '\0')
		return (NULL);
	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	final_line = ft_substr(line, 0, i + 1);
	return (final_line);
}

char	*get_next_line(int fd)
{
	static char		*line;
	char			*buffer;
	char			*final_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	line = fill_line(fd, line, buffer);
	free(buffer);
	if (!line)
		return (NULL);
	final_line = get_line_substr(line);
	line = line_position(line);
	return (final_line);
}
