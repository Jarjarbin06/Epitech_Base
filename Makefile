##
## EPITECH PROJECT, 2025
## Main - Makefile
## File description:
## Generic repo build system
## See documentation here : https://jarjarbin06.github.io/Epitech_Base/makefile.html
##


###############################################################################
# META
# -----------------------------------------------------------------------------
# Project metadata and build configuration reference.
###############################################################################
info_NAME	=	Epitech Base
info_VERSION	=	v1.0.6
info_LAST_UPDATE	=	2026/06/03 09h
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
EPITECH_BASE_PATH	?=	/home/jarjarbin/Desktop/c/Epitech_Base
HAS_CSFML	?=	false
ALLOW_UNBUILD	?=	false	#	true / false
ALLOW_AUTO_PUSH	?=	false	#	true / false
BONUS	?=	false			#	true / false
DEBUG	?=	false			#	true / false
ARCH	?=	generic			#	native / generic
NAME	?=	binary			#	binary name

# -----------------------------------------------------------------------------
# PATHS
# -----------------------------------------------------------------------------
SRC_PATH		= sources
BONUS_PATH		= bonus
TEST_PATH	=	tests
LIB_SRC_PATH	= lib
INCLUDE_PATH	= includes
LIB_PATH		= lib

# -----------------------------------------------------------------------------
# SOURCES
# -----------------------------------------------------------------------------
SRC	=	$(sort $(shell [ -d "$(SRC_PATH)" ] && find $(SRC_PATH) -type f -name "*.c" ! -name "main.c"))

# -----------------------------------------------------------------------------
# INCLUDES
# -----------------------------------------------------------------------------
INCLUDES	=	$(sort $(addprefix -I,$(shell [ -d "$(INCLUDE_PATH)" ] && find $(INCLUDE_PATH) -type d)))

# -----------------------------------------------------------------------------
# BONUS
# -----------------------------------------------------------------------------
BONUS_SRC     =	$(sort $(shell [ -d "$(BONUS_PATH)" ] && find $(BONUS_PATH) -type f -name "*.c"))

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
# TEST
# -----------------------------------------------------------------------------
TEST_SRC	=	$(sort $(shell [ -d "$(TEST_PATH)" ] && find $(TEST_PATH) -type f -name "*.c"))

# -----------------------------------------------------------------------------
# OBJECTS
# -----------------------------------------------------------------------------
SRC_OBJ	=	$(SRC:.c=.o)
BONUS_OBJ	=	$(BONUS_SRC:.c=.o)
MAIN_OBJ	=	$(MAIN:.c=.o)
TEST_OBJ	=	$(TEST_SRC:.c=.o)

# -----------------------------------------------------------------------------
# COMPILATION FLAGS
# -----------------------------------------------------------------------------
CC	=	clang
CNAME	=	$(NAME)
CARG	=

CFLAGS_BASE	=	-Wall -Wextra -Werror -MMD -MP -fdata-sections -ffunction-sections
CFLAGS_DEBUG	=	-g3 -O0
CFLAGS_RELEASE	=	-O3 -fno-plt

ifeq ($(ARCH), native)
CFLAGS_RELEASE	+=	-march=native -mtune=native
endif

ifeq ($(DEBUG), true)
CFLAGS	=	$(CFLAGS_BASE) $(CFLAGS_DEBUG)
else
CFLAGS	=	$(CFLAGS_BASE) $(CFLAGS_RELEASE)
endif

CFLAGS	+=	$(LDFLAGS_EXTRA)

ifeq ($(BONUS), true)
CFLAGS	+=	-DBONUS=1
else
CFLAGS	+=	-DBONUS=0
endif

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
TEST_CNAME	=	unit_tests
TEST_CFLAGS	=	-g -O0 -lcriterion

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
$(CNAME):	$(SRC_OBJ) $(MAIN_OBJ) $(BONUS_OBJ)
	$(CC) $(CFLAGS) -o $(CNAME) $(MAIN_OBJ) $(SRC_OBJ) $(BONUS_OBJ) $(CFLAGS_PLUS)

