# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: egomez-g <egomez-g@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/05 12:19:14 by egomez-g          #+#    #+#              #
#    Updated: 2024/02/07 18:15:49 by egomez-g         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SOURCES =			pipex.c ft_strjoin.c ft_strncmp.c ft_split.c errors.c

SOURCES_BONUS =		pipex_bonus.c strjoin_bonus.c strncmp_bonus.c \
					split_bonus.c errors_bonus.c child_bonus.c \
					utils_bonus.c heredoc_bonus.c gnl_pipex_bonus.c \
					gnl_ut_pipex_bonus.c

OBJECTS = $(SOURCES:.c=.o)
OBJECTS_BONUS = $(SOURCES_BONUS:.c=.o)

CFLAGS = -Wall -Wextra -Werror
REMOVE = rm -f
CC = gcc
CHACHE = .cache

all : $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(OBJECTS) $(CFLAGS) -o $(NAME)

bonus: $(CHACHE)

$(CHACHE) : $(OBJECTS_BONUS)
	touch $(CHACHE)
	@rm -rf $(OBJECTS)
	@rm -rf $(NAME)
	$(CC) $(OBJECTS_BONUS) $(CFLAGS) -o $(NAME)

clean:
	$(REMOVE) $(OBJECTS)
	$(REMOVE) $(OBJECTS_BONUS)

fclean: clean
	$(REMOVE) $(NAME)

re: fclean all

.PHONY: clean fclean re 