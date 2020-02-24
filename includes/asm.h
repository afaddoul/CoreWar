/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <afaddoul@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 09:41:11 by afaddoul          #+#    #+#             */
/*   Updated: 2020/01/12 19:00:51 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
#define ASM_H

#include "libft.h"
#include <stdio.h>
#include <fcntl.h>
# define BUFF_SIZE 1000
# define MAX_SIZE 1000000

void			check_fextension(char *str);
char			*read_file(int fd);
size_t			ft_vrealloc(char *buff, size_t buff_size);

#endif
