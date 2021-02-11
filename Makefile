.PHONY: all clean fclean re bonus libft create_obj_dir

NAME = cub3D

CC = gcc

CFLAGS			= -Wall -Wextra -Werror
LIB_FLAGS		= -L $(LIBFT_DIR) -lft
INCLUDE_FLAGS 	= -I $(INCLUDES_DIR) -I $(LIBFT_DIR)

GREEN =	\033[32m
RED	  =	\033[31m
RESET =	\033[0m

GNL_DIR = get_next_line
INCLUDES_DIR = include
LIBFT_DIR 	 = libft
SRC_DIR		 = src
OBJ_DIR		 = obj

SOURCES =	main.c \
			check_arguments.c
		
OBJECTS = $(addprefix $(OBJ_DIR)/, $(SOURCES:.c=.o))
HEADERS = $(INCLUDES_DIR)/*.h

all: libft create_obj_dir $(NAME)

create_obj_dir:
	@mkdir -p $(OBJ_DIR)

libft:
	@$(MAKE) -C $(LIBFT_DIR) --no-print-directory

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(LIBFT_DIR)/$(LIBFT_NAME)
	@$(CC) $(CFLAGS) -c $< $(INCLUDE_FLAGS) -o $@

$(NAME): $(OBJECTS) $(HEADERS)
	@$(CC) $(CFLAGS) $(OBJECTS) $(LIB_FLAGS) -o $@
	@echo "$(GREEN)$(NAME)$(RESET) created."

clean:
	@$(MAKE) clean -C $(LIBFT_DIR) --no-print-directory 
	@rm -rf $(OBJ_DIR)

fclean: clean
	@$(MAKE) fclean -C $(LIBFT_DIR) --no-print-directory
	@rm -rf $(NAME)
	@echo "[x] $(RED)$(NAME)$(RESET) has been deleted."

re: fclean all