SRC = main.cpp ClapTrap.cpp ScavTrap.cpp
OBJ = ${SRC:.cpp=.o}
CXXFLAG = -Wall -Wextra -Werror
CXX = c++
NAME = ex01

all : ${NAME}

${NAME} : ${OBJ}
	${CC} -o ${NAME} ${OBJ}  ${CXXFLAG}

clean :
	rm -rf ${OBJ}

fclean : clean
	${RM} ${NAME}

re: fclean all
