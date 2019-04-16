/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_defines.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrangie <lbrangie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 00:44:42 by lbrangie          #+#    #+#             */
/*   Updated: 2019/02/21 11:35:24 by lbrangie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_DEFINES_H
# define ASM_DEFINES_H

/*
**	Error messages
*/

# define ASM_MSG_USAGE			"usage: ./asm source_file.s ..."
# define AMS_MSG_EMPTY			"Error (asm): empty source file"
# define ASM_MSG_MALLOC			"Error (asm): malloc failed"
# define ASM_MSG_NAME			"Error (asm): invalid file name"
# define ASM_MSG_SYNTAX			"Error (asm): syntax error"
# define ASM_MSG_COMMAND		"Error (asm): invalid command string"
# define ASM_MSG_PNAME			"Error (asm): invalid or inexistant name"
# define ASM_MSG_PCOMM			"Error (asm): invalid or inexistant comment"
# define ASM_MSG_ARGS			"Error (asm): invalid parameters"
# define ASM_MSG_LABEL			"Error (asm): unknown label"
# define ASM_MSG_OPEN			"Error (asm): cannot open file properly"
# define AMS_MSG_WRITE			"Error (asm): cannot write file properly"
# define ASM_MSG_CLOSE			"Error (asm): cannot close file properly"

/*
**	Defines from op.h
*/

# define CHAR_COMM				'#'
# define CHAR_LABEL				':'
# define CHAR_REGIST			'r'
# define CHAR_DIRECT			'%'
# define CHAR_SEPAR				','

# define STR_LABEL				"abcdefghijklmnopqrstuvwxyz_0123456789"
# define DFT_NAME				"no name"
# define DFT_COMM				"no comment"
# define CMD_NAME				".name"
# define CMD_COMM				".comment"
# define EXT_SRC				".s"
# define EXT_DST				".cor"

# define T_REG					1
# define T_DIR					2
# define T_IND					4

# define LEN_NAME				128
# define LEN_COMM				2048
# define COREWAR_EXEC_MAGIC		0xea83f3

#endif
