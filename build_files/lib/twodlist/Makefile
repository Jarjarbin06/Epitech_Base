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
info_VERSION	=	v0.1.0
info_LAST_UPDATE	=	2026-01-26 11:05:23.047
info_LIB_MAKER	=	Makefile

#########
## var ##
#########
# ./sources/ #
SRC_PATH	=	source
SRC	=	$(SRC_PATH)/twodlist.c
SRC_OBJ	=	$(SRC:.c=.o)

# lib #
LIB_CREATOR	=	ar rc
LIB_NAME	=	lib$(info_NAME)

#################
## Basic rules ##
#################
all:	$(LIB_NAME)

$(LIB_NAME):	$(SRC_OBJ)
	@$(LIB_CREATOR) $(LIB_NAME).a $(SRC_OBJ)

clean:
	@rm -f $(SRC_PATH)/*.o

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
