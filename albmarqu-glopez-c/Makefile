### VARIABLES ###

# Names
LIBRARY = 	DS
TESTERS	=	dll que stk set
RESULTS	=	results
INCLUDE =	../Libft/libft.h

# Instructions
CC 		=	gcc -Wall -Wextra -Werror
AR 		= 	ar rc
RM 		= 	rm -f

# Files
SOURCES = 	$(wildcard ../Libft/*.c datalib/*.c)
OBJECTS =	$(SOURCES:.c=.o)


### RULES ###

# Main rules
all: $(OBJECTS)
	@$(AR) $(LIBRARY) $(OBJECTS)
	@echo "File '$(LIBRARY)' created."

clean:
	@$(RM) -r $(OBJECTS)
	@echo "Object files removed."

fclean: clean
	@$(RM) $(LIBRARY) $(filter-out README.md, $(wildcard *.md)) *.out
	@echo "File '$(LIBRARY)' removed."

re: fclean all
	@echo "It was recompiled."

.PHONY: all clean fclean re

%.o: %.c $(INCLUDE)
	@$(CC) -c $< -o $@
	@echo "- File '$<' compiled."

# Testing rules
bfclean: fclean
	@$(RM) -r $(RESULTS)
	@echo "Folder '$(RESULTS)' removed"

see:
	@echo "Library	:	$(LIBRARY)"
	@echo "Testers	:	$(TESTERS)"
	@echo
	@echo "Compile	:	'$(CC) (...)' + '$(AR) (...)'"
	@echo "Remove	:	'$(RM) (...)'"
	@echo
	@echo "Sources	:	$(SOURCES)"
	@echo "Objects	:	$(OBJECTS)"

tests: all
	@mkdir -p $(RESULTS)
	@for test in $(TESTERS); do \
		$(CC) tests/$$test.c $(LIBRARY) -o $$test.out; \
		./$$test.out > $(RESULTS)/$$test.md; \
	done
	@echo "Tests ejecuted."
	@$(RM) *.out
