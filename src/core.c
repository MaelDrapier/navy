/*
** core.c for navy in /home/mael/navy_tmp
**
** Made by mael drapier
** Login   <mael.drapier@epitech.eu@epitech.net>
**
** Started on  Tue Jan 31 22:33:50 2017 mael drapier
** Last update Thu Feb  2 16:14:55 2017 mael drapier
*/

#include <unistd.h>
#include "navy.h"

char	*discount_capitalizer(char *s)
{
  int	i;

  i = 0;
  while (s[i] != '\0')
    {
      if (s[i] >= 'a' && s[i] <= 'z')
	s[i] = s[i] - 32;
      i = i + 1;
    }
  return (s);
}

int	check_attack(char *s)
{
  s = discount_capitalizer(s);
  if (my_strlen(s) != 2)
    return (RETURN_FAIL);
  if (s[0] >= 'A' && s[0] <= 'H' && s[1] >= '1' && s[1] <= '8')
    return (RETURN_SUCCESS);
  if (s[1] >= 'A' && s[1] <= 'H' && s[0] >= '1' && s[0] <= '8')
    return (RETURN_SUCCESS);
  return (RETURN_FAIL);
}

char	*check_order_again(char *s)
{
  char	tmp;

  s = discount_capitalizer(s);
  if (my_strlen(s) != 2)
    return (s);
  if (s[0] >= '1' && s[0] <= '8')
    {
      tmp = s[0];
      s[0] = s[1];
      s[1] = tmp;
    }
  return (s);
}

void	play_game(t_struct *entity)
{
  while (1)
    {
      display(entity);
      if (entity->player == 1)
	{
	  if (attack_and_check(entity) == 1)
	    return ;
	  player_wait(entity);
	  if (entity->win == 1)
	    return ;
	}
      else
	{
	  player_wait(entity);
	  if (entity->win == 1)
	    return ;
	  if (attack_and_check(entity) == 1)
	    return ;
	}
    }
}

int	show_helper()
{
  my_putstr(1, "USAGE\n	./navy [first player pid] navy_positions\n");
  my_putstr(1, "\nDESCRIPTION\n	first_player_pid	only for the");
  my_putstr(1, " 2nd player. pid of the first player.\n	navy_positions");
  my_putstr(1, "		file representing the positions of the ships");
  my_putstr(1, ".\n");
  return (RETURN_SUCCESS);
}
