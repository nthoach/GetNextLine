/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/* By: Hoach Nguyen <honguyen@student.42abudhabi.ae>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 10:26:19 by marvin            #+#    #+#             */
/*   Updated: 2023/11/24 10:26:19 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	len_str_gnl(const char *str)
{
	size_t	len;

	len = 0;
	if (!str)
		return (0);
	while (str[len] && str[len] != '\n')
		len++;
	if (str[len] == '\n') /*count only one '\n' in the len*/
		len++;
	return (len);
}

char	*join_str_gnl(char *s1, char *s2)
{
	char		*line_out;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;

	line_out = (char *)malloc(sizeof(char) * (len_str_gnl(s1) + 
			len_str_gnl(s2) + 1));
	if (!line_out)
		return (NULL);
	while (s1 && s1[j])
		line_out[i++] = s1[j++];
	j = 0;
	while (s2 && s2[j])
	{
		line_out[i++] = s2[j++]; /*should copy the first '\n'*/
		if (s2[j-1] == '\n')
			break ;
	}
	line_out[i] = '\0';
	free(s1);
	return (line_out);
}
size_t	edit_str_gnl(char *ptr) /*edit str after found out '\n' or '\0'*/
{
	size_t	i;
	size_t	j;
	size_t	flag;

	i = 0;
	j = 0;
	flag = 0;
	while (ptr[i] != '\0')
	{
		if (flag == 1)
		{
			ptr[j++] = ptr[i];
		}
		if (ptr[i] == '\n')
			flag = 1;
		ptr[i] = '\0';
		i++;		
	}
	return (flag);
}

