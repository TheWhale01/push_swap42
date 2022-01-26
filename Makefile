CC=gcc
BIN_DIR=bin/
OBJ_DIR=obj/
SRC_DIR=src/
CHECKER_OBJ_DIR=obj/checker/
CHECKER_SRC_DIR=src/checker/
LIBFT_DIR=libft/
INCLUDES=includes/
CFLAGS=-Wall -Wextra -Werror -I $(INCLUDES)
CFILES_PUSH_SWAP=$(addprefix $(SRC_DIR), main.c check.c stack.c utils.c stack_func/pop.c stack_func/s.c stack_func/p.c stack_func/r.c \
solver/solver.c solver/lis.c solver/cost.c)
CFILES_CHECKER=$(addprefix $(CHECKER_SRC_DIR), main.c)
OBJS=$(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(CFILES_PUSH_SWAP))
OBJS_CHECKER=$(patsubst $(CHECKER_SRC_DIR)%.c, $(CHECKER_OBJ_DIR)%.o, $(CFILES_CHECKER))
NAME_PUSH_SWAP=$(BIN_DIR)push_swap
NAME_CHECKER=$(BIN_DIR)checker

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@if [ ! -d "$(dir $@)" ]; then mkdir -p $(dir $@); fi
	$(CC) $(CFLAGS) -c $< -o $@

$(CHECKER_OBJ_DIR)%.o: $(CHECKER_SRC_DIR)%.c
	@if [ ! -d "$(dir $@)" ]; then mkdir -p $(dir $@); fi
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME_PUSH_SWAP): $(OBJS)
	@if [ ! -d "./$(BIN_DIR)" ]; then mkdir $(dir $@); fi
	$(MAKE) -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME_PUSH_SWAP) -L ./$(LIBFT_DIR)bin/ -lft

$(NAME_CHECKER): $(OBJS_CHECKER)
	@if [ ! -d "./$(BIN_DIR)" ]; then mkdir $(dir $@); fi
	$(MAKE) -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(OBJS_CHECKER) -o $(NAME_CHECKER) -L ./$(LIBFT_DIR)bin/ -lft

all: $(NAME_PUSH_SWAP)

checker: $(NAME_PUSH_SWAP) $(NAME_CHECKER)

debug: CFLAGS=-Wall -Wextra -Werror -I $(INCLUDES) -g
debug: $(NAME_PUSH_SWAP)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(BIN_DIR)
	$(MAKE) fclean -C $(LIBFT_DIR)

sanitize:CFLAGS=-Wall -Wextra -Werror -I $(INCLUDES) -fsanitize=address
sanitize: $(NAME_PUSH_SWAP)

re: fclean all

re_checker: fclean checker

re_debug: fclean debug

re_sanitize: fclean sanitize

.PHONY: all checker debug clean fclean sanitize re_checker re_debug re_sanitize