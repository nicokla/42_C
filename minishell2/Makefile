###############################################################################

# Basics #######################################################################
NAME	:=	minishell
OPT		:=	
CC		:=	gcc
CFLAGS	:=	-Wall -Wextra -Werror -g
MMD		:=	-MMD

DEBUG_FLAG	:=	-g
FSA_FLAGS	:=	$(DEBUG_FLAG) -fsanitize=address
VAL_FLAGS	:=	--track-origins=yes --show-leak-kinds=all --track-fds=yes 		\
				--show-reachable=no --leak-check=full

# Libraries ####################################################################
LIBFT_DIR		:=	libft
# LIBTERM_DIR		:=	libterm

LIB_INCL		:=	-L $(LIBFT_DIR) -lft
# -L $(LIBTERM_DIR) -lterm -ltermcap

LIBFT_A			:=	$(addprefix $(LIBFT_DIR)/,libft.a)
# LIBTERM_A		:=	$(addprefix $(LIBTERM_DIR)/,libterm.a)

LIBS			:= $(LIBFT_A) 
# $(LIBTERM_A)

# Includes #####################################################################
INCL_DIR	:=	includes libft/includes 
# libterm/includes
INCL_CMD	:=	$(addprefix -I,$(INCL_DIR))

INCL_FILES	:=	ftsh.h lexer.h ast.h auto_completion.h input.h \
				structures.h newstuff.h  \
				builtins.h errors.h cmd_parsing.h execution.h \
				signals.h hashmap.h env.h jobs.h

INCLS		:=	$(addprefix includes/,$(INCL_FILES))


# Directories ##################################################################
SRC_DIR	:=	srcs
	#srcs subdirectories names
	ENV_DIR				:=	environment
	ERRORS_DIR			:=	errors
	LEXER_DIR			:=	lexer
	PARSER_DIR			:=	ast
	PIPELINE_DIR		:=	pipeline
	READER_DIR			:=	reader
	EXPANDS_DIR			:=	expands
	SIGNALS_DIR			:=	signals
	BUILTINS_DIR		:=	builtins
	REDIR_DIR			:=	redirections
	EXEC_DIR			:=	execution
	HASHMAP_DIR			:=	hashmap
	CD_DIR				:=	cd
	TEST_DIR			:=	test
	JOB_CTRL_DIR		:=	job_control

	#list of all srcs subdirectories
	SRC_SUBDIRS	:=	$(ENV_DIR) $(ERRORS_DIR) $(LEXER_DIR) $(PARSER_DIR)			\
					$(PIPELINE_DIR) $(READER_DIR)			\
					$(EXPANDS_DIR) $(SIGNALS_DIR)			\
					$(BUILTINS_DIR) $(REDIR_DIR) $(EXEC_DIR)	\
					$(TMP_VAR_DIR)				\
					$(CD DIR) $(TEST_DIR) $(JOB_CTRL_DIR)						\
					$(addprefix $(BUILTINS_DIR)/,$(HASHMAP_DIR))				\
					$(addprefix $(BUILTINS_DIR)/,$(CD_DIR))						\
					$(addprefix $(BUILTINS_DIR)/,$(TEST_DIR))

#VPATH specifies a list of directories that 'make' should search
VPATH	:=	$(SRC_DIR) $(addprefix $(SRC_DIR)/,$(SRC_SUBDIRS))

