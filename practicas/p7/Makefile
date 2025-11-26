NAME = robot

SQL = db/sql_create.cpp db/sql_insert.cpp
SRCS = src/Robot.cpp src/main.cpp src/Sistema.cpp src/Admin.cpp \
	   src/Doctor.cpp src/Patient.cpp

OBJS = $(SRCS:.cpp=.o)
SQL_OBJ = $(SQL:.cpp=.o)

ROBOT = robot

CC = g++
CFLAGS = -Wall -Wextra -Werror
LIBS = -lsqlite3
RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBS)

sql_tools: $(SQL)
	$(CC) $(CFLAGS) db/sql_create.cpp -o db/create_db $(LIBS)
	$(CC) $(CFLAGS) db/sql_insert.cpp -o db/insert_data $(LIBS)

database: sql_tools
	@cd db && ./create_db

data: sql_tools
	@cd $(SQL_DIR) && ./insert_data

clean:
	$(RM) $(OBJS)
	
fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re