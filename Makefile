# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vsporer <vsporer@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/08/20 14:41:19 by vsporer           #+#    #+#              #
#    Updated: 2017/12/12 16:14:01 by vsporer          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 				lem_in
LIBFT =				libft/libft.a

C_RESET =			\033[0m
C_OK =				\033[32m
C_DEL =				\033[31m
C_SRC =				\033[44m
C_READ =			\033[35;44m
C_ALGO =			\033[33;44m
C_TOOLS =			\033[36;44m

PATH_LIBFT =		libft/
PATH_SRC =			src/
PATH_OBJ =			objs/
PATH_READ = 		$(PATH_SRC)map/
PATH_ALGO = 		$(PATH_SRC)algo/
PATH_TOOLS = 		$(PATH_SRC)tools/

CC =				gcc -Wall -Werror -Wextra
INC =				-I includes/ -I libft/includes/

SRC =				$(PATH_SRC)lem_in.c\
					$(PATH_SRC)lem_in_error.c

READ =				$(PATH_READ)read_map.c\
					$(PATH_READ)check_in.c

#ALGO =				$(PATH_ALGO)get_path.c\
#					$(PATH_ALGO)release_ants.c
#
TOOLS =				$(PATH_TOOLS)del_data.c\
					$(PATH_TOOLS)del_room.c\
					$(PATH_TOOLS)add_pipe.c\
					$(PATH_TOOLS)search_room.c\
					$(PATH_TOOLS)new_room.c

OBJ =				$(patsubst $(PATH_SRC)%.c, $(PATH_OBJ)%.o, $(SRC))\
					$(patsubst $(PATH_READ)%.c, $(PATH_OBJ)%.o, $(READ))\
					$(patsubst $(PATH_ALGO)%.c, $(PATH_OBJ)%.o, $(ALGO))\
					$(patsubst $(PATH_TOOLS)%.c, $(PATH_OBJ)%.o, $(TOOLS))

.PHONY: all clean fclean libft

all: libft $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	@echo "Compiling $@ ..."
	@$(CC) $(INC) $^ -o $@
	@echo "$(C_OK)Done !$(C_RESET)"

$(LIBFT): libft

libft:
	@cd $(PATH_LIBFT) && $(MAKE)

$(PATH_OBJ)%.o: $(PATH_SRC)%.c
	@echo "$(C_SRC)Compiling $< to $@$(C_RESET)"
	@mkdir -p $(@D)
	@$(CC) $(INC) -c $< -o $@

$(PATH_OBJ)%.o: $(PATH_READ)%.c
	@echo "$(C_READ)Compiling $< to $@$(C_RESET)"
	@mkdir -p $(@D)
	@$(CC) $(INC) -c $< -o $@

$(PATH_OBJ)%.o: $(PATH_ALGO)%.c
	@echo "$(C_ALGO)Compiling $< to $@$(C_RESET)"
	@mkdir -p $(@D)
	@$(CC) $(INC) -c $< -o $@

$(PATH_OBJ)%.o: $(PATH_TOOLS)%.c
	@echo "$(C_TOOLS)Compiling $< to $@$(C_RESET)"
	@mkdir -p $(@D)
	@$(CC) $(INC) -c $< -o $@

clean:
	@rm -rf $(PATH_OBJ)
	@cd $(PATH_LIBFT) && $(MAKE) clean
	@echo "$(C_DEL)Object files removed.$(C_RESET)"

fclean: clean
	@rm -f $(NAME)
	@rm -f $(LIBFT)
	@echo "$(C_DEL)$(NAME) and $(LIBFT) removed.$(C_RESET)"

test: all
	@echo "\\/\\/\\/\\/\\/\\/\\/BEGIN TEST\\/\\/\\/\\/\\/\\/\\/"
	@echo ""
	@./$(NAME) < map_test.txt
	@echo ""
	@echo "/\\/\\/\\/\\/\\/\\/\\END TEST/\\/\\/\\/\\/\\/\\/\\"

re: fclean all
