/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frontend_analysis.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 02:23:34 by afaddoul          #+#    #+#             */
/*   Updated: 2020/03/12 20:55:16 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		dummy_del(void *content)
{
	if ((((t_instru*)content)->buff))
		ft_strdel((char**)&(((t_instru*)content)->buff));
	if (content)
		ft_memdel((void**)&(content));
}

t_env		*ft_frontend_analys(t_env *env)
{
	if (!(env->lines = (t_dlist*)ft_memalloc(sizeof(t_dlist))))
		return (NULL);
	if (!(ft_line_parser(env)))
		return (NULL);
	if (!(ft_cmd_parser(env)))
		return (NULL);
	if (!(env->labels = (t_dlist*)ft_memalloc(sizeof(t_dlist))))
		return (NULL);
	if (!(ft_instruparser(env)))
		return (NULL);
	if (!(ft_semantic_analysis(env)))
		return (NULL);
	return (env);
}
