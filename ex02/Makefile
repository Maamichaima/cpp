SRC = Account.cpp tests.cpp 

CXXFLAGS = -std=c++98 #-Wall -Wextra -Werror 

OBJS = ${SRC:.c=.o}

NAME = Account

all : ${NAME}

${NAME} : ${SRC}
	c++ -o ${NAME} ${SRC} ${CXXFLAGS}
clean :
	rm -rf 
fclean : clean
	${RM} ${NAME}
re: fclean all
