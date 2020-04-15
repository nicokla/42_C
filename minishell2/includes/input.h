#ifndef INPUT_H
# define INPUT_H

# include "ftsh.h"

# define BUF_SIZE 8
# define STD_PROMPT "["SHELL_NAME"]"
# define PROMPT_REVERSE_I_SEARCH_SUCC "(reverse-i-search)"
# define PROMPT_REVERSE_I_SEARCH_FAIL "(failed reverse-i-search)"
# define CONTINUE_PROMPT "cont"
# define FC_EDIT_FILENAME "/tmp/.tmp_fc_edit"
# define MAX_INT_LEN 10

typedef enum	e_input
{
	input_break = 1,
	input_continue,
	input_stop
}				t_input;

typedef enum	e_search_case
{
	enter_case = 1,
	ctrl_c_case,
	quit_case
}				t_search_case;

typedef enum	e_input_mode
{
	regular,
	heredoc,
	continue_read
}				t_input_mode;

typedef struct			s_st_txt {
	char				*txt;
	size_t				malloc_size;
	size_t				data_size;
	size_t				tracker;
}						t_st_txt;

typedef struct			s_st_prompt {
	char				*name;
	char				*dir;
	char				*exit;
	char				*end;
	size_t				size;
}						t_st_prompt;

typedef struct			s_st_cmd {
	struct s_st_txt		*st_txt;
	struct s_st_prompt	*st_prompt;
	struct s_st_cmd		*next;
	struct s_st_cmd		*prev;
	int					keep;
	int					cr;
	int					is_cr_sqt;
	char				pad[4];
}						t_st_cmd;

/* arrows */
void	move_arrow_right(t_st_cmd *st_cmd);
void	move_arrow_left(t_st_cmd *st_cmd);
void	delete_left(t_st_cmd *st_cmd);
void	delete_right(t_st_cmd *st_cmd);

/*
** Handling input
*/
int						is_valid_escape(char *str);
int						handle_input(t_st_cmd *st_cmd, t_vars *vars);
void					insert_txt(t_st_cmd *st_cmd, const char *buf);

/*
**	Input checking
*/

int						checkers(t_st_cmd *st_cmd, t_vars *vars, char *buf,
		int mode);
int						check_for_quit(t_st_cmd *st_cmd, const char *buf);
int						check_for_enter(const char *buf);
int						check_for_signal(const char *buf);
int						check_for_delete(t_st_cmd *st_cmd, char *buf);
int						check_for_select_mode(t_st_cmd *st_cmd, char *buf,
		t_vars *vars);
int						check_select_paste(t_st_cmd *st_cmd, char *buf,
		t_vars *vars);
int						check_for_search_histo(t_st_cmd *st_cmd,
		const char *buf_received, int mode);
int						check_for_tab(t_st_cmd *st_cmd, const char *buf,
	t_vars *vars, int mode);
int						check_for_words(t_st_cmd *st_cmd, const char *buf);
char					*auto_completion(char *input, unsigned int len);
char					*auto_completion_spe(char *input,
		unsigned int len);

/*
**	st_txt functions
*/

t_st_txt				*init_st_txt(const char *txt);
void					free_st_txt(t_st_txt **st_txt);

/*
** Read input
*/

int						input_loop(t_st_cmd *st_cmd, t_vars *vars,
		t_input_mode mode);

/*
**	st_prompt functions
*/

void					zsh_newline(t_st_cmd *st_cmd);
t_st_prompt				*init_st_prompt(const char *name, const char *dir,
	int exitno);
char					*exit_to_str(int exit);
char					*dir_to_str(const char *tmp);
void					print_prompt(t_st_cmd *st_cmd, int zsh);
void					free_st_prompt(t_st_prompt **st_prompt);

/*
**	st_cmd functions
*/

t_st_cmd				*get_first_st_cmd(t_st_cmd *st_cmd);
t_st_cmd				*get_last_st_cmd(t_st_cmd *st_cmd);
t_st_cmd				*get_st_cmd(t_st_cmd **new_struct);
t_st_cmd				*init_st_cmd(const char **env);
t_st_cmd				*append_st_cmd(t_st_cmd *st_cmd, const char *txt,
		t_st_prompt *prompt);
t_st_cmd				*reset_st_cmd(t_st_cmd *old_st_cmd, t_vars *vars);
t_st_cmd				*get_st_cmd(t_st_cmd **new_struct);
t_st_cmd				*init_st_cmd(const char **env);
char					*concatenate_txt(t_st_cmd *st_cmd, int mode);
void					free_st_cmd(t_st_cmd *st_cmd);
void					free_all_st_cmds(t_st_cmd **st_cmd);

/*
**	tmp files function
*/

char					*find_unique_filename(char *type);
#endif
