NAME = pipex

CC = clang

CFLAGS = -Wall -Wextra -Werror

HEADER = pipex.h

SRC = pipex.c utils.c family.c path.c split.c

OBJ = $(SRC:c=o)

SRCB = pipex_bonus.c utils_bonus.c family_bonus.c path_bonus.c split_bonus.c

OBJB = $(SRCB:c=o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

%.o: %.c
	@${CC} ${CFLAGS} -c $< -o $@

clean:
	@rm -f $(OBJ) $(OBJB)

fclean:
	@rm -f $(OBJ) $(OBJB)
	@rm -f $(NAME)

re: fclean all

bonus: $(OBJB)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJB)


.PHONY: clean fclean re bonus