/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthoach <nthoach@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 10:00:21 by honguyen          #+#    #+#             */
/*   Updated: 2023/11/23 22:50:43 by nthoach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int fd = 0;
	char *line_out;

	fd = open("test.txt", O_RDWR);
	//printf("%d\n", fd);
	line_out = get_next_line(fd);
	printf("%s\n", line_out);
	while(*line_out)
	{
		line_out = get_next_line(fd);
		printf("%s\n", line_out);
	}
	free(line_out);
	close(fd);
}
