/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenedic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 16:10:34 by tbenedic          #+#    #+#             */
/*   Updated: 2018/06/30 16:01:59 by tbenedic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h> //for the main
#include <sys/types.h> //for the main
#include <sys/types.h> //for the main
#include <fcntl.h>
#include <string.h>

int		main(int ac, char *av[])
{
	int		fd;
	int		strbuf;
	char	*line;

	(void) ac;
	fd = open(av[1], O_RDONLY, 0700);
	printf("%d\n", fd);
	//	if(fd == -1)
	//	{
	//		printf("Failed to create and open and read the file.\n");
	//		return (1);
	//	}
	line = NULL;
	while ((strbuf = get_next_line(fd, &line)) == 1)
	{
		//printf("%d\n", strbuf);
		printf("[%s]\n\n", line);
	}
	//	strbuf = get_next_line(fd, &line);
	//	printf("%s\n", line);
	close(fd);
	return 0;
}
