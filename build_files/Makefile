##
## EPITECH PROJECT, 2025
## build_files - Makefile
## File description:
## make the build_files
##

##########
## info ##
##########
info_NAME	=	build_files
info_VERSION	=	v0.1.2
info_LAST_UPDATE	=	2026/02/18 16:56
info_LIB_MAKER	=	Makefile

#########
## var ##
#########
DO_VALGRIND	=	false
DO_SANITIZE	=	false
CC	=	clang
CFLAGS	=	 \
	-Wall \
	-Wextra

# lib #
NAME	=	$(info_NAME)
RUN_NAME	=	run

#################
## Basic rules ##
#################
all:	$(NAME)

$(NAME):
	@make --no-print-directory -C lib CC=$(CC) all
	@cp */*.a .
	@cp *.a tree/lib
	@cp -r lib/twodlist/includes/* tree/lib/twodlist
	@cp -r lib/llist/includes/* tree/lib/llist
	@cp -r lib/str/includes/* tree/lib/str
	@cp -r lib/newcsfml/includes/* tree/lib/newcsfml
	@cp -r lib/utils/includes/* tree/lib/utils
	@cp -r lib/print/includes/* tree/lib/print

clean:
	@make --no-print-directory -C lib clean

fclean:
	@make --no-print-directory -C lib fclean
	@rm -f *.a
	@rm -f tree/lib/*.a
	@rm -rdf tree/lib/twodlist/*
	@rm -rdf tree/lib/llist/*
	@rm -rdf tree/lib/str/*
	@rm -rdf tree/lib/newcsfml/*
	@rm -rdf tree/lib/print/*
	@rm -rdf tree/lib/utils/*
	@rm -f $(RUN_NAME)

re:	fclean all

run:
	@make --no-print-directory -C lib DO_SANITIZE=$(DO_SANITIZE) CC=$(CC) CFLAGS=$(CFLAGS) RUN_NAME=$(RUN_NAME) run
	@mv lib/$(RUN_NAME) .

ifeq ($(DO_VALGRIND), true)
run_run:
	@make --no-print-directory -C lib DO_SANITIZE=$(DO_SANITIZE) DO_VALGRIND=$(DO_VALGRIND) CC=$(CC) CFLAGS=$(CFLAGS) RUN_NAME=$(RUN_NAME) run_run
	@make --no-print-directory fclean
else
run_run:
	@make --no-print-directory -C lib DO_SANITIZE=$(DO_SANITIZE) DO_VALGRIND=$(DO_VALGRIND) CC=$(CC) CFLAGS=$(CFLAGS) RUN_NAME=$(RUN_NAME) run_run
	@make --no-print-directory fclean
endif

show_info:
	@printf "\033[4minfo_NAME\033[0m : "; echo $(info_NAME)
	@printf "\033[4minfo_VERSION\033[0m : "; echo $(info_VERSION)
	@printf "\033[4minfo_LAST_UPDATE\033[0m : "; echo $(info_LAST_UPDATE)
	@printf "\033[4minfo_LIB_MAKER\033[0m : "; echo $(info_LIB_MAKER)

show_var:
	@printf "\033[4mNAME\033[0m : "; echo $(NAME)

################
## Test rules ##
################
test:
	@make --no-print-directory -C lib test

test_run:
	@make --no-print-directory -C lib DO_SANITIZE=$(DO_SANITIZE) DO_VALGRIND=$(DO_VALGRIND) CC=$(CC) CFLAGS=$(CFLAGS) test_run
	@make --no-print-directory fclean

.PHONY: \
	all \
	clean \
	fclean \
	re \
	run \
	show_info \
	show_var \
	run_test
