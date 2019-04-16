# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbrangie <lbrangie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/10 15:58:04 by lbrangie          #+#    #+#              #
#    Updated: 2019/02/28 14:17:57 by xmazella         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
##                                   TARGET                                   ##
################################################################################
NAME				=		libft.a

################################################################################
##                                   SOURCES                                  ##
################################################################################
# ============================== DIRECTORIES ============================== #
SRCS_DIR			=		srcs/
SRCS_DIR_LIBFT		=		libft/
SRCS_DIR_GNL		=		gnl/

# ================================= FILES ================================= #
FILES_LIBFT			=		ft_abs.c				\
							ft_atoi.c				\
							ft_atol.c				\
							ft_atoll.c				\
							ft_bzero.c				\
							ft_factorial.c			\
							ft_fibonacci.c			\
							ft_isalnum.c			\
							ft_isalpha.c			\
							ft_isascii.c			\
							ft_isblank.c			\
							ft_ischarset.c			\
							ft_iscntrl.c			\
							ft_isdigit.c			\
							ft_isgraph.c			\
							ft_islower.c			\
							ft_isneg.c				\
							ft_isprime.c			\
							ft_isprint.c			\
							ft_ispunct.c			\
							ft_isspace.c			\
							ft_isupper.c			\
							ft_isxdigit.c			\
							ft_itoa.c				\
							ft_itoa_base.c			\
							ft_lstadd.c				\
							ft_lstdel.c				\
							ft_lstdelone.c			\
							ft_lstiter.c			\
							ft_lstmap.c				\
							ft_lstnew.c				\
							ft_memalloc.c			\
							ft_memccpy.c			\
							ft_memchr.c				\
							ft_memcmp.c				\
							ft_memcpy.c				\
							ft_memdel.c				\
							ft_memmove.c			\
							ft_memprnt.c			\
							ft_memset.c				\
							ft_nextprime.c			\
							ft_numlen.c				\
							ft_numlen_base.c		\
							ft_pgcd.c				\
							ft_pow.c				\
							ft_ppcm.c				\
							ft_putchar.c			\
							ft_putchar_endl.c		\
							ft_putchar_endl_fd.c	\
							ft_putchar_fd.c			\
							ft_putfile.c			\
							ft_putfile_fd.c			\
							ft_putnbr.c				\
							ft_putnbr_endl.c		\
							ft_putnbr_endl_fd.c		\
							ft_putnbr_fd.c			\
							ft_putstr.c				\
							ft_putstr_endl.c		\
							ft_putstr_endl_fd.c		\
							ft_putstr_fd.c			\
							ft_puttab.c				\
							ft_puttab_fd.c			\
							ft_sqrt.c				\
							ft_str_isalnum.c		\
							ft_str_isalpha.c		\
							ft_str_isascii.c		\
							ft_str_isblank.c		\
							ft_str_iscntrl.c		\
							ft_str_isdigit.c		\
							ft_str_isgraph.c		\
							ft_str_islower.c		\
							ft_str_isprint.c		\
							ft_str_ispunct.c		\
							ft_str_isspace.c		\
							ft_str_isupper.c		\
							ft_str_isxdigit.c		\
							ft_str_tolower.c		\
							ft_str_toupper.c		\
							ft_strcapitalize.c		\
							ft_strcat.c				\
							ft_strchr.c				\
							ft_strclr.c				\
							ft_strcmp.c				\
							ft_strcpy.c				\
							ft_strcprg.c			\
							ft_strcspn.c			\
							ft_strdel.c				\
							ft_strdup.c				\
							ft_strequ.c				\
							ft_striter.c			\
							ft_striteri.c			\
							ft_strjoin.c			\
							ft_strlcat.c			\
							ft_strlen.c				\
							ft_strmap.c				\
							ft_strmapi.c			\
							ft_strncat.c			\
							ft_strncmp.c			\
							ft_strncpy.c			\
							ft_strndup.c			\
							ft_strnequ.c			\
							ft_strnew.c				\
							ft_strnlen.c			\
							ft_strnstr.c			\
							ft_strpbrk.c			\
							ft_strprg.c				\
							ft_strrchr.c			\
							ft_strrev.c				\
							ft_strsplit.c			\
							ft_strspn.c				\
							ft_strstr.c				\
							ft_strsub.c				\
							ft_strtok.c				\
							ft_strtrim.c			\
							ft_strusplit.c			\
							ft_tabdel.c				\
							ft_tablen.c				\
							ft_tolower.c			\
							ft_toupper.c

FILES_GNL			=		get_next_line.c


# ================================ SOURCES ================================ #
SRCS_LIBFT			=		$(addprefix $(SRCS_DIR_LIBFT), $(FILES_LIBFT))
SRCS_GNL			=		$(addprefix $(SRCS_DIR_GNL), $(FILES_GNL))
SRCS				=		$(addprefix $(SRCS_DIR), $(SRCS_LIBFT)) \
							$(addprefix $(SRCS_DIR), $(SRCS_GNL))


################################################################################
##                                   OBJECTS                                  ##
################################################################################
# ============================== DIRECTORIES ============================== #
OBJS_DIR			=		objs/
OBJS_DIR_LIBFT		=		libft/
OBJS_DIR_GNL		=		gnl/

# ================================ OBJECTS ================================ #
OBJS_LIBFT			=		$(addprefix $(OBJS_DIR_LIBFT), $(FILES_LIBFT:.c=.o))
OBJS_GNL			=		$(addprefix $(OBJS_DIR_GNL), $(FILES_GNL:.c=.o))
OBJS				=		$(addprefix $(OBJS_DIR), $(OBJS_LIBFT)) \
							$(addprefix $(OBJS_DIR), $(OBJS_GNL))


################################################################################
##                                  COMPILING                                 ##
################################################################################
# ============================== COMPILATOR =============================== #
CC					=		gcc
CFLAGS				+=		-Wall -Wextra -Werror
	
# =============================== INCLUDES ================================ #
INC_DIR				=		includes/
INC_FILE			=		libft.h					\
							get_next_line.h
INC_COMP			=		-I$(INC_DIR)

# =============================== LIBRARIES =============================== #
LIB_NAME			=		ft
LIB_PATH			=		./lib$(LIB_NAME)
LIB_COMP			=		-Llib$(LIB_NAME) -l$(LIB_NAME)
LIB_ARCV			=		lib$(LIB_NAME).a
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
	@mkdir -p $@/$(OBJS_DIR_LIBFT)
	@mkdir -p $@/$(OBJS_DIR_GNL)

$(NAME)				:		$(OBJS_DIR) $(OBJS)
	@$(AR) $@ $(OBJS) 
	@$(RAN) $@

clean				:
	@$(RM_DIR) $(OBJS_DIR)

fclean				:		clean
	@$(RM) $(NAME)

re					:
	@$(MAKESLV) . fclean
	@$(MAKESLV) . all

norme 				:		$(INC_DIR) $(SRCS_DIR)
	@norminette $^ | grep -B 1 "Warning\|Error" || true

print-%				:
	@echo $($*)

.PHONY				:		all clean fclean re start norme
