/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honguyen <honguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 12:58:08 by honguyen          #+#    #+#             */
/*   Updated: 2023/11/22 21:04:47 by honguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	strchr_gnl(const char *s, int c)
{
	if (!s)
		return (0);
	while (*s)
	{
		if ((unsigned char)(*s) == (unsigned char)c)
			return (1);
		s++;
	}
	return (0);
}

char	*strjoin_gnl(char *s1, const char *s2)
{
	char	*j_s;
	char	*ptr;
	size_t	len_t;

	if (!s1)
	{
		s1 = malloc(sizeof(char) * 1);
		*s1 = '\0';
	}
	len_t = strlen_gnl(s1) + strlen_gnl(s2);
	j_s = (char *)malloc((len_t + 1) * sizeof(char));
	if (!j_s)
		return (NULL);
	ptr = j_s;
	while (*s1)
		*j_s++ = *s1++;
	while (*s2)
		*j_s++ = *s2++;
	*j_s = '\0';
	free(s1);
	return (ptr);
}

char	*strcpy_gnl(char *d, const char *s, size_t n)
{
	size_t	i;

	i = 0;
	while (s[i] && i < n - 1)
	{
		d[i] = s[i];
		i++;
	}
	d[i] = '\0';
	return (d);
}

size_t	strlen_gnl(const char	*s)
{
	size_t	len_str;

	len_str = 0;
	if (!s)
		return (0);
	while (s[len_str])
		len_str++;
	return (len_str);
}
