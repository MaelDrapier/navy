/*
** error_hdl.c for navy in /home/mael/navy_tmp
**
** Made by mael drapier
** Login   <mael.drapier@epitech.eu@epitech.net>
**
** Started on  Tue Jan 31 17:24:38 2017 mael drapier
** Last update Fri Feb 10 13:22:12 2017 mael drapier
*/

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "navy.h"
#include "gnl.h"

void	my_open_error(char *filename)
{
  my_putstr(2, "ERROR: Cannot open file '");
  my_putstr(2, filename);
  my_putstr(2, "'\n");
  my_putstr(2, "Try './navy -h' for more information.\n");
}

void	my_file_error(char *filename)
{
  my_putstr(2, "ERROR: File '");
  my_putstr(2, filename);
  my_putstr(2, "' is invalid\n");
  my_putstr(2, "Try './navy -h' for more information.\n");
}

int	check_boat_size(char **map, int i, int j)
{
  t_boat	size;

  size = (t_boat) {0, 0, 0, 0};
  while (map[j] != NULL)
    {
      while (map[j][i] != '\0')
	{
	  if (map[j][i] == '2')
	    size.bt_2++;
	  else if (map[j][i] == '3')
	    size.bt_3++;
	  else if (map[j][i] == '4')
	    size.bt_4++;
	  else if (map[j][i] == '5')
	    size.bt_5++;
	  i = i + 1;
	}
      i = 2;
      j = j + 1;
    }
  if (size.bt_2 != 2 || size.bt_3 != 3 || size.bt_4 != 4 || size.bt_5 != 5)
    return (RETURN_FAIL);
  return (RETURN_SUCCESS);
}

int	check_error(char *filename)
{
  char	*s;
  int	i;
  int	fd;

  i = 0;
  fd = open(filename, O_RDONLY);
  if (fd < 0)
    return (-1);
  while (((s = get_next_line(fd)) != NULL) && (my_strlen(s) == 7))
    {
      s = discount_capitalizer(s);
      if (s[0] < '2' || s[0] > '5')
	return (RETURN_FAIL);
      if (check_char(s[2]) == -1 || check_char(s[3]) == -1)
	return (RETURN_FAIL);
      if ((check_char(s[5]) == -1 || check_char(s[6]) == -1))
	return (RETURN_FAIL);
      if (s[1] != ':' || s[4] != ':')
	return (RETURN_FAIL);
      i = i + 1;
    }
  if (i != 4)
    return (RETURN_FAIL);
  close(fd);
  return (RETURN_SUCCESS);
}

int	check_diagonal(char *s, char *filename)
{
  if (no_timeout_please(s) == RETURN_FAIL)
    {
      my_file_error(filename);
      return (RETURN_FAIL);
    }
  if (s[2] != s[5] && s[3] != s[6])
    {
      my_file_error(filename);
      return (RETURN_FAIL);
    }
  if (s[2] == s[5] && s[3] == s[6])
    {
      my_file_error(filename);
      return (RETURN_FAIL);
    }
  return (RETURN_SUCCESS);
}
