NAME = push_swap
BONUS_NAME = checker
SRC_DIR = src
BONUS_DIR = bonus
COMMON_DIR = common
LIBFT_DIR = libft

CC := cc
CFLAGS := -Wall -Wextra -Werror -I$(SRC_DIR) -I$(COMMON_DIR) -g
LDFLAGS := -L$(LIBFT_DIR) -lft

COMMON_SOURCES := $(COMMON_DIR)/common_args_and_checks.c $(COMMON_DIR)/common_free_and_errors.c $(COMMON_DIR)/common_operations1.c $(COMMON_DIR)/common_operations2.c
MAIN_SOURCES := $(SRC_DIR)/push_swap.c $(SRC_DIR)/operations_a.c $(SRC_DIR)/operations_b.c $(SRC_DIR)/operations_together.c $(SRC_DIR)/check_order.c $(SRC_DIR)/find_highest_lowest.c $(SRC_DIR)/find_new_position.c $(SRC_DIR)/calculations_ab.c $(SRC_DIR)/calculations_ba.c $(SRC_DIR)/calculate_combined_rotations.c $(SRC_DIR)/rotate_stacks.c $(SRC_DIR)/rotation_cases_single.c $(SRC_DIR)/rotation_cases_together.c
BONUS_SOURCES := $(BONUS_DIR)/checker.c $(BONUS_DIR)/operations_checker.c

COMMON_OBJECTS := $(patsubst $(COMMON_DIR)/%.c, $(COMMON_DIR)/%.o, $(COMMON_SOURCES))
MAIN_OBJECTS := $(patsubst $(SRC_DIR)/%.c, $(SRC_DIR)/%.o, $(MAIN_SOURCES))
BONUS_OBJECTS := $(patsubst $(BONUS_DIR)/%.c, $(BONUS_DIR)/%.o, $(BONUS_SOURCES))

.PHONY: all bonus clean fclean re

all: $(NAME)

$(NAME): $(MAIN_OBJECTS) $(COMMON_OBJECTS) $(LIBFT_DIR)/libft.a
	@echo "Linking $(NAME)"
	$(CC) $(MAIN_OBJECTS) $(COMMON_OBJECTS) -o $(NAME) $(LDFLAGS)

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJECTS) $(COMMON_OBJECTS) $(LIBFT_DIR)/libft.a
	@echo "Linking $(BONUS_NAME)"
	$(CC) $(BONUS_OBJECTS) $(COMMON_OBJECTS) -o $(BONUS_NAME) $(LDFLAGS)

$(COMMON_DIR)/%.o: $(COMMON_DIR)/%.c $(COMMON_DIR)/push_swap.h
	@echo "Compiling $<"
	$(CC) $(CFLAGS) -MMD -c $< -o $@

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c $(SRC_DIR)/push_swap.h
	@echo "Compiling $<"
	$(CC) $(CFLAGS) -MMD -c $< -o $@

$(BONUS_DIR)/%.o: $(BONUS_DIR)/%.c $(BONUS_DIR)/push_swap.h
	@echo "Compiling $<"
	$(CC) $(CFLAGS) -MMD -c $< -o $@

$(LIBFT_DIR)/libft.a:
	$(MAKE) -C $(LIBFT_DIR) all

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(RM) $(COMMON_OBJECTS) $(COMMON_OBJECTS:.o=.d) $(MAIN_OBJECTS) $(MAIN_OBJECTS:.o=.d) $(BONUS_OBJECTS) $(BONUS_OBJECTS:.o=.d)

fclean: clean
	$(RM) $(NAME) $(BONUS_NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

-include $(COMMON_OBJECTS:.o=.d)
-include $(MAIN_OBJECTS:.o=.d)
-include $(BONUS_OBJECTS:.o=.d)
