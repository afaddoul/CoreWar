# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afaddoul <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/08 09:09:52 by afaddoul          #+#    #+#              #
#    Updated: 2020/03/12 21:15:49 by afaddoul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =libft.a

FLAGS = -Wall -Wextra -Werror

SRC = ft_atoi.c ft_bzero.c ft_digit_counter.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_lstadd.c ft_lstdel.c ft_lstdelone.c ft_lstiter.c ft_lstmap.c ft_lstnew.c ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memdel.c ft_memmove.c ft_memset.c ft_putchar.c ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c ft_strcat.c ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strdel.c ft_strdup.c ft_strequ.c ft_striter.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlen.c ft_strlowcase.c ft_strmap.c ft_strmapi.c ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strnequ.c ft_strnew.c ft_strnstr.c ft_strrchr.c ft_strrev.c ft_strsplit.c ft_strstr.c ft_strsub.c ft_strtrim.c ft_strupcase.c ft_swap.c ft_tolower.c ft_toupper.c ft_unsigned_nb_len.c ft_word_counter.c ft_atol.c ft_countof.c ft_dlstdel.c ft_dlstget.c ft_dlstnew.c ft_dlstpush.c ft_elemnew.c ft_getindex.c ft_htget.c ft_strclen.c ft_strndup.c ft_isulong.c ft_htnew.c ft_htentrynew.c ft_htinsert.c ft_htdel.c ft_htentrydel.c ft_dlstpop.c

OBJ = $(SRC:.c=.o)
INCLUDES = ../includes

all : $(NAME)

$(NAME) : $(OBJ)
	ar rc $(NAME) $(OBJ)

%.o : %.c $(includes)
	gcc $(FLAGS)  $< -o $@ -c  -I $(INCLUDES)

clean :
	@/bin/rm -f $(OBJ)
	@/bin/rm -f libft.h.gch

fclean : clean
	@/bin/rm -f $(NAME)

re : fclean all

.PHONY : clean fclean re
