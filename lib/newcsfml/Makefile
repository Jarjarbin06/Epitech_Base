##
## EPITECH PROJECT, 2025
## NCSFML - New C Simple Fast Multimedia Library
## File description:
## •
## NSFML is a lightweight wrapper over CSFML that simplifies usage
## while reducing low-level flexibility for easier game development.
## •
## Version: ncsfml-v0.2.9
## Author: Jarjarbin06
## Licence: GPL v3
## •
## This library is inspired by SFML/CSFML and is designed for
## educational and game-development purposes.
## •
## It provides higher-level abstractions over CSFML to reduce
## boilerplate code and enforce safer usage patterns.
## •
## WARNING:
## This is NOT the original SFML/CSFML library.
## It is a custom implementation layer built on top of CSFML.
##


###############################################################################
# META
###############################################################################

info_NAME	=	newcsfml
info_VERSION	=	0.2.9
info_LAST_UPDATE	=	2026/06/03 10h
info_LIB_MAKER	=	Makefile


###############################################################################
# CONFIG
###############################################################################

CC	=	clang

DEBUG	?=	false

CFLAGS_BASE	=	-Wall -Wextra -Werror -MMD -MP  -fdata-sections -ffunction-sections
CFLAGS_DEBUG	=	-g3 -O0
CFLAGS_RELEASE	=	-O3 -march=native -mtune=native -fno-plt

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
	$(AR) $(LIB_NAME) $(OBJ)
	$(RANLIB) $(LIB_NAME)


# -----------------------------------------------------------------------------
# CLEAN RULES
# -----------------------------------------------------------------------------
clean:
	$(RM) $(sort $(shell find $(SRC_PATH) -type f -name "*.o"))
	$(RM) $(sort $(shell find $(SRC_PATH) -type f -name "*.d"))

fclean:	clean
	rm -f $(LIB_NAME)

re:	fclean all


###############################################################################
# DEBUG HELPERS
###############################################################################

show_info:
	echo "NAME: $(info_NAME)"
	echo "VERSION: $(info_VERSION)"
	echo "LAST UPDATE: $(info_LAST_UPDATE)"
	echo "LIB MAKER: $(info_LIB_MAKER)"

show_var:
	echo "SRC: $(SRC)"
	echo "OBJ: $(OBJ)"
	echo "LIB: $(LIB_NAME)"


###############################################################################
# SAFETY / PHONY
###############################################################################

.SILENT:	clean fclean show_info show_var
.PHONY:	all clean fclean re show_info show_var

-include $(SRC_OBJ:.o=.d) $(MAIN_OBJ:.o=.d) $(TEST_OBJ:.o=.d)
