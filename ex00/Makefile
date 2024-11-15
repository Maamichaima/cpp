SRC = megaphone.cpp 

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

OBJS = ${SRC:.cpp=.o}

NAME = megaphone
all : ${NAME}

${NAME} : ${OBJS}
	c++ -o ${NAME} ${OBJS} ${CXXFLAGS}

clean :
	rm -rf megaphone.o

fclean : clean
	${RM} ${NAME}

re: fclean all
