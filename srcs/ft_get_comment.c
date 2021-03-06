/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_comment.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <afaddoul@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 21:07:36 by afaddoul          #+#    #+#             */
/*   Updated: 2020/03/12 21:07:36 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int					get_first_comment_line(char *buff, const char *ptr, int *i,
		int *j)
{
	while (ptr[*i] && (ptr[*i] == 9 || ptr[*i] == 32))
		(*i)++;
	if (!ptr[*i])
		return (0);
	if (ptr[(*i)++] != '"')
		return (0);
	while (ptr[*i])
	{
		if (*j > COMMENT_LENGTH)
			return (0);
		if (ptr[*i] == '"' && ptr[*i - 1] != '\\')
		{
			(*i)++;
			break ;
		}
		buff[*j] = ptr[*i];
		(*i)++;
		(*j)++;
	}
	while (ptr[*i] && (ptr[*i] == 9 || ptr[*i] == 32))
		(*i)++;
	return (1);
}

t_element			*get_cmt(t_env *env, const char *ptr, int max_size,
		t_element *elm)
{
	char			buff[max_size + 1];
	int				i;
	int				j;

	i = 0;
	j = 0;
	ft_bzero(buff, max_size + 1);
	if (!(get_first_comment_line(buff, ptr, &i, &j)))
		return (0);
	if (!ptr[i])
	{
		elm = elm->next;
		elm = ft_get_next_node(elm, buff, j, max_size);
		ft_cmd_dup(env, buff, max_size);
		return (elm);
	}
	if (ptr[i] == COMMENT_CHAR || ptr[i] == ALT_COMMENT_CHAR || ptr[i] == '\n')
		ft_cmd_dup(env, buff, max_size);
	return (elm);
}
