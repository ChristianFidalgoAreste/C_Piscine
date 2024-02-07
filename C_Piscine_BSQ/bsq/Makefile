NAME = bsq

CC = cc
CFLAGS = -Wall -Wextra -Werror

BUILD_DIR = ./build
SRC_DIRS = ./src
DEPS_DIRS = ./inc

SRCS = ./src/atoi.c ./src/calculate_solution.c ./src/free_memory.c ./src/ft_malloc.c ./src/generic_utils.c ./src/info_map.c ./src/main.c ./src/map_conditions.c ./src/maps_helper.c ./src/read_from_input.c ./src/square_helper.c ./src/str_utils.c ./src/use_args.c
OBJS = $(SRCS:$(SRC_DIRS)/%.c=$(BUILD_DIR)/%.o)
DEPS = $(SRCS:$(SRC_DIRS)/%.c=$(BUILD_DIR)/%.d) 

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $@

$(BUILD_DIR)/%.o: $(SRC_DIRS)/%.c
	mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -MMD -I ./inc -c $< -o $@

clean:
	rm -rf $(BUILD_DIR)

fclean:	clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

-include $(DEPS)