# -----------------------------------------------------------------------------
# CLEAN
# -----------------------------------------------------------------------------
clean:	lib-clean
	$(RM) $(sort $(shell find $(SRC_PATH) -type f -name "*.o"))
	$(RM) $(sort $(shell find $(SRC_PATH) -type f -name "*.d"))
	$(RM) $(sort $(shell find $(SRC_PATH) -type f -name "*.gc*"))
	$(RM) $(sort $(shell find $(BONUS_PATH) -type f -name "*.o"))
	$(RM) $(sort $(shell find $(BONUS_PATH) -type f -name "*.d"))
	$(RM) $(sort $(shell find $(BONUS_PATH) -type f -name "*.gc*"))
	$(RM) $(sort $(shell find $(TEST_PATH) -type f -name "*.o"))
	$(RM) $(sort $(shell find $(TEST_PATH) -type f -name "*.d"))
	$(RM) $(sort $(shell find $(TEST_PATH) -type f -name "*.gc*"))
	$(RM) $(sort $(shell find $(INCLUDE_PATH) -type f -name "*.pch"))
	$(RM) $(sort $(shell find "." -type f -name "*.out"))
	$(RM) $(sort $(shell find "." -type f -name "*~*"))
	$(RM) $(sort $(shell find "." -type f -name "#*#"))

# -----------------------------------------------------------------------------
# FULL CLEAN
# -----------------------------------------------------------------------------
fclean: clean
	$(RM) $(CNAME)
	$(RM) $(TEST_CNAME)
	$(RM) $(TESTSEGCNAME)

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
	make DEBUG=true LDFLAGS_EXTRA="-fsanitize=address -fno-omit-frame-pointer" re


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
        if [ ! -f lib/lib$$lib.a ]; then \
            $(MAKE) --no-print-directory -C lib/$$lib CC=$(CC) DEBUG="$(DEBUG)"; \
        fi; \
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
	$(RM) $(sort $(shell find "$(LIB_PATH)" -type f -name "*.a"))
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
test-valgrind:
	make --no-print-directory DEBUG=true re
	valgrind --leak-check=full --track-origins=yes ./$(CNAME) $(CARG)

# -----------------------------------------------------------------------------
# COVERAGE
# -----------------------------------------------------------------------------
test-gcovr:
	make --no-print-directory DEBUG=true LDFLAGS_EXTRA="-fprofile-arcs -ftest-coverage -fprofile-instr-generate -fcoverage-mapping" test-run
	gcovr --gcov-executable "llvm-cov gcov" -e $(TEST_PATH)

# -----------------------------------------------------------------------------
# STYLE CHECK
# -----------------------------------------------------------------------------
test-style:
	-make --no-print-directory CC=epiclang re fclean
	printf '\x1b[92mepiclang done\x1b[0m\n'

# -----------------------------------------------------------------------------
# UNIT TESTS
# -----------------------------------------------------------------------------
test-build: fclean lib-fclean lib-build $(TEST_OBJ) $(SRC_OBJ)
	$(CC) $(TEST_CFLAGS) -o $(TEST_CNAME) $(TEST_OBJ) $(SRC_OBJ) $(CFLAGS_PLUS)

# -----------------------------------------------------------------------------
# UNIT TESTS RUNNING
# -----------------------------------------------------------------------------
test-run: test-build
	./$(TEST_CNAME)

tests_run: test-gcovr


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
	printf '\x1b[91mPushLib is disabled. To enable it, set ALLOW_AUTO_PUSH to "true" before calling lib-push.\x1b[0m\n'
	exit 84
endif

ifeq ($(ALLOW_AUTO_PUSH), true)
git-push-makefile:
	-git add Makefile
	-git commit -m "[REPO] Makefile auto-update"
	-git push origin main
else
git-push-makefile:
	printf '\x1b[91mPushMakefile is disabled. To enable it, set ALLOW_AUTO_PUSH to "true" before calling lib-push.\x1b[0m\n'
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
	cp -rf $(EPITECH_BASE_PATH)/build_files/tree/.gitignore ./
	-make git-push-repo
else
setup-build:
	printf '\x1b[91mBuild is disabled. To enable it, call the unbuild rule.\x1b[0m\n'
	exit 84
