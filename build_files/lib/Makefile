##
## EPITECH PROJECT, 2025
## build_files - lib - Makefile
## File description:
## make the lib
##

##########
## info ##
##########
info_NAME	=	lib
info_VERSION	=	v0.0.1
info_LAST_UPDATE	=	2025-11-27 15:51:13.323668
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
	@printf "\033[4mvar_NAME\033[0m : "; echo $(var_NAME)
