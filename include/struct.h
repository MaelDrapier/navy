/*
** struct.h for navy in /home/mael/navy_tmp
**
** Made by mael drapier
** Login   <mael.drapier@epitech.eu@epitech.net>
**
** Started on  Tue Jan 31 13:32:14 2017 mael drapier
** Last update Fri Feb  3 12:31:41 2017 mael drapier
*/

#ifndef STRUCT_H_
# define STRUCT_H

# include <unistd.h>

typedef	struct		s_struct
{
  char			**map;
  char			**enemy_map;
  pid_t			my_pid;
  pid_t			enemy_pid;
  int			sig1;
  int			sig2;
  int			player;
  int			win;
}			t_struct;

typedef struct		s_boat
{
  int			bt_2;
  int			bt_3;
  int			bt_4;
  int			bt_5;
}			t_boat;

#endif /* !STRUCT_H_ */
