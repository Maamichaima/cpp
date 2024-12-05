SRC = main.cpp Zombie.cpp newZombie.cpp randomChump.cpp
OBJ = ${SRC:.cpp=.o}

NAME = BraiiiiiiinnnzzzZ

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
