/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cestevez <cestevez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:17:06 by cestevez          #+#    #+#             */
/*   Updated: 2023/07/05 20:44:29 by cestevez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_next_line(int fd)
{
	int			read_ret;
	char		*buff;
	static char	*stash[1024];
	char		*new_line_ptr;

	read_ret = 0;
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	new_line_ptr = strchr_newline(stash[fd], '\n');
	while (new_line_ptr == 0)
	{
		buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (buff == 0)
			return (NULL);
		read_ret = read(fd, buff, BUFFER_SIZE);
		if (read_ret < 0)
			return (stash[fd] = free_stash(stash[fd], buff));
		if (read_ret == 0)
			return (buff = free_buff(&stash[fd], &buff));
		buff[read_ret] = '\0';
		new_line_ptr = save_buff_srch(&buff, &stash[fd]);
	}
	return (complete_line(&stash[fd], new_line_ptr));
}

char	*save_buff_srch(char **buff, char **stash)
{
	if (*stash != 0 && *buff != 0)
	{
		if (my_strjoin(stash, buff) == 0)
			return (NULL);
	}
	if (*stash == 0 && *buff != 0)
		*stash = ft_strdup(*buff);
	free (*buff);
	return (strchr_newline(*stash, '\n'));
}

char	*complete_line(char **stash, char *new_line_ptr)
{
	char	*line;
	int		j;

	line = (char *)malloc(ft_strlen(*stash) - ft_strlen(new_line_ptr) + 2);
	if (*stash == 0 || line == 0)
		return (NULL);
	if (new_line_ptr == 0)
		return (*stash);
	j = 0;
	while (stash[0][j] != '\n')
	{
		line[j] = stash[0][j];
		j++;
	}
	line[j] = '\n';
	line[j + 1] = '\0';
	free (*stash);
	*stash = NULL;
	if (new_line_ptr[1] != '\0')
		*stash = ft_strdup(&new_line_ptr[1]);
	free (new_line_ptr);
	new_line_ptr = NULL;
	return (line);
}

void	*free_stash(char *stash, char *buff)
{
	free(buff);
	buff = NULL;
	if (stash != 0)
	{
		free(stash);
		stash = NULL;
	}
	return (NULL);
}

char	*free_buff(char **stash, char **buff)
{
	free(*buff);
	*buff = *stash;
	*stash = NULL;
	return (*buff);
}
