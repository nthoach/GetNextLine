/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honguyen <honguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 10:00:21 by honguyen          #+#    #+#             */
/*   Updated: 2023/11/18 10:57:14 by honguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

// void	static_var_exm(void)
// {
// 	static int	var = 0;

// 	printf("Static Variable = %d\n", var);
// 	var++;
// }

// int	main(void)
// {
// 	static_var_exm();
// 	static_var_exm();
// 	static_var_exm();
// 	static_var_exm();
// 	static_var_exm();
// 	return (0);
// }

// int	func_count(void)
// {
// 	static int	counter = 0;

// 	return (++counter);
// }

// int	main(void)
// {
// 	printf("Counter: %d\n", func_count());
// 	printf("Counter: %d\n", func_count());
// 	printf("Counter: %d\n", func_count());
// 	printf("Counter: %d\n", func_count());
// 	printf("Counter: %d\n", func_count());
// 	return (0);
// }

// static int	g_file_static_var = 10;

// void	file_functions(void)
// {
// 	printf("File Encapsulaed Variable = %d\n", g_file_static_var);
// 	g_file_static_var++;
// }

// int	main(void)
// {
// 	file_functions();
// 	printf("value = %d\n", g_file_static_var);
// 	file_functions();
// 	printf("value = %d\n", g_file_static_var);
// 	file_functions();
// 	printf("value = %d\n", g_file_static_var);
// 	return (0);
// }

#define BUFFER_SIZE 1024

int	main(void)
{
	char	buffer[BUFFER_SIZE];
	ssize_t	bytes_read;

	bytes_read = read(STDIN_FILENO, buffer, sizeof(buffer) - 1);
	if (bytes_read == -1)
	{
		perror("Error reading from standard input");
		return (1);
	}
	buffer[bytes_read] = '\0';
	printf("bytes_read: %zd, contents: %s", bytes_read, buffer);
	return (0);
}
