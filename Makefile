##
## Makefile for  in /home/paul/epitech/CPE_pushswap_2017
## 
## Made by paul
## Login   <paul.young@epitech.eu>
## 
## Started on  Tue Nov 14 17:01:01 2017 paul
## Last update Wed Nov 15 15:43:46 2017 paul
##

NAME	= push_swap

CC	= gcc

RM	= rm -f

SRCS	= ./src/main.c \
	  ./src/operations.c \
	  ./src/pushswap.c \
	  ./src/special_cases.c \
	  ./src/utils.c 

OBJS	= $(SRCS:.c=.o)

CFLAGS = -I ./inc/
CFLAGS += -W -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
