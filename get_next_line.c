/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenedic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 13:05:22 by tbenedic          #+#    #+#             */
/*   Updated: 2018/06/29 18:31:40 by tbenedic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static size_t		new_line_ind(char *buf)
{
	size_t i;

	i = 0;
	while (buf[i] != '\n' && buf[i] != '\0')
		i++;
	return (i);
}

static char		*ft_change(char *line)
{
	char	*recycle;

	recycle = ft_strchr(line, '\n');
	recycle++;
	recycle = ft_strdup(recycle);
	return (recycle);
}

int		get_next_line(const int fd, char **line)
{
	char		*buf;
	static char	*keep;
	size_t		buffout;

	if (fd < 0 || !line || BUFF_SIZE < 1)
		return (-1);
	if (keep == NULL)
		keep = ft_strnew(0);
	buf = ft_strnew(BUFF_SIZE);
	while ((buffout = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[buffout] = '\0';  
		keep = ft_strjoin(keep, buf);
		if (ft_contain_char(keep, '\n'))
			break ;
	}	
	if (*keep == 0 && buffout == 0)
		return (READ_COMPLETE);
//	printf("\n 1 \n");
	*line = ft_strsub(keep, 0, new_line_ind(keep));
//	printf("\n 2 \n");
	keep = ft_change(keep);
//	printf("\n 3 \n");
	return (READ_SUCCESS);
}
