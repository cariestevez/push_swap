/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cestevez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 16:38:11 by cestevez          #+#    #+#             */
/*   Updated: 2023/03/03 12:37:48 by cestevez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	my_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i] != 0)
		i++;
	return (i);
}

char	*my_strdup(char *s)
{
	char	*ptr;
	int		length;

	if (s == 0)
		return (NULL);
	length = 0;
	while (s[length] != '\0')
		length++;
	ptr = (char *)malloc(sizeof(char) * length + 1);
	if (ptr == 0)
		return (NULL);
	length = 0;
	while (s[length] != '\0')
	{
		ptr[length] = s[length];
		length++;
	}
	ptr[length] = '\0';
	return (ptr);
}

char	*my_strjoin(char **stash, char **buff)
{
	char	*temp;
	int		len;
	int		i;
	int		j;

	i = ft_strlen(*stash);
	len = i + ft_strlen(*buff);
	temp = (char *)malloc(len + 1);
	if (temp == 0)
		return (NULL);
	j = -1;
	while ((*stash)[++j] != '\0')
		temp[j] = (*stash)[j];
	j = -1;
	while ((*buff)[++j] != '\0')
	{
		temp[i] = (*buff)[j];
		i++;
	}
	temp[i] = '\0';
	free (*stash);
	*stash = temp;
	return (*stash);
}

char	*strchr_newline(char *stash, int new_line_char)
{
	int	i;

	i = 0;
	if (stash == 0)
		return (NULL);
	while (stash[i] != '\0')
	{
		if (stash[i] == (char)new_line_char)
			return (ft_strdup(&stash[i]));
		i++;
	}
	return (NULL);
}
