/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honguyen <honguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 10:00:21 by honguyen          #+#    #+#             */
/*   Updated: 2023/11/22 21:01:16 by honguyen         ###   ########.fr       */
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
    	FILE *file = fopen("test.txt", "w");

    	// Check if the file was opened successfully
    	if (file == NULL)
	{
        printf("Error opening file!\n");
        return 1; // Exit with an error code
    	}

    	// Write content to the file
    	fprintf(file, "0123456789\n");
    	fprintf(file, "0123456789\n");
	fprintf(file, "0123456789\n");
	fprintf(file, "0123456789\n");
	fprintf(file, "0123456789\n");
	fprintf(file, "0123456789\n");

    	// Close the file
    	fclose(file);
    	printf("File created successfully: test.txt\n");

	//
    
    	fd = open("test.txt", O_RDWR);

	// Check if the file was opened successfully
if (fd == -1) {
	perror("Error opening file");
	return 1; // Exit with an error code
}
	fd = open("test.txt", O_RDWR);
	line_out = get_next_line(fd);
	printf("%s", line_out);
	while(*line_out)
	{
		line_out = get_next_line(fd);
		printf("%s", line_out);
	}
	free(line_out);
	close(fd);
	return 0; // Exit with success
}
