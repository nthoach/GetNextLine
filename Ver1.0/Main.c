/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthoach <nthoach@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 10:00:21 by honguyen          #+#    #+#             */
/*   Updated: 2023/11/25 16:17:01 by nthoach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int	fd;
	char	*line_out;

	
	// Open the file in write mode
    fd = open("test.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);

    // Check if the file was opened successfully
    if (fd == -1) 
	{
       perror("Error opening the file");
	   return 1; // Exit the program with an error code
    }
    // Write content to the file
	write(fd, "0123456789\n", 11);
    write(fd, "0123456789\n", 11);
	write(fd, "0123456789\n", 11);
	write(fd, "0123456789\n", 11);
	write(fd, "0123456789\n", 11);
	write(fd, "0123456789\n", 11);
	write(fd, "0123456789\n", 11);
	write(fd, "0123456789\n", 11);
	write(fd, "0123456789\n", 11);
	
	// Close the file
	close(fd);
	printf("File created successfully: test.txt\n");

	//    
    fd = open("test.txt", O_RDONLY);

	// Check if the file was opened successfully
	if (fd == -1) 
	{
		perror("Error opening file");
		return 1; // Exit with an error code
	}
	fd = open("test.txt", O_RDWR);
	line_out = get_next_line(fd);
	printf("%s", line_out);
	while(1)
	{
		line_out = get_next_line(fd);
		printf("%s", line_out);
		if (line_out == NULL)
			break;
	}
	free(line_out);
	close(fd);
	//system("leaks a.out");
	return (0); // Exit with success
}
