SRC = megaphone.cpp 

OBJS = megaphone.o

CXXFLAGS = -Wall -Wextra -Werror #-std=c++98

OBJS = ${SRC:.c=.o}

NAME = megaphone

all : ${NAME}

${NAME} : ${OBJS}
	g++ -o ${NAME} ${OBJS}
clean :
# ${RM} ${OBJS}
fclean : clean
	${RM} ${NAME}
re: fclean all