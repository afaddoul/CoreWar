NAME = asm

FLAGS = -Wextra -Wall -Werror -g 
FILES = srcs/main.c \
	srcs/check_fextension.c \
	srcs/read_file.c \
	srcs/ft_vrealloc.c \
	srcs/frontend_analysis.c  \
	srcs/ft_assembler.c  \
	srcs/line_parser.c  \
	srcs/ft_cmd_parser.c  \
	srcs/op.c  \
	srcs/code_parser.c  \
	srcs/syntax_analys.c  \
	srcs/semantic_analys.c  \
	srcs/ft_nodepop.c  \
	srcs/ft_backend_analysis.c  \
	srcs/champ_exe_code.c  \

OBJ = $(FILES:.c=.o)

LIBFT = ./libft/libft.a

INCLUDES = includes/

all: $(NAME)

$(NAME) : $(LIBFT) $(OBJ) $(HEADER_FILES)
	gcc $(FLAGS) $(OBJ) $(LIBFT) -o $(NAME)

$(OBJ) : %.o : %.c
	gcc $(FLAGS)  $< -o $@ -c -I $(INCLUDES) -I $(INCLUDES)

$(LIBFT) :
	make -C ./libft/

clean :
	@rm -rf $(OBJ)
	@make clean -C ./libft

fclean : clean
	@rm -rf $(NAME)
	@make fclean -C ./libft

re : fclean all

.PHONY : clean fclean re $(LIBFT)
