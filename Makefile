NAME = libftprintf.a
CC = gcc
CFLAGS =

SRCS = src/ft_printf.c \
	   src/ft_treat_c.c \
	   src/ft_treat_modulo.c \
	   src/ft_treat_s.c \
	   src/utils.c \
	   src/wich_all.c \
	   src/ft_treat_p.c \
	   src/ft_treat_d.c \

OBJS = $(SRCS:.c=.o)

all: $(NAME)

./%.o:./%.c ft_printf.h
	@$(CC) $(CFLAGS) -I includes -c $< -o $@

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all
