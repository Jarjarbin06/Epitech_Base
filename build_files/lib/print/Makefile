##
## EPITECH PROJECT, 2025
## str - Makefile
## File description:
## make the str lib
##

##########
## info ##
##########
info_NAME	=	print
info_VERSION	=	v0.1.0
info_LAST_UPDATE	=	2026-01-26 11:05:23.047
info_LIB_MAKER	=	Makefile

#########
## var ##
#########
# ./sources/ #
SRC_PATH	=	.
SRC	=	\
	$(SRC_PATH)/base/base_is_inf_or_nan.c \
	$(SRC_PATH)/base/base_is_num.c \
	$(SRC_PATH)/base/base_my_get_nbr.c \
	$(SRC_PATH)/base/base_my_printf.c \
	$(SRC_PATH)/base/base_my_put_char.c \
	$(SRC_PATH)/base/base_my_put_str.c \
	$(SRC_PATH)/base/base_my_strlen.c \
	$(SRC_PATH)/conv/conv_display_conv.c \
	$(SRC_PATH)/conv/conv_err.c \
	$(SRC_PATH)/conv/conv_len_to_var.c \
	$(SRC_PATH)/conv/conv_put_char.c \
	$(SRC_PATH)/conv/conv_put_float.c \
	$(SRC_PATH)/conv/conv_put_g.c \
	$(SRC_PATH)/conv/conv_put_line.c \
	$(SRC_PATH)/conv/conv_put_modulo.c \
	$(SRC_PATH)/conv/conv_put_nbr.c \
	$(SRC_PATH)/conv/conv_put_nbr_base.c \
	$(SRC_PATH)/conv/conv_put_pointer.c \
	$(SRC_PATH)/conv/conv_put_scientific.c \
	$(SRC_PATH)/conv/conv_put_str.c \
	$(SRC_PATH)/conv/conv_stderr.c \
	$(SRC_PATH)/flag/flag_err.c \
	$(SRC_PATH)/flag/flag_get_flag.c \
	$(SRC_PATH)/flag/flag_get_hashtag.c \
	$(SRC_PATH)/flag/flag_get_plus.c \
	$(SRC_PATH)/flag/flag_get_plus.c \
	$(SRC_PATH)/flag/flag_get_precision.c \
	$(SRC_PATH)/flag/flag_get_space.c \
	$(SRC_PATH)/len_mod/len_mod_err.c
SRC_OBJ	=	$(SRC:.c=.o)

# lib #
LIB_CREATOR	=	ar rc
LIB_NAME	=	lib$(info_NAME)

#################
## Basic rules ##
#################
all:	$(LIB_NAME)

$(LIB_NAME):	$(SRC_OBJ)
	$(LIB_CREATOR) $(LIB_NAME).a $(SRC_OBJ)

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
