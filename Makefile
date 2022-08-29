CFLAGS = -Wall -Wextra -Werror -I./mlx -g
LFLAGS = -framework AppKit -framework OpenGL -L./mlx -lmlx
MLX = ./mlx/libmlx.a
GNL = $(wildcard gnl/*c)
GNLOBJS = $(GNL:.c=.o)
SRCS = so_long.c	
OBJS = $(SRCS:.c=.o)
NAME = so_long

all : $(MLX) $(NAME)

$(MLX) :
	make -C ./libft
	make -C ./ft_printf
	make -C ./mlx

$(NAME) : $(OBJS) $(GNLOBJS)
	gcc -g $(OBJS) $(GNLOBJS) $(LFLAGS) ./libft/libft.a ./ft_printf/libftprintf.a -o $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS) $(NAME)

fclean:
	rm -rf $(OBJS) $(NAME)
	rm -rf ./gnl/*.o
	make clean -C ./mlx
	make fclean -C ./libft
	make fclean -C ./ft_printf

norm:
	norminette ./*.c

re : fclean all

.PHONY: clean fclean re norm