NAME	= Bureaucrat

CC		= g++
CFLAGS	= -Werror -Wextra -Wall -g -std=c++98

SRC		= 	Form.cpp \
			Bureaucrat.cpp \
			main.cpp

OBJ		= $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all re clean fclean
