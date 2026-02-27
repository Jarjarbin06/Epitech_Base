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
info_VERSION	=	v0.1.3
info_LAST_UPDATE	=	2026/02/18 16:56
info_LIB_MAKER	=	Makefile

#########
## Var ##
#########
DO_VALGRIND	=	false
DO_SANITIZE	=	false
CC	=	clang
CFLAGS	=	 \
	-Wall \
	-Wextra

# ./test_lib #
RUN_PATH	=	main_test.c
TEST_PATH	=	test_lib
TEST_BASE	=	$(TEST_PATH)/test_base.c
TEST_PRINT	=	$(TEST_PATH)/test_print.c
TEST_UTILS	=	$(TEST_PATH)/test_utils.c
TEST_TWODLIST	=	$(TEST_PATH)/test_twodlist.c
TEST_LLIST	=	$(TEST_PATH)/test_llist.c
TEST_STR	=	$(TEST_PATH)/test_str.c

# lib #
NAME	=	$(info_NAME)

# tests #
RUN_COMPILER	=	$(CC)
RUN_NAME	=	run
RUN_FLAGS	=	\
	-I./lib/newcsfml/includes/ \
	-I./lib/twodlist/includes/ \
	-I./lib/llist/includes/ \
	-I./lib/str/includes/ \
	-I./lib/print/includes/ \
	-I./lib/utils/includes/ \
	-I./lib/test_lib/ \
	-L./ \
	-lnewcsfml \
	-ltwodlist \
	-lllist \
	-lstr \
	-lprint \
	-lutils \
	-g

ifeq ($(DO_SANITIZE), true)
RUN_FLAGS	+=	-fsanitize=address
endif

TEST_COMPILER	=	$(CC)
TEST_NAME_TWODLIST	=	test_twodlist
TEST_NAME_LLIST	=	test_llist
TEST_NAME_STR	=	test_str
TEST_NAME_PRINT	=	test_print
TEST_NAME_UTILS	=	test_utils
TEST_FLAG_NEWCSFML	=	\
	-lcsfml-graphics \
	-lcsfml-window \
	-lcsfml-system
TEST_FLAG	=	\
	$(RUN_FLAGS) \
	--coverage \
	-lcriterion

#################
## Basic rules ##
#################
all:	$(NAME)

