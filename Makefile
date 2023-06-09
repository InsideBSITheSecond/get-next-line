# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llegrand <llegrand@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/20 14:22:16 by llegrand          #+#    #+#              #
#    Updated: 2023/06/20 13:42:50 by llegrand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC := cc
CCARGS := #-Wall -Werror -Wextra

AR := ar
ARARGS := -crs

SRCS := get_next_line.c get_next_line_utils.c

OBJS := $(SRCS:.c=.o)

NAME := gnl.a

$(NAME) : $(OBJS)
	$(AR) $(ARARGS) $(NAME) $(OBJS)

%.o : %.c
	$(CC) $(CCARGS) -Iincludes -c $< -o ${<:.c=.o}

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

all : $(NAME)

re : fclean all

test : main.c
	reset
	gcc -I. -fdiagnostics-color=always -g3 $(SRCS) main.c -D BUFFER_SIZE=$(bs) -o main
	valgrind --leak-check=full --show-leak-kinds=all ./main $(file)

reset :
	reset

catgirl :
	@echo "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣀⣠⣤⣤⣶⣤⣤"
	@echo "⠀⠀⠀⠀⠀⠀⠀⠀⢀⣀⣤⣤⣤⣤⣄⣀⣀⣀⣀⣀⣀⣠⣴⠶⠶⠟⣛⣛⣛⣛⣛⣛⣻⠶⢶⣦⣤⣤⣶⣶⣾⣿⣿⢿⡿⣿⡻⢶⣣⡽"
	@echo "⠀⠀⠀⠀⠀⠀⠀⢀⣾⣻⣭⡵⣭⣳⣽⢿⣿⡿⣟⡿⣭⢷⡶⣛⡿⣻⣭⣻⣭⣯⡽⣹⡞⣽⢯⡞⣽⣫⢟⣻⢿⣷⣿⣻⣽⣳⢽⣫⢷⣹"
	@echo "⠀⠀⠀⠀⠀⠀⢀⣾⣿⣿⡼⣳⢳⣧⣿⣻⡭⣟⡵⣯⠽⠞⠃⠉⢉⢀⣀⣀⠀⠀⠀⠉⠉⠓⠻⠞⣧⢯⢯⡽⣞⢮⢯⣟⡷⣽⡞⣧⢟⣧"
	@echo "⠀⠀⠀⠀⠀⠀⢠⣿⣿⣽⣾⡽⢯⡽⣎⡷⡽⢚⣩⡴⢖⣚⡛⣹⡩⠯⠉⠉⠛⠙⠛⠛⠒⠶⠤⣄⡀⠉⠓⢿⡼⣫⢷⣹⢾⣹⡽⣞⡽⣺"
	@echo "⠀⠀⠀⠀⠀⠀⢸⣿⡿⣾⡳⣽⢫⢷⠝⣡⠞⠋⠀⠀⠀⣠⡟⠁⠀⠀⠀⠀⠀⢰⠀⠀⠀⠀⠀⠀⠉⠙⠦⣄⡉⠻⣞⢧⣯⢳⡽⣎⡷⢯"
	@echo "⠀⠀⠀⠀⠀⠀⢸⣿⡿⡷⣝⣧⡿⣡⠞⠁⠀⠀⠀⠀⣜⡟⠀⠀⠀⠀⠀⠀⠀⢸⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⢦⡈⢻⡼⣏⢷⡻⣼⢯"
	@echo "⠀⠀⠀⠀⠀⠀⣾⣿⣹⢟⣵⣾⠞⠁⠀⠀⠀⠀⠀⣜⡿⠀⠀⠀⠀⠀⠀⠀⠀⡸⠀⠀⠀⠀⠀⢠⠀⠀⠀⠀⠀⠀⠙⢦⡙⣞⢯⣳⢯⣞"
	@echo "⠀⠀⠀⠀⠀⢰⣿⡏⣯⣟⣾⠋⠀⠀⠀⠀⠀⠀⡸⣽⡇⢀⠇⠀⠀⠀⠀⠀⠀⡇⠀⠀⠀⠀⠀⠘⡄⠀⠀⠀⠀⠀⠀⠈⢳⡌⢯⣗⢯⣞"
	@echo "⠀⠀⠀⠀⠀⢼⡿⢸⣧⡿⡁⠀⠀⠀⠀⠀⠀⣰⣿⣹⣧⣸⠀⠀⠀⠀⠀⠀⠀⣧⣠⣄⣀⣀⡀⠀⢻⡀⠀⠀⠀⠀⠀⠀⢀⢻⡜⣞⡯⣞"
	@echo "⠀⠀⠀⠀⠀⣾⣧⡿⢋⡺⠁⠀⠀⠀⣠⠴⣻⠟⢱⢹⡇⢻⠀⠀⠀⠀⠀⠀⠀⣿⡄⠀⠀⠈⠉⠙⢺⣇⡀⠀⠀⠀⠀⠀⠈⡆⢻⣼⣳⢯"
	@echo "⠀⠀⠀⢤⣼⣟⣍⣦⠟⠁⠀⠀⠀⠐⣡⡾⠋⠀⠘⡌⣷⢻⠀⠀⠀⠀⠀⠀⠀⢸⣷⡀⠀⠀⠀⠀⢸⣷⠈⠢⠀⠀⠀⠀⠀⢹⠸⣷⢟⡾"
	@echo "⠀⠀⠀⢠⣿⢯⣿⠋⠀⠀⠀⠀⢠⡞⠃⠀⠀⢀⠀⡘⠼⣿⡷⣄⡀⠀⠀⠀⠀⠈⣧⠻⣦⠀⠀⠀⡸⢾⠀⠀⠀⠀⠀⠀⠀⠸⡀⢽⡾⣿"
	@echo "⠀⠀⠀⣾⢯⣿⠃⠀⢀⠀⠠⠀⣼⢦⣠⣴⣾⣭⣯⣭⡇⠈⢻⣌⡛⠳⠶⢤⣄⣀⣹⣟⣚⣻⣦⡤⣃⣿⡄⠀⠀⠀⠀⠀⠀⠀⡇⡝⣷⣿"
	@echo "⠀⠀⣸⣯⣿⡏⠀⣠⡇⠀⠄⢳⣿⣿⣿⣿⣿⠿⠿⠿⠷⠀⠀⠀⠈⠉⠉⠒⠒⠣⣿⣿⣿⣿⣿⣿⣿⣿⣄⣠⡆⠀⠀⢀⠀⠠⡇⢻⣼⣿"
	@echo "⠀⣰⡿⣼⣿⣧⢫⣱⠃⠠⠀⢀⣿⢋⠍⠤⢂⠦⠂⡀⠄⠀⠀⠀⠀⠀⠀⠀⠀⣀⠠⡀⠤⡉⡉⢛⢻⡿⢿⠋⡆⠀⠀⠄⡀⢸⠁⡈⣿⣿"
	@echo "⢰⣿⡳⣿⣽⢿⣷⡞⢰⠀⠁⣾⡇⡊⠤⠑⠂⠠⠁⡀⠄⠲⢧⣀⡠⠶⠤⠶⠞⠋⢀⠐⡐⠠⠉⢆⣾⠃⢀⡜⠇⠀⢈⠀⡀⡾⠀⠄⣿⣿"
	@echo "⣿⡿⣱⣿⣯⣿⡿⣁⢾⠀⢁⢻⣧⡀⠐⠈⠀⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠠⠀⠠⣁⣬⣾⡯⡚⢥⠻⠀⢀⢂⠀⣰⠇⢈⠀⣿⣿"
	@echo "⣿⣷⡝⣿⣿⣷⣦⡷⣿⠀⠠⢸⣙⢻⣦⣄⣀⣀⣂⣀⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀⣀⡠⢤⣚⣴⠟⣜⠩⡖⠁⡀⢂⡼⣰⢿⡀⢀⣼⣿⣿"
	@echo "⠈⢻⣿⣼⣯⣿⣽⣿⡿⣧⣀⠈⢮⠹⣟⠛⣛⢛⣛⣛⡛⠻⠿⣷⡿⣿⣿⣿⡿⡿⣷⢷⣾⣽⣷⣾⣶⣭⣴⣶⢾⠿⣛⢭⣿⣷⣿⡿⣟⣾"
	@echo "⠀⠀⢈⣿⡿⢛⣥⣿⢃⣼⠿⣷⠾⣷⢿⡿⣝⡯⣞⡽⣛⣷⣱⣿⣿⣿⢳⢧⣻⡵⣏⡿⡼⢶⢯⣝⡻⢿⣿⣿⣦⣷⣾⣻⣾⢿⣽⣻⢿⣽"
	@echo "⢀⣴⡿⢋⣴⣿⣿⡏⣾⣝⣻⡼⣻⡝⣮⢟⡾⣱⢯⣳⢟⣼⣿⣿⢯⡷⣏⣟⡶⣏⡷⣽⣹⣛⣮⢏⣟⠷⣮⡙⢿⣟⡿⣿⣯⣿⢯⣿⢯⣿"
	@echo "⣿⠟⣰⣿⢫⣿⣾⣗⢯⡞⣵⣏⡷⣽⢫⡾⡽⣭⢷⣯⡿⣻⣿⣟⣿⢿⣼⣣⢿⡜⣷⣣⢯⣳⠽⡾⣭⢟⡾⣹⢷⣍⠻⣷⣟⡿⣿⣯⣿⣻"
	@echo "⢃⡾⢿⣜⢯⣿⢾⣿⣣⣟⣳⢾⣱⢯⣏⣷⣻⣾⣟⠟⣽⢯⣿⣿⣯⡿⣷⡽⣺⠽⣖⣯⢳⣏⠿⣵⣛⡾⣹⡽⣎⣟⡷⣜⢻⣿⣽⣻⡾⣿"
	@echo "⣸⢻⣝⡮⢯⣿⢿⣽⣷⢯⣾⢷⣻⣾⢯⣿⣽⠗⣍⣾⢟⢺⣿⣞⣿⣽⣟⣿⢯⣛⡷⣚⣯⢞⣻⡵⣫⣞⢷⣹⡽⢮⣝⢯⣧⡹⣷⡿⣽⣿"

.PHONY : clean fclean all re 
