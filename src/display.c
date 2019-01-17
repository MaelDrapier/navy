/*
** display.c for navy in /home/mael/navy_tmp/src
**
** Made by mael drapier
** Login   <mael.drapier@epitech.eu@epitech.net>
**
** Started on  Tue Jan 31 14:13:17 2017 mael drapier
** Last update Sun Feb  5 12:47:42 2017 etienne.filliat
*/

#include <unistd.h>
#include "navy.h"

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      i = i + 1;
    }
  return (i);
}

void	my_putstr(int fd, char *str)
{
  write(fd, str, my_strlen(str));
}

void	my_putnbr(int nb)
{
  char	digit;

  if (nb < 0)
    {
      my_putstr(1, "-");
      nb = nb * -1;
    }
  digit = nb % 10 + 48;
  nb = nb / 10;
  if (nb != 0)
    my_putnbr(nb);
  my_putchar(digit);
}

void		my_ultimate_showtab(char **tab)
{
  int	j;
  int	y;

  j = 0;
  y = 0;
  while (tab[j] != NULL)
    {
      while (tab[j][y] != '\0')
	{
	  what_to_colorise(tab, j, y);
	  y++;
	}
      my_putchar(tab[j][y]);
      my_putchar('\n');
      y = 0;
      j++;
    }
  my_putchar('\n');
}

char	*my_strcat(char *dest, char *src)
{
  int	len;
  int	i;

  len = my_strlen(dest);
  i = 0;
  while (src[i] != '\0')
    {
      dest[len + i] = src[i];
      i = i + 1;
    }
  dest[len + i] = '\0';
  return (dest);
}