# Srcs file names ##############################################################
SRC_FILES	:=	st_txt.c prompt_str.c st_prompt.c st_cmd_freeing.c \
				st_cmd_editing.c st_cmd_getters.c \
				newstuff.c handle_input.c free.c main.c \
				clean_exit.c ft_strjoin_free_left.c\
				tmp_file.c t_vars.c
	ENV_FILES		:=	environ_set.c environ_utils.c init_env.c shlvl.c		\
						environ_unset.c set_default_shell_vars.c				\
						variables_utils.c ntab_utils.c variables_utils2.c
	ERRORS_FILES	:=	errors.c print_errors.c error_exit.c
	LEXER_FILES		:=	lexer.c lexer_tools.c lexer_op_chart.c get_token.c		\
						copy_token_list.c lexer_escape_tools.c					\
						check_special_token.c
	PARSER_FILES	:=	ast.c ast_utils.c ast_exec.c background_case.c
	PIPELINE_FILES	:=	parse_pipeline.c check_token_type.c
	READER_FILES	:=	input_utils.c prompt.c txt_cat.c \
						input_loop.c
	EXPANDS_FILES	:=	parse_expands.c parse_tildes.c parse_vars.c				\
						parse_quotes.c special_lltoa.c		\
						substitute_utils.c parse_tildes_utils.c get_var_name.c	\
						parse_assignation.c
	SIGNALS_FILES	:=	signals_handlers.c signals_setup.c
	BUILTINS_FILES	:=	cmd_cd.c builtins_cmd.c cmd_hash.c cmd_exit.c			\
						cmd_type.c cmd_echo.c cmd_jobs.c cmd_fg.c cmd_bg.c		\
						cmd_exit_utils.c cmd_jobs_utils.c						\
						cmd_test.c check_builtins.c				\
						cmd_set.c cmd_unset.c cmd_export.c cmd_export_utils.c
	CD_FILES		:=	cmd_cd_options.c cmd_cd_cdpath.c						\
						cmd_cd_format.c cmd_cd_remove_char.c					\
						cmd_cd_change_env.c cmd_cd_check.c cmd_cd_utils.c
	TEST_FILES		:=	cmd_test_bcdef.c cmd_test_checks.c						\
						cmd_test_glprs.c cmd_test_suwxz.c cmd_test_bin.c		\
						cmd_test_oper.c cmd_test_bin_utils.c					\
						cmd_test_opposite.c cmd_test_get_opt.c
	REDIR_FILES		:=	redir_dgreat.c redir_fd_great.c fd_utils.c				\
						redir_great.c redir_less.c parse_redirections.c			\
						redir_fd_less.c redirections_errors.c redir_fd_utils.c	\
						close_open_fds.c
	EXEC_FILES		:=	cmd_path.c execute_commands.c token_to_argv.c			\
						execute_no_pipe_builtin.c exit_status.c exec_bin.c		\
						check_no_pipe_builtin.c
	HASHMAP_FILES	:=	find_next_prime.c hash_main.c hashfun.c hashmap.c		\
						hashmap_alloc.c hashmap_delete.c hashmap_print.c		\
						get_hash_args.c hashmap_errors.c
	JOB_CTRL_FILES	:=	job_utils.c job_init.c free_job.c job_background.c \
						job_continue.c job_display.c job_foreground.c \
						job_notification.c job_status.c launch_job.c \
						launch_process.c process_list.c wait_for_job.c \
						job_list.c copy_tokens.c find_job.c job_id_parser.c \
						set_current.c free_process.c exit_str.c \
						launch_job_utils.c

#list of all .c files
C_FILES	:=	$(SRC_FILES) $(ENV_FILES) $(ERRORS_FILES) $(LEXER_FILES)			\
			$(PARSER_FILES) $(PIPELINE_FILES) $(READER_FILES)					\
			$(EXPANDS_FILES) $(SIGNALS_FILES)					\
			$(BUILTINS_FILES) $(REDIR_FILES) $(EXEC_FILES)	\
			$(HASHMAP_FILES) 			\
			$(CD_FILES) $(TEST_FILES) $(TMP_VAR_FILES)			\
			$(JOB_CTRL_FILES)

# Complete path of each .c files ###############################################
SRC_PATH			:=	$(addprefix $(SRC_DIR)/,$(SRC_FILES))
ENV_PATH			:=	$(addprefix $(ENV_DIR)/,$(ENV_FILES))
ERRORS_PATH			:=	$(addprefix $(ERRORS_DIR)/,$(ERRORS_FILES))
LEXER_PATH			:=	$(addprefix $(LEXER_DIR)/,$(LEXER_FILES))
PARSER_PATH			:=	$(addprefix $(PARSER_DIR)/,$(PARSER_FILES))
PIPELINE_PATH		:=	$(addprefix $(PIPELINE_DIR)/,$(PIPELINE_FILES))
READER_PATH			:=	$(addprefix $(READER_DIR)/,$(READER_FILES))
EXPANDS_PATH		:=	$(addprefix $(EXPANDS_DIR)/,$(EXPANDS_FILES))
SIGNALS_PATH		:=	$(addprefix $(SIGNALS_DIR)/,$(SIGNALS_FILES))
BUILTINS_PATH		:=	$(addprefix $(BUILTINS_DIR)/,$(BUILTINS_FILES))
REDIR_PATH			:=	$(addprefix $(REDIR_DIR)/,$(REDIR_FILES))
EXEC_PATH			:=	$(addprefix $(EXEC_DIR)/,$(EXEC_FILES))
HASHMAP_PATH		:=	$(addprefix $(HASHMAP_DIR)/,$(HASHMAP_FILES))
CD_PATH				:=	$(addprefix $(CD_DIR)/,$(CD_FILES))
TEST_PATH			:=	$(addprefix $(TEST_DIR)/,$(TEST_FILES))

