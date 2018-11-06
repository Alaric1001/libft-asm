# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Rules.mk                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asenat <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/22 11:06:56 by asenat            #+#    #+#              #
#    Updated: 2018/11/06 15:32:15 by asenat           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TEST_CFLAGS	:= -I. -g -c -o
TEST_LFLAGS	:= -L./ -lfts
TEST_FILES	:=	ft_bzero.c \
				ft_strcat.c \
				single_char_functions.c \
				ft_strlen.c
				
CURR_DIR		:= tests
TEST_OBJECTS	:= $(addprefix $(CURR_DIR)/$(OBJECT_DIR)/, $(TEST_FILES:.c=.o))
RUN_TEST_RULES	:= $(addprefix test_, $(TEST_FILES:.c=))

TEST_FILES		:= $(addprefix $(CURR_DIR)/, $(TEST_FILES))
TEST_TARGETS	:= $(TEST_FILES:.c=)
TEST_OBJ_DIR	:= $(CURR_DIR)/$(OBJECT_DIR)

OBJ_DIRS 	+= $(TEST_OBJ_DIR)

.PRECIOUS: $(TEST_TARGETS) $(TEST_OBJECTS)
.PHONY: test_all
test_all: $(RUN_TEST_RULES)

.PHONY: clear-tests
clear-tests:
	rm -rf $(TEST_OBJ_DIR)
	rm -f $(TEST_TARGETS)

test_%: all $(TEST_OBJ_DIR) $(CURR_DIR)/%
	$(eval FAIL := $(shell $(addprefix $(CURR_DIR)/, $*) > $*.out; $(ECHO) $$?))
	@if [ $(FAIL) -gt 0 ]; \
	then \
		$(ECHO) "["$(RED)KO$(RESET)"] -" $*; \
		cat $*.out; \
	else \
		$(ECHO)  "["$(GREEN)OK$(RESET)"] -" $*; \
	fi
	@rm -f $*.out

$(CURR_DIR)/%: $(CURR_DIR)/$(OBJECT_DIR)/%.o $(NAME)
	$(C_CC) $(TEST_LFLAGS) -o $@ $< $(OBJECTS)

$(CURR_DIR)/$(OBJECT_DIR)/%.o: $(CURR_DIR)/%.c
	$(C_CC) $(TEST_CFLAGS) -c -o $@ $<

$(TEST_OBJ_DIR):
	mkdir $@
