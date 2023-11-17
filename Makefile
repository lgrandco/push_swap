NAME = push_swap

SRC_PATH = srcs

SRC = main.c actions.c stacks_ops.c costs.c

SRC := $(addprefix $(SRC_PATH)/,$(SRC))

OBJ = $(SRC:.c=.o)

CC = clang

CFLAGS = -Wall -Werror -Wextra -g3 -I.

RM = rm -f

LIBFT_PATH = ./libft

LIBFT = $(LIBFT_PATH)/libft.a

all : $(NAME)

$(LIBFT) :
	make bonus -C $(LIBFT_PATH)

$(NAME) : $(LIBFT) ${OBJ} push_swap.h
	${CC} -o ${NAME} ${OBJ} ${LIBFT}

bonus : $(NAME)

clean :
	make clean -C $(LIBFT_PATH)
	$(RM) $(NAME) $(OBJ)

fclean : clean
	make fclean -C $(LIBFT_PATH)
	$(RM) $(NAME)

c : ${NAME}
	${CC} -g3 -L. -lftprintf
	valgrind ./a.out
	rm ./a.out

re : fclean all

.PHONY : all clean fclean re
