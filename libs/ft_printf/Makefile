# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbrangie <lbrangie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/09 13:29:53 by lbrangie          #+#    #+#              #
#    Updated: 2018/11/21 16:24:43 by lbrangie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
##                                   TARGET                                   ##
################################################################################
NAME				=		libftprintf.a


################################################################################
##                                   SOURCES                                  ##
################################################################################
# ============================== DIRECTORIES ============================== #
SRCS_DIR			=		srcs/

# ================================= FILES ================================= #
FILES_PRINTF		=		ft_printf.c				\
							ft_vprintf.c			\
							ptf_buffer.c			\
							ptf_lltoa_base.c		\
							ptf_get_flags.c			\
							ptf_put_arbs.c			\
							ptf_put_bin.c			\
							ptf_put_char.c			\
							ptf_put_dec.c			\
							ptf_put_hex.c			\
							ptf_put_ldec.c			\
							ptf_put_loct.c			\
							ptf_put_ludec.c			\
							ptf_put_mhex.c			\
							ptf_put_oct.c			\
							ptf_put_ptr.c			\
							ptf_put_ret.c			\
							ptf_put_str.c			\
							ptf_put_udec.c			\
							ptf_put_wchar.c			\
							ptf_put_wstr.c			\
							ptf_select_cast.c		\
							ptf_singleton_colors.c	\
							ptf_singleton_hash.c	\
							ptf_utils_ctype_abs.c	\
							ptf_utils_len.c			\
							ptf_write_num.c


# ================================ SOURCES ================================ #
SRCS_PRINTF			=		$(addprefix $(SRCS_DIR), $(FILES_PRINTF))


################################################################################
##                                   OBJECTS                                  ##
################################################################################
# ============================== DIRECTORIES ============================== #
OBJS_DIR			=		objs/

# ================================ OBJECTS ================================ #
OBJS_PRINTF			=		$(addprefix $(OBJS_DIR), $(FILES_PRINTF:.c=.o))


################################################################################
##                                  COMPILING                                 ##
################################################################################
# ============================== COMPILATOR =============================== #
CC					=		gcc
CFLAGS				+=		-Wall -Wextra -Werror -O3
	
# =============================== INCLUDES ================================ #
INC_DIR				=		includes/
INC_FILE			=		ft_printf.h				\
							ft_printf_defines.h		\
							ft_printf_typedefs.h
INC_COMP			=		-I$(INC_DIR)

# =============================== LIBRARIES =============================== #
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
##                                    RULES                                   ##
################################################################################

all					:		$(NAME)

proper				:
	@$(MAKESLV) . all
	@$(MAKESLV) . clean
 
$(OBJS_DIR)%.o		:		$(SRCS_DIR)%.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(INC_COMP)

$(OBJS_DIR)			:
	@mkdir -p $@

$(LIB_PATH)$(LIB_ARCV)	:
	@$(MAKESLV) $(LIB_PATH) all

$(NAME)				:		$(OBJS_DIR) $(OBJS_PRINTF)
	@$(AR) $@ $(OBJS_PRINTF)
	@$(RAN) $@

clean				:
	@$(RM_DIR) $(OBJS_DIR)

fclean				:		clean
	@$(RM) $(NAME)

re					:
	@$(MAKESLV) . fclean
	@$(MAKESLV) . all

norme				:		$(INC_DIR) $(SRCS_DIR)
	@norminette $^ | grep -B 1 "Warning\|Error" || true

print-%				:
	@echo $($*)

.PHONY				:		all proper clean fclean re norme
