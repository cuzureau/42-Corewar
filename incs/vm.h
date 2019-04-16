/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayache <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 22:57:21 by jayache           #+#    #+#             */
/*   Updated: 2019/03/08 17:26:44 by xmazella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

# include "../libs/libft/includes/libft.h"
# include "../libs/ft_printf/includes/ft_printf.h"
# include <ncurses.h>
# include "vm_struct.h"
# include "vm_def.h"

# define FIRST_PARAM_MASK 192
# define SECOND_PARAM_MASK 48
# define THIRD_PARAM_MASK 12

# define FIRST_CHAR_INT_MASK 4278190080
# define SECOND_CHAR_INT_MASK 16711680
# define THIRD_CHAR_INT_MASK 65280
# define FOURTH_CHAR_INT_MASK 255

# define PARAM_REGISTER 1
# define PARAM_INDIRECT 3
# define PARAM_DIRECT 2

# define DEBUG_PRINT_LIVES 16
# define DEBUG_PRINT_CYCLE 8
# define DEBUG_PRINT_DEATHS 4
# define DEBUG_PRINT_MOVE 2
# define DEBUG_PRINT_EXEC 1

# define ERROR_MALLOC1 "Could not malloc the player!\n"
# define ERROR_MALLOC2 "Could not malloc the player->name!\n"
# define ERROR_FLAGU "is not a valid flag\n"
# define ERROR_FLAGN1 "Error: -n <...> need valid numeric parameter\n"
# define ERROR_FLAGN2 "Error: -n <...> numbers is not valid\n"
# define ERROR_DEBUG1 "Error: -d <...> need valid numeric parameter\n"
# define ERROR_DEBUG2 "Error: -d <...> numbers is not valid\n"
# define ERROR_FLAGD1 "Error: -dump <...> need valid numeric parameter\n"
# define ERROR_FLAGD2 "Error: -dump <...> numbers is not valid\n"
# define ERROR_CHAMPION "Error: the format champion is not valid\n"
# define ERROR_CHAMPION2 "Error: invalid champion. False or Need magic number\n"
# define ERROR_CHAMPION3 "Error: invalid champion. Need prog_name in header\n"
# define ERROR_CHAMPION4 "Error: invalid champion. The champion is to big\n"
# define ERROR_CHAMPION5 "Error: invalid champion. The header is to small\n"
# define ERROR_CHAMPION6 "Error: invalid champion. The prog_size is invalid\n"
# define ERROR_VISU "Error: VISU parameters are not valid\n"

# define COLOR_BACK 5
# define COLOR_BACK2 6
# define COLOR_BACK3 7
# define COLOR_PLAYER1 9
# define COLOR_PLAYER2 10
# define COLOR_PLAYER3 11
# define COLOR_PLAYER4 12
# define COLOR_NULL 13
# define COLOR_TXT1 14
# define COLOR_TXT2 15
# define COLOR_TXT3 16

/*
** VIRTUAL MACHINE DEFINES
*/

# define REG_CODE				1
# define DIR_CODE				2
# define IND_CODE				3

# define REG_NUMBER				16

# define CYCLE_TO_DIE			1536
# define CYCLE_DELTA			50
# define NBR_LIVE				21
# define MAX_CHECKS				10

# define MAX_ARGS_NUMBER		4
# define MAX_PLAYERS			4
# define MEM_SIZE				(4 * 1024)
# define IDX_MOD				(MEM_SIZE / 8)
# define CHAMP_MAX_SIZE			(MEM_SIZE / 6)

#endif
