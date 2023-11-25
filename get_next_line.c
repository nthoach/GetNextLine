/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthoach <nthoach@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 09:52:41 by marvin            #+#    #+#             */
/*   Updated: 2023/11/25 09:56:29 by nthoach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	char	*line;
	static char	ptr[FOPEN_MAX][BUFFER_SIZE + 1];
	
	if (fd < 0 || fd > FOPEN_MAX || BUFFER_SIZE < 1)
		return (NULL);
	line = NULL;
	while (ptr[fd][0] || read(fd, ptr[fd], BUFFER_SIZE) > 0) /*read until EOF or cannot read*/
	{
		//ptr[fd][BUFFER_SIZE] = '\0';
		line = join_str_gnl(line, ptr[fd]); /*special join: ending by true line*/
		if (len_str_gnl(ptr[fd]) == 0) /*There is no more line*/
			return (line);
		if (edit_str_gnl(ptr[fd]) == 1) /*untill found '\n' or '\0', edit ptr to new start of line*/
			break ;
		if (read(fd, ptr[fd], 0) < 0) /* reading failure*/
		{
			free(line);
			return (NULL);
		}
	}
	return (line);
}
