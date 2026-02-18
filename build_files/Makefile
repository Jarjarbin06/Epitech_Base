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
CC	=	clang
CFLAGS	=	 \
	-Wall \
	-Wextra

# lib #
NAME	=	$(info_NAME)

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

fclean:	clean
	@make --no-print-directory -C lib fclean
	@rm -f *.a
	@rm -f tree/lib/*.a
	@rm -rdf tree/lib/twodlist/*
	@rm -rdf tree/lib/llist/*
	@rm -rdf tree/lib/str/*
	@rm -rdf tree/lib/newcsfml/*
	@rm -rdf tree/lib/print/*
	@rm -rdf tree/lib/utils/*

re:	fclean all

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
	@make --no-print-directory -C lib DO_VALGRIND=$(DO_VALGRIND) CC=$(CC) CFLAGS=$(CFLAGS) test_run
	@make --no-print-directory fclean

.PHONY: \
	all \
	clean \
	fclean \
	re \
	show_info \
	show_var \
	run_test
