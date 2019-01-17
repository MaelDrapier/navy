/*
** colorise.c for navy in /home/spiki/delivery/B2/PSU_2016_navy/bonus/src/
**
** Made by etienne.filliat
** Login   <etienne.filliat@epitech.eu>
**
** Started on  Fri Feb  3 19:25:54 2017 etienne.filliat
** Last update Fri Feb 10 14:03:00 2017 mael drapier
*/

#include "navy.h"

void		put_x_red(char x)
{
  my_putstr(1, COL_X_RED);
  my_putstr(1, FG_BOLD);
  my_putchar(x);
  my_putstr(1, COL_DEF);
}

void		put_o_blue(char x)
{
  my_putstr(1, COL_O_BLUE);
  my_putstr(1, FG_BOLD);
  my_putchar(x);
  my_putstr(1, COL_DEF);
}

void		what_to_colorise(char **tab, int j, int y)
{
  if (tab[j][y] == 'x')
    put_x_red(tab[j][y]);
  else if (tab[j][y] == 'o')
    put_o_blue(tab[j][y]);
  else if (tab[j][y] == '2' && j > 0 && y > 1)
    put_2_green(tab[j][y]);
  else if (tab[j][y] == '3' && j > 0 && y > 1)
    put_3_yellow(tab[j][y]);
  else if (tab[j][y] == '4' && j > 0 && y > 1)
    put_4_blue(tab[j][y]);
  else if (tab[j][y] == '5' && j > 0 && y > 1)
    put_5_purple(tab[j][y]);
  else
    my_putchar(tab[j][y]);
}
