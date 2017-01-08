/*
** my_getnbr.c for my_getnbr in /home/Maxime/delivery/CPool_Day04
**
** Made by Maxime JENNY
** Login   <Maxime@epitech.net>
**
** Started on  Thu Oct  6 19:18:32 2016 Maxime JENNY
** Last update Fri Jan  6 11:15:01 2017 Maxime JENNY
*/

int		my_get_number(char *str, int *i)
{
  int		nbr;

  if (str[*i] == '\n')
    *i = *i + 1;
  if (str[*i] <= '9' && str[*i] >= '0')
    nbr = str[*i] - 48;
  else
    nbr = str[*i];
  return (nbr);
}
