CC = gcc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address,undefined
CFLAGS += -I includes/
FILES = main fillit parse helpers 
OBJS = $(addsuffix .o, $(FILES)) 
ODIR = objs/
TARGET = fillit

all : libft $(TARGET)

libft : 
	make -C libft

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) libft/libft.a -o $@ $(OBJS)

$(ODIR)%.o : %.c | $(ODIR)
	$(CC) -c $(CFLAGS) $< -o $@

$(ODIR) :
	mkdir -p $@

.PHONY : all clean fclean re

clean :
	/bin/rm $(OBJS)

fclean : 
	/bin/rm $(OBJS)
	/bin/rm $(TARGET)

re : 
	fclean all
