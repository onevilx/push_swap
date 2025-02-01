# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yaboukir <yaboukir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/24 20:57:37 by yaboukir          #+#    #+#              #
#    Updated: 2025/02/01 21:38:13 by yaboukir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_PUSH_SWAP = mandatory/push_swap.c mandatory/ft_atoi.c mandatory/ft_helperfs1.c \
	mandatory/ft_helperfs2.c mandatory/ft_itoa.c mandatory/ft_parsing.c \
	mandatory/ft_push.c mandatory/ft_reverse_rotate.c mandatory/ft_rotate.c \
	mandatory/ft_fill.c mandatory/ft_sort_stack.c mandatory/ft_split.c \
	mandatory/ft_sort_three.c mandatory/ft_sorting.c mandatory/ft_swap.c \
	mandatory/struct_utils1.c mandatory/struct_utils2.c mandatory/valid_input.c \

SRCS_PUSH_SWAP_BONUS = bonus/ft_atoi_bonus.c bonus/ft_helperfs1_bonus.c \
	bonus/ft_helperfs2_bonus.c bonus/ft_itoa_bonus.c bonus/ft_parsing_bonus.c \
	bonus/ft_push_bonus.c bonus/ft_reverse_rotate_bonus.c bonus/ft_rotate_bonus.c \
	bonus/ft_fill_bonus.c bonus/ft_sort_stack_bonus.c bonus/ft_split_bonus.c \
	bonus/ft_sort_three_bonus.c bonus/ft_sorting_bonus.c bonus/ft_swap_bonus.c \
	bonus/struct_utils1_bonus.c bonus/struct_utils2_bonus.c bonus/valid_input_bonus.c \
	bonus/get_next_line_bonus.c bonus/checkerpro_bonus.c \

OBJS_PUSH_SWAP = $(SRCS_PUSH_SWAP:.c=.o)
OBJS_PUSH_SWAP_BONUS = $(SRCS_PUSH_SWAP_BONUS:.c=.o)

CC = cc
AR = ar r
RM = rm -f
CFLAGS = -Wall -Wextra -Werror
INCLUDE = mandatory/push_swap.h
INCLUDE_BONUS = bonus/push_swap_bonus.h
NAME_PUSH_SWAP = push_swap
NAME_PUSH_SWAP_BONUS = checker

all: $(NAME_PUSH_SWAP)

$(NAME_PUSH_SWAP): $(OBJS_PUSH_SWAP)
	$(CC) $(CFLAGS) $(OBJS_PUSH_SWAP) -o $(NAME_PUSH_SWAP)

bonus: $(NAME_PUSH_SWAP_BONUS)

$(NAME_PUSH_SWAP_BONUS): $(OBJS_PUSH_SWAP_BONUS)
	$(CC) $(CFLAGS) $(OBJS_PUSH_SWAP_BONUS) -o $(NAME_PUSH_SWAP_BONUS)

mandatory/%.o: mandatory/%.c $(INCLUDE)
	$(CC) $(CFLAGS) -c $< -o $@

bonus/%.o: bonus/%.c $(INCLUDE_BONUS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS_PUSH_SWAP) $(OBJS_PUSH_SWAP_BONUS)

fclean: clean
	$(RM) $(NAME_PUSH_SWAP) $(NAME_PUSH_SWAP_BONUS)

re: fclean all

.PHONY: clean fclean re all bonus
