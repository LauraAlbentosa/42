#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
/*
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


char    *get_line(int fd, int nbytes)
{
    char    *buffer;
    size_t bytes_read;
    char    *temp;
    static char *line;
    char    *new_line;
    char    *index_ptr;
    int     index;

    buffer = malloc((nbytes + 1)*sizeof(char));
    if (!buffer)
    {
        free(buffer);
        return ("error buffer");
    }
    bytes_read = read(fd, buffer, nbytes);
    if (bytes_read < 0)
    {
        free(buffer);
        return ("error en lectura");
    }
    line = malloc((nbytes + 1)*sizeof(char));
    if (!line)
    {
        free(buffer);
        return ("erroe en reserva de memoria para linea");
    }
    while(bytes_read > 0)
    {
        temp = ft_strjoin(line, buffer);
        free(line);
        line = temp;
        buffer = malloc((nbytes + 1)*sizeof(char));
        if (!buffer)
        {
            free(buffer);
            return ("error buffer");
        }
        index_ptr = ft_strchr(line, (int)'\n');
        if (index_ptr)
        {  
            index  = index_ptr - line;
            new_line = ft_substr(line, 0, index + 1);
            temp = ft_strdup(line + index + 1);
            free(line);
            line = temp;
            free(buffer);
            return(new_line);
        }
        bytes_read = read(fd, buffer, nbytes);
        if (bytes_read < 0)
        {
            free(buffer);
            return ("error en lectura");
        }   
    }
    free(buffer);
    if (bytes_read < 0 || ft_strlen(line) == 0)
    {
        free(line);
        line = NULL;
        return (NULL);
    }
    new_line = ft_strdup(line);
    free(line);
    line = NULL;
    return (new_line);

}

int     main(void)
{
    int fd;

    fd = open("test_file.txt", O_RDONLY);
    if (fd < 0)
        return 1;
    printf("%s", get_line(fd, 1));
    close(fd);
}
*/

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


char    *get_next_line(int fd)
{
    char    *buffer;
    size_t bytes_read;
    char    *temp;
    static char *line;
    char    *new_line;
    char    *index_ptr;
    int     index;

    buffer = malloc((BUFFER_SIZE + 1)*sizeof(char));
    if (!buffer)
    {
        return (NULL);
    }
    bytes_read = read(fd, buffer, BUFFER_SIZE);
    line = malloc((BUFFER_SIZE + 1)*sizeof(char));
    if (!line)
    {
        free(buffer);
        return (NULL);
    }
    while(bytes_read > 0)
    {
		buffer[bytes_read] = '\0';
        temp = ft_strjoin(line, buffer);
        free(line);
        line = temp;
        index_ptr = ft_strchr(line, (int)'\n');
        if (index_ptr)
        {  
            index  = index_ptr - line;
            new_line = ft_substr(line, 0, index + 1);
            temp = ft_strdup(line + index + 1);
            free(line);
            line = temp;
            free(buffer);
            return(new_line);
        }
		
        bytes_read = read(fd, buffer, BUFFER_SIZE);
        
    }
	free(buffer);
    if (ft_strlen(line) == 0)
    {
        free(line);
        line = NULL;
        return (NULL);
    }
    new_line = ft_strdup(line);
    free(line);
    line = NULL;
    return (new_line);

}

/*
int     main(void)
{
    int fd;

    fd = open("test_file.txt", O_RDONLY);
    if (fd < 0)
        return 1;
	while (line != NULL)
	{
		printf("%s", line);
		free(line);
	}
    close(fd);
}
*/
