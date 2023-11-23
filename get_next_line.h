/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honguyen <honguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 11:44:29 by honguyen          #+#    #+#             */
/*   Updated: 2023/11/22 20:46:31 by honguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h> /* write, read */
# include <stddef.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42 
# endif

/* Major functions */
char	*add2_line(int fd, char *ptr_line);
char	*take_line(char	*ptr_line);
char	*renew_line(char *ptr_line);
char	*get_next_line(int fd);

/* Utilities functions */
size_t	strchr_gnl(const char *s, int c);
char	*strjoin_gnl(char *s1, const char *s2);
char	*strcpy_gnl(char *d, const char *s, size_t n);
size_t	strlen_gnl(const char	*s);

#endif