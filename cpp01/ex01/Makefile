SRC = main.cpp Zombie.cpp zombieHorde.cpp
OBJ = ${SRC:.cpp=.o}

NAME = Moar_brainz

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