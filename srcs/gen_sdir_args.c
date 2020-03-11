/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_sdir_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ada <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 23:37:03 by ada               #+#    #+#             */
/*   Updated: 2020/03/11 23:38:26 by ada              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void						ft_gen_sdir_arg1(t_symbol_tab *sym_tab, t_env *env,
		int i, int *pc)
{
	if (sym_tab->arg_1[1] == LABEL_CHAR)
	{
		*pc = ft_get_label_pc_dir(env, sym_tab->arg_1);
		sym_tab->val_1.val = *pc - sym_tab->pc;
	}
	env->exec[i] = ((char*)(&sym_tab->val_1.val))[1];
	env->exec[i + 1] = ((char*)(&sym_tab->val_1.val))[0];
}

void						ft_gen_sdir_arg2(t_symbol_tab *sym_tab, t_env *env,
		int i, int *pc)
{
	if (sym_tab->arg_2[1] == LABEL_CHAR)
	{
		*pc = ft_get_label_pc_dir(env, sym_tab->arg_2);
		sym_tab->val_2.val = *pc - sym_tab->pc;
	}
	env->exec[i] = ((char*)(&sym_tab->val_2.val))[1];
	env->exec[i + 1] = ((char*)(&sym_tab->val_2.val))[0];
}

void						ft_gen_sdir_arg3(t_symbol_tab *sym_tab, t_env *env,
		int i, int *pc)
{
	if (sym_tab->arg_3[1] == LABEL_CHAR)
	{
		*pc = ft_get_label_pc_dir(env, sym_tab->arg_3);
		sym_tab->val_3.val = *pc - sym_tab->pc;
	}
	env->exec[i] = ((char*)(&sym_tab->val_3.val))[1];
	env->exec[i + 1] = ((char*)(&sym_tab->val_3.val))[0];
}
