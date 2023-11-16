CC      = cc
CFLAGS  = -Wall -Wextra 
NAME    = pipex

SRC_PATH = src/
OBJ_PATH = obj/

SRC = errorhandling.c \
	forking.c \
	main.c \
	reading_arg.c

SRCS    = $(addprefix $(SRC_PATH), $(SRC))
OBJ     = $(SRC:.c=.o)
OBJS    = $(addprefix $(OBJ_PATH), $(OBJ))
INCS    = -I ./includes/ -I $(LIBFT_PATH)/includes
LIBFT_PATH      =   ./libft
LIBFT           =   $(LIBFT_PATH)/libft.a

all: $(OBJ_PATH) $(LIBFT) $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCS)

$(OBJ_PATH):
	mkdir $(OBJ_PATH)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -L$(LIBFT_PATH) -lft -g

$(LIBFT): $(LIBFT_PATH)/libft.a

$(LIBFT_PATH)/libft.a: $(wildcard $(LIBFT_PATH)/*.c) $(wildcard $(LIBFT_PATH)/*.h)
	@echo "Compiling library..."
	make -C $(LIBFT_PATH) all
	@echo "Library compilation complete."

clean:
	rm -rf $(OBJ_PATH)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
