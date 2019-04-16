/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_typedefs.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrangie <lbrangie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 02:18:28 by lbrangie          #+#    #+#             */
/*   Updated: 2019/02/21 11:14:13 by lbrangie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_TYPEDEFS_H
# define ASM_TYPEDEFS_H

/*
**		STRUCT S_FILE_H:
**	The struct s_file_h is a meta-structure of the doubly linked list where
**	we store the source file
**	-	The fd integer is the file descriptor of the source file we will get and
**		the file descriptor of the file we will write into.
**	- 	The file_name string is the name of the source file without the ending
**		EXT_SRC string.
**	-	The dst_file string is the name of the destination file. It is composed
**		of file_name and EXT_DST at the end.
**	-	The head pointer to a struct s_file is a pointer to the begining of
**		the doubly linked list where the source file is stored.
**	-	The tail pointer to a struct s_file is a pointer to the end of the
**		doubly linked list where the source file is stored.
*/

typedef struct	s_file_h
{
	int				fd;
	char			*file_name;
	char			*dst_name;
	char			opts;
	char			nb_opts;
	struct s_file	*head;
	struct s_file	*tail;
}				t_file_h;

/*
**		STRUCT S_FILE:
**	The struct s_file is a link of the doubly linked list where we store the
**	source file.
**	-	The line string is a line of the source file.
**	-	The header pointer to a struc s_file_h is the reference of the
**		meta-structure of the doubly linked list.
**	-	The next pointer to a struc s_file is a pointer to the next link of
**		the list.
**	-	The prev pointer to a struc s_file is a pointer to the previous link
**		of the list.
*/

typedef struct	s_file
{
	char			*line;
	unsigned int	num_line;
	struct s_file_h	*header;
	struct s_file	*next;
	struct s_file	*prev;
}				t_file;

/*
**		STRUCT S_OP:
**	The struct s_op contains the informations of each instructions that can be
**	encoded in the destination file.
**	-	The name string is the name of the instruction.
**	-	The nb_args integer is the number of arguments that a given instruction
**		requires.
**	-	The args integer array describes the type of each argument of the
**		instruction can take.
**	-	The opcode integer is the code of the instruction to encode in the
**		destination file.
**	-	The ocp integer is the parameter encode byte. This byte determines the
**		type of the parameters of the instruction.
**	-	The dir_size integer determines the length of the direct parameters of
**		the instruction. This integer can have a value of 2 or 4, depending of
**		the instruction.
*/

typedef struct	s_op
{
	char			*name;
	size_t			nb_args;
	int				args[4];
	int				opcode;
	int				ocp;
	int				dir_size;
}				t_op;

/*
**		STRUCT S_HEADER:
**	The struct s_header contains every informations about the header of the
**	destination file.
**	-	The magic unsigned int is the first value writen in the destination
**		file. Its value is define by COREWAR_EXEC_MAGIC in asm_defines.h.
**	-	The name string is the name of the programm that writen in the
**		destination file. The LEN_NAME value is define in asm_defines.h. The
**		four characters added to LEN_NAME are always null-characters and padd
**		the end of the string.
**	-	The size unsigned int is the length of the programm writen in the
**		destination file.
**	-	The comm string is the commentaire of the programm writen in the
**		destination file. The LEN_COMM value is define in asm_defines.h. The
**		four characters added to LEN_COMM are always null-characters and padd
**		the end of the string.
*/

typedef struct	s_header
{
	unsigned int	magic;
	char			name[LEN_NAME + 4];
	unsigned int	size;
	char			comm[LEN_COMM + 4];
}				t_header;

/*
**		STRUCT S_PROG:
**	The struct s_prog contains every information about the programm writen in
**	the destination file.
**	-	cf: STRUCT S_HEADER upward for more information about the header struct
**		s_header.
*/

typedef struct	s_label
{
	char			*name;
	unsigned int	num_line;
	int				addr;
	struct s_label	*next;
}				t_label;

typedef struct	s_arg
{
	char			*str;
	int				type;
	int				size;
	int				label;
	struct s_arg	*next;
}				t_arg;

typedef struct	s_inst
{
	char			**tab_args;
	unsigned int	num_line;
	int				addr;
	struct s_op		infos;
	struct s_arg	*arg;
	struct s_inst_h	*header;
	struct s_inst	*next;
	struct s_inst	*prev;
}				t_inst;

typedef struct	s_inst_h
{
	struct s_inst	*head;
	struct s_inst	*tail;
}				t_inst_h;

typedef struct	s_prog
{
	struct s_header	header;
	struct s_label	*label;
	struct s_inst_h	inst_h;
	unsigned int	num_line;
}				t_prog;

typedef enum	e_opts
{
	ASM_OPTS_B,
	ASM_OPTS_P
}				t_opts;

typedef enum	e_error_code
{
	ASM_NO_ERROR,
	ASM_ERROR_USAGE,
	ASM_ERROR_EMPTY,
	ASM_ERROR_MALLOC,
	ASM_ERROR_NAME,
	ASM_ERROR_SYNTAX,
	ASM_ERROR_COMMAND,
	ASM_ERROR_PNAME,
	ASM_ERROR_PCOMM,
	ASM_ERROR_ARGS,
	ASM_ERROR_LABEL,
	ASM_ERROR_OPEN,
	ASM_ERROR_WRITE,
	ASM_ERROR_CLOSE
}				t_error_code;

#endif
