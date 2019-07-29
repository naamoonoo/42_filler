FILL	=	hnam.filler
VISU	=	visualizer

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror -Iincludes -g -fsanitize=address

SRC		=	$(wildcard src/filler/*.c)
OBJ		=	$(patsubst src/filler/%.c, obj/filler/%.o, $(SRC))
SRC_V	=	$(wildcard src/visualizer/*.c)
OBJ_V	=	$(patsubst src/visualizer/%.c, obj/visualizer/%.o, $(SRC_V))

all		:	$(FILL) $(VISU)

obj/%.o	: 	src/%.c
			@$(CC) $(CFLAGS) $(OPTION) -c -o $@ $<

$(FILL)	:	obj $(OBJ)
			@cd lib && make
			@mv lib/libftprintf.a .
			@$(CC) -o $(FILL) $(CFLAGS) $(OBJ) libftprintf.a
			@echo "excutable file $(FILL) has been made"

$(VISU)	:	obj $(OBJ_V)
			@cd lib && make
			@mv lib/libftprintf.a .
			@$(CC) -o $(VISU) $(CFLAGS) $(OBJ_V) libftprintf.a -Iincludes -L framework/SDL2/lib/ -l SDL2-2.0.0
			@echo "excutable file $(VISU) has been made"

obj		:
			@mkdir obj
			@mkdir obj/filler
			@mkdir obj/visualizer

clean	:
			-cd lib && make clean
			-rm -rf obj

fclean	:	clean
			-rm -f $(FILL) $(VISU)
			-rm -f libftprintf.a

re		:	fclean $(FILL) $(VISU)

.PHONY	:	clean fclean re
