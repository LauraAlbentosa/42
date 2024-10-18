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

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

int ft_strlen(char *s)
{
    int     i;

    i = 0;
    while (s[i])
        i++;
    
    return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new_str;
	size_t	total_len;
	int		i;
	int		j;

	i = 0;
	j = 0;
	total_len = ft_strlen(s1) + ft_strlen(s2);
	new_str = (char *)malloc((total_len + 1) * sizeof(char));
	if (new_str == NULL)
		return (NULL);
	while (s1[i])
	{
		new_str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		new_str[i + j] = s2[j];
		j++;
	}
	new_str[j + i] = '\0';
	return (new_str);
}

char	*ft_strchr(const char *s, int c)
{
	const char	*ptr;
	int			i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
		{
			ptr = s + i;
			return ((char *)ptr);
		}
		i++;
	}
	if (s[i] == (char)c)
	{
		ptr = s + i;
		return ((char *)ptr);
	}
	return (NULL);
}

char	*ft_strdup(const char *s)
{
	char	*ptr;
	int		i;
	int		len;

	i = 0;
	len = ft_strlen((char *)s);
	ptr = malloc((len + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	while (i < len)
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;
	size_t	len_s;

	i = 0;
	len_s = ft_strlen((char *)s);
	if (start >= len_s)
		return (ft_strdup(""));
	if (len > len_s - start)
		len = len_s - start;
	substr = (char *)malloc((len + 1) * sizeof(char));
	if (substr == NULL)
		return (NULL);
	while (s[i] && i < len)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}

char	*fill_line(int fd, char *temp)
{
	//char	*temp;
	char	*buffer_copy;
	char	*buffer;
	size_t	bytes_read;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	buffer_copy = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer_copy)
	{
		free(buffer);
		return (NULL);
	}
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		buffer[bytes_read] = '\0';
		temp = ft_strjoin(buffer_copy, buffer);
		if (!temp)
		{
			free(buffer);
			free(buffer_copy);
			return (NULL);
		}
		free(buffer_copy);
		buffer_copy = temp;
		if (ft_strchr(buffer_copy, '\n'))
			break;
		bytes_read = read(fd, buffer, BUFFER_SIZE);
	}
	free(buffer);
	return(buffer_copy);
}

char	*get_next_line(int fd)
{
	static char	*buffer_copy;
	char	*line;
	char	*temp;
	char	*index;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	temp = NULL;
	buffer_copy = fill_line(fd, temp);
	if (!buffer_copy)
		return (NULL);
	index = ft_strchr(buffer_copy, '\n');
	line = NULL;
	if (index)
	{
		line = ft_substr(buffer_copy, 0, (index - buffer_copy) + 1);
		temp = ft_strdup(buffer_copy + (index - buffer_copy) + 1);
		free(buffer_copy);
		buffer_copy = temp;
		if (buffer_copy[0] == '\0')
		{
			free(buffer_copy);
			buffer_copy = NULL;
		}
	}
	else
	{
		line = ft_strdup(buffer_copy);
		free(buffer_copy);
		buffer_copy = NULL;
	}
	return(line);
}

