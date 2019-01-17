/*
** map.c for navy in /home/mael/navy_tmp/src
**
** Made by mael drapier
** Login   <mael.drapier@epitech.eu@epitech.net>
**
** Started on  Tue Jan 31 13:21:07 2017 mael drapier
** Last update Fri Feb  3 02:05:15 2017 mael drapier
*/

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "navy.h"
#include "gnl.h"

char	**set_empty_map(char **map)
{
  int	i;

  i = 0;
  if ((map = malloc(sizeof(char *) * 11)) == NULL)
    return (NULL);
  while (i < 10)
    {
      if ((map[i] = malloc(sizeof(char) * 18)) == NULL)
	return (NULL);
      i = i + 1;
    }
  map[0] = my_strcat(map[0], " |A B C D E F G H");
  map[1] = my_strcat(map[1], "-+---------------");
  map[2] = my_strcat(map[2], "1|. . . . . . . .");
  map[3] = my_strcat(map[3], "2|. . . . . . . .");
  map[4] = my_strcat(map[4], "3|. . . . . . . .");
  map[5] = my_strcat(map[5], "4|. . . . . . . .");
  map[6] = my_strcat(map[6], "5|. . . . . . . .");
  map[7] = my_strcat(map[7], "6|. . . . . . . .");
  map[8] = my_strcat(map[8], "7|. . . . . . . .");
  map[9] = my_strcat(map[9], "8|. . . . . . . .");
  map[10] = NULL;
  return (map);
}

int	draw_boat(t_struct *entity, char *s, int i, char *filename)
{
  int	x;
  int	y;

  x = (s[2] - 64) * 2;
  y = s[3] - 47;
  while (i < s[0] - 48)
    {
      if (x < 2 || x > 16 || y < 2 || y > 9)
	return (RETURN_FAIL);
      if (entity->map[y][x] != '.')
	my_file_error(filename);
      if (entity->map[y][x] != '.')
	return (RETURN_FAIL);
      entity->map[y][x] = s[0];
      if (s[2] < s[5])
	x = x + 2;
      else if (s[2] > s[5])
	x = x - 2;
      else if (s[3] < s[6])
	y = y + 1;
      else if (s[3] > s[6])
	y = y - 1;
      i = i + 1;
    }
  return (RETURN_SUCCESS);
}

char	*check_order(char *s)
{
  char	tmp;

  s = discount_capitalizer(s);
  if (s[2] >= '0' && s[2] <= '9' && s[3] >= 'A' && s[3] <= 'H')
    {
      tmp = s[2];
      s[2] = s[3];
      s[3] = tmp;
    }
  if (s[5] >= '0' && s[5] <= '9' && s[6] >= 'A' && s[6] <= 'H')
    {
      tmp = s[5];
      s[5] = s[6];
      s[6] = tmp;
    }
  return (s);
}

int	my_fill_map(t_struct *entity, char *filename)
{
  int	fd;
  char	*s;

  if (check_error(filename) == RETURN_FAIL)
    {
      my_file_error(filename);
      return (RETURN_FAIL);
    }
  fd = open(filename, O_RDONLY);
  if (fd < 0)
    {
      my_open_error(filename);
      return (RETURN_FAIL);
    }
  while ((s = get_next_line(fd)) != NULL)
    {
      s = check_order(s);
      if (check_diagonal(s, filename) == RETURN_FAIL)
	return (RETURN_FAIL);
      if (draw_boat(entity, s, 0, filename) == RETURN_FAIL)
	return (RETURN_FAIL);
    }
  close(fd);
  return (RETURN_SUCCESS);
}

int my_create_map(char *filename, t_struct *entity)
{
  entity->map = set_empty_map(entity->map);
  entity->enemy_map = set_empty_map(entity->enemy_map);
  if (my_fill_map(entity, filename) == RETURN_FAIL)
    return (RETURN_FAIL);
  if (check_boat_size(entity->map, 2, 2) == RETURN_FAIL)
    {
      my_file_error(filename);
      return (RETURN_FAIL);
    }
  return (RETURN_SUCCESS);
}
