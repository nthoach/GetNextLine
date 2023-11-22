/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honguyen <honguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 12:48:48 by honguyen          #+#    #+#             */
/*   Updated: 2023/11/22 21:10:42 by honguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* add2_line
1- read reach buffer
2- join with old string to make a raw line
*/

char	*add2_line(int fd, char *ptr_line)
{
	char	*buff;
	ssize_t	nb;

	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	nb = 1;
	while (nb && strchr_gnl(ptr_line, '\n') == 0)
	{
		nb = read(fd, buff, BUFFER_SIZE);
		if (nb == -1)
		{
			free(buff);
			free(ptr_line);
			return (NULL);
		}
		buff[nb] = '\0';
		ptr_line = strjoin_gnl(ptr_line, buff);
	}
	free(buff);
	return (ptr_line);
}

/* get the line by terminating at the true \n or eof
1- check crash
2- malloc to create a new true line
2- copy current_line to the true-line by length*/

char	*take_line(char	*ptr_line)
{
	char	*line_out;
	size_t	i;

	if (!ptr_line)
		return (NULL);
	i = 0;
	while (ptr_line[i] && ptr_line[i] != '\n')
		i++;
	line_out = (char *)malloc(sizeof(char) * i);
	if (!line_out)
		return (NULL);
	strcpy_gnl(line_out, ptr_line, i - 1);
	return (line_out);
}

/* update the current_line by the remain of the last 
current_line after refining the true-line 
1- check crash
2- if perfect true --> free and return null
3- if redudant, malloc and copy the rest*/

char	*renew_line(char *ptr_line)
{
	char	*new_line;
	int		i;

	i = 0;
	while (!(ptr_line[i]) || ptr_line[i] != '\n')
		i++;
	if (!ptr_line[i])
	{
		free(ptr_line);
		return (NULL);
	}
	new_line = (char *)malloc(sizeof(char)
			* (strlen_gnl(ptr_line + i) + 1));
	if (!new_line)
	{
		free(ptr_line);
		return (NULL);
	}
	i++;
	strcpy_gnl(new_line, ptr_line + i, strlen_gnl(ptr_line + i));
	free(ptr_line);
	return (new_line);
}

/* main functions: */
/*
1- add2_line:adding each buffer reading to make line
2- take_line: taking the true line to output
3- renew_line: update pointer for new_line reading
 */

char	*get_next_line(int fd)
{
	static char	*ptr_line;
	char		*line_out;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	ptr_line = add2_line(fd, ptr_line);
	if (ptr_line == 0)
		return (NULL);
	line_out = take_line(ptr_line);
	ptr_line = renew_line(ptr_line);
	return (line_out);
}
