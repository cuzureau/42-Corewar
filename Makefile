# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbrangie <lbrangie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/16 10:26:59 by lbrangie          #+#    #+#              #
#    Updated: 2019/03/10 12:17:58 by xmazella         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
##                                   TARGET                                   ##
################################################################################
NAME_ASM			=		asm
NAME_VM				=		corewar


################################################################################
##                                   SOURCES                                  ##
################################################################################
# ============================== DIRECTORIES ============================== #
SRCS_DIR			=		srcs/
SRCS_DIR_ASM		=		asm/
SRCS_DIR_VM			=		vm/

# ================================= FILES ================================= #
FILES_ASM			=		asm.c						\
							asm_add_arg.c				\
							asm_add_inst.c				\
							asm_add_label.c				\
							asm_check_label.c			\
							asm_del_data.c				\
							asm_error.c					\
							asm_get_file.c				\
							asm_get_header.c			\
							asm_get_prog.c				\
							asm_utils.c					\
							asm_write_output.c			\

FILES_VM			=		error_message.c				\
							execute_opcode.c			\
							fork_tools.c				\
							garbage_collector.c			\
							handle_death.c				\
							info_visu.c					\
							init.c						\
							interprete_arg.c			\
							load_champions.c			\
							load_opcodes_1.c			\
							load_opcodes_2.c			\
							load_opcodes_3.c			\
							load_opcodes_4.c			\
							load_tools.c				\
							loop.c						\
							main.c						\
							move_tools.c				\
							opcodes_1.c					\
							opcodes_2.c					\
							opcodes_3.c					\
							opcodes_4.c					\
							parse.c						\
							players_tools.c				\
							print_memory.c				\
							read_arg_by_code.c			\
							read_arg_by_size.c			\
							read_tools.c				\
							room_visu.c					\
							tools.c						\
							tools_2.c					\
							tools_parse.c				\
							tools_visu.c				\
							tools_visu2.c				\
							verify_args.c				\
							visu.c

# ================================ SOURCES ================================ #
SRCS_ASM_TMP		=		$(addprefix $(SRCS_DIR_ASM), $(FILES_ASM))
SRCS_ASM			=		$(addprefix $(SRCS_DIR), $(FILES_ASM))
SRCS_VM_TMP			=		$(addprefix $(SRCS_DIR_VM), $(FILES_VM))
SRCS_VM				=		$(addprefix $(SRCS_DIR), $(FILES_VM))


################################################################################
##                                   OBJECTS                                  ##
################################################################################
# ============================== DIRECTORIES ============================== #
OBJS_DIR			=		objs/
OBJS_DIR_ASM		=		asm/
OBJS_DIR_VM			=		vm/

# ================================ OBJECTS ================================ #
OBJS_ASM_TMP		=		$(addprefix $(OBJS_DIR_ASM), $(FILES_ASM:.c=.o))
OBJS_ASM			=		$(addprefix $(OBJS_DIR), $(OBJS_ASM_TMP))
OBJS_VM_TMP			=		$(addprefix $(OBJS_DIR_VM), $(FILES_VM:.c=.o))
OBJS_VM				=		$(addprefix $(OBJS_DIR), $(OBJS_VM_TMP))


################################################################################
##                                  COMPILING                                 ##
################################################################################
# ============================== COMPILATOR =============================== #
CC					=		gcc
CFLAGS				+=		-Wall -Wextra -Werror -O2

# =============================== INCLUDES ================================ #
INC_DIR				=		incs/
INC_FILE			=		asm.h					\
							asm_defines.h			\
							asm_typedefs.h			\
							vm.h					\
							vm_def.h				\
							vm_struct.h

INC_COMP			=		-I$(INC_DIR) -Ilibs/libft/includes -Ilibs/ft_printf/includes
INC_ASM				=		$(addprefix $(INC_DIR), $(INC_FILE))

# =============================== LIBRARIES =============================== #
LIB_DIR				=		libs/

