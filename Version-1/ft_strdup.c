/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 15:31:11 by marvin            #+#    #+#             */
/*   Updated: 2023/11/24 15:31:11 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strdup(char *s)
{
	char	*a;
	int		b;
	int		count;

	count = 0;
	while (s[count] != '\0')
		count++;
	a = (char *) malloc((count + 1) * sizeof(char));
	if (a == NULL)
		return (NULL);
	b = 0;
	while (s[b] != '\0')
	{
		a[b] = s[b];
		b++;
	}
	a[b] = '\0';
	return (a);
}
