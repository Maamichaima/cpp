SRC = main.cpp HumanA.cpp HumanB.cpp Weapon.cpp
OBJ = ${SRC:.cpp=.o}

NAME = battle

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