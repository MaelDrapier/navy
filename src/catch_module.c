/*
** catch_module.c for navy in /home/spiki/delivery/B2/PSU_2016_navy/Signals/catch_mod.c/
**
** Made by etienne.filliat
** Login   <etienne.filliat@epitech.eu>
**
** Started on  Wed Feb  1 11:35:12 2017 etienne.filliat
** Last update Sun Feb  5 16:47:35 2017 etienne.filliat
*/

#include <stdlib.h>
#include <signal.h>
#include "navy.h"

int		data_hdl(int act, pid_t sig_pid)
{
  static int	res = 0;
  static int	stop = 0;
  static pid_t	pid = 0;
  int		final_res;

  if (act == -84)
    {
      final_res = res;
      stop = 0;
      res = 0;
      return (final_res);
    }
  if (act == -2)
    return (pid);
  if (sig_pid != 0)
    pid = sig_pid;
  if (act == -1)
    stop = 1;
  else
    res = res + act;
  if (stop == 1)
    return (-1);
  return (res);
}

void usr_hdl (int sig, siginfo_t *siginfo, void *context)
{
  if (g_match_pid != 0 && g_match_pid != siginfo->si_pid)
    return ;
  else if (sig == 10)
    data_hdl(1, siginfo->si_pid);
  else if (sig == 12)
    data_hdl(-1, 0);
  siginfo = context;
}

void		*my_memset(void *s, char c, int size)
{
  char		*out;
  int		i;

  i = 0;
  out = s;
  while (i < size)
    {
      out[i] = c;
      i++;
    }
  return (out);
}

int			catch_module(t_struct *entity)
{
  struct sigaction 	act;

  my_memset(&act, '\0', sizeof(act));
  act.sa_sigaction = &usr_hdl;
  act.sa_flags = SA_SIGINFO;
  if (sigaction(SIGUSR1, &act, NULL) < 0)
    return (RETURN_FAIL);
  if (sigaction(SIGUSR2, &act, NULL) < 0)
    return (RETURN_FAIL);
  while (data_hdl(0, 0) != -1)
    pause();
  entity->sig1 = data_hdl(-84, 0);
  while (data_hdl(0, 0) != -1)
    pause();
  entity->sig2 = data_hdl(-84, 0);
  entity->enemy_pid = data_hdl(-2, 0);
  if (g_match_pid == 0)
    return (RETURN_SUCCESS);
  if (entity->enemy_pid == g_match_pid)
    return (RETURN_SUCCESS);
  else
    {
      sending_unmatch(entity->enemy_pid);
      return (RETURN_FAIL);
    }
}
