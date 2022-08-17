# COLORS #
GREEN = @echo "\033[0;32m"
BLUE = @echo "\033[0;34m" 
PURPLE = @echo "\033[0;35m"
CYAN = @echo "\033[0;36m"
RESET = "\033[1;0m"

# RESOURCES #
SRCS = ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_memchr.c \
ft_memcmp.c ft_strlen.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c  \
ft_isprint.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c  \
ft_strlcpy.c ft_strlcat.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c  \
ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_putchar_fd.c  \
ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_striteri.c ft_count_list.c\
ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c \
ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c get_next_line.c get_next_line_utils.c


# FLAGS #
OBJS = ${SRCS:.c=.o}

NAME = libft.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra

AR = ar rcs


# Instructions #
all:${NAME}

${NAME}: ${OBJS}
	${AR} ${NAME} ${OBJS}
	$(BLUE) LIBFT Library Ensambled $(RESET)	
	
%.o:	%.c 
	$(CYAN) Compiling LIBFT Object $< $(RESET)
	$(CC) $(CFLAGS) -c $<

clean:
	$(PURPLE) Cleaning LIBFT Objects $(RESET)
	@rm -rf ${OBJS}
fclean: clean
	rm -rf ${NAME}

re: fclean all

.PHONY: all clean fclean re






