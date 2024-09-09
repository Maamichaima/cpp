SRC = Contact.cpp PhoneBook.cpp ex01.cpp

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

OBJS = ${SRC:.c=.o}

NAME = PhoneBook

all : ${NAME}

${NAME} : ${SRC}
	c++ -o ${NAME} ${SRC} ${CXXFLAGS}
clean :
	rm -rf 
fclean : clean
	${RM} ${NAME}
re: fclean all
