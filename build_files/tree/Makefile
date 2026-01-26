##
## EPITECH PROJECT, 2025
## Makefile
## File description:
## <description>
##

###############
## important ##
###############
all:	$(CNAME)


#########
## var ##
#########
# ./source/ #
SRC_PATH = source

SRC	=	$(SRC_PATH)/source_file.c

# ./bonus/ #
BONUS_PATH = bonus

BONUS	=	$(BONUS_PATH)/bonus_file.c

# ./includes/ #
INCLUDE_DIR	=	include

INCLUDE	=	$(INCLUDE_DIR)/include_file.h
INCLUDE	+=	$(INCLUDE_DIR)/include_test.h

# ./lib/ #
LIB_PATH	=	lib

# ./ #
MAIN	=	main.c

# ./tests/ #
TEST_PATH	=	test

TEST_REDIRECT	=	$(TEST_PATH)/test_redirect.c

TEST_SEG	=	$(TEST_PATH)/test_seg.c

TEST	=	$(TEST_PATH)/test_file.c

# other #
CC	=	clang
CNAME	=	compiled_program
CFLAGS	=	 -I./$(INCLUDE_DIR) -L./$(LIB_PATH) -lstr -llist -l2list -Wall -Werror
TESTCNAME	=	unit_tests
TESTSEGCNAME	=	seg_tests
TESTCFLAGS	=	--coverage -lcriterion
ALLOW_UNBUILD	=	false
FILE_TREE = $(wildcard *)

#################
## Basic rules ##
#################
$(CNAME):
	@$(CC) -o $(CNAME) $(SRC) $(MAIN) -I$(INCLUDE_DIR)

clean:
	@rm -f *.o
	@rm -f *.a
	@rm -f *.out
	@rm -f *.pch
	@rm -f *.gc*
	@rm -f *~
	@rm -f *#

fclean:	clean
	@rm -f $(CNAME)
	@rm -f $(TESTCNAME)
	@rm -f $(TESTSEGCNAME)

re:	fclean all

###################
## testing rules ##
###################
test_$(TESTCNAME): clean
	@$(CC) -o $(TESTCNAME) $(SRC) $(TEST_REDIRECT) $(TEST) -I$(INCLUDE_DIR) $(TESTCFLAGS)

test_$(TESTCNAME)_run: fclean test_$(TESTCNAME)
	@./$(TESTCNAME)

test_$(TESTSEGCNAME): clean
	@$(CC) -o $(TESTSEGCNAME) $(SRC) $(TEST_REDIRECT) $(TEST_SEG) -I$(INCLUDE_DIR) $(TESTCFLAGS)

test_$(TESTSEGCNAME)_run: fclean test_$(TESTSEGCNAME)
	@./$(TESTSEGCNAME)

test_valgrind: fclean $(CNAME) test_$(TESTCNAME) test_$(TESTSEGCNAME)
	@valgrind ./$(CNAME)
	@valgrind ./$(TESTCNAME)
	@valgrind ./$(TESTSEGCNAME)

test_gcovr: test_$(TESTCNAME)
	@gcovr -e $(TEST_PATH) || true

test_style_check:
	@epiclang $(MAIN) $(SRC) $(BONUS) $(INCLUDE) $(TEST_REDIRECT) $(TEST_SEG) $(TEST) || true
	@printf '\033[92mepiclang done\033[0m\n'

###############
## git rules ##
###############
git_get_commit:
	@python3 bonus/perso/commit_name.py || true

git_pull:
	@git pull origin main || true

git_info:
	@git status --long || true

################
## repo setup ##
################
ifeq ($(FILE_TREE), Makefile)
build:
	@mkdir bonus include source test lib || true
	@echo -e '/*\n** EPITECH PROJECT, 2025\n** <file>\n** File description:\n** <description>\n*/\n\n#include "../include/include_file.h"\n\nint bonus_function(void)\n{\n    return true;\n}' > bonus/bonus_file.c || true
	@echo -e '/*\n** EPITECH PROJECT, 2025\n** include.h\n** File description:\n** <description>\n*/\n\n#ifndef INCLUDE_H\n    #define INCLUDE_H\n    #define EXIT_SUCCESS 0\n    #define EXIT_ERROR 84\n    #include <stdbool.h>\n\nint function(void);\n\n#endif' > include/include_file.h || true
	@echo -e '/*\n** EPITECH PROJECT, 2025\n** test.h\n** File description:\n** <description>\n*/\n\n#ifndef TEST_H\n    #define TEST_H\n\nvoid redirect_all_std(void);\n\n#endif\n' > include/include_test.h || true
	@echo -e '/*\n** EPITECH PROJECT, 2025\n** <file>\n** File description:\n** <description>\n*/\n\n#include "../include/include_file.h"\n\nint function(void)\n{\n    return true;\n}' > source/source_file.c || true
	@echo -e '/*\n** EPITECH PROJECT, 2025\n** test_file.c\n** File description:\n** None\n*/\n\n#include <criterion/criterion.h>\n#include "../include/include_test.h"\n\nTest(main, test, .init=redirect_all_std)\n{\n    cr_assert(1);\n}' > test/test_file.c || true
	@echo -e '/*\n** EPITECH PROJECT, 2025\n** test_seg.c\n** File description:\n** None\n*/\n\n#include <criterion/criterion.h>\n#include "../include/include_test.h"\n\nTest(main, test, .init=redirect_all_std)\n{\n    cr_assert(1);\n}' > test/test_seg.c || true
	@echo -e '/*\n** EPITECH PROJECT, 2025\n** test_redirect.c\n** File description:\n** None\n*/\n\n#include <criterion/redirect.h>\n\nvoid redirect_all_std(void)\n{\n    cr_redirect_stdout();\n    cr_redirect_stderr();\n}' > test/test_redirect.c || true
	@echo -e '/*\n** EPITECH PROJECT, 2025\n** main.c\n** File description:\n** <description>\n*/\n\n#include "include/include_file.h"\n\nint main(int argc, char **argv)\n{\n    bool err = false;\n\n    err = ((function()) ? (true) : (err));\n    return (!(err) ? (EXIT_SUCCESS) : (EXIT_ERROR));\n}' > main.c || true
	@git add bonus/* include/* source/* test/* main.c Makefile
	@git commit -m "[INIT] initial build files"
	@git push origin main

else
build:
	@printf '\033[91mBuild is disabled. To enable it, call the unbuild rule.\033[0m\n'
	@exit 84

endif

ifeq ($(ALLOW_UNBUILD), true)
unbuild: fclean
	@rm -fr bonus include source test main.c

else
unbuild:
	@printf '\033[91mUnbuild is disabled. To enable it, set ALLOW_UNBUILD to "true" before calling unbuild.\033[0m\n'
	@exit 84

endif

##########################
## Built-in Target Name ##
##########################
error:
	@printf "\033[91mUnknown rule, see \"make help\" to see available rules\033[0m\n"

##########################
## Built-in Target Name ##
##########################
.DEFAULT: error

.PHONY: \
	all \
	help \
	$(CNAME) \
	clean \
	fclean \
	re \
	test_$(TESTCNAME) \
	test_$(TESTCNAME)_run \
	test_$(TESTSEGCNAME) \
	test_$(TESTSEGCNAME)_run \
	test_valgrind \
	test_gcovr \
	test_style_check \
	git_get_commit \
	git_pull \
	git_info \
	build \
	unbuild \
	error