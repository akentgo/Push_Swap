NAME        := push_swap
FLAGS       := -Wall -Wextra -Werror 
SRCS        :=      srcs/parser.c \
                          srcs/main.c \
                          srcs/simple.c \
                          srcs/radix.c \
                          srcs/indexer.c \
                          srcs/rotate.c \
                          srcs/utils.c \
                          srcs/list.c \
						  srcs/r_rotate.c \
						  srcs/push.c \
						  srcs/swap.c \

                          
OBJS := $(addprefix obj/,$(notdir $(SRCS:.c=.o)))

all:		$(NAME)

$(NAME):	$(OBJS)
			make -C libft/ all
			gcc $(FLAGS) -o $(NAME) $(OBJS) libft/libft.a

obj/%.o:	srcs/%.c  | obj
			gcc $(FLAGS) -c $< -o $@

obj:
			@ mkdir -p obj

clean:
			@ rm -rf obj
			@ make -C libft/ clean
			@ echo "Deleting $(NAME) objs ✔️"

fclean:		clean
			@ rm $(NAME)
			@ make -C libft/ fclean
			@ echo "Deleting $(NAME) binary ✔️"

re:			fclean all

.PHONY:		all clean fclean re


