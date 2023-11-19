NAME = push_swap

NAME_BONUS = checker

SRC_PATH = srcs

SRC = main.c actions.c stacks_ops.c costs.c algo.c utils.c errors.c

SRC_BONUS = checker.c actions.c stacks_ops.c costs.c algo.c utils.c errors.c

SRC := $(addprefix $(SRC_PATH)/,$(SRC))

SRC_BONUS := $(addprefix $(SRC_PATH)/,$(SRC_BONUS))

OBJ = $(SRC:.c=.o)

OBJ_BONUS = $(SRC_BONUS:.c=.o)

CC = clang

CFLAGS = -Wall -Werror -Wextra -g3 -I.

RM = rm -f

LIBFT_PATH = ./libft

LIBFT = $(LIBFT_PATH)/libft.a

all : $(NAME)

$(LIBFT) : $(LIBFT_PATH)/Makefile
	make bonus -C $(LIBFT_PATH)

$(NAME) : $(LIBFT) ${OBJ} push_swap.h Makefile
	${CC} -o ${NAME} ${OBJ} ${LIBFT}

$(NAME_BONUS) : $(LIBFT) $(OBJ_BONUS) push_swap.h Makefile
	${CC} -o ${NAME_BONUS} ${OBJ_BONUS} ${LIBFT}

bonus : $(NAME_BONUS)

clean :
	make clean -C $(LIBFT_PATH)
	$(RM) $(NAME) $(OBJ) $(BONUS_OBJ)

fclean : clean
	make fclean -C $(LIBFT_PATH)
	$(RM) $(NAME) $(NAME_BONUS)

c : ${NAME}
	${CC} -g3 -L. -lftprintf
	valgrind ./a.out
	rm ./a.out

re : fclean all

.PHONY : all clean fclean re
