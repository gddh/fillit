# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmatthew <tmatthew@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/19 20:05:48 by tmatthew          #+#    #+#              #
#    Updated: 2018/05/04 18:30:22 by tmatthew         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft.a
CC=clang
FLAGS= -Wall -Wextra -Werror -Wpedantic
TEST=test
TEST_OPTS= $(FLAGS) -g -o $(TEST)
SRC = \
ft_atoi.c\
ft_bzero.c\
ft_isalnum.c\
ft_isalpha.c\
ft_isascii.c\
ft_isdigit.c\
ft_isprint.c\
ft_itoa.c\
ft_lstadd.c\
ft_lstdel.c\
ft_lstdelone.c\
ft_lstiter.c\
ft_lstmap.c\
ft_lstnew.c\
ft_memalloc.c\
ft_memccpy.c\
ft_memchr.c\
ft_memcmp.c\
ft_memcpy.c\
ft_memdel.c\
ft_memmove.c\
ft_memset.c\
ft_putchar.c\
ft_putchar_fd.c\
ft_putendl.c\
ft_putendl_fd.c\
ft_putnbr.c\
ft_putnbr_fd.c\
ft_putstr.c\
ft_putstr_fd.c\
ft_strcat.c\
ft_strchr.c\
ft_strclr.c\
ft_strcmp.c\
ft_strcpy.c\
ft_strdel.c\
ft_strdup.c\
ft_strequ.c\
ft_striter.c\
ft_striteri.c\
ft_strjoin.c\
ft_strlcat.c\
ft_strlen.c\
ft_strmap.c\
ft_strmapi.c\
ft_strncat.c\
ft_strncmp.c\
ft_strncpy.c\
ft_strnequ.c\
ft_strnew.c\
ft_strnstr.c\
ft_strrchr.c\
ft_strsplit.c\
ft_strstr.c\
ft_strsub.c\
ft_strtrim.c\
ft_tolower.c\
ft_toupper.c\
ft_skip_delim.c\
ft_count_by_delim.c\
ft_next_delim.c\
ft_count_digits.c\
ft_fast_memcpy.c\
ft_fast_memcmp.c\
ft_lstat.c\
ft_lstfind.c\
ft_lstlast.c\
ft_lstmerge.c\
ft_lstpushback.c\
ft_lstpushfront.c\
ft_lstpushparams.c\
ft_lstcndremove.c\
ft_lstreverse.c\
ft_lststart.c\
ft_lstsize.c

all: $(NAME)

$(NAME):
	@echo -n 'Compiling library functions... '
	@$(CC) $(FLAGS) -c $(SRC)
	@echo  'Done'
	@echo -n 'Creating library archive... '
	@ar rc $(NAME) $(SRC:.c=.o)
	@echo  'Done'
	@echo -n 'Creating library indexes... '
	@ranlib $(NAME)
	@echo  'Done'

clean:
	@echo -n 'Cleaning library object files... '
	@rm -rf $(SRC:.c=.o) $(TEST) $(TEST).dSYM
	@echo  'Done'

fclean: clean
	@echo -n 'Cleaning library file... '
	@rm -rf $(NAME)
	@echo  'Done'

re: fclean all

build: fclean all
	@echo -n 'Compiling test... '
	@$(CC) $(TEST_OPTS) $(NAME)
	@echo  'Done'

test: re build	
	echo -n 'Running...\n'
	./$(TEST)
	@echo 'Done'

debug: re build
	@echo -n 'Running...'
	lldb $(TEST)
	@echo 'Done'

.PHONY: all clean fclean re test debug
