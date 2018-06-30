/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenedic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 13:05:22 by tbenedic          #+#    #+#             */
/*   Updated: 2018/06/30 16:01:57 by tbenedic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static int		new_line_ind(char *buf)
{
	int i;

	i = 0;
	while (buf[i] != '\n' && buf[i] != '\0')
		i++;
	return (i);
}

static char		*ft_remainder(char *line)
{
	char	*recycle;

	recycle = ft_strchr(line, '\n');
	if ((recycle != NULL))
	{
		recycle++;
		recycle = ft_strdup(recycle);
	}
	return (recycle);
}

int		get_next_line(const int fd, char **line)
{
	char		buf[BUFF_SIZE + 1];
	static char	*keep;
	int			buffout;

	if (fd < 0 || !line || BUFF_SIZE < 1 || read(fd, "", 0) < 0)
		return (READ_ERROR);
	if (keep == NULL)
		keep = ft_strnew(1);
	while ((buffout = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[buffout] = '\0';
		keep = ft_strjoin(keep, buf);
	//	printf("<<<%s>>>\n", keep);
		if (ft_contain_char(keep, '\n'))
			break ;
	}
	if (*keep == 0 && buffout == 0)
		return (READ_COMPLETE);
	*line = ft_strsub(keep, 0, new_line_ind(keep));
	keep = ft_remainder(keep);
	//printf("|--%s--|\n", keep);
	return (READ_SUCCESS);
}
