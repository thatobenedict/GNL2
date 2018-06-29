/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenedic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 16:10:34 by tbenedic          #+#    #+#             */
/*   Updated: 2018/06/29 18:31:43 by tbenedic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GNL/get_next_line.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h> //for the main
#include <sys/types.h> //for the main
#include <sys/types.h> //for the main
#include <fcntl.h>
#include <string.h>

int		main(void)
{
	int		fd;
	int		strbuf;
	char	*line;

	fd = open("file.txt", O_RDONLY, 0700);
	if(fd == -1)
	{
		printf("Failed to create and open and read the file.\n");
		return (1);
	}
	while ((strbuf = get_next_line(fd, &line)) == 1)
		printf("%s\n", line);
//	strbuf = get_next_line(fd, &line);
//	printf("%s\n", line);
	close(fd);
	return 0;
}
