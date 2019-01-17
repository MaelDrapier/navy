/*
** send.c for navy in /home/spiki/delivery/B2/PSU_2016_navy/Signals/
**
** Made by etienne.filliat
** Login   <etienne.filliat@epitech.eu>
**
** Started on  Tue Jan 31 14:06:47 2017 etienne.filliat
** Last update Thu Feb 16 14:35:41 2017 mael drapier
*/

#include <unistd.h>
#include <signal.h>
#include "navy.h"

int		send_that(int i, int pid_dest)
{
  while (i > 0)
    {
      if (kill(pid_dest, SIGUSR1) < 0)
	return (RETURN_FAIL);
      usleep(100);
      i--;
    }
  kill(pid_dest, SIGUSR2);
  usleep(200);
  return (RETURN_SUCCESS);
}

int	send_this(char *message, t_struct *entity)
{
  int	i;

  message = check_order_again(message);
  i = message[0] - 64;
  if (send_that(i, entity->enemy_pid) == RETURN_FAIL)
    return (RETURN_FAIL);
  i = message[1] - 48;
  if (send_that(i, entity->enemy_pid) == RETURN_FAIL)
    return (RETURN_FAIL);
  return (RETURN_SUCCESS);
}

void	sending_error(pid_t pid)
{
  my_putstr(2, "ERROR: wrong pid '");
  my_putnbr(pid);
  my_putstr(2, "'\n");
  my_putstr(2, "Try './navy -h' for more information.\n");
}

void	sending_unmatch(pid_t pid)
{
  my_putstr(1, "\nERROR: Sending torpedos from unknown terminal AKA '");
  my_putnbr(pid);
  my_putstr(1, "'\n");
}
