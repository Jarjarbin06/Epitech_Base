##
## EPITECH PROJECT, 2025
## build_files - lib - str - Makefile
## File description:
## make the str lib
##

##########
## info ##
##########
info_NAME	=	str
info_VERSION	=	v0.0.1
info_LAST_UPDATE	=	2025-11-27 15:51:13.323668
info_LIB_MAKER	=	Makefile

#########
## var ##
#########
# ./source/ #
var_SRC_PATH	=	source
var_SRC	=	$(var_SRC_PATH)/source_file.c
var_SRC_OBJ	=	$(var_SRC:.c=.o)

# lib #
var_LIB_CREATOR	=	ar rc
var_LIB_NAME	=	$(info_NAME)

#################
## Basic rules ##
#################
all:	$(var_LIB_NAME)

$(var_LIB_NAME):
	@$(var_LIB_CREATOR) $(var_LIB_NAME).a $(var_SRC_OBJ)

clean:
	@rm -f $(var_SRC_PATH)/*.o

fclean:	clean
	@rm -f $(var_LIB_NAME)

re:	fclean all

show_info:
	@printf "\033[4minfo_NAME\033[0m : "; echo $(info_NAME)
	@printf "\033[4minfo_VERSION\033[0m : "; echo $(info_VERSION)
	@printf "\033[4minfo_LAST_UPDATE\033[0m : "; echo $(info_LAST_UPDATE)
	@printf "\033[4minfo_LIB_MAKER\033[0m : "; echo $(info_LIB_MAKER)

show_var:
	@printf "\033[4mvar_SRC_PATH\033[0m : "; echo $(var_SRC_PATH)
	@printf "\033[4mvar_SRC\033[0m : "; echo $(var_SRC)
	@printf "\033[4mvar_SRC_OBJ\033[0m : "; echo $(var_SRC_OBJ)
	@printf "\033[4mvar_LIB_CREATOR\033[0m : "; echo $(var_LIB_CREATOR)
	@printf "\033[4mvar_LIB_NAME\033[0m : "; echo $(var_LIB_NAME)
