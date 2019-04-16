/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_def.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayache <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 14:55:21 by jayache           #+#    #+#             */
/*   Updated: 2019/03/10 12:17:34 by xmazella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_DEF_H
# define VM_DEF_H

/*
** GARBAGE COLLECTOR
*/

void		ft_free(void);
void		*ft_malloc(size_t size);
void		*ft_gmemalloc(size_t size);
char		*ft_gstrdup(const char *s1);

/*
** ERROR FUNCTIONS
*/

int			error_message(char const *str, void *a, void *b, void *c);
void		error(char const *str, void *a, void *b, void *c);

/*
** INIT FUNCTIONS
*/

t_vm		*init_vm(void);
void		init_processes(t_vm *vm);
int			load_players(t_vm *vm);

/*
** DEBUG FUNCTIONS
*/

void		p_arg(char const *name, int id, t_arg arg);
void		print_memory(char *arena, int pos);
void		print_mem_chunk(t_vm *vm, int pos, int l);
void		print_winner(t_vm *vm);

/*
** parse
*/

int			parse(int ac, char **av, char *ptr, t_vm *vm);
int			check_nb_player(int nb, t_vm *vm);
int			checkplayer_and_sort(t_vm *vm);
size_t		byte_reverse(size_t n);
/*
** ncurse
*/

void		print_war_title(WINDOW *box);
void		print_player(t_vm *vm, WINDOW *players);
void		print_info(t_vm *vm, WINDOW *info, int end);
int			check_id(t_vm *vm, int i);
void		init_visu(void);
void		back(WINDOW *wnd, int x, int y);
void		back_room(void);
void		free_wnd(WINDOW *arena, WINDOW *box, WINDOW *info, WINDOW *player);
int			room_page(void);
int			war_page(t_vm *vm, int end);
void		chose_color_playerinfo(t_vm *vm, WINDOW *info, int id);

/*
** WRITE A VALUE
*/

void		write_in_mem(t_vm *vm, t_process *process, int pos, int to_write);
void		load_in_reg(t_process *process, int nb, int val);

/*
** READ A VALUE
*/

int			read_from_reg(t_process *process, int nb);
int			read_from_mem(t_vm *vm, int pos);

/*
** TOOLS
*/

int			get_player_number(t_vm *vm, int nb);
char		*get_player_name(t_vm *vm, int nb);
t_player	*get_player_struct(t_vm *vm, int nb);
t_header	*get_header(t_vm *vm, int nb);
int			convert_pos(t_process *process, int pos);
int			convert_pos_print(t_process *process, int pos);
int			convert_pos_long(t_process *process, int pos);
int			convert_pos_long_print(t_process *process, int pos);
void		live(t_vm *vm, int nb);
void		move_process(t_vm *vm, t_process *process, int l);
t_process	*clone(t_vm *vm, t_process *p);
void		add_process(t_vm *vm, t_process *f);
int			verbose_level(t_vm *vm, int debug);

/*
** FREE
*/

void		free_process(t_process *process);

/*
** DEATH
*/

void		apply_death(t_vm *vm);
int			check_if_all_dead(t_vm *vm);

/*
**	INTERPRETARD
*/

void		game_loop(t_vm *vm);
void		execute_instruction(t_vm *vm, t_process *process);
void		load_next_instruction(t_vm *vm, t_process *process);

/*
** READ ARG
*/

char		arg_size_1(char *arena, int pos);
short		arg_size_2(char *arena, int pos);
int			arg_size_4(char *arena, int pos);
t_arg		read_arg(char *arena, int pos, int size);
int			get_arg_value(t_process *p, t_arg arg, int nb);
int			read_arg_val(t_process *p, int nb);
int			arg_is(int arg, int a, int b);
int			valid_arg_nb(t_arg arg);
int			skip_invalid_arg(t_arg arg);

/*
** OPCODES
*/

void		execute_ld(t_vm *vm, t_process *process);
void		execute_lld(t_vm *vm, t_process *process);
void		execute_st(t_vm *vm, t_process *process);
void		execute_sti(t_vm *vm, t_process *process);
void		execute_live(t_vm *vm, t_process *process);
void		execute_zjmp(t_vm *vm, t_process *process);
void		execute_and(t_vm *vm, t_process *process);
void		execute_add(t_vm *vm, t_process *process);
void		execute_xor(t_vm *vm, t_process *process);
void		execute_sub(t_vm *vm, t_process *process);
void		execute_fork(t_vm *vm, t_process *process);
void		execute_lfork(t_vm *vm, t_process *process);
void		execute_ldi(t_vm *vm, t_process *process);
void		execute_lldi(t_vm *vm, t_process *process);
void		execute_or(t_vm *vm, t_process *process);
void		execute_aff(t_vm *vm, t_process *process);
int			load_ld(t_vm *vm, t_process *process);
int			load_lld(t_vm *vm, t_process *process);
int			load_st(t_vm *vm, t_process *process);
int			load_sti(t_vm *vm, t_process *process);
int			load_live(t_vm *vm, t_process *process);
int			load_zjmp(t_vm *vm, t_process *process);
int			load_and(t_vm *vm, t_process *process);
int			load_xor(t_vm *vm, t_process *process);
int			load_add(t_vm *vm, t_process *process);
int			load_sub(t_vm *vm, t_process *process);
int			load_fork(t_vm *vm, t_process *process);
int			load_lfork(t_vm *vm, t_process *process);
int			load_ldi(t_vm *vm, t_process *process);
int			load_lldi(t_vm *vm, t_process *process);
int			load_or(t_vm *vm, t_process *process);
int			load_aff(t_vm *vm, t_process *process);

#endif
