/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <afaddoul@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 21:08:54 by afaddoul          #+#    #+#             */
/*   Updated: 2020/03/12 22:15:43 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		ft_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int			main(int argc, char *argv[])
{
	t_env	*env;
	char	*file;
	int		fd;

	if (argc != 2)
		ft_error();
	check_fextension(argv[1]);
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		ft_error();
	file = read_file(fd);
	close(fd);
	if (!(env = (t_env*)ft_memalloc(sizeof(t_env))))
	{
		ft_strdel((char**)&file);
		ft_error();
	}
	if (!(env->file_name = ft_fname_extracter(argv[1])))
	{
		ft_strdel((char**)&file);
		ft_memdel((void**)&env);
		return (0);
	}
	env->vect = file;
	ft_assembler(env);
	return (0);
}
