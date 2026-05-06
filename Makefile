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
info_VERSION	=	v0.3.1
info_LAST_UPDATE	=	2026/05/05 14:09
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
SRC     = $(shell find $(SRC_PATH) -type f -name "*.c" ! -name "main.c")

# Includes #
INCLUDES = $(shell find $(INCLUDE_PATH) -type d -printf '-I%p ')

# Bonus #
BONUS_PATH	=	bonus
BONUS	=	$(BONUS_PATH)/bonus_file.c

# Lib list #
LIBS_LIST	=	$(notdir $(shell find lib -mindepth 1 -maxdepth 1 -type d))
LIB_FLAGS	=	\
	$(foreach lib,$(LIBS_LIST), \
    $(if $(wildcard lib/$(lib)/lib$(lib).a),-l$(lib),))

# Main #
MAIN	=	$(SRC_PATH)/main.c

# Objects #
SRC_OBJ	=	$(SRC:.c=.o)
MAIN_OBJ	=	$(MAIN:.c=.o)

# Tests #
TEST_PATH	=	tests
TEST_REDIRECT	=	$(TEST_PATH)/test_redirect.c
TEST	=	$(TEST_PATH)/test_file.c

# Compilation #
CC	=	clang
CNAME	=	binary
CARG	=

CFLAGS	=	-g3 -O0 # Enhance Valgrind
CFLAGS	+=	-O3 -Ofast -Os # Compilation optimization
CFLAGS	+=	-Wall -Wextra # Compilation warning & error

CPPFLAGS	=	$(INCLUDES)

CFLAGS_PLUS	=	-L./$(LIB_PATH) $(LIB_FLAGS)
ifneq ($(filter -lnewcsfml,$(CFLAGS_PLUS)),)
    CFLAGS_PLUS	+=	\
		-lcsfml-graphics \
		-lcsfml-window \
		-lcsfml-system \
		-lcsfml-audio \
		-lm
endif

TESTCNAME	=	unit_tests
TESTCFLAGS	=	\
	--coverage \
	-lcriterion

ALLOW_UNBUILD	=	false
ALLOW_AUTO_PUSH	=	true
#################
## Basic rules ##
#################
all:
	@make --no-print-directory compile_libs
	@make --no-print-directory $(CNAME)

$(CNAME):	$(SRC_OBJ) $(MAIN_OBJ)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(SRC_OBJ) $(MAIN_OBJ) -o $(CNAME) $(CFLAGS_PLUS)

clean:	clean_libs
	@rm -f $(SRC_OBJ)
	@rm -f $(MAIN_OBJ)
	@rm -f *.out */*.out */*/*.out
	@rm -f *.pch */*.pch */*/*.pch
	@rm -f *.gc* */*.gc* */*/*.gc*
	@rm -f *~* */*~* */*/*~*
	@rm -f *# */*# */*/*#

fclean:	fclean_libs clean
	@rm -f $(CNAME)
	@rm -f $(TESTCNAME)
	@rm -f $(TESTSEGCNAME)
	@rm -f lib/*.a

re:	fclean all

run: all
	./$(CNAME) $(CARG)

asan:
	@make CFLAGS="$(CFLAGS) -fsanitize=address" re

###############
## Lib rules ##
###############
compile_libs:
	@for lib in $(LIBS_LIST); do \
		$(MAKE) --no-print-directory -C lib/$$lib CC=$(CC) CFLAGS="$(CFLAGS)"; \
	done
	@cp -f lib/*/*.a lib/ 2>/dev/null || true
	@for lib in $(LIBS_LIST); do \
		ranlib lib/lib$$lib.a; \
	done

clean_libs:
	@for lib in $(LIBS_LIST); do \
		$(MAKE) --no-print-directory -C lib/$$lib clean; \
	done

fclean_libs:
	@for lib in $(LIBS_LIST); do \
		$(MAKE) --no-print-directory -C lib/$$lib fclean; \
	done


###################
## testing rules ##
###################
test_valgrind: re
	@valgrind --leak-check=full --track-origins=yes ./$(CNAME) $(CARG)

test_$(TESTCNAME): clean
	$(CC) -o $(TESTCNAME) $(SRC_OBJ) $(CFLAGS) $(CPPFLAGS) $(CFLAGS_PLUS)

test_$(TESTCNAME)_run: fclean test_$(TESTCNAME)
	@./$(TESTCNAME)

test_gcovr: test_$(TESTCNAME)
	@gcovr -e $(TEST_PATH)

test_style:
	-@make --no-print-directory CC=epiclang re fclean
	@printf '\033[92mepiclang done\033[0m\n'

test_run: test_$(TESTCNAME)_run

###############
## git rules ##
###############
git_get_commit:
	@python3 /home/jarjarbin/Desktop/python/commit_name.py

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
	-@make push_setup
else
build:
	@printf '\033[91mBuild is disabled. To enable it, call the unbuild rule.\033[0m\n'
	@exit 84
endif

ifeq ($(ALLOW_UNBUILD), true)
unbuild: fclean
	@rm -dfr bonus includes lib sources tests main.c
