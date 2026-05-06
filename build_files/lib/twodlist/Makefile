##
## EPITECH PROJECT, 2025
## 2list - Makefile
## File description:
## make the 2list lib
##

##########
## info ##
##########
info_NAME	=	twodlist
info_VERSION	=	v0.1.3
info_LAST_UPDATE	=	2026/03/30 13:24
info_LIB_MAKER	=	Makefile


#########
## VAR ##
#########
# Paths #
SRC_PATH        = sources
INCLUDE_PATH    = includes

# Sources #
SRC     = $(shell find $(SRC_PATH) -type f -name "*.c")
SRC_OBJ = $(SRC:.c=.o)

# Includes #
INCLUDES = $(shell find $(INCLUDE_PATH) -type d -printf '-I%p ')

# Lib #
LIB_CREATOR	=	ar rc
LIB_NAME	=	lib$(info_NAME)

# Compilation #
CC	=	clang
CFLAGS	=	 \
	-Wall \
	-Wextra
CPPFLAGS	=	$(INCLUDES)

#################
## BASIC RULES ##
#################
all:	$(LIB_NAME)

$(LIB_NAME):	$(SRC_OBJ)
	$(LIB_CREATOR) $(LIB_NAME).a $(SRC_OBJ)
	ranlib $(LIB_NAME).a

clean:
	@rm -f $(SRC_OBJ)

fclean:	clean
	@rm -f $(LIB_NAME).a

re:	fclean all

show_info:
	@printf "\033[4minfo_NAME\033[0m : "; echo $(info_NAME)
	@printf "\033[4minfo_VERSION\033[0m : "; echo $(info_VERSION)
	@printf "\033[4minfo_LAST_UPDATE\033[0m : "; echo $(info_LAST_UPDATE)
	@printf "\033[4minfo_LIB_MAKER\033[0m : "; echo $(info_LIB_MAKER)

show_var:
	@printf "\033[4mSRC_PATH\033[0m : "; echo $(SRC_PATH)
	@printf "\033[4mSRC\033[0m : "; echo $(SRC)
	@printf "\033[4mSRC_OBJ\033[0m : "; echo $(SRC_OBJ)
	@printf "\033[4mLIB_CREATOR\033[0m : "; echo $(LIB_CREATOR)
	@printf "\033[4mLIB_NAME\033[0m : "; echo $(LIB_NAME)

.PHONY:	\
	all \
	clean \
	fclean \
	re \
	show_info \
	show_var
