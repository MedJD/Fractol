NAME = fractol

SRCS = colors_a.c colors_b.c fractals_a.c fractals_b.c main.c draw.c
SRCS += window_img.c mouse_key.c

INCLUDES = ./minilibx_macos

FLAGS= -Wall -Wextra -Werror

LIBRARIES = ./minilibx -lmlx -framework OpenGL -framework AppKit

LIBFT = ./libft/ -lft

all: $(NAME)
$(NAME):
	@make -C libft
	@gcc $(FLAGS) -o $(NAME) $(SRCS) -I $(INCLUDES) -L $(LIBRARIES) -L $(LIBFT)

clean:
	@make clean -C libft

fclean: clean
	@make fclean -C libft
	@rm -f $(NAME)

re: fclean all
