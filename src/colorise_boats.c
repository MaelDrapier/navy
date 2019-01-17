/*
** colorise_boats.c for navy in /home/spiki/delivery/B2/PSU_2016_navy/bonus/src/
**
** Made by etienne.filliat
** Login   <etienne.filliat@epitech.eu>
**
** Started on  Sun Feb  5 12:38:56 2017 etienne.filliat
** Last update Sun Feb  5 12:39:52 2017 etienne.filliat
*/

#include "navy.h"

void		put_2_green(char x)
{
  my_putstr(1, COL_2_GREEN);
  my_putstr(1, FG_BOLD);
  my_putchar(x);
  my_putstr(1, COL_DEF);
}

void		put_3_yellow(char x)
{
  my_putstr(1, COL_3_YELLOW);
  my_putstr(1, FG_BOLD);
  my_putchar(x);
  my_putstr(1, COL_DEF);
}

void		put_4_blue(char x)
{
  my_putstr(1, COL_4_BLUE);
  my_putstr(1, FG_BOLD);
  my_putchar(x);
  my_putstr(1, COL_DEF);
}

void		put_5_purple(char x)
{
  my_putstr(1, COL_5_PURPLE);
  my_putstr(1, FG_BOLD);
  my_putchar(x);
  my_putstr(1, COL_DEF);
}
