##
## EPITECH PROJECT, 2025
## lib - Makefile
## File description:
## make the lib
##

##########
## Info ##
##########
info_NAME	=	lib
info_VERSION	=	v0.0.1
info_LAST_UPDATE	=	2025-11-27 15:51:13.323668
info_LIB_MAKER	=	Makefile

#########
## Var ##
#########
# ./test_lib #
var_TEST_PATH	=	test_lib
var_TEST	=	$(var_TEST_PATH)/test_base.c
var_TEST	+=	$(var_TEST_PATH)/test_str.c

# lib #
var_NAME	=	$(info_NAME)

# test #
var_TEST_COMPILER	=	clang
var_TEST_NAME	=	_test
var_TEST_FLAG	=	\
	-I/2list/include/ \
	-I./lib/llist/include/ \
	-I./lib/str/include/ \
	-I./lib/test_lib/ \
	-L./ \
	-Wall \
	-Werror \
	--coverage \
	-lcriterion \
	-l2list \
	-lllist \
	-lstr

#################
## Basic rules ##
#################
all:	$(var_NAME)

$(var_NAME):
	@make --no-print-directory -C 2list all
	@make --no-print-directory -C llist all
	@make --no-print-directory -C str all
	@cp */*.a ./

clean:
	@make --no-print-directory -C 2list clean
	@make --no-print-directory -C llist clean
	@make --no-print-directory -C str clean
	@rm -f $(var_TEST_NAME)
	@rm -f *.gc*

fclean: clean
	@make --no-print-directory -C 2list fclean
	@make --no-print-directory -C llist fclean
	@make --no-print-directory -C str fclean
	@rm -f *.a

re: fclean all

show_info:
	@printf "\033[4minfo_NAME\033[0m : "; echo $(info_NAME)
	@printf "\033[4minfo_VERSION\033[0m : "; echo $(info_VERSION)
	@printf "\033[4minfo_LAST_UPDATE\033[0m : "; echo $(info_LAST_UPDATE)
	@printf "\033[4minfo_LIB_MAKER\033[0m : "; echo $(info_LIB_MAKER)

show_var:
	@printf "\033[4mvar_NAME\033[0m : "; echo $(var_NAME)
	@printf "\033[4mvar_TEST_COMPILER\033[0m : "; echo $(var_TEST_COMPILER)
	@printf "\033[4mvar_TEST_NAME\033[0m : "; echo $(var_TEST_NAME)
	@printf "\033[4mvar_TEST_FLAG\033[0m : "; echo $(var_TEST_FLAG)

################
## Test rules ##
################
run_test:	re
	ls
	$(var_TEST_COMPILER) -o $(var_TEST_NAME) $(var_TEST) $(var_TEST_FLAG)
	@./$(var_TEST_NAME) || true
	@make --no-print-directory fclean

.PHONY:	\
	all \
	$(var_NAME) \
	clean \
	fclean \
	re \
	show_info \
	show_var \
	run_test
