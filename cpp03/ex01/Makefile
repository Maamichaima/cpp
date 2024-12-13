SRC = main.cpp ClapTrap.cpp ScavTrap.cpp
OBJ = ${SRC:.cpp=.o}
CXXFLAGS = -Wall -Wextra -Werror
CXX = c++
NAME = ex01

all : ${NAME}

${NAME} : ${OBJ}
	${CXX} -o ${NAME} ${OBJ}  ${CXXFLAGS}

clean :
	rm -rf ${OBJ}

fclean : clean
	${RM} ${NAME}

re: fclean all
