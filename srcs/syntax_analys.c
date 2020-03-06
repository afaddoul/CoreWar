/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_analys.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ada <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 02:20:22 by ada               #+#    #+#             */
/*   Updated: 2020/03/06 12:15:24 by afaddoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			ft_islabel(char c)
{
	if ((c >= 97 && c <= 122) || (c >= 48 && c <= 57)
			|| c == '_')
		return (1);
	return (0);
}

int 			ft_isop(char c)
{
	if ((c >= 97 && c <= 122))
		return (1);
	return (0);
}

char				*ft_instrucpy(char *ptr, char *dest)
{
	int 			i;
	int 			j;

	i = 0;
	j = 0;
	while (ptr[i])
	{
		if (ptr[i] != 9 && ptr[i] != 32)
		{
			dest[j] = ptr[i];
			j++;
		}
		i++;
	}
	return (dest);
}

char 				*ft_wsdel(char *str)
{
	int 			i;
	size_t			len;
	int 			counter;
	char 			*dest;

	i = 0;
	counter = 0;
	while (str[i])
	{
		if (str[i] == 9 || str[i] == 32)
			counter++;
		i++;
	}
	len = ft_strlen(str) - counter;
	if (!(dest = (char*)ft_memalloc(sizeof(char) * (len + 1))))
		return (NULL);
	dest = ft_instrucpy(str, dest);
	return (dest);
}

t_label				*ft_labelnew(char *token)
{
	t_label 		*elm;

	if (!(elm = (t_label*)ft_memalloc(sizeof(t_label))))
		return (NULL);
	elm->label = token;
	return (elm);
}

int 				ft_lbltokenizer(t_env *env, t_element *elm,
		char *ptr, int len)
{
	char 			*str;
	t_label			*element;
	t_element 		*label;

	if (!(str = (char*)ft_memalloc(sizeof(char) * (len + 1))))
		return (0);
	ft_strncpy(str, ptr, len);
	if (!(element = ft_labelnew(str)))
	{
		ft_strdel((char**)&str);
		return (0);
	}
	if (!(label = ft_elemnew(element)))
	{
		ft_strdel((char**)&str);
		ft_memdel((void**)&element);
		return (0);
	}
	ft_dlstpush(env->labels, label);
	SYM_TAB->label = ft_strdup(str);
	((t_instru*)(elm->content))->lbl_flg = 1;
	return (1);
}

int 				ft_isreg(t_element *elm, char *arg)
{
	int 			i;
	int 			reg;

	i = 0;
	reg = 0;
	while (arg[i])
	{
		if (!(ft_isdigit(arg[i])))
			return (0);
		i++;
	}
	reg = ft_atoi(arg);
	if (reg < 1 || reg > 16)
		return  (0);
	SYM_TAB->val_1->val = reg;
	SYM_TAB->val_1->nature = T_REG;
	return (1);
}

int 				ft_check_args(t_element *elm, char *arg, int arg_nb)
{
	int 			val;

	val = -1;
	if (*arg == 'r')
	{
		if (!(ft_isreg(elm, arg + 1)))
			return (0);
	}
	else if (*arg == DIRECT_CHAR)
	{
		if (!(ft_isdir(elm, arg + 1)))
			return (0)
	}
	else if (*arg == LABEL_CHAR || *arg == '-' || ft_isdigit(*arg))
	{
		if (!(ft_isindir(elm, arg)))
			return (0);
	}
return (1)
}

int					ft_argtokenizer(t_element *elm, char *str, int start,
		int end)
{
	int 			i;
	int				len;
	char 			*arg;

	i = 0;
	len  = end - start;
	if (!(arg = ft_strsub(str, start, len)))
		return (0);
	if (!SYM_TAB->arg_1)
	{
		SYM_TAB->arg_1 = arg;
		if (!(ft_check_arg(elm, arg, 1)))
			return (0);
	}
	else if (!SYM_TAB->arg_2)
	{
		SYM_TAB->arg_2 = arg;
		if (!(ft_check_arg(elm, arg, 2)))
			return (0);
	}
	else if (!SYM_TAB->arg_3)
	{
		SYM_TAB->arg_3 = arg;
		if (!(ft_check_arg(elm, arg, 3)))
			return (0);
	}
	else
		return (0);
	return (1);
}

int 				ft_argscanner(t_element *elm, char *str, int index)
{
	int 			i;
	int 			j;
	int 			calls_nb;

	i = 0;
	j = 0;
	calls_nb = 1;
	while (str[i])
	{
		if (str[i] == 'r' || str[i] == DIRECT_CHAR || str[i] == LABEL_CHAR ||
				ft_isdigit(str[i]) || str[i] == '-')
		{
			j = i;
			while (str[i])
			{
				if (str[i] == SEPARATOR_CHAR || str[i] == '\n' ||
						str[i] == COMMENT_CHAR || str[i] == ALT_COMMENT_CHAR)
				{
					if (calls_nb > g_op_tab[index].arg_nb)
						return (0);
					if (!ft_argtokenizer(elm, str, j, i))
						return (0);
					calls_nb++;
					break ;
				}
				i++;
			}
		}
		if (str[i] == '\n' || str[i] == COMMENT_CHAR ||
				str[i] == ALT_COMMENT_CHAR)
			break ;
		i++;
	}
	if (!SYM_TAB->arg_1)
		return (0);
	return (1);
}

t_env				*ft_get_instru(t_env *env, t_element *elm, char *str)
{
	int 			i;
	int				len;
	int 			index;
	char 			*ptr;

	i = 0;
	if (!(ptr = ft_wsdel(str)))
		return (NULL);
	while (i < 16)
	{
		if ((ft_strstr(ptr, g_op_tab[i].op)))
		{
			if (!ft_strncmp(ptr, g_op_tab[i].op, ft_strlen(g_op_tab[i].op)))
				{
					len = ft_strlen(g_op_tab[i].op);
					if (ptr[len] == 'r' || ptr[len] == DIRECT_CHAR ||
							ptr[len] == LABEL_CHAR ||
						ft_isdigit(ptr[len]) || ptr[len] == '-')
					{
						break ;
					}
				}
		}
		if (i == 15)
			return (NULL);
		i++;
	}
	if (!(SYM_TAB->op = ft_strdup(g_op_tab[i].op)))
		return (NULL);
	index = i;
	i = ft_strlen(g_op_tab[i].op);
	((t_instru*)(elm->content))->op_flg = 1;
	if (!(ft_argscanner(elm, ptr + i, index)))
		return (NULL);
	return (env);
}

t_env				*ft_getop(t_env *env, t_element *elm, char *ptr)
{
	int 			i;

	i = 0;
	while (ptr[i])
	{
		if (!ft_isop(ptr[i]))
		{
			if (!ft_get_instru(env, elm, ptr))
				return (NULL);
			else
				return (env);
		}
		i++;
	}
	return (NULL);
}

int 				ft_instru_tokenizer(t_env *env, t_element *elm, char *ptr)
{
	if (!(ft_getop(env, elm, ptr)))
		return (0);
	return (1);
}

int 				ft_syntax_analys(t_env *env, t_element *elm, char *ptr)
{
	int 			i;
	i = 0;
	while (ptr[i])
	{
		if (!ft_islabel(ptr[i]))
		{
			if (ptr[i] == LABEL_CHAR)
			{
				if (!(ft_lbltokenizer(env, elm, ptr, i)))
					return (0);
				i++;
				break ;
			}
			else
				break ;
		}
		i++;
	}
	if (((t_instru*)(elm->content))->lbl_flg == 1)
	{
		if (ptr[i] == COMMENT_CHAR ||
				ptr[i] == ALT_COMMENT_CHAR || ptr[i] == '\n')
			return (1);
		else
		{
			if (!(ft_instru_tokenizer(env, elm, (ptr + i))))
			{
				//free last cash
				return (0);
			}
		}
	}
	else if (!(ft_instru_tokenizer(env, elm, ptr)))
	{
		//free last cash
		return (0);
	}
	return (1);
}
