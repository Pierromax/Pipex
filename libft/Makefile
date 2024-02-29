CC	= cc
CFLAGS	= -Wall -Wextra -Werror
SRCS	= ft_atoi.c  ft_isalpha.c ft_itoa.c ft_memset.c  ft_memchr.c ft_putstr_fd.c  ft_strlcat.c  ft_strnstr.c  ft_tolower.c \
	ft_bzero.c    ft_isascii.c  ft_memcmp.c   ft_putchar_fd.c  ft_strchr.c ft_strlcpy.c  ft_strrchr.c  ft_toupper.c \
	ft_calloc.c   ft_isdigit.c  ft_memcpy.c   ft_putendl_fd.c  ft_strdup.c ft_strlen.c ft_strjoin.c ft_split.c \
	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c \
	ft_isalnum.c  ft_isprint.c  ft_putnbr_fd.c ft_strncmp.c  ft_substr.c ft_memmove.c ft_strtrim.c ft_strmapi.c ft_striteri.c \
	get_next_line.c get_next_line_utils.c ft_printf.c ft_printf_utils.c ft_printf_utils2.c ft_atof.c \
	ft_tablen.c clean_2Dtab.c
OBJS	= $(SRCS:.c=.o)
RM  	= rm -rf
NAME	= libft.a

# CURSOR MOVEMENTS
MOV_U			= 	\033[1A
MOV_D			= 	\033[1B
MOV_F			= 	\033[1C
MOV_B			= 	\033[1D

ERASE_ALL		= 	\033[0J

# COLORS 
YELLOW 			= 	\033[0;33m
GREEN 			= 	\033[0;32m
BLUE 			= 	\033[0;34m
RED				= 	\033[0;31m
PURPLE 			= 	\033[0;35m
CYAN 			= 	\033[0;36m
BLACK 			= 	\033[0;30
WHITE 			= 	\033[0;37m

.o : .c
	@$(CC) $(CFLAGS) -c $@ -o $<
	@echo "$(RED)compiling..."
	@echo "$(PURPLE)libft ready to use"

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)

all 	: $(NAME)

clean :
	@$(RM) $(OBJS)

fclean : clean
	@$(RM) $(NAME)

compil :
	@$(CC) $(CFLAGS) -g -o lezgo $(SRCS)
	@./lezgo

re : fclean all
