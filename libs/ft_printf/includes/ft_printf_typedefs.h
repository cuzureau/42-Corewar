/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_typedefs.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrangie <lbrangie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 14:46:07 by lbrangie          #+#    #+#             */
/*   Updated: 2019/02/28 14:52:04 by jayache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_TYPEDEFS_H
# define FT_PRINTF_TYPEDEFS_H

/*
**		STRUCT S_FLAGS:
**	The 's_flags' structure contains all the informations about the formatting
**	of the convertions in the string 'format' of ft_printf.
**	 -	The attribut flags are stored, using bitwise, in the 'p_flags' char,
**		that can be represented as follow:		[][][][ ][+][-][0][#]
**	 -	The length modifiers are stored in the string 'length'.
**	 -	The character 'type' contains the character of the convertion.
**	 -	The field width is stored in 'field'.
**	 -	The precision in 'pres'.
**	(Supported flags: '#', '0', '-', '+' and ' ')
**	(Supported length modifier: 'h', 'l', 'j', 'z', 'hh' and 'll')
*/

/*
**		STRUCT S_BUFF:
**	The 's_buff' structure contains multiple informations about the buffer used
**	in the vfprint and vdprint functions.
**	 -	The string 'str' is the string that will be printed by the function.
**	 -	The integer 'index' is the index where we are at in str.
**	 -	The integer 'ret' is the number of bytes wrote by the function.
**	 -	The integer 'fd' is the descriptor of the file we have to print into.
*/

/*
**		STRUCT S_CONV:
**	The 's_conv' structure contains some informations about the number we will
**	convert in the s, S, p, d, D, i, o, O, u, U, x, X, c, C, n and b
**	convertions.
**	 -	The character 'c_char' is used, in c convertion, to store the character
**		that will be print.
**	 -	The 's_str' pointer is used in the s convertion to store the string to
**		print.
**	 -	The string 'w_char' is used in convertion C to hold the differents bytes
**		of the Unicode character to print.
**	 -	The 'w_str' pointer is used in the S convertion to store the Unicode
**		string to print.
**	 -	The uintmax_t 'n_tmp' contains the return value of va_arg() in the
**		numericals convertions.
**	 -	The string 'n_str' is the string representing the number to print.
**	 -	The string 'n_sign' contains the sign of the number printed in the
**		dDi convertions or the prefix of the number in the xXoOb convertions.
**	 -	The void pointer 'ptr' is used in the n convertion to store the number
**		of bytes printed.
**	 -	The character 'fill' is either a space or a zero (' ' or '0') that will
**		fill the field if a field length is given.
**	 -	The integer 'nlen' is the length of the number.
**	 -	The integer 'flen' is the number of 'fill' char that have to be print.
**	(Supported convertions: s, S, p, d, D, i, o, O, u, U, x, X, c, C and n)
**	(Bonus convertions: b (binary notation), @ (see the 'e_colors' enum note))
*/

/*
**		ENUM E_COLORS:
**	The 'e_colors' enum contains the values of the differents colors and format
**	we can used in the (v)(/f/d)printf function. We use the character '@' as the
**	color flag.
**	Exemple:
**		printf("This is %@red%@.\n", RED, EOC)
*/

typedef struct	s_flags
{
	char			p_flags;
	char			len[4];
	char			type;
	int				field;
	int				pres;
}				t_flags;

typedef struct	s_buff
{
	char			str[PRINTF_BUFF_SIZE];
	int				index;
	int				ret;
	int				fd;
}				t_buff;

typedef struct	s_conv
{
	char			c_char;
	char			*s_str;
	unsigned char	w_char[3];
	wchar_t			*w_str;
	uintmax_t		n_tmp;
	char			n_str[65];
	char			n_sign[3];
	void			*ptr;
	char			fill;
	int				nlen;
	int				flen;
}				t_conv;

typedef enum	e_colors
{
	RED,
	GREEN,
	BLUE,
	WHITE,
	CYAN,
	MAGENTA,
	YELLOW,
	BLACK,
	LIGHT_BLUE,
	PURPLE,
	ORANGE,
	BRED,
	BGREEN,
	BBLUE,
	BWHITE,
	BCYAN,
	BMAGENTA,
	BYELLOW,
	BBLACK,
	BLIGHT_BLUE,
	BPURPLE,
	BORANGE,
	BOLD,
	DIM,
	UNDERLINE,
	BLINK,
	HIDDEN,
	INVERTED,
	ITALIC,
	EOC
}				t_colors;

#endif
