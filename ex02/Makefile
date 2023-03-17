GREEN = \033[92m
EOC = \033[0m

NAME		=		PmergeMe

CC 			=		c++

CFLAGS 		=		-std=c++98 -Wall -Wextra -Werror

SRCS		=		main.cpp PmergeMe.cpp

OBJ			=		$(SRCS:.cpp=.o)

%.o:				%.cpp
					$(CC) $(CFLAGS) -c $(SRCS)
					@echo "$(GREEN)compiling srcs..$(EOC)"

all:				$(NAME)

$(NAME):        $(OBJ)
				$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
				@echo "$(GREEN)objects to binary..$(EOC)"

clean:
				rm -rf $(OBJ)

fclean:			clean
				rm -rf $(NAME)

re:				fclean all

.PHONY:			clean fclean all re