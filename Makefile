CC = gcc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address
CFLAGS += -I includes/ 
FILES = main parse helpers fillit
SDIR = srcs/
ODIR = objs/
OBJS = $(addprefix $(ODIR), $(addsuffix .o, $(FILES)))
TARGET = test
LIBFT = libft/libft.a
LDFLAGS = -L libft/ -lft

all : $(TARGET)

$(TARGET) : $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS) $(LDFLAGS) 

$(ODIR)%.o : $(SDIR)%.c
	$(CC) -c $(CFLAGS) $< -o $@

$(OBJS) : $(ODIR)

$(ODIR):
	mkdir -p $@

$(LIBFT) : 
	make -C libft

.PHONY : clean fclean re all

clean :
	rm $(OBJS)
	make -C libft clean

fclean : 
	rm -rf $(ODIR)
	rm $(TARGET)
	make -C libft fclean

re : fclean all
