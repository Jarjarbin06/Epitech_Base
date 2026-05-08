##
## EPITECH PROJECT, 2025
## Main - Makefile
## File description:
## Generic repo build system
##


###############################################################################
# META
# -----------------------------------------------------------------------------
# Project metadata and build configuration reference.
###############################################################################
info_NAME	=	Epitech Base
info_VERSION	=	v1.0.3
info_LAST_UPDATE	=	2026/05/08 18h
info_LIB_MAKER	=	Makefile


# =============================================================================
# VARIABLES
# -----------------------------------------------------------------------------
# Global configuration values used throughout the build system.
# =============================================================================

# -----------------------------------------------------------------------------
# CONFIG (CUSTOMIZABLE)
# Safe to modify unless stated otherwise.
# -----------------------------------------------------------------------------
EPITECH_BASE_PATH	=	/home/jarjarbin/Desktop/c/Epitech_Base
ALLOW_UNBUILD	=	false
ALLOW_AUTO_PUSH	=	true
DEBUG	?=	false
HAS_CSFML	=	false

# -----------------------------------------------------------------------------
# PATHS
# -----------------------------------------------------------------------------
SRC_PATH        = sources
LIB_SRC_PATH    = lib
INCLUDE_PATH    = includes
LIB_PATH        = lib

# -----------------------------------------------------------------------------
# SOURCES
# -----------------------------------------------------------------------------
SRC     =	$(sort $(shell [ -d "$(SRC_PATH)" ] && find $(SRC_PATH) -type f -name "*.c" ! -name "main.c"))

# -----------------------------------------------------------------------------
# INCLUDES
# -----------------------------------------------------------------------------
INCLUDES	=	$(sort $(addprefix -I,$(shell [ -d "$(INCLUDE_PATH)" ] && find $(INCLUDE_PATH) -type d)))

# -----------------------------------------------------------------------------
# BONUS
# -----------------------------------------------------------------------------
BONUS_PATH	=	bonus
BONUS	=	$(BONUS_PATH)/bonus_file.c

# -----------------------------------------------------------------------------
# LIBRARIES
# -----------------------------------------------------------------------------
LIBS_LIST	=	$(sort $(notdir $(shell [ -d "$(LIB_SRC_PATH)" ] && find $(LIB_SRC_PATH) -mindepth 1 -maxdepth 1 -type d)))
LIB_FLAGS	=	\
	$(foreach lib,$(LIBS_LIST), \
    $(if $(wildcard lib/$(lib)/lib$(lib).a),-l$(lib),))

# -----------------------------------------------------------------------------
# MAIN
# -----------------------------------------------------------------------------
MAIN	=	$(SRC_PATH)/main.c

# -----------------------------------------------------------------------------
# TEST VARIABLES
# -----------------------------------------------------------------------------
TEST_PATH	=	tests
TEST	=	$(sort $(shell [ -d "$(TEST_PATH)" ] && find $(TEST_PATH) -type f -name "*.c"))

# -----------------------------------------------------------------------------
# OBJECTS
# -----------------------------------------------------------------------------
SRC_OBJ	=	$(SRC:.c=.o)
MAIN_OBJ	=	$(MAIN:.c=.o)
TEST_OBJ	=	$(TEST:.c=.o)

# -----------------------------------------------------------------------------
# COMPILATION FLAGS
# -----------------------------------------------------------------------------
CC	=	clang
CNAME	=	binary
CARG	=

CFLAGS	=	-Wall -Wextra -Werror -MMD -MP

DEBUG_FLAGS	=	-g3 -O0
RELEASE_FLAGS = -O3 -march=native

ifeq ($(DEBUG), true)
CFLAGS	+=	$(DEBUG_FLAGS)
else
CFLAGS	+=	$(RELEASE_FLAGS)
endif

CFLAGS	+=	$(CFLAGS_EXTRA)

CPPFLAGS	=	$(INCLUDES)

# -----------------------------------------------------------------------------
# LIBRARY FLAGS
# -----------------------------------------------------------------------------
CFLAGS_PLUS	=	-L./$(LIB_PATH) $(LIB_FLAGS)


