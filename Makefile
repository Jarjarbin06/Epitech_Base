##
## EPITECH PROJECT, 2025
## Makefile
## File description:
## <description>
##

#########
## var ##
#########
# ./source/ #
var_SRC_PATH = source

var_SRC	=	$(var_SRC_PATH)/file.c

# ./bonus/ #
var_BONUS_PATH = bonus

var_BONUS	=	$(var_BONUS_PATH)/file.c

# ./includes/ #
var_INCLUDE_PATH	=	include

var_INCLUDE	=	$(var_INCLUDE_PATH)/include.h
var_INCLUDE	+=	$(var_INCLUDE_PATH)/test_h

# ./ #
var_MAIN	=	main.c

# ./tests/ #
var_TEST_PATH	=	test

var_TEST_R	=	$(var_TEST_PATH)/redirect.c

var_TEST_SEG	=	$(var_TEST_PATH)/test_seg.c

var_TEST	=	$(var_TEST_PATH)/test.c

# other #
var_COMPILER	=	clang
var_COMPILE_NAME	=	compiled_program
var_TEST_FLAGS	=	--coverage -lcriterion
var_TEST_NAME	=	unit_tests
var_SEG_NAME	=	seg_tests
var_ALLOW_UNBUILD	=	false
var_FILE_TREE = $(shell ls)
var_FILE_TREE_ECHO = $(shell echo $(var_FILE_TREE))

#################
## Basic rules ##
#################
all:	$(var_COMPILE_NAME)

$(var_COMPILE_NAME):
	@$(var_COMPILER) -o $(var_COMPILE_NAME) $(var_SRC) $(var_MAIN) -I$(var_INCLUDE_PATH) || true

clean:
	@rm -f *.o
	@rm -f *.a
	@rm -f *.out
	@rm -f *.pch
	@rm -f *.gc*
	@rm -f *~
	@rm -f *#

fclean:	clean
	@rm -f $(var_COMPILE_NAME)
	@rm -f $(var_TEST_NAME)
	@rm -f $(var_SEG_NAME)

re:	fclean all

###################
## testing rules ##
###################
test_$(var_TEST_NAME): clean
	@$(var_COMPILER) -o $(var_TEST_NAME) $(var_SRC) $(var_TEST_R) $(var_TEST) -I$(var_INCLUDE_PATH) $(var_TEST_FLAGS) || true

test_$(var_TEST_NAME)_run: fclean test_$(var_TEST_NAME)
	@./$(var_TEST_NAME)

test_$(var_SEG_NAME): clean
	@$(var_COMPILER) -o $(var_SEG_NAME) $(var_SRC) $(var_TEST_R) $(var_TEST_SEG) -I$(var_INCLUDE_PATH) $(var_TEST_FLAGS) || true

test_$(var_SEG_NAME)_run: fclean test_$(var_SEG_NAME)
	@./$(var_SEG_NAME)

test_valgrind: fclean $(var_COMPILE_NAME) test_$(var_TEST_NAME) test_$(var_SEG_NAME)
	@valgrind ./$(var_COMPILE_NAME) || true
	@valgrind ./$(var_TEST_NAME) || true
	@valgrind ./$(var_SEG_NAME) || true

test_gcovr: test_$(var_TEST_NAME)
	@gcovr -e $(var_TEST_PATH) || true

test_style_check:
	@epiclang $(var_MAIN) $(var_SRC) $(var_BONUS) $(var_INCLUDE) $(var_TEST_R) $(var_TEST_SEG) $(var_TEST) || true
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
ifeq ($(var_FILE_TREE_ECHO), Makefile)
build:
	@mkdir bonus include source test || true
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

ifeq ($(var_ALLOW_UNBUILD), true)
unbuild: fclean
	@rm -r bonus include source test main.c || true

else
unbuild:
	@printf '\033[91mUnbuild is disabled. To enable it, set var_ALLOW_UNBUILD to "true" before calling unbuild.\033[0m\n'
	@exit 84

endif
