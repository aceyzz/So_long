# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/21 08:25:32 by cedmulle          #+#    #+#              #
#    Updated: 2023/11/23 16:11:23 by cedmulle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ---------------------------------------------------------------------------- #
#                                 Variables                                    #
# ---------------------------------------------------------------------------- #
# ------ EXECUTABLES ------ #
NAME		= so_long
# ------ DIRECTORIES ------ #
INC			= inc/
OBJ_DIR		= obj/
# ----- SOURCES FILES ----- #
SRC_DIR		= src/
SRC			= $(wildcard $(SRC_DIR)*.c)
OBJ			= $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)so_long/%.o,$(SRC))
# ------- FT_PRINTF ------- #
PF_DIR		= $(INC)ft_printf/
PF_SRC		= $(wildcard $(PF_DIR)*.c)
PF_OBJ		= $(patsubst $(PF_DIR)%.c,$(OBJ_DIR)ft_printf/%.o,$(PF_SRC))
PF_LIB		= libftprintf.a
# ---------- GNL ---------- #
GL_DIR		= $(INC)get_next_line/
GL_SRC		= $(wildcard $(GL_DIR)*.c)
GL_OBJ		= $(patsubst $(GL_DIR)%.c,$(OBJ_DIR)get_next_line/%.o,$(GL_SRC))
GL_LIB		= libgnl.a
# ---------- MLX ---------- #
MX_DIR		= $(INC)mlx/
MX_LIB		= libmlx.a
# ------ COMPILATION ------ #
CC			= gcc
CFLAGS		= -Wall -Werror -Wextra -I
LDFLAGS		= -L./lib -lftprintf -lgnl
RM			= rm -f

# ---------------------------------------------------------------------------- #
#                                 Fonctions                                    #
# ---------------------------------------------------------------------------- #
# Règle générale ------------------------------------------------------------- #
all:
				@echo "\033[1;34mLoading...\033[0m"
				@$(MAKE) $(NAME) $(PF_LIB) $(GL_LIB) > /dev/null
				@echo "\033[1;36mObject files created\t\t√\033[0m"
				@echo "\033[1;36m\"$(NAME)\" compiled\t\t√\033[0m"
				@echo "\033[1;36m\"$(GL_LIB)\" compiled\t\t√\033[0m"
				@echo "\033[1;36m\"$(PF_LIB)\" compiled\t√\033[0m"
				@echo "\033[1;36m\"$(MX_LIB)\" compiled\t\t√\033[0m"

# Création de l'éxécutable client -------------------------------------------- #
$(NAME): 		$(OBJ) $(PF_LIB) $(GL_LIB) $(MX_LIB)
				@$(CC) $(CFLAGS) $(INC) $(OBJ) -o $(NAME) $(LDFLAGS)

# Création librairie ft_printf ----------------------------------------------- #
$(PF_LIB):		$(PF_OBJ)
				@ar rc $(PF_LIB) $(PF_OBJ)
				@ranlib $(PF_LIB)
				@mkdir -p ./lib/
				@mv $(PF_LIB) ./lib/
				
# Création librairie gnl ----------------------------------------------------- #
$(GL_LIB):		$(GL_OBJ)
				@ar rc $(GL_LIB) $(GL_OBJ)
				@ranlib $(GL_LIB)
				@mkdir -p ./lib/
				@mv $(GL_LIB) ./lib/

# Création librairie MLX ----------------------------------------------------- #
$(MX_LIB):
				@make -C $(MX_DIR) > /dev/null 2>&1

# Création des fichiers objets executables ----------------------------------- #
$(OBJ_DIR)so_long/%.o:	$(SRC_DIR)%.c 
				@mkdir -p $(@D)
				@$(CC) $(CFLAGS) $(INC) -c $< -o $@

# Création des fichiers objets printf ---------------------------------------- #
$(OBJ_DIR)ft_printf/%.o:	$(PF_DIR)%.c 
				@mkdir -p $(@D)
				@$(CC) $(CFLAGS) $(INC) -c $< -o $@

# Création des fichiers objets printf ---------------------------------------- #
$(OBJ_DIR)get_next_line/%.o:	$(GL_DIR)%.c 
				@mkdir -p $(@D)
				@$(CC) $(CFLAGS) $(INC) -c $< -o $@

# Suppression fichiers objets ------------------------------------------------ #
clean:
				@$(RM) -r $(OBJ_DIR)
				@echo "\033[1;35mObject files deleted \t\t√\033[0m"

# Suppression fichiers objets + éxécutables + librairie printf --------------- #
fclean: 		clean
				@$(RM) $(NAME)
				@$(RM) -r ./lib
				@make -C $(MX_DIR) clean
				@echo "\033[1;35m\"${NAME}\" deleted\t\t√\033[0m"
				@echo "\033[1;35m\"${GL_LIB}\" deleted\t\t√\033[0m"
				@echo "\033[1;35m\"${PF_LIB}\" deleted\t\t√\033[0m"
				@echo "\033[1;35m\"${MX_LIB}\" deleted\t\t√\033[0m"

# Suppression fichiers objets + éxécutables + librairie printf + recompile --- #
re: 			fclean all

# Bonus inclus dans les fichiers de base ------------------------------------- #
bonus:			all

.PHONY: 		start all clean fclean re
