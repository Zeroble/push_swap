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
			memory_manager.o

BONUS_OBJ =	greedy_calcurater.o \
			greedy_rotate.o \
			greedy_sort.o \
			lst_create.o \
			lst_delete.o \
			lst_read.o \
			bonus_main.o \
			bonus_push_swap_utils_push.o \
			bonus_push_swap_utils_reverse_rotate.o \
			bonus_push_swap_utils_rotate.o \
			bonus_push_swap_utils_swap.o \
			utils_atoi.o \
			utils_init_values.o \
			utils_str.o \
			utils_min_max.o \
			utils_pivot_finder.o \
			utils_set_lst_first_elem_min.o \
			utils_split_push.o \
			memory_manager.o

CC = cc
CFLAGS = -Wall -Werror -Wextra
NAME = push_swap
BONUS_NAME = checker

all : ${NAME}

bonus : ${BONUS_NAME}

%.o : %.c
	${CC} ${CFLAGS} -c $? -o $@

# %.o : %.c
# 	${CC} -c $? -o $@

$(NAME) : ${MAIN_OBJ}
	${CC} $? -o ${NAME}

$(BONUS_NAME) : ${BONUS_OBJ}
	${CC} $? -o ${BONUS_NAME}

clean :
	rm -f ${MAIN_OBJ}
	rm -f ${BONUS_OBJ}

fclean : clean
	rm -f ${NAME}
	rm -f ${BONUS_NAME}

re : fclean all
rebonus : fclean bonus
