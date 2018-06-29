/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenedic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 13:05:38 by tbenedic          #+#    #+#             */
/*   Updated: 2018/06/29 18:31:45 by tbenedic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#define	READ_SUCCESS 1
#define READ_COMPLETE 0
#define	READ_ERROR -1
#define BUFF_SIZE 10
#include "libft/libft.h"
#include <fcntl.h>
#include <unistd.h>

int		get_next_line(const int fd, char **line);

#endif
