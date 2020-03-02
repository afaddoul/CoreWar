/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaddoul <afaddoul@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 09:41:11 by afaddoul          #+#    #+#             */
/*   Updated: 2020/03/02 14:14:00 by ada              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
#define ASM_H

#include "libft.h"
#include "op.h"
#include <stdio.h>
#include <fcntl.h>
# define BUFF_SIZE 1000
# define MAX_SIZE 1000000
# define SYM_TAB ((t_symbol_tab*)(((t_instru*)(elm->content))->sym_tab))


typedef struct s_op
{
	char		*op;
	int			arg_nb;
	int 		arg[3];
	int 		op_index;
	int 		cycle;
	char 		*op_desc;
	int			arg_tcode;
	int 		dir_size;
}				t_op;

t_op				g_op_tab[17];

typedef struct 		s_label
{
	char			*label;
}					t_label;

typedef struct 		s_symbol_tab
{
	char			*label;
	char 			*op;
	char 			*arg_1;
	char 			*arg_2;
	char 			*arg_3;
}					t_symbol_tab;

typedef struct 		s_instru
{
	char			*buff;
	int				op_flg;
	int				lbl_flg;
	int 			index;
	t_symbol_tab	*sym_tab;
}					t_instru;


typedef struct 		s_env
{
	t_dlist 		*lines;
	t_dlist 		*labels;
	char 			*vect;
	char 			*name;
	char 			*comment;
}					t_env;

void			check_fextension(char *str);
char			*read_file(int fd);
char 			*ft_vrealloc(char **buff, size_t buff_size);
void			ft_assembler(t_env *env);
t_env			*ft_frontend_analys(t_env *env);
t_env			*ft_line_parser(t_env *env);
char			*ft_get_line(t_env *env, int start, int end);
t_instru		*ft_instru_new(char *line);
t_env			*get_name(t_env *env, const char *ptr, int max_size);
t_env			*get_cmt(t_env *env, const char *ptr, int max_size);
t_env			*ft_get_cmd_dispatcher(t_env *env, const char *ptr);
t_env			*ft_cmd_parser(t_env *env);
void 			ft_error(void);
void			dummy_del(void *content);
t_env			*ft_instruparser(t_env *env);
t_env			*ft_scanner(t_env *env, t_element *elm, char *ptr);
int				ft_syntax_analysis(t_env *env, t_element *elm, char *ptr);
int				ft_instru_tokenizer(t_env *env, t_element *elm, char *ptr);
t_env			*ft_getop(t_env *env, t_element *elm, char *ptr);
t_env			*ft_get_instru(t_env *env, t_element *elm, char *str);
int				ft_argscanner(t_element *elm, char *str,
		int index);
int                 ft_argtokenizer(t_element *elm, char *str, int start,
		int arg);
int					ft_lbltokenizer(t_env *env, t_element *elm,char *ptr,
		int len);
//static t_label	*ft_labelnew(char *token);
char			*ft_wsdel(char *str);
char			*ft_intrucpy(char *ptr, char *dest);


#endif
