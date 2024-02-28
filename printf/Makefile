NAME	=	libftprintf.a

SRCS	=	ft_itoa_u.c	ft_print_type.c	ft_printf.c	ft_utils.c\
			ft_some.c

HEADER	=	ft_printf.h

OBJ	=	$(SRCS:%.c=%.o)

CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror

.PHONY	:	all clean fclean re bonus

all		:	$(NAME)

$(NAME) : $(OBJ)
	 ar rcs $(NAME) $(OBJ)

 %.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

bonus	: $(OBJ_B)
	 ar rcs $(NAME) $(OBJ_B)

clean	:
	rm -f $(OBJ) $(OBJ_B)

fclean : clean
	$(RM) $(NAME)

re	:	fclean all
	