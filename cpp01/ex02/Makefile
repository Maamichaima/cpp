SRC = main.cpp 
OBJ = ${SRC:.cpp=.o}

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = out

CXX = c++
all : ${NAME}

${NAME} : ${OBJ}
	${CXX} -o ${NAME}  ${OBJ} ${CXXFLAGS}

fclean : clean
	rm -rf ${NAME}

clean : 
	rm -rf ${OBJ}

re : fclean all
