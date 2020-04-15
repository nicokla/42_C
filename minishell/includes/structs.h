/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <nicolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 09:35:48 by cyhuet            #+#    #+#             */
/*   Updated: 2019/11/25 19:14:57 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct	s_hash_lst
{
	char				*key;
	char				*value;
	struct s_hash_lst	*next;
}				t_hash_lst;

typedef struct	s_env
{
	t_hash_lst	*l;
	char		**a;
}				t_env;

typedef struct	s_rdir
{
	char	*file;
	int		fd;
}				t_rdir;

typedef struct	s_cmd
{
	char	**argv;
	char	*str;
	t_rdir	*in;
	t_rdir	*out;
	t_rdir	*out_dbl;
}				t_cmd;

typedef struct	s_sub
{
	int		i;
	int		j;
	int		len;
	char	buf[2000];
	int		len_total;
	int		inter_backslash[2];
	char	*with;
	char	*needle;
	int		quotes[2];
	char	extquote;
}				t_sub;

#endif
