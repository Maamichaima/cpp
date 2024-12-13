SRC = main.cpp ClapTrap.cpp
OBJ = ${SRC:.cpp=.o}
CXXFLAG = -Wall -Wextra -Werror -std=c++98
CXX = c++
NAME = ex00

all : ${NAME}

${NAME} : ${OBJ}
	${CXX} -o ${NAME} ${OBJ}  ${CXXFLAG}

clean :
	rm -rf ${OBJ}

fclean : clean
	${RM} ${NAME}

re: fclean all
