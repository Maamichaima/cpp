SRC = Account.cpp tests.cpp

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

OBJS = ${SRC:.cpp=.o}

NAME = Account

all : ${NAME}

${NAME} : ${OBJS}
	c++ -o ${NAME} ${OBJS} ${CXXFLAGS}
clean :
	rm -rf ${OBJS}
fclean : clean
	${RM} ${NAME}
re: fclean all