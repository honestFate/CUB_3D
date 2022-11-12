NAME = cub3D
CC = gcc
INC = /usr/include
INCLIB = $(INC)/minilibx_linux/lib
INCLUDES = includes/cub.h
CFLAGS = -Wall -Wextra -Werror -I$(INC) -g -Iincludes -Ilibft

MAC_MINILIBX = $(MINILIBX_DIRECTORY)libmlx.a
MAC_MINILIBX_DIRECTORY = minilibx_macos
MAC_MINILIBX_HEADERS = $(MINILIBX_DIRECTORY)

SRCS = srcs/gameloop.c \
		srcs/initilization.c \
		srcs/main.c \
		srcs/window.c \
		srcs/movement.c \
		srcs/camera.c \
		srcs/raycasting.c \
		srcs/textures.c \
		srcs/convert_img.c \
		srcs/parse_config.c \
		srcs/parse_config_line.c \
		srcs/parse_config_map.c \
		srcs/parse_rgb.c \
		srcs/read_config.c \
		srcs/print_utils.c \
		srcs/clear.c \
		srcs/color.c \
		srcs/print_default.c \
		srcs/print_error.c \
		srcs/utils.c \
		srcs/validate.c \
		srcs/clear_cub.c \
		gnl/get_next_line.c \
		gnl/get_next_line_utils.c

OBJS = $(SRCS:%.c=%.o)

UNAME := $(shell uname)
ifeq ($(UNAME), Darwin)
	# MacOS
	LFLAGS = -lmlx -lm -L$(MAC_MINILIBX_DIRECTORY) -framework OpenGL -framework AppKit
else
	# Linux
	LFLAGS = -Lminilibx_linux -lmlx -L$(INCLIB) -lXext -lX11 -lm -lbsd
	CFLAGS += -Iminilibx_linux
endif


%.o: %.c $(INCLUDES)
	@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)
	@echo "Building: \033[0;34m$<\033[0m"

$(NAME): $(OBJS)
	@echo "Building: \033[0;34m42libft\033[0m"
	@make -C libft -s

ifneq ($(UNAME), Darwin)
	@echo "Building: \033[0;34mminilibx\033[0m"
	@make -C minilibx_linux -s
endif
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LFLAGS) libft/libft.a
	@echo "Binary \033[0;32m$(NAME)\033[0m successfully linked!"

all: $(NAME)

clean:
	@make -C minilibx_macos clean -s
ifneq ($(UNAME), Darwin)
	@make -C minilibx_linux clean -s
endif
	@make -C libft clean -s
	@$(RM) $(OBJS)
	@echo "Cleanup: \033[0;34mlinked files\033[0m"

fclean: clean
	@make -C minilibx_macos clean -s
	@$(RM) minilibx_linux/libmlx.a
	@$(RM) minilibx_linux/libmlx_Linux.a
	@make -C libft fclean -s
	@$(RM) $(NAME)
	@echo "Cleanup: \033[0;34mobject files\033[0m"

re: clean all

norminette:
	norminette $(SRCS) $(INCLUDES)
	norminette libft
	@echo "\033[0;35mAll files in accordance with norminette!\033[0m"

bonus: $(NAME)

# NAME = cub3D
# CC = gcc
# INC = /usr/include
# INCLIB = $(INC)/minilibx_linux/lib
# INCLUDES = includes/cub.h
# CFLAGS = -Wall -Wextra -Werror -I$(INC) -g -Iincludes -Ilibft

# MAC_MINILIBX = $(MINILIBX_DIRECTORY)libmlx.a
# MAC_MINILIBX_DIRECTORY = minilibx_macos
# MAC_MINILIBX_HEADERS = $(MINILIBX_DIRECTORY)

# SRCS = srcs/gameloop.c \
# 		srcs/initilization.c \
# 		srcs/main.c \
# 		srcs/window.c \
# 		srcs/movement.c \
# 		srcs/camera.c \
# 		srcs/raycasting.c \
# 		srcs/textures.c \
# 		srcs/convert_img.c \
# 		srcs/parse_config.c \
# 		srcs/parse_config_line.c \
# 		srcs/parse_config_map.c \
# 		srcs/parse_rgb.c \
# 		srcs/read_config.c \
# 		srcs/print_utils.c \
# 		srcs/clear.c \
# 		srcs/color.c \
# 		srcs/print_default.c \
# 		srcs/print_error.c \
# 		srcs/utils.c \
# 		srcs/validate.c \
# 		srcs/clear_cub.c \
# 		gnl/get_next_line.c \
# 		gnl/get_next_line_utils.c

# OBJS = $(SRCS:%.c=%.o)

# UNAME := $(shell uname)
# ifeq ($(UNAME), Darwin)
#  	#MacOS
#  	LFLAGS = -lm -Lminilibx_macos -framework OpenGL -framework AppKit
# else
#  	# Linux
# 	LFLAGS = -Lminilibx_linux -lmlx -L$(INCLIB) -lXext -lX11 -lm -lbsd
# 	CFLAGS += -Iminilibx_linux
# endif

# %.o: %.c $(INCLUDES)
# 	@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)
# 	@echo "Building: \033[0;34m$<\033[0m"

# $(NAME): $(OBJS)
# 	@echo "Building: \033[0;34m42libft\033[0m"
# 	@make -C libft -s
# 	@make -C minilibx_macos -s
# ifneq ($(UNAME), Darwin)
# 	@echo "Building: \033[0;34mminilibx\033[0m"
# 	@make -C minilibx_linux -s
# endif
# 	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LFLAGS) libft/libft.a minilibx_macos/libmlx.a
# 	@echo "Binary \033[0;32m$(NAME)\033[0m successfully linked!"

# all: $(NAME)

# clean:
# 	@make -C minilibx_macos clean -s
# ifneq ($(UNAME), Darwin)
# 	@make -C minilibx_linux clean -s
# endif
# 	@make -C libft clean -s
# 	@$(RM) $(OBJS)
# 	@echo "Cleanup: \033[0;34mlinked files\033[0m"

# fclean: clean
# 	@make -C minilibx_macos clean -s
# 	@$(RM) minilibx_linux/libmlx.a
# 	@$(RM) minilibx_linux/libmlx_Linux.a
# 	@make -C libft fclean -s
# 	@$(RM) $(NAME)
# 	@echo "Cleanup: \033[0;34mobject files\033[0m"

# re: clean all

# norminette:
# 	norminette $(SRCS) $(INCLUDES)
# 	norminette libft
# 	@echo "\033[0;35mAll files in accordance with norminette!\033[0m"

# bonus: $(NAME)
