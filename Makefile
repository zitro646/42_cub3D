# COLORS #
GREEN = @echo "\033[0;32m"
BLUE = @echo "\033[0;34m" 
PURPLE = @echo "\033[0;35m"
CYAN = @echo "\033[0;36m"
RESET = "\033[1;0m"

# VARIABLES #
NAME = cub3D
LIBFT_NAME = libft.a

AR = ar rcs
CC = gcc
CFLAGS = -Wall -Werror -Wextra #-fsanitize=address -g3
CFLAGS += -I ./$(INC_PATH) -I ./$(LIBFT_PATH)
MINILIBX = #-lmlx -framework OpenGL -framework AppKit

# PATHs #
LIBFT_PATH  = srcs/libft
MAP_PATH  = srcs/map
INC_PATH    = includes
SRC_PATH    = srcs
OBJ_PATH    = objects

# SOURCES #
SRC =   main.c

SRC_MAP = mapreader.c mapcheck.c get_file_height.c

SRC_LIBFT = ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_memchr.c \
ft_memcmp.c ft_strlen.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c  \
ft_isprint.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c  \
ft_strlcpy.c ft_strlcat.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c  \
ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_putchar_fd.c  \
ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_striteri.c ft_count_list.c\
ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c \
ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c get_next_line.c get_next_line_utils.c

# RULES #
all: $(NAME)

###		TO COMPILE OBJECTS		###

#OBJ_LIBFT = $(SRCS_LIBFT:%.c=%.o)
##		ADDprefix		##
SRCS = $(addprefix $(SRC_PATH)/, $(SRC))
SRCS_MAP = $(addprefix $(MAP_PATH)/, $(SRC_MAP))
SRCS_LIBFT = $(addprefix $(LIBFT_PATH)/, $(SRC_LIBFT))

OBJS =  $(addprefix $(OBJ_PATH)/, $(SRC:%.c=%.o))
OBJS_MAPS =  $(addprefix $(OBJ_PATH)/, $(SRC_MAP:%.c=%.o))
OBJS_LIBFT =  $(addprefix $(OBJ_PATH)/, $(SRC_LIBFT:%.c=%.o))

$(OBJ_PATH):
	mkdir -p $(OBJ_PATH) 2> /dev/null

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c | $(OBJ_PATH)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_PATH)/%.o: $(MAP_PATH)/%.c | $(OBJ_PATH)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_PATH)/%.o: $(LIBFT_PATH)/%.c | $(OBJ_PATH)
	$(CC) $(CFLAGS) -c $< -o $@
            
$(NAME): $(OBJS) $(OBJS_LIBFT) $(OBJS_MAPS)
	$(GREEN) Objects compiled $(RESET)
	$(CC) $(CFLAGS) $(OBJS_MAPS) $(OBJS) $(OBJS_LIBFT) $(MINILIBX) -o $(NAME) 
	$(GREEN) Program asembled $(RESET)

##RULES
$(MAKE): make

norminette:
	norminette $(SRCS)
	norminette $(LIBFT_PATH)
	norminette $(MAP_PATH)

clean:
	$(PURPLE) CLEANING OBJECTS $(RESET)
	rm -rf $(OBJ_PATH)
#rm -rf $(OBJS)
#rm -rf $(OBJS_MAPS)
	
fclean: clean
	$(PURPLE) CLEANING DIRECTORY AND EXEC $(RESET)
	rm -rf $(NAME)
	rm -rf $(OBJ_PATH)
	
re: fclean all

PHONY.: all clean fclean re norminette