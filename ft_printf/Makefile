CC = cc 
CFLAGS = -Wall -Werror -Wextra
SRC = ft_printf.c ft_putst.c ft_putnb.c
OBJ = $(SRC:.c=.o)
NAME = libftprintf.a

all: $(NAME)

$(NAME) : $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)

fclean: clean 
	@rm -f $(NAME)

re: fclean all