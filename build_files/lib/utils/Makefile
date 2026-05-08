##
## EPITECH PROJECT, 2025
## Lib Utils - Makefile
## File description:
## Generic per-library build system (main-makefile compatible)
##

###############################################################################
# META
###############################################################################

info_NAME	=	utils
info_VERSION	=	v0.1.4
info_LAST_UPDATE	=	2026/05/08 18h
info_LIB_MAKER	=	Makefile


###############################################################################
# CONFIG
###############################################################################

CC	=	clang

DEBUG	?=	false

CFLAGS_BASE	=	-Wall -Wextra -Werror -MMD -MP
CFLAGS_DEBUG	=	-g3 -O0
CFLAGS_RELEASE	=	-O3 -march=native

ifeq ($(DEBUG), true)
CFLAGS	=	$(CFLAGS_BASE) $(CFLAGS_DEBUG)
else
CFLAGS	=	$(CFLAGS_BASE) $(CFLAGS_RELEASE)
endif

CPPFLAGS	=	-Iincludes


###############################################################################
# PATHS
###############################################################################

SRC_PATH	=	sources
INC_PATH	=	includes


###############################################################################
# SOURCES
###############################################################################

SRC	=	$(sort $(shell [ -d "$(SRC_PATH)" ] && find $(SRC_PATH) -type f -name "*.c"))
OBJ	=	$(SRC:.c=.o)


###############################################################################
# OUTPUT
###############################################################################

LIB_NAME	=	lib$(info_NAME).a
AR	=	ar rc
RANLIB	=	ranlib


###############################################################################
# RULES
###############################################################################

all:	$(LIB_NAME)


# -----------------------------------------------------------------------------
# ARCHIVE BUILD
# -----------------------------------------------------------------------------
$(LIB_NAME):	$(OBJ)
	$(AR) $@ $^
	$(RANLIB) $@


# -----------------------------------------------------------------------------
# CLEAN RULES
# -----------------------------------------------------------------------------
clean:
	@rm -f $(OBJ)
	@rm -f $(DEP)

fclean:	clean
	@rm -f $(LIB_NAME)

re:	fclean all


###############################################################################
# DEBUG HELPERS
###############################################################################

show_info:
	@echo "NAME: $(info_NAME)"
	@echo "VERSION: $(info_VERSION)"
	@echo "LAST UPDATE: $(info_LAST_UPDATE)"
	@echo "LIB MAKER: $(info_LIB_MAKER)"

show_var:
	@echo "SRC: $(SRC)"
	@echo "OBJ: $(OBJ)"
	@echo "LIB: $(LIB_NAME)"


###############################################################################
# SAFETY / PHONY
###############################################################################
.PHONY:	all clean fclean re show_info show_var

-include $(SRC_OBJ:.o=.d) $(MAIN_OBJ:.o=.d) $(TEST_OBJ:.o=.d)
