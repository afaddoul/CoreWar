/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <afaddoul@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 02:28:36 by afaddoul          #+#    #+#             */
/*   Updated: 2020/03/07 13:56:12 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
void	swap_bytes(void *src, void *dst, int size)
{
	int i = 0;
	int j = size - 1;
	while (i < size)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[j];
		j--;
		i++;
	}
}
int main()
{
	char 	c;
	c = 0;

	c = c << 2;
}

int main()
{
	char 	str[4];
	int fd;
	str[0] = ‘a’;
	str[1] = ‘b’;
	str[2] = ‘c’;
	str[3] = ‘\0’;
	fd = open(“output”, O_CREAT | O_WRONLY);
	write(fd, &str, 3);
}

int main()
{
	int nb = 15;
	int fd;
	fd = open("output2", O_CREAT | O_WRONLY);
	int nbswapped = 0;
	swap_bytes(&nb, &nbswapped, 1);
	write(fd, &nbswapped, 1);
}
