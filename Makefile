SRC = free.c ft_bzero.c ft_memalloc.c cord_max.c ft_putstr.c ft_sqrt.c ft_strsplit.c get_params.c main.c \
        print.c solution.c valid.c
OFILES = free.o ft_bzero.o ft_memalloc.o cord_max.o ft_putstr.o ft_sqrt.o ft_strsplit.o get_params.o main.o \
                 print.o solution.o valid.o
GCC = gcc -Wall -Wextra -Werror
HEADERS = fillit.h
NAME = fillit
all: $(NAME)
$(NAME): $(OFILES) $(LIB)
	$(GCC) -o $(NAME) $(OFILES) -I $(HEADERS)
$(OFILES): $(LIB)
	$(GCC) -c $(SRC)
%.o: %.c $(HEADERS)
	gcc -c $< $@
clean:
	rm -rf $(OFILES)
fclean: clean
	rm -rf $(NAME)
re: clean all