#	builtin/ + hashmap/.c
HASHMAP_PATH		:=	$(addprefix $(BUILTINS_DIR)/,$(HASHMAP_PATH))
CD_PATH				:=	$(addprefix $(BUILTINS_DIR)/,$(CD_PATH))
TEST_PATH			:=	$(addprefix $(BUILTINS_DIR)/,$(TEST_PATH))
TMP_VAR_PATH		:=	$(addprefix $(TMP_VAR_DIR)/,$(TMP_VAR_FILES))
JOB_CTRL_PATH		:=	$(addprefix $(JOB_CTRL_DIR)/,$(JOB_CTRL_FILES))


#list of all "path/.c"
SRCS	:=	$(addprefix $(SRC_DIR)/,$(ENV_PATH)) \
			$(addprefix $(SRC_DIR)/,$(ERRORS_PATH)) \
			$(addprefix $(SRC_DIR)/,$(LEXER_PATH)) \
			$(addprefix $(SRC_DIR)/,$(PARSER_PATH)) \
			$(addprefix $(SRC_DIR)/,$(PIPELINE_PATH)) \
			$(addprefix $(SRC_DIR)/,$(READER_PATH)) \
			$(addprefix $(SRC_DIR)/,$(EXPANDS_PATH)) \
			$(addprefix $(SRC_DIR)/,$(SIGNALS_PATH)) \
			$(addprefix $(SRC_DIR)/,$(BUILTINS_PATH)) \
			$(addprefix $(SRC_DIR)/,$(REDIR_PATH)) \
			$(addprefix $(SRC_DIR)/,$(EXEC_PATH)) \
			$(addprefix $(SRC_DIR)/,$(HASHMAP_PATH)) \
			$(addprefix $(SRC_DIR)/,$(CD_PATH)) \
			$(addprefix $(SRC_DIR)/,$(TEST_PATH)) \
			$(addprefix $(SRC_DIR)/,$(TMP_VAR_PATH)) \
			$(addprefix $(SRC_DIR)/,$(JOB_CTRL_PATH)) \
			$(SRC_PATH)

#Object ########################################################################
OBJ_DIR		:=	objs
OBJ_FILES	:=	$(C_FILES:.c=.o)
DEPS		:=	$(OBJ_FILES:.o=.d)
OBJS		:=	$(addprefix $(OBJ_DIR)/,$(OBJ_FILES))


DEPENDENCIES	:= $(addprefix $(OBJ_DIR)/,$(DEPS))


# Rules ########################################################################

.PHONY: all
all: $(LIBFT_A) $(OBJ_DIR) $(NAME)
#  $(LIBTERM_A)

$(LIBFT_A): FORCE
	@make -C $(LIBFT_DIR)

# $(LIBTERM_A): FORCE
# 	@make -C $(LIBTERM_DIR)

.PHONY: fsa
fsa: $(SRCS) $(LIBS) $(INCLS)
	$(CC) $(CFLAGS) $(FSA_FLAGS) $(INCL_CMD) $(LIB_INCL) $(SRCS) -o $(NAME)
	$(OPT) ./$(NAME)

.PHONY: val
val: $(SRCS) $(LIBS) $(INCLS)
	$(CC) $(DEBUG_FLAG) $(INCL_CMD) $(LIB_INCL) $(SRCS) -o $(NAME)
	valgrind $(VAL_FLAGS) $(OPT) ./$(NAME)

$(NAME): $(OBJS) libft/libft.a 
	@$(CC) $(CFLAGS) $(INCL_CMD) $^ -o $@ $(LIB_INCL)
# libterm/libterm.a

-include $(DEPENDENCIES)
$(OBJ_DIR)/%.o: %.c Makefile | $(OBJ_DIR)
	@echo Compiling $@
	@$(CC) $(CFLAGS) $(MMD) $(INCL_CMD) -o $@ -c $<

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

.PHONY: tags
tags:
	ctags -R .

#print-%  : ; @echo $* = $($*)

.PHONY: clean
clean: 
	$(MAKE) clean -C libft
	$(RM) -rf $(OBJ_DIR)
# $(MAKE) clean -C libterm

.PHONY: fclean
fclean: clean
	$(MAKE) fclean -C libft
	$(RM) $(NAME)
	$(RM) -r $(NAME).dSYM
# $(MAKE) fclean -C libterm

FORCE:

.PHONY: re
re: fclean all

.PHONY: d
d: all
	@$(OPT) ./$(NAME)

.PHONY: norm
norm:
	norminette $(SRCS) | grep -v -e "C++ comment" -e "42 header"\
		| grep -B 1 "Error"
	norminette $(INCLS) | grep -v -e "C++ comment" -e "42 header"\
		| grep -B 1 "Error"
