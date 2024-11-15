SRC = Contact.cpp PhoneBook.cpp main.cpp

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

OBJS = ${SRC:.cpp=.o}

NAME = PhoneBook

all : ${NAME}

${NAME} : ${OBJS}
	c++ -o ${NAME} ${OBJS} ${CXXFLAGS}
clean :
	rm -rf ${OBJS}
fclean : clean
	${RM} ${NAME}
re: fclean all
