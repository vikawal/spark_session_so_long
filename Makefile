NAME = so_long
FLAGS = -Wall -Wextra -Werror -Wunreachable-code -Ofast
HEADER = so_long.h
LIBMLX	= ./MLX42

LIBS = $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
SRCS = \
sparkle.c
# example.c \
# test.c \
# so_long_main.c


OBJS = $(SRCS:.c=.o)
LIBFT_PATH = ./LIBFT
LIBFT = $(LIBFT_PATH)/libft.a


all: libmlx $(NAME)
libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

$(NAME): $(OBJS) $(LIBFT) $(LIBMLX)
	cc $(OBJS) -o $(NAME) $(LIBFT) $(LIBS)

$(LIBFT):
	$(MAKE) -C $(LIBFT_PATH)

%.o: %.c
	cc $(FLAGS) -I./MLX42/include/MLX42 -c $< -o $@

clean: 
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME) 

re: fclean all

# test: all
# 	./$(NAME)


.PHONY: all clean fclean re test libmlx