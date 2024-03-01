##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## my_radar
##

NAME	=	my_radar

SRC	=	my_radar.c \
		free.c \
		init/init.c \
		init/init_corners.c \
		init/init_buttons.c \
		init/texts.c \
		buttons/buttons_menu.c \
		buttons/buttons_my_files.c \
		buttons/buttons_modes.c \
		parsing/parsing.c \
		parsing/list_towers.c \
		move/move.c \
		move/move2.c \
		move/move_storm.c \
		update/update.c \
		update/update_planes.c \
		draw/draw_planes.c \
		draw/draw_towers.c \
		draw/draw_storm.c \
		draw/draw_texts.c \
		draw/draw.c \
		collisions/collision.c \
		collisions/collision2.c \
		event/event.c \
		event/event_mouse_button.c \
		event/event_mouse_button2.c \
		event/change_activation.c \
		event/restart.c \
		realist_mode/realist_mode.c \
		my_lib/tools.c \
		my_lib/my_putnbr.c \
		my_lib/my_int_to_str.c \
		my_lib/my_strcmp.c \
		my_lib/my_strdup.c \
		my_lib/my_strcat.c \

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-Werror -Wall -Wextra

CPPFLAGS	=	-lcsfml-graphics -lcsfml-system -lcsfml-window \
				-lcsfml-audio -lm -Iincludes

all:	$(NAME)

$(NAME):	$(OBJ)
	@$(CC) -o $(NAME) $(OBJ) $(CPPFLAGS)

clean:
	@$(RM) *~
	@$(RM) $(OBJ)

fclean:	clean
	@$(RM) $(NAME)

re: fclean all