endif

# -----------------------------------------------------------------------------
# WARNING: DESTRUCTIVE
# -----------------------------------------------------------------------------
ifeq ($(ALLOW_UNBUILD), true)
setup-unbuild: fclean
	rm -dfr *
else
setup-unbuild:
	printf '\x1b[91mUnbuild is disabled. To enable it, set ALLOW_UNBUILD to "true" before calling unbuild.\x1b[0m\n'
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

setup-import-newerror: lib-fclean
	-rm -rdf ./lib/newerror ./includes/lib_includes/newerror
	-mkdir ./lib/newerror
	cp -rf $(EPITECH_BASE_PATH)/build_files/lib/newerror/* ./lib/newerror
	-mkdir ./includes/lib_includes/newerror
	cp -rf lib/newerror/includes/* ./includes/lib_includes/newerror
	-make git-push-libs

setup-import-llist: lib-fclean
	-rm -rdf ./lib/llist ./includes/lib_includes/llist
	-mkdir ./lib/llist
	cp -rf $(EPITECH_BASE_PATH)/build_files/lib/llist/* ./lib/llist
	-mkdir ./includes/lib_includes/llist
	cp -rf lib/llist/includes/* ./includes/lib_includes/llist
	-make git-push-libs

setup-import-newcsfml: lib-fclean
	-rm -rdf ./lib/newcsfml ./includes/lib_includes/newcsfml
	-mkdir ./lib/newcsfml
	cp -rf $(EPITECH_BASE_PATH)/build_files/lib/newcsfml/* ./lib/newcsfml
	-mkdir ./includes/lib_includes/newcsfml
	cp -rf lib/newcsfml/includes/* ./includes/lib_includes/newcsfml
	-make git-push-libs

setup-import-print: lib-fclean
	-rm -rdf ./lib/print ./includes/lib_includes/print
	-mkdir ./lib/print
	cp -rf $(EPITECH_BASE_PATH)/build_files/lib/print/* ./lib/print
	-mkdir ./includes/lib_includes/print
	cp -rf lib/print/includes/* ./includes/lib_includes/print
	-make git-push-libs

setup-import-str: lib-fclean
	-rm -rdf ./lib/str ./includes/lib_includes/str
	-mkdir ./lib/str
	cp -rf $(EPITECH_BASE_PATH)/build_files/lib/str/* ./lib/str
	-mkdir ./includes/lib_includes/str
	cp -rf lib/str/includes/* ./includes/lib_includes/str
	-make git-push-libs

setup-import-twodlist: lib-fclean
	-rm -rdf ./lib/twodlist ./includes/lib_includes/twodlist
	-mkdir ./lib/twodlist
	cp -rf $(EPITECH_BASE_PATH)/build_files/lib/twodlist/* ./lib/twodlist
	-mkdir ./includes/lib_includes/twodlist
	cp -rf lib/twodlist/includes/* ./includes/lib_includes/twodlist
	-make git-push-libs

setup-import-file: lib-fclean
	-rm -rdf ./lib/file ./includes/lib_includes/file
	-mkdir ./lib/file
	cp -rf $(EPITECH_BASE_PATH)/build_files/lib/file/* ./lib/file
	-mkdir ./includes/lib_includes/file
	cp -rf lib/file/includes/* ./includes/lib_includes/file
	-make git-push-libs

setup-import-flag: lib-fclean
	-rm -rdf ./lib/flag ./includes/lib_includes/flag
	-mkdir ./lib/flag
	cp -rf $(EPITECH_BASE_PATH)/build_files/lib/flag/* ./lib/flag
	-mkdir ./includes/lib_includes/flag
	cp -rf lib/flag/includes/* ./includes/lib_includes/flag
	-make git-push-libs

setup-import-utils: lib-fclean
	-rm -rdf ./lib/utils ./includes/lib_includes/utils
	-mkdir ./lib/utils
	cp -rf $(EPITECH_BASE_PATH)/build_files/lib/utils/* ./lib/utils
	-mkdir ./includes/lib_includes/utils
	cp -rf lib/utils/includes/* ./includes/lib_includes/utils
	-make git-push-libs

setup-import-all:
	setup-import-newerror \
	setup-import-llist \
	setup-import-newcsfml \
	setup-import-print \
	setup-import-str \
	setup-import-file \
	setup-import-flag \
	setup-import-twodlist \
	setup-import-utils


# =============================================================================
# UTILITIES
# -----------------------------------------------------------------------------
# Helper commands and miscellaneous project tools.
# =============================================================================

help:
	echo -e "============================================================"
	echo -e "                    \x1b[1;36m$(info_NAME)\x1b[0m"
	echo -e "                    Version: $(info_VERSION)"
	echo -e "============================================================"
	echo -e ""

	make --no-print-directory --silent help-base

	make --no-print-directory --silent help-test

	make --no-print-directory --silent help-lib

	make --no-print-directory --silent help-git

	make --no-print-directory --silent help-setup

	echo -e "============================================================"
	echo -e "\x1b[2;37mTip: variables like DEBUG=true ARCH=native can be used\x1b[0m"
	echo -e "============================================================"

help-base:
	echo -e "\x1b[1;33mBUILD\x1b[0m"
	echo -e "  make                     → Build project"
	echo -e "  make run                 → Build + run binary"
	echo -e "  make re                  → Full rebuild"
	echo -e ""

	echo -e "\x1b[1;33mCLEANING\x1b[0m"
	echo -e "  make clean               → Remove objects & temp files"
	echo -e "  make fclean              → Full clean (binary + libs)"
	echo -e ""

help-test:
	echo -e "\x1b[1;33mDEBUG / TEST\x1b[0m"
	echo -e "  make debug-asan          → Build with AddressSanitizer"
	echo -e "  make test-run            → Run unit tests"
	echo -e "  make test-valgrind       → Run with Valgrind"
	echo -e "  make test-gcovr          → Coverage report"
	echo -e "  make test-style          → Style check"
	echo -e ""

help-lib:
	echo -e "\x1b[1;33mLIBRARIES\x1b[0m"
	echo -e "  make lib-build           → Build all libs"
	echo -e "  make lib-clean           → Clean libs"
	echo -e "  make lib-fclean          → Full clean libs"
	echo -e ""

	echo -e "\x1b[1;33mIMPORT SYSTEM\x1b[0m"
	echo -e "  make setup-import-all    → Import all libs"
	echo -e "  make setup-import-*      → Import specific lib"
	echo -e ""

help-git:
	echo -e "\x1b[1;33mGIT\x1b[0m"
	echo -e "  make git-status          → Show git status"
	echo -e "  make git-pull            → Pull main branch"
	echo -e "  make git-push-repo       → Push repository"
	echo -e ""

help-setup:
	echo -e "\x1b[1;33mSETUP\x1b[0m"
	echo -e "  make setup-build         → Initialize project"
	echo -e "  make maint-update        → Update Makefile"
	echo -e ""

.DEFAULT_GOAL	:=	all

.SILENT: \
	git-commit-msg git-pull git-status git-push-repo git-push-libs git-push-makefile \
	setup-build setup-unbuild setup-import-all \
	setup-import-newerror setup-import-llist setup-import-newcsfml \
	setup-import-print setup-import-str setup-import-file \
	setup-import-flag setup-import-twodlist setup-import-utils \
	maint-update help help-base help-test help-lib help-git help-setup

.PHONY: \
	all clean fclean re run debug-asan \
	lib-build lib-clean lib-fclean \
	test-build test-run test-valgrind test-gcovr test-style \
	git-commit-msg git-pull git-status git-push-repo git-push-libs git-push-makefile \
	setup-build setup-unbuild setup-import-all \
	setup-import-newerror setup-import-llist setup-import-newcsfml \
	setup-import-print setup-import-str setup-import-file \
	setup-import-flag setup-import-twodlist setup-import-utils \
	maint-update help help-base help-test help-lib help-git help-setup

-include $(SRC_OBJ:.o=.d) $(MAIN_OBJ:.o=.d) $(TEST_OBJ:.o=.d)
