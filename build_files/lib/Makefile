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
info_VERSION	=	v0.1.0
info_LAST_UPDATE	=	2026-01-26 11:05:23.047
info_LIB_MAKER	=	Makefile

#########
## Var ##
#########
# ./test_lib #
TEST_PATH	=	test_lib
TEST	=	$(TEST_PATH)/test_base.c
TEST	+=	$(TEST_PATH)/test_str.c

# lib #
NAME	=	$(info_NAME)

# tests #
TEST_COMPILER	=	clang
TEST_NAME	=	_test
TEST_FLAG	=	\
	-I/twod_list/include/ \
	-I./lib/llist/include/ \
	-I./lib/str/include/ \
	-I./lib/test_lib/ \
	-L./ \
	-Wall \
	-Werror \
	--coverage \
	-lcriterion \
	-ltwod_list \
	-lllist \
	-lstr

#################
## Basic rules ##
#################
all:	$(NAME)

$(NAME):
	@make --no-print-directory -C twod_list all
	@make --no-print-directory -C llist all
	@make --no-print-directory -C str all
	@cp */*.a ./

clean:
	@make --no-print-directory -C twod_list clean
	@make --no-print-directory -C llist clean
	@make --no-print-directory -C str clean
	@rm -f $(TEST_NAME)
	@rm -f *.gc*

fclean: clean
	@make --no-print-directory -C twod_list fclean
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
	@printf "\033[4mNAME\033[0m : "; echo $(NAME)
	@printf "\033[4mTEST_COMPILER\033[0m : "; echo $(TEST_COMPILER)
	@printf "\033[4mTEST_NAME\033[0m : "; echo $(TEST_NAME)
	@printf "\033[4mTEST_FLAG\033[0m : "; echo $(TEST_FLAG)

################
## Test rules ##
################
test: re
	$(TEST_COMPILER) -o $(TEST_NAME) $(TEST) $(TEST_FLAG)

run_test:	test
	@./$(TEST_NAME) || true
	@make --no-print-directory fclean

.PHONY: \
	all \
	$(NAME) \
	clean \
	fclean \
	re \
	show_info \
	show_var \
	run_test
