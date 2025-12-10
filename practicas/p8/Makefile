CYAN    = \033[0;36m

NAME = robot

SQL = db/sql_create.cpp db/sql_insert.cpp
SRCS = src/Robot.cpp src/main.cpp src/Sistema.cpp src/Admin.cpp \
	   src/Doctor.cpp src/Patient.cpp src/SistemaUtils.cpp \
	   src/AdminUtils.cpp

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
	@echo "$(CYAN)Creando tabla..."
	@./db/create_db

data: sql_tools
	@echo "$(CYAN)Insertando datos..."
	@./db/insert_data

test_sql: sql_tools
	@echo "$(CYAN)Probando manejo de excepciones SQL..."
	@./db/test_exceptions

clean:
	$(RM) $(OBJS)
	$(RM) db/create_db db/insert_data
	
fclean: clean
	$(RM) $(NAME)
	$(RM) appointment_system.db

re: fclean all

.PHONY: all clean fclean re