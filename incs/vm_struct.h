/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_struct.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayache <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 22:59:14 by jayache           #+#    #+#             */
/*   Updated: 2019/03/07 15:34:53 by jayache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_STRUCT_H
# define VM_STRUCT_H

# define PROG_NAME_LENGTH		(128)
# define COMMENT_LENGTH			(2048)
# define COREWAR_EXEC_MAGIC		0xea83f3

typedef WINDOW	t_win;

typedef struct		s_header
{
	unsigned int		magic;
	char				prog_name[PROG_NAME_LENGTH + 1];
	unsigned int		prog_size;
	char				comment[COMMENT_LENGTH + 1];
}					t_header;

typedef struct		s_arg
{
	int				param[3];
	int				type[3];
	unsigned char	codage;
	unsigned char	opcode;
	char			size;
	int				player_id;
}					t_arg;

typedef struct		s_player
{
	t_header		header;
	char			*name;
	int				nb;
	int				color;
	int				nb_tmp;
	int				div_arena;
	int				mod_arena;
	int				lives;
	struct s_player	*next;
}					t_player;

typedef struct		s_process
{
	int				*regist;
	char			carry;
	int				id;
	int				pc;
	int				cycle;
	t_arg			arg;
	char			alive;
	unsigned int	lives;
	int				last_live;
	int				player_id;
}					t_process;

typedef struct		s_vm
{
	char			*arena;
	int				*info_arena;
	unsigned int	nb_players;
	struct s_player	*player;
	t_list			*processes;
	off_t			len_buffer;
	int				jump;
	int				dump;
	int				debug;
	int				visu;
	int				x_arena;
	int				y_arena;
	int				last_act;
	int				last_check;
	int				delta;
	int				nb_process;
	int				nb_checks;
	int				nb_lives;
	int				cycle;
	int				last_live_id;
}					t_vm;

typedef	enum		e_opcode
{
	LIVE = 1,
	LD,
	ST,
	ADD,
	SUB,
	AND,
	OR,
	XOR,
	ZJMP,
	LDI,
	STI,
	FORK,
	LLD,
	LLDI,
	LFORK,
	AFF
}					t_opcode;

#endif
