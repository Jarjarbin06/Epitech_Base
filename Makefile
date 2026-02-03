##
## EPITECH PROJECT, 2025
## Makefile
## File description:
## <description>
##

##########
## info ##
##########
info_NAME	=	Epitech Base
info_VERSION	=	v0.1.1
info_LAST_UPDATE	=	2026-02-03 11:59:56.337
info_LIB_MAKER	=	Makefile

#########
## var ##
#########
EPITECH_BASE_PATH	=	/home/jarjarbin/Desktop/c/GIT/Epitech_Base/

# ./sources/ #
SRC_PATH	=	sources

SRC	=	$(SRC_PATH)/source.c

# ./bonus/ #
BONUS_PATH	=	bonus

BONUS	=	$(BONUS_PATH)/bonus.c

# ./includes/ #
INCLUDE_DIR	=	include

INCLUDE	=	\
	$(INCLUDE_DIR)/sub_include/include_define.h \
	$(INCLUDE_DIR)/sub_include/include_include.h \
	$(INCLUDE_DIR)/sub_include/include_prototype.h \
	$(INCLUDE_DIR)/sub_include/include_typedef.h \
	$(INCLUDE_DIR)/include.h \
	$(INCLUDE_DIR)/include_test.h

# ./lib/ #
LIB_PATH	=	lib

# ./ #
MAIN	=	main.c

# ./tests/ #
TEST_PATH	=	tests

TEST_REDIRECT	=	$(TEST_PATH)/test_redirect.c

TEST_SEG	=	$(TEST_PATH)/test_seg.c

TEST	=	$(TEST_PATH)/test_file.c

# other #
OBJ	=	$(SRC:.c=.o) $(MAIN:.c=.o)
CC	=	clang
CNAME	=	compiled_program
CARG	=
CFLAGS	=	 \
	-I./$(INCLUDE_DIR) \
	-I./$(LIB_PATH)/2list \
	-I./$(LIB_PATH)/llist \
	-I./$(LIB_PATH)/str \
	-L./$(LIB_PATH) \
	-lstr \
	-lllist \
	-ltwodlist \
	-Wall \
	-Wextra
TESTCNAME	=	unit_tests
TESTSEGCNAME	=	seg_tests
TESTCFLAGS	=	\
	--coverage \
	-lcriterion
ALLOW_UNBUILD	=	false

#################
## Basic rules ##
#################
all:	$(CNAME)

$(CNAME): $(OBJ)
	$(CC) -o $(CNAME) $(OBJ) $(CFLAGS)

clean:
	@rm -f *.o */*.o */*/*.o
	@rm -f *.out */*.out */*/*.out
	@rm -f *.pch */*.pch */*/*.pch
	@rm -f *.gc* */*.gc* */*/*.gc*
	@rm -f *~* */*~* */*/*~*
	@rm -f *# */*# */*/*#

fclean:	clean
	@rm -f $(CNAME)
	@rm -f $(TESTCNAME)
	@rm -f $(TESTSEGCNAME)

re:	fclean all

run: re
	./$(CNAME) $(CARG)

###################
## testing rules ##
###################
test_$(TESTCNAME): clean
	@$(CC) -o $(TESTCNAME) $(SRC) $(TEST_REDIRECT) $(TEST) $(CFLAGS) $(TESTCFLAGS)

test_$(TESTCNAME)_run: fclean test_$(TESTCNAME)
	@./$(TESTCNAME)

test_$(TESTSEGCNAME): clean
	@$(CC) -o $(TESTSEGCNAME) $(SRC) $(TEST_REDIRECT) $(TEST_SEG) $(CFLAGS) $(TESTCFLAGS)

test_$(TESTSEGCNAME)_run: fclean test_$(TESTSEGCNAME)
	@./$(TESTSEGCNAME)

test_valgrind: fclean $(CNAME) test_$(TESTCNAME) test_$(TESTSEGCNAME)
	@valgrind ./$(CNAME) $(CARG)
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
ifeq ($(wildcard *), Makefile)
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
	@rm -fr bonus includes lib sources tests main.c

else
unbuild:
	@printf '\033[91mUnbuild is disabled. To enable it, set ALLOW_UNBUILD to "true" before calling unbuild.\033[0m\n'
	@exit 84

endif

###########
## other ##
###########
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


##########################
## built-in target name ##
##########################
.PHONY: \
	all \
	clean \
	fclean \
	re \
	test_$(TESTCNAME)_run \
	test_$(TESTSEGCNAME)_run \
	test_valgrind \
	test_gcovr \
	test_style_check \
	git_get_commit \
	git_pull \
	git_info \
	build \
	unbuild \
	help