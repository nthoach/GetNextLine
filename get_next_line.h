/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthoach <nthoach@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 09:56:06 by marvin            #+#    #+#             */
/*   Updated: 2023/11/24 19:21:41 by nthoach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 15
# endif

# include <unistd.h>
# include <stdio.h> /* for read, FOPEN_MAX */
# include <stdlib.h> /* for write */

/* All functions here*/
char	*get_next_line(int fd);
char	*join_str_gnl(char *s1, char *s2);
size_t	len_str_gnl(const char *str);
size_t	edit_str_gnl(char *str);
char	*ft_strdup(char *s);

#endif
