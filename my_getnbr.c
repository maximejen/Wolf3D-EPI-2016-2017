/*
** my_getnbr.c for my_getnbr in /home/Maxime/delivery/CPool_Day04
**
** Made by Maxime JENNY
** Login   <Maxime@epitech.net>
**
** Started on  Thu Oct  6 19:18:32 2016 Maxime JENNY
** Last update Tue Dec 13 11:15:41 2016 Maxime JENNY
*/

int		my_get_number(char *str, int *i)
{
  int		nbr;

  if (str[*i] == '\n')
    *i = *i + 1;
  nbr = str[*i] - 48;
  return (nbr);
}
