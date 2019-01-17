/*
** main.c for navy in /home/mael/navy_tmp/src
**
** Made by mael drapier
** Login   <mael.drapier@epitech.eu@epitech.net>
**
** Started on  Tue Jan 31 14:13:05 2017 mael drapier
** Last update Thu Feb 16 15:48:38 2017 mael drapier
*/
#include <unistd.h>
#include "navy.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}

void	my_show_pid(t_struct *entity)
{
  entity->my_pid = getpid();
  my_putstr(1, "my_pid: ");
  my_putnbr(entity->my_pid);
  my_putstr(1, "\n");
}

int	select_player2(char **av, t_struct *entity)
{
  entity->player = 2;
  entity->enemy_pid = my_getnbr(av[1]);
  g_match_pid = entity->enemy_pid;
  if (my_create_map(av[2], entity) == RETURN_FAIL)
    return (RETURN_FAIL);
  if (send_this("A1", entity) == RETURN_FAIL)
    {
      sending_error(entity->enemy_pid);
      return (RETURN_FAIL);
    }
  catch_module(entity);
  my_putstr(1, "successfully connected\n\n");
  return (RETURN_SUCCESS);
}

int	select_player(int ac, char **av, t_struct *entity)
{
  int	res;

  res = 0;
  if (ac == 2)
    {
      entity->player = 1;
      g_match_pid = 0;
      if (my_create_map(av[1], entity) == RETURN_FAIL)
	return (RETURN_FAIL);
      my_putstr(1, "waiting for enemy connexion...\n");
      catch_module(entity);
      g_match_pid = entity->enemy_pid;
      usleep(10000);
      send_this("A1", entity);
      my_putstr(1, "enemy connected\n\n");
    }
  else if (ac == 3)
    res = select_player2(av, entity);
  return (res);
}

int		main(int ac, char **av)
{
  t_struct	entity;
  int		ret;

  if (ac == 2 && my_strlen(av[1]) == 2 && av[1][0] == '-' && av[1][1] == 'h')
    return (show_helper());
  if (ac < 2 || ac > 3)
    {
      my_putstr(2, "ERROR: too few or too much arguments\n");
      my_putstr(2, "Try './navy -h' for more information.\n");
      return (RETURN_FAIL);
    }
  entity.win = 0;
  my_show_pid(&entity);
  if (select_player(ac, av, &entity) == RETURN_FAIL)
    return (RETURN_FAIL);
  play_game(&entity);
  ret = disp_win(&entity);
  return (ret);
}
