CC = gcc
CFLAGS = -Wall -Wextra -Werror
CFLAGS += -I includes/
FILES = queue helper_queue main board fillit parse 
OBJS = $(addsuffix .o, $(FILES)) 
ODIR = objs/
TARGET = fillit

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

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
