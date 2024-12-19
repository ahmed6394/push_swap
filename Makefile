CC = cc
# CFLAGS = -g -fsanitize=address
CFLAGS = -g -fsanitize=address

# SRC = src/main.c
SRC = src/push_swap.c src/parse.c src/error.c src/utiles.c
OBJ = $(SRC:.c=.o)

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

PRINTF_DIR = ft_printf
PRINTF = $(PRINTF_DIR)/libftprintf.a

GNL_DIR = gnl
GNL = $(GNL_DIR)/gnl.a

NAME = push_swap

# Default target
all: $(NAME)

$(LIBFT): $(LIBFT_DIR)
	make -C $(LIBFT_DIR)

$(PRINTF): $(PRINTF_DIR)
	make -C $(PRINTF_DIR)

$(GNL): $(GNL_DIR)
	make -C $(GNL_DIR)

$(NAME): $(OBJ) $(LIBFT) $(PRINTF) $(GNL)
	$(CC) $(CFLAGS) -o $@ $(OBJ) $(LIBFT) $(PRINTF) $(GNL)

clean:
	@rm -f $(OBJ)
	@make clean -C $(LIBFT_DIR)
	@make clean -C $(PRINTF_DIR)
	@make clean -C $(GNL_DIR)

fclean: clean
	@rm -f $(NAME)
	@rm -f $(LIBFT)
	@rm -f $(PRINTF)
	@rm -f $(GNL)
	@echo "Removing $(NAME)"

re: fclean all
