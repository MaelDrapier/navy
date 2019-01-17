/*
** player1.c for navy in /home/mael/PSU_2016_navy
**
** Made by mael drapier
** Login   <mael.drapier@epitech.eu@epitech.net>
**
** Started on  Wed Feb  1 18:39:29 2017 mael drapier
** Last update Thu Feb 16 16:05:04 2017 mael drapier
*/

#include "navy.h"
#include "gnl.h"

void	player_wait_more(t_struct *entity, int x, int y)
{
  if (entity->map[y][x] >= '2' && entity->map[y][x] <= '5')
    {
      my_putstr(1, ": hit");
      entity->map[y][x] = 'x';
      if (my_xtab(entity->map) == 14)
	{
	  entity->win = 1;
	  send_this("I9", entity);
	}
      else
	send_this("C3", entity);
    }
  else
    {
      my_putstr(1, ": missed");
      if (entity->map[y][x] != 'x')
	entity->map[y][x] = 'o';
      send_this("A1", entity);
    }
  my_putstr(1, "\n\n");
}

void	player_wait(t_struct *entity)
{
  char	pos[3];
  int	x;
  int	y;

  my_putstr(1, "waiting for enemy's attack...\n");
  while (catch_module(entity) == RETURN_FAIL);
  x = entity->sig1 * 2;
  y = entity->sig2 + 1;
  pos[0] = entity->sig1 + 64;
  pos[1] = entity->sig2 + 48;
  pos[2] = '\0';
  my_putstr(1, pos);
  player_wait_more(entity, x, y);
}

int	player_attack(t_struct *entity)
{
  char	*s;
  int	x;
  int	y;

  while ((s = get_next_line(0)) == NULL || (check_attack(s) == RETURN_FAIL))
    my_putstr(1, "wrong position\nattack: ");
  send_this(s, entity);
  while (catch_module(entity) == RETURN_FAIL);
  x = (s[0] - 64) * 2;
  y = s[1] - 47;
  my_putstr(1, s);
  if (entity->sig1 != 1 && entity->sig2 != 1)
    {
      entity->enemy_map[y][x] = 'x';
      my_putstr(1, ": hit\n\n");
      if (entity->sig1 == 9 && entity->sig2 == 9)
	return (1);
    }
  else
    {
      if (entity->enemy_map[y][x] != 'x')
	entity->enemy_map[y][x] = 'o';
      my_putstr(1, ": missed\n\n");
    }
  return (0);
}

int	check_char(char c)
{
  if (c >= '1' && c <= '8')
    return (RETURN_SUCCESS);
  if (c >= 'A' && c <= 'H')
    return (RETURN_SUCCESS);
  return (-1);
}

int	no_timeout_please(char *s)
{
  if (s[2] < s[5])
    {
      if (s[5] - s[2] != s[0] - 49)
	return (RETURN_FAIL);
    }
  if (s[2] > s[5])
    {
      if (s[2] - s[5] != s[0] - 49)
	return (RETURN_FAIL);
    }
  if (s[3] < s[6])
    {
      if (s[6] - s[3] != s[0] - 49)
	return (RETURN_FAIL);
    }
  if (s[3] > s[6])
    {
      if (s[3] - s[6] != s[0] - 49)
	return (RETURN_FAIL);
    }
  return (RETURN_SUCCESS);
}
