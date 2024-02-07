NAME = rush-02

CC = cc
CFLAGS = -Wall -Wextra -Werror

BUILD_DIR = ./build
SRC_DIRS = ./src
DEPS_DIRS = ./deps

SRCS = $(shell find $(SRC_DIRS) -name '*.c')
OBJS = $(SRCS:$(SRC_DIRS)/%.c=$(BUILD_DIR)/%.o)
DEPS = $(shell find $(DEPS_DIRS) -name '*.h')


all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $@

$(BUILD_DIR)/%.o: $(SRC_DIRS)/%.c $(DEPS)
	mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR)

fclean:	clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re