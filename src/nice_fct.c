/*
** nice_fct.c for navy in /home/mael/PSU_2016_navy
**
** Made by mael drapier
** Login   <mael.drapier@epitech.eu@epitech.net>
**
** Started on  Thu Feb 16 15:25:27 2017 mael drapier
** Last update Thu Feb 16 15:25:50 2017 mael drapier
*/

#include "navy.h"

int	disp_win(t_struct *entity)
{
  if (entity->win == 2)
    {
      display(entity);
      my_putstr(1, "I won\n");
      return (1);
    }
  else
    {
      display(entity);
      my_putstr(1, "Enemy won\n");
      return (0);
    }
}

int	attack_and_check(t_struct *entity)
{
  my_putstr(1, "attack: ");
  if (player_attack(entity) == 1)
    {
      entity->win = 2;
      return (1);
    }
  else
    return (0);
}

int	my_getnbr(char *str)
{
  int	i;
  int	res;

  i = 0;
  res = 0;
  while (str[i] != '\0')
    {
      if (str[i] < '0' || str[i] > '9')
	return (res);
      res = res * 10;
      res = res + str[i] - 48;
      i = i + 1;
    }
  return (res);
}

int	my_xtab(char **tab)
{
  int	j;
  int	y;
  int	x;

  j = 2;
  y = 2;
  x = 0;
  while (tab[j] != NULL)
    {
      while (tab[j][y] != '\0')
	{
	  if (tab[j][y] == 'x')
	    x++;
	  y++;
	}
      y = 0;
      j++;
    }
  return (x);
}

void	display(t_struct *entity)
{
  my_putstr(1, "my positions:\n");
  my_ultimate_showtab(entity->map);
  my_putstr(1, "enemy's positions:\n");
  my_ultimate_showtab(entity->enemy_map);
}
