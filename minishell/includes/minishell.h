/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <nicolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 09:40:34 by cyhuet            #+#    #+#             */
/*   Updated: 2019/11/25 20:11:48 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <dirent.h>
# include <sys/ioctl.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/dir.h>
# include <sys/stat.h>
# include <sys/param.h>
# include <sys/resource.h>
# include <sys/resource.h>
# include <fcntl.h>
# include "libft.h"
# include "structs.h"
# include <errno.h>

# define MAX_HASH 4096
# define BUFFER_SIZE 1

int				get_next_line(int fd, char **line);

int				is_builtin(t_cmd *cmd);
void			exec_builtin(t_cmd *cmd);
void			exec_pwd(t_cmd *cmd);
void			exec_cd(t_cmd *cmd);
void			update_pwd();
void			exec_echo(t_cmd *cmd);
void			exec_export(t_cmd *cmd);
void			exec_unset(t_cmd *cmd);
void			exec_exit(t_cmd *cmd);

void			free_arr(char **arr);
char			*ft_rm_quotes(char *cmd);
int				arr_len(char **arr);
void			print_error(char *cmd);
int				not_even(char *str);
void			lstadd_back(t_hash_lst **alst, t_hash_lst *new);
void			str_append(char **s, char *suffix);
void			handle_not_even(char **argv);

char			*env_get_value(char *key);
void			env_set_value(char *key, char *value);
int				env_size();
void			create_env_list(char **envp);
void			create_env_array();

unsigned int	ft_hash_code(const char *key);
void			ft_free_item(t_hash_lst *item);
void			ft_delete_item(t_hash_lst *table[], const char *key);
t_hash_lst		*ft_search(t_hash_lst *head, const char *key);
void			ft_insert_item(t_hash_lst **hash, const char *key,
					const char *val);
int				is_true_quote(char *str, int i, char c);

void			ft_hash_table_bin(t_hash_lst **table, char **path);
void			ft_create_stack();
char			*ft_build_exec(char *name_exec);

int				has_rdir(t_cmd *cmd);
int				open_cmd_files(t_cmd *cmd);
void			dup_cmd_files(t_cmd *cmd);
void			close_cmd_files(t_cmd *cmd);
void			handle_rdir(t_cmd *cmd);

void			handle_pipes(char **cmds);
int				has_pipes(t_cmd *cmd);

void			ft_str_substitution(char **str);

int				is_executable(char *bin_path);
void			exec_cmd(t_cmd *cmd);
void			dispatch_cmd(char *cmd);
void			exec_pipe_rdir_cmd(t_cmd *cmd);
void			run_single_cmd(t_cmd *cmd);

void			init_file_cmd(t_cmd *cmd);
void			free_cmd(t_cmd *cmd);

void			get_argv(t_cmd *cmd);
void			handle_sig(int sig);

void			print_buffer(t_sub *sub, char *str, int len);
void			essai_avance_backslash(t_sub *sub, char *s);
void			essai_avance_quote(t_sub *sub, char *s);
void			concat_itoa(t_sub *sub);
void			concat_env(t_sub *sub, char *s);
int				check_empty(char **line);

void			fatal_error(char *str);
t_env			*get_env();
t_hash_lst		**get_hash();
int				*get_executed();
int				*get_exit_status();
char			**get_line();

#endif
