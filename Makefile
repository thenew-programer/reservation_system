CC = cc
RM = rm -rf
CFLAGS = -Wall -Werror -Wextra -I ${HEADER}

HEADER = ./includes/
SRCS_DIR = ./srcs
SRCS = $(wildcard ${SRCS_DIR}/*.c)
OBJS_DIR = ./objs
OBJS = $(patsubst ${SRCS_DIR}/%.c, ${OBJS_DIR}/%.o, ${SRCS})

TARGET = youcode

${TARGET}: ${OBJS}
	@echo "Linking..."
	${CC} -o $@ $^
	@echo "Compiled Succesfully"

${OBJS_DIR}/%.o : ${SRCS_DIR}/%.c
	@echo "Compliling..."
	@mkdir -p ${OBJS_DIR}
	${CC} ${CFLAGS} -c $< -o $@

all: ${TARGET}

clean:
	${RM} ${OBJS_DIR}

fclean: clean
	${RM} ${TARGET}

re: fclean all

.PHONY: all clean fclean re
