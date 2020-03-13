# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iounejja <iounejja@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/16 18:14:13 by iounejja          #+#    #+#              #
#    Updated: 2020/03/10 18:37:48 by iounejja         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	Cub3D.a
EXE  =  cub3D
SRCS = 	cast_rays.c \
		check_errors.c \
		floor_and_ceil.c \
		game_utils.c \
		info_conf.c \
		parse_info.c \
		parse_map.c \
		player_info.c \
		player_move.c \
		rotate_came.c \
		sprite_info.c \
		tables_utils.c \
		utils_config.c \
		cast_sprite.c \
		cast_map.c \
		data_cast_map.c \
		check_map.c \
		bmp.c \
		utils/gnl/get_next_line.c \
		utils/gnl/get_next_line_utils.c \
		utils/libft/ft_strlen.c \
		utils/libft/ft_split.c \
		utils/libft/ft_isdigit.c \
		utils/libft/ft_isalpha.c \
		utils/libft/ft_atoi.c \
		utils/libft/ft_strncmp.c \
		utils/libft/ft_putstr_fd.c \
		utils/libft/ft_strcmp.c
BSRC =	cast_rays_bonus.c \
		check_errors_bonus.c \
		floor_and_ceil_bonus.c \
		game_utils_bonus.c \
		info_conf_bonus.c \
		parse_info_bonus.c \
		parse_map_bonus.c \
		player_info_bonus.c \
		player_move_bonus.c \
		rotate_came_bonus.c \
		sprite_info_bonus.c \
		tables_utils_bonus.c \
		utils_config_bonus.c \
		cast_sprite_bonus.c \
		cast_map_bonus.c \
		data_cast_map_bonus.c \
		check_map_bonus.c \
		bmp_bonus.c \
		utils/gnl/get_next_line.c \
		utils/gnl/get_next_line_utils.c \
		utils/libft/ft_strlen.c \
		utils/libft/ft_split.c \
		utils/libft/ft_isdigit.c \
		utils/libft/ft_isalpha.c \
		utils/libft/ft_atoi.c \
		utils/libft/ft_strncmp.c \
		utils/libft/ft_putstr_fd.c \
		utils/libft/ft_strcmp.c
OBJS =	$(SRCS:.c=.o)
BOBJ =	$(BSRC:.c=.o)
FLAG =	-Wall -Wextra -Werror
IMLX =	-lmlx -framework OpenGl -framework AppKit

all:	$(NAME)

$(NAME): $(OBJS)
		ar rcs $(NAME) $(OBJS)
		gcc $(FLAG) $(IMLX) cub3d.c $(NAME) -o $(EXE) -I includes/

bonus: $(BOBJ)
		ar rcs $(NAME) $(BOBJ)
		gcc $(FLAG) $(IMLX) cub3d_bonus.c $(NAME) -o $(EXE) -I includes/

%.o : %.c
	gcc -c $(FLAG) $< -o $@ -I includes/

clean:
	rm -f *.o
	rm -f utils/*/*.o

fclean: clean
	rm -f $(NAME)

re: fclean all