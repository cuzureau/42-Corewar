/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_defines.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrangie <lbrangie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 16:50:41 by lbrangie          #+#    #+#             */
/*   Updated: 2019/02/28 14:19:24 by jayache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_DEFINES_H
# define FT_PRINTF_DEFINES_H

# ifndef PRINTF_BUFF_SIZE
#  define PRINTF_BUFF_SIZE	1024
# endif
# ifndef PRINTF_FLAGS
#  define PRINTF_FLAGS	"#0-+ "
# endif

# ifndef STR_BASE_UP
#  define STR_BASE_UP	"0123456789ABCDEF"
# endif
# ifndef STR_BASE_LO
#  define STR_BASE_LO	"0123456789abcdef"
# endif

# ifndef PRINTF_F_HASH
#  define PRINTF_F_HASH	0b00000001
# endif
# ifndef PRINTF_F_ZERO
#  define PRINTF_F_ZERO	0b00000010
# endif
# ifndef PRINTF_F_MINU
#  define PRINTF_F_MINU	0b00000100
# endif
# ifndef PRINTF_F_PLUS
#  define PRINTF_F_PLUS	0b00001000
# endif
# ifndef PRINTF_F_SPAC
#  define PRINTF_F_SPAC	0b00010000
# endif

# ifndef PRINTF_WC_MASK_0
#  define PRINTF_WC_MASK_0	0b000000000000001111111
# endif
# ifndef PRINTF_WC_MASK_1
#  define PRINTF_WC_MASK_1	0b000000000000000111111
# endif
# ifndef PRINTF_WC_MASK_2
#  define PRINTF_WC_MASK_2	0b000000000011111000000
# endif
# ifndef PRINTF_WC_MASK_3
#  define PRINTF_WC_MASK_3	0b000000000111111000000
# endif
# ifndef PRINTF_WC_MASK_4
#  define PRINTF_WC_MASK_4	0b000001111000000000000
# endif
# ifndef PRINTF_WC_MASK_5
#  define PRINTF_WC_MASK_5	0b000111111000000000000
# endif
# ifndef PRINTF_WC_MASK_6
#  define PRINTF_WC_MASK_6	0b111000000000000000000
# endif
#endif

/*
**		UNICODE MASKS:
**	In order to print a character, there are 4 possible forms. The first form is
**	the most used simply because it prints ASCII characters. The other ones are
**	used to print Unicode characters. In every cases, we have to give a precise
**	number of byte to the write function if we want to print a character with
**	this methode. The four differents form can be represented as follow:
**		                           0xxxxxxx
**		                  110xxxxx 10xxxxxx
**		         1110xxxx 10xxxxxx 10xxxxxx
**		11110xxx 10xxxxxx 10xxxxxx 10xxxxxx
**
**	So, in the first place, we have to count how many usefull bit their are in
**	the character. We count the bits from the first 1-bit from the left all the
**	way to the rigth side.
**
**	Then, we choose witch form we will use to print the character. For exemple,
**	if there are 14 bits in the character, we will use the third form, because
**	the second is too small and the fourth is too large.
**
**	Finally, we will use the masks above to highlight the 1-bits and move those
**	bits in order to align them with the 'x' shown in the representations.
**
**	The last thing to do is to write the bytes that we have created and voila,
**	the write function will not print anything until the last byte is writen
**	and the Unicode character that we want is printed.
**
**	Below, there are a alignement of the four different form and the masks:
**		                           0xxxxxxx
**	0	00000000 00000000 00000000 01111111
**
**		                  110xxxxx 10xxxxxx
**	2	00000000 00000000 00000111 11000000
**	1	00000000 00000000 00000000 00111111
**
**		         1110xxxx 10xxxxxx 10xxxxxx
**	4	00000000 00000000 11110000 00000000
**	3	00000000 00000000 00001111 11000000
**	1	00000000 00000000 00000000 00111111
**
**		11110xxx 10xxxxxx 10xxxxxx 10xxxxxx
**	6	00000000 00011100 00000000 00000000
**	5	00000000 00000011 11110000 00000000
**	3	00000000 00000000 00001111 11000000
**	1	00000000 00000000 00000000 00111111
*/
