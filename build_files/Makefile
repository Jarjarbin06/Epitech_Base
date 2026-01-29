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
info_VERSION	=	v0.1.0
info_LAST_UPDATE	=	2026-01-26 11:05:23.047
info_LIB_MAKER	=	Makefile

#########
## var ##
#########
# lib #
var_NAME	=	$(info_NAME)

#################
## Basic rules ##
#################
all:	$(var_NAME)

$(var_NAME):
	@make --no-print-directory -C lib all
	@cp */*.a .
	@cp *.a tree/lib
	@cp -r lib/twod_list/include/* tree/lib/twod_list
	@cp -r lib/llist/include/* tree/lib/llist
	@cp -r lib/str/include/* tree/lib/str

clean:
	@make --no-print-directory -C lib clean

fclean:	clean
	@make --no-print-directory -C lib fclean
	@rm -f *.a
	@rm -f tree/lib/*.a
	@rm -rdf tree/lib/twod_list/*
	@rm -rdf tree/lib/llist/*
	@rm -rdf tree/lib/str/*

re:	fclean all

show_info:
	@printf "\033[4minfo_NAME\033[0m : "; echo $(info_NAME)
	@printf "\033[4minfo_VERSION\033[0m : "; echo $(info_VERSION)
	@printf "\033[4minfo_LAST_UPDATE\033[0m : "; echo $(info_LAST_UPDATE)
	@printf "\033[4minfo_LIB_MAKER\033[0m : "; echo $(info_LIB_MAKER)

show_var:
	@printf "\033[4mvar_NAME\033[0m : "; echo $(var_NAME)

################
## Test rules ##
################
test:
	@make --no-print-directory -C lib test

run_test:
	@make --no-print-directory -C lib run_test
	@make --no-print-directory fclean

.PHONY: \
	all \
	$(var_NAME) \
	clean \
	fclean \
	re \
	show_info \
	show_var \
	run_test
