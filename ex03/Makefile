pro = interface
com = c++
flages = -Wall -Werror -Wextra -std=c++98

src = main.cpp AMateria.cpp Cure.cpp Ice.cpp Character.cpp MateriaSource.cpp
obj = $(src:.cpp=.o)

all: $(pro)

$(pro): $(obj)
	$(com) $(flages) $(obj) -o $(pro)

%.o: %.cpp
	$(com) $(flages) -c $< -o $@

re: fclean all

clean:
	rm -rf $(obj)

fclean: clean
	rm -rf $(pro)

.SECONDARY : $(obj)