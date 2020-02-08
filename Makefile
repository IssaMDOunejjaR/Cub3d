# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iounejja <iounejja@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/16 18:14:13 by iounejja          #+#    #+#              #
#    Updated: 2020/02/03 13:34:07 by iounejja         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=	test
SRCS= 	*.c \
		utils/*/*.c
OBJS=	$(SRCS:.c=.o)
FLAG= -Wall -Wextra -Werror
IMLX= -lmlx -framework OpenGl -framework AppKit

all:	$(NAME)

$(NAME):	$(OBJS)
	ar rcs $(NAME) $(OBJ)

%.o : %.c
	gcc -c $< -o $@ -I includes/

clean:	rm -f *.a

fclean: clean

re: fclean all