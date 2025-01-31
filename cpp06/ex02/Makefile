SRC = Base.cpp main.cpp
OBJ = ${SRC:.cpp=.o}
CXXFLAGS = -Wall -Wextra -Werror -std=c++98  
CXX = c++
NAME = ex02

all : ${NAME}

${NAME} : ${OBJ}
	${CXX} -o ${NAME} ${OBJ} ${CXXFLAGS}

clean :
	rm -rf ${OBJ}

fclean : clean
	${RM} ${NAME}

re: fclean all