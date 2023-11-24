/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthoach <nthoach@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 11:44:29 by honguyen          #+#    #+#             */
/*   Updated: 2023/11/23 22:45:36 by nthoach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h> /* write, read */
# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5 
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