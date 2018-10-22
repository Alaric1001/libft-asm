# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asenat <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/22 10:52:15 by asenat            #+#    #+#              #
#    Updated: 2018/10/22 13:49:22 by asenat           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

## Standard things
#
.SUFFIXES:
NAME		:= libfts.a
CC 			:= nasm
C_CC		:= clang
AR			:= ar
CFLAGS		:= -f macho64
LFLAGS		:= rc
RM			:= rm -f
OBJECT_DIR	:= obj
COMP		:= $(CC) $(CFLAGS) -o
ifeq ($(shell uname -s), Darwin)
ECHO		:= echo
else
ECHO		:= echo -e
endif
#

## Sources directories
#
TEST_DIRS	:= tests
SRC_DIRS	:= src
#

## Colors
#
BLUE		:= "\033[34m"
GREEN		:= "\033[32m"
RED		:= "\033[31m"
RESET		:= "\033[0m"
PNAME		:= $(BLUE)$(NAME)$(RESET)
#

.PHONY: all
all: $(NAME)

## Including sources files
#
include $(patsubst %, %/Sources.mk, $(SRC_DIRS))
#

OBJ_DIRS	:= $(patsubst %, %/obj, $(SRC_DIRS))

$(NAME): $(OBJ_DIRS) $(OBJECTS) $(IMPL_OBJS)
	$(AR) $(LFLAGS) $(NAME) $(OBJECTS) $(IMPL_OBJS)
	@$(ECHO) $(PNAME)$(GREEN) "linking complete"$(RESET)

## Including compilation rules
#
include $(patsubst %, %/Rules.mk, $(SRC_DIRS))
#

%/$(OBJECT_DIR):
	mkdir $@

## Including tests
#
-include $(patsubst %, %/Rules.mk, $(TEST_DIRS))
#

.PHONY: clean
clean:
	@$(RM) -r $(OBJ_DIRS)
	@$(ECHO) "Objects directories removed"

.PHONY: fclean
fclean: clean
	@$(RM) $(NAME) $(TEST_TARGETS)
	@$(ECHO) $(NAME) "deleted"

.PHONY: re
re: fclean all

.PHONY: makedeps
makedeps:
	python3.7 ./gen_make_sources.py --source='.s' $(SRC_DIRS)
