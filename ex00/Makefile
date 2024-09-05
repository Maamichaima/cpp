SRC = megaphone.cpp 

OBJS = megaphone.o

CXXFLAGS = -Wall -Wextra -Werror #-std=c++98

OBJS = ${SRC:.c=.o}

NAME = megaphone
all : ${NAME}

${NAME} : ${OBJS}
	c++ -o ${NAME} ${OBJS}
clean :
	rm -rf megaphone.o
fclean : clean
	${RM} ${NAME}
re: fclean all