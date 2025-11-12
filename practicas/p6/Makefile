NAME = robot
SRCS = src/Robot.cpp src/main.cpp

OBJS = $(SRCS:.c=.o)

ROBOT = robot

CC = g++
CFLAGS = -Wall -Wextra -Werror #-g3 -fsanitize=address
RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(NAME)

clean:
	$(RM) $(OBJS)
fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re