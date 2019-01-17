/*
** navy.h for navy in /home/mael/navy_tmp
**
** Made by mael drapier
** Login   <mael.drapier@epitech.eu@epitech.net>
**
** Started on  Tue Jan 31 13:27:39 2017 mael drapier
** Last update Fri Feb 10 13:23:29 2017 mael drapier
*/

#ifndef NAVY_H_
# define NAVY_H_

# define RETURN_SUCCESS 0
# define RETURN_FAIL 84
# define COL_X_RED	"\033[31m"
# define BG_BLUE	"\033[44m"
# define FG_BOLD	"\033[1m"
# define COL_2_GREEN	"\033[32m"
# define COL_3_YELLOW	"\033[33m"
# define COL_4_BLUE	"\033[34m"
# define COL_5_PURPLE	"\033[35m"
# define COL_O_BLUE	"\033[36m"
# define COL_DEF	"\033[0m"
# include "struct.h"

int		g_match_pid;

int		show_helper();
int		check_char(char c);
int		my_xtab(char **map);
int		my_strlen(char *str);
int		my_getnbr(char *str);
int		check_attack(char *s);
int		who_win(t_struct *entity);
int		no_timeout_please(char *s);
int		disp_win(t_struct *entity);
int		check_error(char *filename);
int		catch_module(t_struct *entity);
int		player_attack(t_struct *entity);
int		attack_and_check(t_struct *entity);
int		check_diagonal(char *s, char *filename);
int		check_boat_size(char **map, int i, int j);
int		send_this(char *message, t_struct *entity);
int		my_create_map(char *filename, t_struct *entity);
char		*check_order_again(char *s);
char		*discount_capitalizer(char *s);
char		*my_strcat(char *dest, char *src);
void		my_putnbr(int nb);
void		put_x_red(char x);
void		put_o_blue(char x);
void		my_putchar(char c);
void		put_4_blue(char x);
void		put_2_green(char x);
void		put_3_yellow(char x);
void		put_5_purple(char x);
void		sending_error(pid_t pid);
void		display(t_struct *entity);
void		sending_unmatch(pid_t pid);
void		play_game(t_struct *entity);
void		my_putstr(int fd, char *str);
void		my_open_error(char *filename);
void		my_file_error(char *filename);
void		player_wait(t_struct *entity);
void		my_ultimate_showtab(char **tab);
void		what_to_colorise(char **tab, int j, int y);

#endif /* !NAVY_H_ */
