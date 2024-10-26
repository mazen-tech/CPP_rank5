# COLORS
RESET	= "\033[0m"
GREEN	= "\033[32m"

# MAIN
CXX = c++
NAME = RPN
RM = rm -f

# FLAGS
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

# SOURCE FILES AND OBJECT FILES
SRCS = scr/RPN.cpp scr/main.cpp
OBJS = $(SRCS:.cpp=.o)

# RULES
all: $(NAME)

$(NAME): $(OBJS)
	@echo $(GREEN)"...linking $(NAME)..."$(RESET)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@echo $(GREEN)"Compilation Successful: $(NAME) created!"$(RESET)

# Rule to compile .cpp files into .o files
%.o: %.cpp
	@echo $(GREEN)"...compiling $<..."$(RESET)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up object files
clean:
	@echo $(GREEN)"...cleaning object files..."$(RESET)
	$(RM) $(OBJS)

# Full clean up: object files + executable
fclean: clean
	@echo $(GREEN)"...cleaning $(NAME)..."$(RESET)
	$(RM) $(NAME)

# Rebuild the project
re: fclean all