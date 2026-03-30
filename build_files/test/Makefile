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
info_VERSION	=	v0.2.0
info_LAST_UPDATE	=	2026/03/30 12:26
info_LIB_MAKER	=	Makefile

#########
## var ##
#########
EPITECH_BASE_PATH	=	/home/jarjarbin/Desktop/c/Epitech_Base

# Paths #
SRC_PATH        = sources
LIB_SRC_PATH    = lib
INCLUDE_PATH    = includes
LIB_PATH        = lib

# Sources #
SRC     = $(shell find $(SRC_PATH) -type f -name "*.c")
LIB_SRC = $(shell find $(LIB_SRC_PATH) -type f -path "*/sources/*.c")

# Objects #
OBJ     = $(SRC:.c=.o) $(LIB_SRC:.c=.o) $(MAIN:.c=.o)

# Includes #
INCLUDE_DIRS = $(shell find $(INCLUDE_PATH) -type d)
LIB_INCLUDE_DIRS = $(shell find $(LIB_PATH) -type d -path "*/includes")

# Bonus #
BONUS_PATH	=	bonus
BONUS	=	$(BONUS_PATH)/bonus_file.c

# Lib list #
LIBS_LIST	=	\
	llist \
	newcsfml \
	print \
	str \
	twodlist \
	utils

# Main #
MAIN	=	main.c

# Tests #
TEST_PATH	=	tests
TEST_REDIRECT	=	$(TEST_PATH)/test_redirect.c
TEST_SEG	=	$(TEST_PATH)/test_seg.c
TEST	=	$(TEST_PATH)/test_file.c

# Compilation #
CC	=	clang
CNAME	=	compiled_program
CARG	=

CFLAGS	=	\
	-Wall \
	-Wextra

CFLAGS_PLUS	= \
	-L./$(LIB_PATH) \
	$(foreach lib,$(LIBS_LIST), \
	  $(if $(wildcard lib/$(lib)), \
		$(eval CFLAGS_PLUS += -l$(lib)) \
	  ) \
	) \
	$(addprefix -I, $(INCLUDE_DIRS)) \
	$(addprefix -I, $(LIB_INCLUDE_DIRS))

TESTCNAME	=	unit_tests
TESTSEGCNAME	=	seg_tests
TESTCFLAGS	=	\
	--coverage \
	-lcriterion

ALLOW_UNBUILD	=	false

#################
## Basic rules ##
#################
all: $(CNAME)

$(CNAME): $(OBJ)
	-@make --no-print-directory -C lib/newcsfml re CC=$(CC) CFLAGS="$(CFLAGS)"
	-@make --no-print-directory -C lib/str re CC=$(CC) CFLAGS="$(CFLAGS)"
	-@make --no-print-directory -C lib/llist re CC=$(CC) CFLAGS="$(CFLAGS)"
	-@make --no-print-directory -C lib/twodlist re CC=$(CC) CFLAGS="$(CFLAGS)"
	-@make --no-print-directory -C lib/print re CC=$(CC) CFLAGS="$(CFLAGS)"
	-@make --no-print-directory -C lib/utils re CC=$(CC) CFLAGS="$(CFLAGS)"
	-@cp -f lib/*/*.a lib/
	$(CC) -o $(CNAME) $(OBJ) $(CFLAGS) $(CFLAGS_PLUS)

clean:
	@rm -f $(OBJ)
	@rm -f *.out */*.out */*/*.out
	@rm -f *.pch */*.pch */*/*.pch
	@rm -f *.gc* */*.gc* */*/*.gc*
	@rm -f *~* */*~* */*/*~*
	@rm -f *# */*# */*/*#
	-@make --no-print-directory -C lib/newcsfml clean
	-@make --no-print-directory -C lib/str clean
	-@make --no-print-directory -C lib/llist clean
	-@make --no-print-directory -C lib/twodlist clean
	-@make --no-print-directory -C lib/print clean
	-@make --no-print-directory -C lib/utils clean

fclean:	clean
	@rm -f $(CNAME)
	@rm -f $(TESTCNAME)
	@rm -f $(TESTSEGCNAME)
	@rm -f lib/*.a
	-@make --no-print-directory -C lib/newcsfml fclean
	-@make --no-print-directory -C lib/str fclean
	-@make --no-print-directory -C lib/llist fclean
	-@make --no-print-directory -C lib/twodlist fclean
	-@make --no-print-directory -C lib/print fclean
	-@make --no-print-directory -C lib/utils fclean

re:	fclean all

run: all
	./$(CNAME) $(CARG)

###################
## testing rules ##
###################
test_$(TESTCNAME): clean
	@$(CC) -o $(TESTCNAME) $(SRC) $(TEST_REDIRECT) $(TEST) $(CFLAGS) $(CFLAGS_PLUS) $(TESTCFLAGS)

test_$(TESTCNAME)_run: fclean test_$(TESTCNAME)
	@./$(TESTCNAME)

test_$(TESTSEGCNAME): clean
	@$(CC) -o $(TESTSEGCNAME) $(SRC) $(TEST_REDIRECT) $(TEST_SEG) $(CFLAGS) $(CFLAGS_PLUS) $(TESTCFLAGS)

test_$(TESTSEGCNAME)_run: fclean test_$(TESTSEGCNAME)
	@./$(TESTSEGCNAME)

test_valgrind: fclean $(CNAME) test_$(TESTCNAME) test_$(TESTSEGCNAME)
	@valgrind ./$(CNAME) $(CARG)
	@valgrind ./$(TESTCNAME)
	@valgrind ./$(TESTSEGCNAME)

test_gcovr: test_$(TESTCNAME)
	@gcovr -e $(TEST_PATH)

test_style_check:
	@epiclang $(MAIN) $(SRC) $(BONUS) $(CFLAGS)
	@printf '\033[92mepiclang done\033[0m\n'

test_run: test_$(TESTCNAME)_run

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
	cp -rf $(EPITECH_BASE_PATH)/.gitignore ./

	cp -rf $(EPITECH_BASE_PATH)/build_files/tree/* ./
	cp -rf $(EPITECH_BASE_PATH)/build_files/lib/llist/* ./lib/llist
	cp -rf $(EPITECH_BASE_PATH)/build_files/lib/twodlist/* ./lib/twodlist
	cp -rf $(EPITECH_BASE_PATH)/build_files/lib/str/* ./lib/str
	cp -rf $(EPITECH_BASE_PATH)/build_files/lib/newcsfml/* ./lib/newcsfml
	cp -rf $(EPITECH_BASE_PATH)/build_files/lib/print/* ./lib/print
	cp -rf $(EPITECH_BASE_PATH)/build_files/lib/utils/* ./lib/utils
	cp -rf lib/str/includes/* ./includes/lib_includes/str/
	cp -rf lib/llist/includes/* ./includes/lib_includes/llist/
	cp -rf lib/twodlist/includes/* ./includes/lib_includes/twodlist/
	cp -rf lib/newcsfml/includes/* ./includes/lib_includes/newcsfml/
	cp -rf lib/print/includes/* ./includes/lib_includes/print/
	cp -rf lib/utils/includes/* ./includes/lib_includes/utils/
	-@git add bonus/* includes/* sources/* tests/* lib/* .gitignore main.c Makefile
	-@git commit -m "[INIT] Initial build files"
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