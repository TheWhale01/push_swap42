CC=gcc
BIN_DIR=bin/
OBJ_DIR=obj/
SRC_DIR=src/
LIBFT_DIR=libft/
INCLUDES=includes/
CFLAGS=-Wall -Wextra -Werror -I $(INCLUDES)
CFILES=$(addprefix $(SRC_DIR), main.c checker.c stack.c stack_func/p.c stack_func/r.c stack_func/rr.c stack_func/s.c)
OBJS=$(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(CFILES))
NAME=$(BIN_DIR)push_swap

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@if [ ! -d "$(dir $@)" ]; then mkdir -p $(dir $@); fi
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@if [ ! -d "./$(BIN_DIR)" ]; then mkdir $(dir $@); fi
	$(MAKE) -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -L ./$(LIBFT_DIR)bin/ -lft

all: $(NAME)

debug: CFLAGS=-Wall -Wextra -Werror -I $(INCLUDES) -g
debug: fclean $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(LIBFT_DIR)

sanitize:CFLAGS=-Wall -Wextra -Werror -I $(INCLUDES) -fsanitize=address
sanitize: fclean $(NAME)

re: fclean all

re_debug: fclean debug

.PHONY: all debug clean fclean re_debug