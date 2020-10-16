NAME = parser
CFLAGS := -Wall -Wextra -Werror -g

LIBFT_DIR = libft/
LIBFT = $(LIBFT_DIR)libft.a
LIBFT_HEADERS_DIR = $(LIBFT_DIR)includes/
LIB_FLAG := -L./$(LIBFT_DIR) -lft

HEADER_LIST = parser.h
HEADER_DIR = includes/ 
HEADER := $(addprefix $(HEADER_DIR), $(HEADER_LIST))

INCLUDES := -I $(HEADER_DIR) -I $(LIBFT_HEADERS_DIR)

SRC_LIST = funforparse.c config.c main.c section.c
SRC_DIR = src/
SRC = $(addprefix $(SRC_DIR), $(SRC_LIST))

OBJ_DIR = objects/
OBJ_LIST = $(patsubst %.c, %.o, $(SRC_LIST))
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_LIST))

all: lib $(NAME)

lib:
	make -sC $(LIBFT_DIR)

$(NAME): $(LIBFT) $(OBJ_DIR) $(OBJ)
	gcc $(CFLAGS) $(INCLUDES) $(OBJ) $(LIB_FLAG) -o $(NAME)
	
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

objects/%.o : src/%.c $(HEADERS)
	gcc $(CFLAGS) -c $(INCLUDES) $< -o $@
	
clean:
	make -sC $(LIBFT_DIR) clean
	rm -rf $(OBJ_DIR)

fclean: clean
	make -sC $(LIBFT_DIR) fclean
	rm -f $(NAME)
	rm -f $(LIBFT)

re: fclean all

.PHONY: all clean fclean re lib