else
unbuild:
	@printf '\033[91mUnbuild is disabled. To enable it, set ALLOW_UNBUILD to "true" before calling unbuild.\033[0m\n'
	@exit 84
endif

push_setup:
	-@git add -A
	-@git commit -m "[REPO] Repo initialization"
	-@git push origin main

update:
	@cp $(EPITECH_BASE_PATH)/Makefile ./
	-@make push_makefile

ifeq ($(ALLOW_AUTO_PUSH), true)
push_makefile:
	-@git add Makefile
	-@git commit -m "[REPO] Makefile auto-update"
	-@git push origin main
else
push_makefile:
	@printf '\033[91mPushMakefile is disabled. To enable it, set ALLOW_LIB_PUSH to "true" before calling push_lib.\033[0m\n'
	@exit 84
endif

import_newerror:
	-@rm -rdf ./lib/newerror ./includes/lib_includes/newerror
	-@mkdir ./lib/newerror
	@cp -rf $(EPITECH_BASE_PATH)/build_files/lib/newerror/* ./lib/newerror
	-@mkdir ./includes/lib_includes/newerror
	@cp -rf lib/newerror/includes/* ./includes/lib_includes/newerror
	-@make push_lib

import_llist:
	-@rm -rdf ./lib/llist ./includes/lib_includes/llist
	-@mkdir ./lib/llist
	@cp -rf $(EPITECH_BASE_PATH)/build_files/lib/llist/* ./lib/llist
	-@mkdir ./includes/lib_includes/llist
	@cp -rf lib/llist/includes/* ./includes/lib_includes/llist
	-@make push_lib

import_newcsfml:
	-@rm -rdf ./lib/newcsfml ./includes/lib_includes/newcsfml
	-@mkdir ./lib/newcsfml
	@cp -rf $(EPITECH_BASE_PATH)/build_files/lib/newcsfml/* ./lib/newcsfml
	-@mkdir ./includes/lib_includes/newcsfml
	@cp -rf lib/newcsfml/includes/* ./includes/lib_includes/newcsfml
	-@make push_lib

import_print:
	-@rm -rdf ./lib/print ./includes/lib_includes/print
	-@mkdir ./lib/print
	@cp -rf $(EPITECH_BASE_PATH)/build_files/lib/print/* ./lib/print
	-@mkdir ./includes/lib_includes/print
	@cp -rf lib/print/includes/* ./includes/lib_includes/print
	-@make push_lib

import_str:
	-@rm -rdf ./lib/str ./includes/lib_includes/str
	-@mkdir ./lib/str
	@cp -rf $(EPITECH_BASE_PATH)/build_files/lib/str/* ./lib/str
	-@mkdir ./includes/lib_includes/str
	@cp -rf lib/str/includes/* ./includes/lib_includes/str
	-@make push_lib

import_twodlist:
	-@rm -rdf ./lib/twodlist ./includes/lib_includes/twodlist
	-@mkdir ./lib/twodlist
	@cp -rf $(EPITECH_BASE_PATH)/build_files/lib/twodlist/* ./lib/twodlist
	-@mkdir ./includes/lib_includes/twodlist
	@cp -rf lib/twodlist/includes/* ./includes/lib_includes/twodlist
	-@make push_lib

import_file:
	-@rm -rdf ./lib/file ./includes/lib_includes/file
	-@mkdir ./lib/file
	@cp -rf $(EPITECH_BASE_PATH)/build_files/lib/file/* ./lib/file
	-@mkdir ./includes/lib_includes/file
	@cp -rf lib/file/includes/* ./includes/lib_includes/file
	-@make push_lib

import_utils:
	-@rm -rdf ./lib/utils ./includes/lib_includes/utils
	-@mkdir ./lib/utils
	@cp -rf $(EPITECH_BASE_PATH)/build_files/lib/utils/* ./lib/utils
	-@mkdir ./includes/lib_includes/utils
	@cp -rf lib/utils/includes/* ./includes/lib_includes/utils
	-@make push_lib

import_all:
	-@make import_newerror import_llist import_newcsfml import_print import_str import_file
	 import_twodlist import_utils

ifeq ($(ALLOW_AUTO_PUSH), true)
push_lib:
	-@git add lib includes/lib_includes
	-@git commit -m "[REPO] Library auto-import / auto-update"
	-@git push origin main
else
push_lib:
	@printf '\033[91mPushLib is disabled. To enable it, set ALLOW_LIB_PUSH to "true" before calling push_lib.\033[0m\n'
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
.SILENT: \
	test_run \
	test_valgrind \
	test_gcovr \
	test_style_check \
	git_get_commit \
	git_pull \
	git_info \
	build \
	unbuild \
	help \
	update \
	import_all \
	import_llist \
	import_newcsfml \
	import_newerror \
	import_print \
	import_str \
	import_twodlist \
	import_utils \
	import_file \
	push_setup \
	push_lib

.PHONY: \
	all \
	clean \
	fclean \
	re \
	run \
	asan \
