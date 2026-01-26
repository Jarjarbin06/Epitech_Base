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

help:
	@echo "Usage: make [rule]"
	@echo ""
	@echo "Main rules:"
	@echo "    make                         Compile the project"
	@echo "    make clean                   Remove temporary and unnecessary files"
	@echo "    make fclean                  Clean + remove binaries"
	@echo "    make re                      Recompile everything"
	@echo ""
	@echo "Testing:"
	@echo "    make test_[test_name]        Compile tests"
	@echo "    make test_[test_name]_run    Run unit tests"
	@echo "    make test_valgrind           Run valgrind"
	@echo "    make test_gcovr              Code coverage"
	@echo "    make test_style_check        Check coding style"
	@echo ""
	@echo "Utilities:"
	@echo "    make show_var                Show internal variables"
	@echo "    make build                   Initialize project (dangerous)"
	@echo "    make unbuild                 Remove project files (dangerous)"

##########
## info ##
##########
info_NAME	=	Epitech Base
info_VERSION	=	v0.1.0
info_LAST_UPDATE	=	2026-01-26 11:05:23.047
info_LIB_MAKER	=	Makefile

#########
## var ##
#########
EPITECH_BASE_PATH	=	/home/jarjarbin/Desktop/c/GIT/Epitech_Base/

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
CFLAGS	=	 -I./$(INCLUDE_DIR) -L./$(LIB_PATH) -lstr -llist -l2list -Wall -Wextra -Werror
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
	@rm -f *.o *.a *.out *.pch *.gc* *~ *#

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
	@gcovr -e $(TEST_PATH)

test_style_check:
	@epiclang $(MAIN) $(SRC) $(BONUS) $(INCLUDE) $(TEST_REDIRECT) $(TEST_SEG) $(TEST)
	@printf '\033[92mepiclang done\033[0m\n'

test_run: test_$(TESTCNAME)_run #TA

###############
## git rules ##
###############
git_get_commit:
	@python3 bonus/perso/commit_name.py

git_pull:
	@git pull origin main

git_info:
	@git status --long

################
## repo setup ##
################
ifeq ($(FILE_TREE), Makefile)
build:
	@make -sC $(EPITECH_BASE_PATH)/build_files/ re
	@cp -rf $(EPITECH_BASE_PATH)/build_files/tree/* ./
	@make -sC $(EPITECH_BASE_PATH)/build_files/ fclean
	-@git add bonus/* include/* source/* test/* main.c Makefile
	-@git commit -m "[INIT] initial build files"
	-@git push origin main

else
build:
	@printf '\033[91mBuild is disabled. To enable it, call the unbuild rule.\033[0m\n'
	@exit 84

endif

ifeq ($(ALLOW_UNBUILD), true)
unbuild: fclean
	@rm -fr bonus include lib source test main.c

else
unbuild:
	@printf '\033[91mUnbuild is disabled. To enable it, set ALLOW_UNBUILD to "true" before calling unbuild.\033[0m\n'
	@exit 84

endif

##########################
## Built-in Target Name ##
##########################
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
	unbuild