ifeq ($(HAS_CSFML), true)
CFLAGS_PLUS	+=	\
	-lcsfml-graphics \
	-lcsfml-window \
	-lcsfml-system \
	-lcsfml-audio \
	-lm
else
CFLAGS_PLUS	+=
endif

CFLAGS_PLUS	+=	$(LDFLAGS_EXTRA)

# -----------------------------------------------------------------------------
# TEST FLAGS
# -----------------------------------------------------------------------------
TESTCNAME	=	unit_tests
TEST_CFLAGS	=	-Wall -Wextra -g3 -O0 --coverage

# -----------------------------------------------------------------------------
# COMMANDS
# -----------------------------------------------------------------------------
RM	=	rm -f

# =============================================================================
# BUILD RULES
# -----------------------------------------------------------------------------
# Core compilation and binary generation rules.
# =============================================================================

# -----------------------------------------------------------------------------
# ENTRY POINT
# -----------------------------------------------------------------------------
all:	lib-build $(CNAME)

# -----------------------------------------------------------------------------
# MAIN BUILD
# -----------------------------------------------------------------------------
$(CNAME):	$(SRC_OBJ) $(MAIN_OBJ)
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $(CNAME) $(MAIN_OBJ) $(SRC_OBJ) $(CFLAGS_PLUS)

# -----------------------------------------------------------------------------
# CLEAN
# -----------------------------------------------------------------------------
clean:	lib-clean
	$(RM) $(sort $(shell find $(SRC_PATH) -type f -name "*.o"))
	$(RM) $(sort $(shell find $(SRC_PATH) -type f -name "*.d"))
	$(RM) $(sort $(shell find "." -type f -name "*.out"))
	$(RM) $(sort $(shell find "." -type f -name "*.pch"))
	$(RM) $(sort $(shell find "." -type f -name "*.gc*"))
	$(RM) $(sort $(shell find "." -type f -name "*~*"))
	$(RM) $(sort $(shell find "." -type f -name "#*#"))

# -----------------------------------------------------------------------------
# FULL CLEAN
# -----------------------------------------------------------------------------
fclean:	lib-fclean clean
	$(RM) $(CNAME)
	$(RM) $(TESTCNAME)
	$(RM) $(TESTSEGCNAME)
	$(RM) $(sort $(shell find "$(LIB_PATH)" -type f -name "*.a"))

# -----------------------------------------------------------------------------
# REBUILD
# -----------------------------------------------------------------------------
re:	fclean all

# -----------------------------------------------------------------------------
# RUN
# -----------------------------------------------------------------------------
run: all
	./$(CNAME) $(CARG)

# -----------------------------------------------------------------------------
# SANITIZER BUILD
# -----------------------------------------------------------------------------
debug-asan:
	make DEBUG=true CFLAGS_EXTRA="-fsanitize=address -fno-omit-frame-pointer" LDFLAGS_EXTRA="-fsanitize=address" re


# =============================================================================
# LIBRARY RULES
# -----------------------------------------------------------------------------
# Compilation, cleanup, and management of internal libraries.
# =============================================================================

