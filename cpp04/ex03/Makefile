SRC = main.cpp AMateria.cpp Ice.cpp Cure.cpp Character.cpp ICharacter.cpp IMateriaSource.cpp MateriaSource.cpp
OBJ = ${SRC:.cpp=.o}
# CXXFLAGS = -std=c++98 -fsanitize=address -g3
CXX = c++ 
NAME = ex03

all : ${NAME}

${NAME} : ${OBJ}
	${CXX} -o ${NAME} ${OBJ}  ${CXXFLAGS}

clean :
	rm -rf ${OBJ}

fclean : clean
	${RM} ${NAME}

re: fclean all