LIBPTF_PATH			=		./$(LIB_DIR)ft_printf/
LIBPTF_SRC_NAME		=		$(shell make -C $(LIBPTF_PATH) print-SRCS)
LIBPTF_SRC			=		$(addprefix $(LIBPTF_PATH), $(LIBPTF_SRC_NAME))
LIBPTF_ARCV			=		$(LIBPTF_PATH)libftprintf.a

LIBFT_PATH			=		./$(LIB_DIR)libft/
LIBFT_SRC_NAME		=		$(shell make -C $(LIBFT_PATH) print-SRCS)
LIBFT_SRC			=		$(addprefix $(LIBFT_PATH), $(LIBFT_SRC_NAME))
LIBFT_ARCV			=		$(LIBFT_PATH)libft.a

AR					=		ar rc
RAN					=		ranlib

# ================================ SLAVES ================================= #
MAKESLV				=		make -C


################################################################################
##                                  DELETION                                  ##
################################################################################
RM					=		rm -f
RM_DIR				=		rm -rfd


################################################################################
##                                   DISPLAY                                  ##
################################################################################
# ================================ COLORS ================================= #
RED				=		\033[31m
GRN				=		\033[32m
BLU				=		\033[34m
WHT				=		\033[97m
CYN				=		\033[36m
MGT				=		\033[35m
YLW				=		\033[33m
BCK				=		\033[30m
LBLU			=		\033[94m
PRL				=		\033[38;5;55m
ORG				=		\033[38;5;202m
GRE				=		\033[90m
SLM				=		\033[38;5;203m

# ================================ FORMAT ================================= #
BOLD			=		\033[1m
DIM				=		\033[2m
UNDER			=		\033[4m
BLINK			=		\033[5m
HIDDEN			=		\033[8m
INVERT			=		\033[7m
ITALIC			=		\033[3m
EOF				=		\033[0m

# ============================== CHARACTERS =============================== #
CHECK			=		\\xE2\\x9C\\x94
CROSS			=		\\xE2\\x9C\\x98
HGLSS			=		\\xE2\\xA7\\x97
RAROW			=		\\xE2\\x9E\\x9C
COPYR			=		\\xC2\\xA9

# ================================ MACROS ================================= #
OK				=		$(GRN)$(CHECK)$(EOF)
KO				=		$(RED)$(CROSS)$(EOF)
WAIT			=		$(LBLU)$(HGLSS)$(EOF)
ARROW			=		$(LBLU)$(RAROW)$(EOF)
COFFE			=		\t  S\n\t$(UNDER)C[_]$(EOF)


################################################################################
##                                    RULES                                   ##
################################################################################

all					:		$(NAME_ASM) $(NAME_VM)

proper				:
	@$(MAKESLV) . all
	@$(MAKESLV) . clean




$(OBJS_DIR)			:
	@mkdir -p $@
	@printf "\t$(UNDER)$(BOLD)Created$(EOF) : $@/ $(OK)\n"
	@mkdir -p $@/$(OBJS_DIR_ASM)
	@printf "\t$(UNDER)$(BOLD)Created$(EOF) : $@/$(OBJS_DIR_ASM) $(OK)\n"
	@mkdir -p $@/$(OBJS_DIR_VM)
	@printf "\t$(UNDER)$(BOLD)Created$(EOF) : $@/$(OBJS_DIR_VM) $(OK)\n"



$(LIBFT_ARCV)		:		$(LIBFT_SRC)
	@printf "\t$(UNDER)$(BOLD)Creation$(EOF) $@ $(WAIT)\n\t\tPlease, wait..."
	@$(MAKESLV) $(LIBFT_PATH) all
	@printf "\033[K\r"
	@printf "\033[1A"
	@printf "\033[K\r"
	@printf "\t$(UNDER)$(BOLD)Archive created$(EOF) : $@ $(OK)\n"

$(LIBPTF_ARCV)		:		$(LIBPTF_SRC)
	@printf "\t$(UNDER)$(BOLD)Creation$(EOF) $@ $(WAIT)\n\t\tPlease, wait..."
	@$(MAKESLV) $(LIBPTF_PATH) all
	@printf "\033[K\r"
	@printf "\033[1A"
	@printf "\033[K\r"
	@printf "\t$(UNDER)$(BOLD)Archive created$(EOF) : $@ $(OK)\n"



$(OBJS_DIR)$(OBJS_DIR_VM)%.o		:		$(SRCS_DIR)$(SRCS_DIR_VM)%.c $(INC_ASM) Makefile
	@printf "\t$(UNDER)$(BOLD)Compiled$(EOF) : $@ $(OK)"
	@$(CC) $(CFLAGS) -o $@ -c $< $(INC_COMP)
	@printf "\033[2K\r"

$(NAME_VM)		:		$(OBJS_DIR) $(LIBFT_ARCV) $(LIBPTF_ARCV) $(OBJS_DIR) $(OBJS_VM)
	@$(CC) $(CFLAGS) -o $@ $(OBJS_VM) $(LIBPTF_ARCV) $(LIBFT_ARCV) $(INC_COMP) -lncurses
	@printf "\t$(UNDER)$(BOLD)Executable created$(EOF) : $@ $(OK)            \n"


$(OBJS_DIR)$(OBJS_DIR_ASM)%.o		:		$(SRCS_DIR)$(SRCS_DIR_ASM)%.c $(INC_ASM) Makefile
	@printf "\t$(UNDER)$(BOLD)Compiled$(EOF) : $@ $(OK)"
	@$(CC) $(CFLAGS) -o $@ -c $< $(INC_COMP)
	@printf "\033[2K\r"

$(NAME_ASM)		:		$(OBJS_DIR) $(LIBFT_ARCV) $(LIBPTF_ARCV) $(OBJS_DIR) $(OBJS_ASM)
	@$(CC) $(CFLAGS) -o $@ $(OBJS_ASM) $(LIBPTF_ARCV) $(LIBFT_ARCV) $(INC_COMP)
	@printf "\t$(UNDER)$(BOLD)Executable created$(EOF) : $@ $(OK)            \n"




clean				:
	@$(RM_DIR) $(OBJS_DIR)
	@printf "\t$(UNDER)$(BOLD)Removed$(EOF) : $(OBJS_DIR) $(OK)\n"
	@$(RM_DIR) $(OBJS_DIR)$(OBJS_DIR_ASM)
	@printf "\t$(UNDER)$(BOLD)Removed$(EOF) : $(OBJS_DIR)$(OBJS_DIR_ASM) $(OK)\n"
	@$(RM_DIR) $(OBJS_DIR)$(OBJS_DIR_VM)
	@printf "\t$(UNDER)$(BOLD)Removed$(EOF) : $(OBJS_DIR)$(OBJS_DIR_VM) $(OK)\n"
	@$(MAKESLV) $(LIBFT_PATH) clean
	@$(MAKESLV) $(LIBPTF_PATH) clean

fclean				:		clean
	@$(RM) $(NAME_ASM)
	@printf "\t$(UNDER)$(BOLD)Removed$(EOF) : $(NAME_ASM) $(OK)\n"
	@$(RM) $(NAME_VM)
	@printf "\t$(UNDER)$(BOLD)Removed$(EOF) : $(NAME_VM) $(OK)\n"
	@$(MAKESLV) $(LIBFT_PATH) fclean
	@$(MAKESLV) $(LIBPTF_PATH) fclean
	@$(RM_DIR) $(NAME_ASM).dSYM

re					:
	@$(MAKESLV) . fclean
	@$(MAKESLV) . all

norme				:		$(INC_DIR) $(SRCS_DIR)$(SRCS_DIR_ASM)
	@norminette $^ | grep -B 1 "Warning\|Error" || true
	@$(MAKESLV) $(LIBFT_PATH) clean
	@$(MAKESLV) $(LIBPTF_PATH) clean

print-%				:
	@echo $($*)

coffee				:
	@echo "Here's a cup of coffee\n$(COFFE)"
	
.PHONY				:		all proper clean fclean re norme coffee