# -----------------------------------------------------------------------------
# COMPILE LIBS
# -----------------------------------------------------------------------------
lib-build:
	for lib in $(LIBS_LIST); do \
		$(MAKE) --no-print-directory -C lib/$$lib CC=$(CC) DEBUG="$(DEBUG)"; \
	done
	cp -f lib/*/*.a lib/ 2>/dev/null || true
	for lib in $(LIBS_LIST); do \
		[ -f lib/lib$$lib.a ] && ranlib lib/lib$$lib.a || true; \
	done

# -----------------------------------------------------------------------------
# CLEAN LIBS
# -----------------------------------------------------------------------------
lib-clean:
	for lib in $(LIBS_LIST); do \
		$(MAKE) --no-print-directory -C lib/$$lib clean; \
	done

# -----------------------------------------------------------------------------
# FULL CLEAN LIBS
# -----------------------------------------------------------------------------
lib-fclean:
	for lib in $(LIBS_LIST); do \
		$(MAKE) --no-print-directory -C lib/$$lib fclean; \
	done


# =============================================================================
# TESTING
# -----------------------------------------------------------------------------
# Unit testing, coverage, and debugging utilities.
# =============================================================================

# -----------------------------------------------------------------------------
# DEBUG / TEST
# -----------------------------------------------------------------------------
test-valgrind: re
	valgrind --leak-check=full --track-origins=yes ./$(CNAME) $(CARG)

# -----------------------------------------------------------------------------
# COVERAGE
# -----------------------------------------------------------------------------
test-gcovr: test-run
	gcovr -e $(TEST_PATH)

# -----------------------------------------------------------------------------
# STYLE CHECK
# -----------------------------------------------------------------------------
test-style:
	-make --no-print-directory CC=epiclang re fclean
	printf '\033[92mepiclang done\033[0m\n'

# -----------------------------------------------------------------------------
# UNIT TESTS
# -----------------------------------------------------------------------------
test-build: lib-build $(TEST_OBJ) $(SRC_OBJ)
	$(CC) $(TEST_CFLAGS) $(CPPFLAGS) -o $(TESTCNAME) $(TEST_OBJ) $(SRC_OBJ) $(CFLAGS_PLUS)

# -----------------------------------------------------------------------------
# UNIT TESTS RUNNING
# -----------------------------------------------------------------------------
test-run: test-build
	./$(TESTCNAME)

test_run: test-run


# =============================================================================
# GIT / VERSION CONTROL
# -----------------------------------------------------------------------------
# Automated repository interaction and metadata handling.
# =============================================================================

git-commit-msg:
	python3 /home/jarjarbin/Desktop/python/commit_name.py

git-pull:
	git pull origin main

git-status:
	git status --long

git-push-repo:
	-git add -A
	-git commit -m "[REPO] Repo initialization"
	-git push origin main

ifeq ($(ALLOW_AUTO_PUSH), true)
git-push-libs:
	-git add lib includes/lib_includes
	-git commit -m "[REPO] Library auto-import / auto-update"
	-git push origin main
else
git-push-libs:
	printf '\033[91mPushLib is disabled. To enable it, set ALLOW_LIB_PUSH to "true" before calling lib-push.\033[0m\n'
	exit 84
endif

ifeq ($(ALLOW_AUTO_PUSH), true)
git-push-makefile:
	-git add Makefile
	-git commit -m "[REPO] Makefile auto-update"
	-git push origin main
else
git-push-makefile:
	printf '\033[91mPushMakefile is disabled. To enable it, set ALLOW_LIB_PUSH to "true" before calling lib-push.\033[0m\n'
	exit 84
endif


# =============================================================================
# REPOSITORY SETUP
# -----------------------------------------------------------------------------
# Project initialization and bootstrap operations.
# =============================================================================

ifeq ($(wildcard *), Makefile)
setup-build:
	cp -rf $(EPITECH_BASE_PATH)/.gitignore ./
	cp -rf $(EPITECH_BASE_PATH)/build_files/tree/* ./
	-make git-push-repo
else
setup-build:
	printf '\033[91mBuild is disabled. To enable it, call the unbuild rule.\033[0m\n'
	exit 84
endif

# -----------------------------------------------------------------------------
# WARNING: DESTRUCTIVE
# -----------------------------------------------------------------------------
ifeq ($(ALLOW_UNBUILD), true)
setup-unbuild: fclean
	rm -dfr bonus includes lib sources tests main.c
else
setup-unbuild:
	printf '\033[91mUnbuild is disabled. To enable it, set ALLOW_UNBUILD to "true" before calling unbuild.\033[0m\n'
	exit 84
endif

maint-update:
	cp $(EPITECH_BASE_PATH)/Makefile ./
	-make git-push-makefile


# =============================================================================
# IMPORT SYSTEM
# -----------------------------------------------------------------------------
# Manages external library imports into the project.
# =============================================================================

setup-import-newerror:
	-rm -rdf ./lib/newerror ./includes/lib_includes/newerror
	-mkdir ./lib/newerror
	cp -rf $(EPITECH_BASE_PATH)/build_files/lib/newerror/* ./lib/newerror
	-mkdir ./includes/lib_includes/newerror
	cp -rf lib/newerror/includes/* ./includes/lib_includes/newerror
	-make git-push-libs

setup-import-llist:
	-rm -rdf ./lib/llist ./includes/lib_includes/llist
	-mkdir ./lib/llist
	cp -rf $(EPITECH_BASE_PATH)/build_files/lib/llist/* ./lib/llist
	-mkdir ./includes/lib_includes/llist
	cp -rf lib/llist/includes/* ./includes/lib_includes/llist
	-make git-push-libs

setup-import-newcsfml:
	-rm -rdf ./lib/newcsfml ./includes/lib_includes/newcsfml
	-mkdir ./lib/newcsfml
	cp -rf $(EPITECH_BASE_PATH)/build_files/lib/newcsfml/* ./lib/newcsfml
	-mkdir ./includes/lib_includes/newcsfml
	cp -rf lib/newcsfml/includes/* ./includes/lib_includes/newcsfml
	-make git-push-libs

setup-import-print:
	-rm -rdf ./lib/print ./includes/lib_includes/print
	-mkdir ./lib/print
	cp -rf $(EPITECH_BASE_PATH)/build_files/lib/print/* ./lib/print
	-mkdir ./includes/lib_includes/print
	cp -rf lib/print/includes/* ./includes/lib_includes/print
	-make git-push-libs

setup-import-str:
	-rm -rdf ./lib/str ./includes/lib_includes/str
	-mkdir ./lib/str
	cp -rf $(EPITECH_BASE_PATH)/build_files/lib/str/* ./lib/str
	-mkdir ./includes/lib_includes/str
	cp -rf lib/str/includes/* ./includes/lib_includes/str
	-make git-push-libs

setup-import-twodlist:
	-rm -rdf ./lib/twodlist ./includes/lib_includes/twodlist
	-mkdir ./lib/twodlist
	cp -rf $(EPITECH_BASE_PATH)/build_files/lib/twodlist/* ./lib/twodlist
	-mkdir ./includes/lib_includes/twodlist
	cp -rf lib/twodlist/includes/* ./includes/lib_includes/twodlist
	-make git-push-libs

setup-import-file:
	-rm -rdf ./lib/file ./includes/lib_includes/file
	-mkdir ./lib/file
	cp -rf $(EPITECH_BASE_PATH)/build_files/lib/file/* ./lib/file
	-mkdir ./includes/lib_includes/file
	cp -rf lib/file/includes/* ./includes/lib_includes/file
	-make git-push-libs

setup-import-utils:
	-rm -rdf ./lib/utils ./includes/lib_includes/utils
	-mkdir ./lib/utils
	cp -rf $(EPITECH_BASE_PATH)/build_files/lib/utils/* ./lib/utils
	-mkdir ./includes/lib_includes/utils
	cp -rf lib/utils/includes/* ./includes/lib_includes/utils
	-make git-push-libs

setup-import-all:
	make \
	setup-import-newerror \
	setup-import-llist \
	setup-import-newcsfml \
	setup-import-print \
	setup-import-str \
	setup-import-file \
	setup-import-twodlist \
	setup-import-utils


# =============================================================================
# UTILITIES
# -----------------------------------------------------------------------------
# Helper commands and miscellaneous project tools.
# =============================================================================

help:
	echo "helper not done"

.DEFAULT_GOAL	:=	all

.SILENT: \
	git-commit-msg git-pull git-status git-push-repo git-push-libs git-push-makefile \
	setup-build setup-unbuild setup-import-all \
	setup-import-newerror setup-import-llist setup-import-newcsfml \
	setup-import-print setup-import-str setup-import-file \
	setup-import-twodlist setup-import-utils \
	maint-update help

.PHONY: \
	all clean fclean re run debug-asan \
	lib-build lib-clean lib-fclean \
	test-build test-run test-valgrind test-gcovr test-style \
	git-commit-msg git-pull git-status git-push-repo git-push-libs git-push-makefile \
	setup-build setup-unbuild setup-import-all \
	setup-import-newerror setup-import-llist setup-import-newcsfml \
	setup-import-print setup-import-str setup-import-file \
	setup-import-twodlist setup-import-utils \
	maint-update help

-include $(SRC_OBJ:.o=.d) $(MAIN_OBJ:.o=.d) $(TEST_OBJ:.o=.d)
