# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: slatchma <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/18 20:03:20 by slatchma          #+#    #+#              #
#    Updated: 2018/01/15 14:39:35 by slatchma    ###    #+. /#+    ###.fr      #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc -Wall -Wextra -Werror
FILES = ft_atoi ft_bzero ft_isalnum ft_isalpha ft_isascii ft_isdigit ft_isprint ft_lstaffich ft_lstcompt ft_lstend ft_lstfirst ft_lstnsearch ft_lstsearch ft_lstsupdel ft_memalloc ft_memccpy ft_memchr ft_memcmp ft_memcpy ft_memdel ft_memmove ft_memset ft_putchar_fd ft_putchar ft_putendl_fd ft_putendl ft_putnbr_fd ft_putnbr ft_putstr_fd ft_putstr ft_strcat ft_strchr ft_strclr ft_strcmp ft_strcpy ft_strdel ft_strdup ft_strequ ft_striter ft_striteri ft_strjoin ft_strlcat ft_strlen ft_strmap ft_strsupchr ft_strmapi ft_strncat ft_strncmp ft_strncpy ft_strnequ ft_strnew ft_strnstr ft_strrchr ft_strsplit ft_strstr ft_strsub ft_strtrim ft_tolower ft_toupper ft_itoa
FILESC = $(addsuffix .c, $(FILES))
FILESO = $(addsuffix .o, $(FILES))


all : $(NAME)

$(NAME) : $(FILESO)
	ar rc libft.a $(FILESO)
	ranlib libft.a

%.o: %.c
	$(CC) -o $@ -c $?

clean :
	/bin/rm -f $(FILESO)

fclean : clean
	/bin/rm -f a.out $(NAME)

re : fclean all
