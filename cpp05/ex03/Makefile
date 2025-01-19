SRC = Bureaucrat.cpp main.cpp AForm.cpp ShrubberyCreationForm.cpp PresidentialPardonForm.cpp RobotomyRequestForm.cpp Intern.cpp
OBJ = ${SRC:.cpp=.o}
CXXFLAGS = -Wall -Wextra -Werror -std=c++98  
CXX = c++
NAME = ex03

all : ${NAME}

${NAME} : ${OBJ}
	${CXX} -o ${NAME} ${OBJ} ${CXXFLAGS}

clean :
	rm -rf ${OBJ}

fclean : clean
	${RM} ${NAME}

re: fclean all