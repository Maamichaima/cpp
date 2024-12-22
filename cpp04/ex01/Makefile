
SRC = main.cpp Animal.cpp Dog.cpp Cat.cpp WrongAnimal.cpp WrongCat.cpp Brain.cpp
OBJ = ${SRC:.cpp=.o}
# CXXFLAGS = -Wall -Wextra -Werror -std=c++98x
CXX = c++
NAME = ex01

all : ${NAME}

${NAME} : ${OBJ}
	${CXX} -o ${NAME} ${OBJ} ${CXXFLAGS}

clean :
	rm -rf ${OBJ}

fclean : clean
	${RM} ${NAME}

re: fclean all
