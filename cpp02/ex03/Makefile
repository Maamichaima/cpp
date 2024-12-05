SRC = main.cpp Fixed.cpp Point.cpp
OBJ = ${SRC:.cpp=.o}

NAME = ex03

CXXFLAGS = -Wall -Wextra -Werror -std=c++98
CXX = c++
all : ${NAME}

${NAME} : ${OBJ}
	${CXX} -o ${NAME}  ${OBJ} ${CXXFLAGS}

fclean : clean
	rm -rf ${NAME}

clean : 
	rm -rf ${OBJ}

re : fclean all