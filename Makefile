### VARIABLES ###

# Names
LIBRARY = 	DS

# Instructions
CC 		=	gcc -Wall -Wextra -Werror
AR 		= 	ar rc
RM 		= 	rm -f

# Files
SOURCES = 	$(wildcard Libft/*.c datalib/*.c)
OBJECTS =	$(SOURCES:.c=.o)
TESTING	= 	$(wildcard tests/*.c)


### RULES ###

# Main rules
all: $(OBJECTS)
	@$(AR) $(LIBRARY) $(OBJECTS)
	@echo "File '$(LIBRARY)' created."

clean:
	@$(RM) -r $(OBJECTS)
	@echo "Object files removed."

fclean: clean
	@$(RM) $(LIBRARY) *.md
	@echo "File '$(LIBRARY)' removed."

re: fclean all
	@echo "It was recompiled."

.PHONY: all clean fclean re

%.o: %.c
	@$(CC) -c $< -o $@
	@echo "* File '$<' compiled."

# Testing rules
see:
	@echo "Library	:	$(LIBRARY)"
	@echo
	@echo "Compile	:	'$(CC) (...)' + '$(AR) (...)'"
	@echo "Remove	:	'$(RM) (...)'"
	@echo
	@echo "Sources	:	$(SOURCES)"
	@echo "Objects	:	$(OBJECTS)"

norm:
	@norminette $(SOURCES)

