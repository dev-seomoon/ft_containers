
CLANG = clang++ 
FLAGS = -Wall -Wextra -Werror -std=c++98

NAME = test

SRCS = main.cpp
OBJS = $(SRCS:.cpp=.o)

%.o: %.cpp
	$(CLANG) $(FLAGS) -c $(SRCS) -I.

$(NAME): $(OBJS)
	$(CLANG) $(FLAGS) -o $(NAME) $(OBJS)

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