$(NAME):
	-@make --no-print-directory -C newcsfml CC=$(CC) all
	-@make --no-print-directory -C twodlist CC=$(CC) all
	-@make --no-print-directory -C llist CC=$(CC) all
	-@make --no-print-directory -C str CC=$(CC) all
	-@make --no-print-directory -C print CC=$(CC) all
	-@make --no-print-directory -C utils CC=$(CC) all
	@cp */*.a ./

clean:
	@make --no-print-directory -C newcsfml clean
	@make --no-print-directory -C twodlist clean
	@make --no-print-directory -C llist clean
	@make --no-print-directory -C str clean
	@make --no-print-directory -C print clean
	@make --no-print-directory -C utils clean
	@rm -f $(TEST_NAME_TWODLIST)
	@rm -f $(TEST_NAME_LLIST)
	@rm -f $(TEST_NAME_STR)
	@rm -f $(TEST_NAME_PRINT)
	@rm -f $(TEST_NAME_UTILS)
	@rm -f *.gc*

fclean: clean
	@make --no-print-directory -C newcsfml fclean
	@make --no-print-directory -C twodlist fclean
	@make --no-print-directory -C llist fclean
	@make --no-print-directory -C str fclean
	@make --no-print-directory -C print fclean
	@make --no-print-directory -C utils fclean
	@rm -f *.a
	@rm -f $(RUN_NAME)

re: fclean all

run: re
	@$(RUN_COMPILER) -o $(RUN_NAME) $(RUN_PATH) $(RUN_FLAGS) $(CFLAGS) $(TEST_FLAG_NEWCSFML)

ifeq ($(DO_VALGRIND), true)
run_run: run
	@valgrind --leak-check=full -s ./$(RUN_NAME)
	@make --no-print-directory fclean
else
run_run: run
	./$(RUN_NAME)
	@make --no-print-directory fclean
endif

show_info:
	@printf "\033[4minfo_NAME\033[0m : "; echo $(info_NAME)
	@printf "\033[4minfo_VERSION\033[0m : "; echo $(info_VERSION)
	@printf "\033[4minfo_LAST_UPDATE\033[0m : "; echo $(info_LAST_UPDATE)
	@printf "\033[4minfo_LIB_MAKER\033[0m : "; echo $(info_LIB_MAKER)

show_var:
	@printf "\033[4mNAME\033[0m : "; echo $(NAME)
	@printf "\033[4mTEST_COMPILER\033[0m : "; echo $(TEST_COMPILER)
	@printf "\033[4mTEST_NAME_TWODLIST\033[0m : "; echo $(TEST_NAME_TWODLIST)
	@printf "\033[4mTEST_NAME_LLIST\033[0m : "; echo $(TEST_NAME_LLIST)
	@printf "\033[4mTEST_NAME_STR\033[0m : "; echo $(TEST_NAME_STR)
	@printf "\033[4mTEST_NAME_PRINT\033[0m : "; echo $(TEST_NAME_PRINT)
	@printf "\033[4mTEST_NAME_UTILS\033[0m : "; echo $(TEST_NAME_UTILS)
	@printf "\033[4mTEST_FLAG\033[0m : "; echo $(TEST_FLAG)

################
## Test rules ##
################
test: re
	-$(TEST_COMPILER) -o $(TEST_NAME_TWODLIST) $(TEST_BASE) $(TEST_TWODLIST) $(TEST_FLAG) $(CFLAGS)
	-$(TEST_COMPILER) -o $(TEST_NAME_LLIST) $(TEST_BASE) $(TEST_LLIST) $(TEST_FLAG) $(CFLAGS)
	-$(TEST_COMPILER) -o $(TEST_NAME_STR) $(TEST_BASE) $(TEST_STR) $(TEST_FLAG) $(CFLAGS)
	-$(TEST_COMPILER) -o $(TEST_NAME_PRINT) $(TEST_BASE) $(TEST_PRINT) $(TEST_FLAG) $(CFLAGS)
	-$(TEST_COMPILER) -o $(TEST_NAME_UTILS) $(TEST_BASE) $(TEST_UTILS) $(TEST_FLAG) $(CFLAGS)

ifeq ($(DO_VALGRIND), true)
test_run:	test
	@printf "\033[4mTWODLIST\033[0m\n"
	-@valgrind --leak-check=full --show-leak-kinds=all -s ./$(TEST_NAME_TWODLIST)
	@printf "\033[4mLLIST\033[0m\n"
	-@valgrind --leak-check=full --show-leak-kinds=all -s ./$(TEST_NAME_LLIST)
	@printf "\033[4mSTR\033[0m\n"
	-@valgrind --leak-check=full --show-leak-kinds=all -s ./$(TEST_NAME_STR)
	@printf "\033[4mPRINT\033[0m\n"
	-@valgrind --leak-check=full --show-leak-kinds=all -s ./$(TEST_NAME_PRINT)
	@printf "\033[4mUTILS\033[0m\n"
	-@valgrind --leak-check=full --show-leak-kinds=all -s ./$(TEST_NAME_UTILS)
	@make --no-print-directory fclean

else
test_run:	test
	@printf "\033[4mTWODLIST\033[0m\n"
	-@./$(TEST_NAME_TWODLIST)
	@printf "\033[4mLLIST\033[0m\n"
	-@./$(TEST_NAME_LLIST)
	@printf "\033[4mSTR\033[0m\n"
	-@./$(TEST_NAME_STR)
	@printf "\033[4mPRINT\033[0m\n"
	-@./$(TEST_NAME_PRINT)
	@printf "\033[4mUTILS\033[0m\n"
	-@./$(TEST_NAME_UTILS)
	@make --no-print-directory fclean

endif

.PHONY: \
	all \
	clean \
	fclean \
	re \
	run \
	show_info \
	show_var \
	run_test
