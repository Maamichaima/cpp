SRC = main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp 
OBJ = ${SRC:.cpp=.o}
CXXFLAG = -Wall -Wextra -Werror -std=c++98
CXX = c++
NAME = ex02

all : ${NAME}

${NAME} : ${OBJ}
	${CC} -o ${NAME} ${OBJ}  ${CXXFLAG}

clean :
	rm -rf ${OBJ}

fclean : clean
	${RM} ${NAME}

re: fclean all
