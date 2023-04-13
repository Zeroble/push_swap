MAIN_OBJ =	greedy_calcurater.o \
			greedy_rotate.o \
			greedy_sort.o \
			lst_create.o \
			lst_delete.o \
			lst_read.o \
			main.o \
			push_swap_utils_push.o \
			push_swap_utils_reverse_rotate.o \
			push_swap_utils_rotate.o \
			push_swap_utils_swap.o \
			utils_atoi.o \
			utils_init_values.o \
			utils_str.o \
			utils_min_max.o \
			utils_pivot_finder.o \
			utils_set_lst_first_elem_min.o \
			utils_split_push.o \

CC = cc
CFLAGS = -Wall -Werror -Wextra
NAME = push_swap

all : ${NAME}

%.o : %.c
	${CC} -c $? -o $@

$(NAME) : ${MAIN_OBJ}
	${CC} $? -o ${NAME}

clean :
	rm -f ${MAIN_OBJ}

fclean : clean
	rm -f ${NAME}

re : fclean all
