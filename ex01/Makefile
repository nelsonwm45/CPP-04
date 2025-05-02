#------Colours------#
DEF_COLOR='\033[0;39m'
RESET = '\033[0;0m'
BLACK='\033[0;30m'
RED='\033[1;91m'
GREEN='\033[1;92m'
YELLOW='\033[0;93m'
BLUE='\033[0;94m'
MAGENTA='\033[0;95m'
CYAN='\033[0;96m'
GRAY='\033[0;90m'
WHITE='\033[0;97m'
PINK  = '\033[35m'

# Program Name
NAME = DeepCopy
# SUB_NAME = WrongAnimal

# Compiler
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -g3 $(FSAN)
FSAN = -fsanitize=address
RM = rm -f

# Source and Object
SRCS =	main.cpp \
		Animal.cpp \
		Cat.cpp \
		Dog.cpp \
		test.cpp \
		Brain.cpp
		
# WRONG_SCS = Wrongmain.cpp \
# 			WrongAnimal.cpp \
# 			WrongCat.cpp \

OBJ = $(SRCS:.cpp=.o)

# WRONG_OBJ = $(WRONG_SCS:.cpp=.o)

# Rules
all: $(NAME)

$(NAME): $(OBJ)
	@ echo $(GREEN)" 🍕 Compiling "$(RED)"[$(NAME)]"$(GREEN)"..."$(RESET)
	@ $(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@ echo $(RED)" 🍟 [$(NAME)]"$(GREEN)" successfully compiled!"$(RESET)
	@ echo $(GREEN)" 🌭 Your"$(RED)" [$(NAME)] "$(GREEN)"is ready to use"$(RESET)

# $@ = target file
# $< = first dependency
# $^ = all dependencies
%.o: %.cpp
	@ $(CC) $(CFLAGS) -c $< -o $@

# wrong: $(SUB_NAME)

# $(SUB_NAME): $(WRONG_OBJ)
# 	@ echo $(GREEN)" 🍕 Compiling "$(RED)"[$(SUB_NAME)]"$(GREEN)"..."$(RESET)
# 	@ $(CC) $(CFLAGS) $(WRONG_OBJ) -o $(SUB_NAME)
# 	@ echo $(RED)" 🍟 [$(SUB_NAME)]"$(GREEN)" successfully compiled!"$(RESET)
# 	@ echo $(GREEN)" 🌭 Your"$(RED)" [$(SUB_NAME)] "$(GREEN)"is ready to use"$(RESET)

clean:
	@ echo $(CYAN)" 🥨 Cleaning Object Files..."$(RESET)
	@ $(RM) $(OBJ)
# @ $(RM) $(WRONG_OBJ)

fclean: clean
	@ echo $(MAGENTA)" 🥯 Removing "$(RED)"[$(NAME)]"$(GREEN)"..."$(RESET)
	@ $(RM) $(NAME)
# @ $(RM) $(SUB_NAME)

re : fclean all
