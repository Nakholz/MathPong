/*
** my_getnbr.c for  in /home/arnhol_m/rendu/pong
** 
** Made by Martin Arnholz
** 
** Started on  Sat Nov 15 18:27:54 2014 Martin Arnholz
** Last update Mon Apr 25 14:35:02 2016 
*/

int	my_getnbr(char *nbr)
{
  char	*base = "0123456789";
  int	i;
  int	nb_retur;
  int	j;
  int	inv;

  inv = 1;
  nb_retur = 0;
  i = 0;
  j = limite(nbr);
  while (base[i] != 0)
    {
      if (base[i] == nbr[j] && base[i] != 0)
	{
	  i = i * inv;
	  nb_retur = nb_retur + i;
	  inv = inv * 10;
	  i = (-1);
	  j--;
	}
      i++;
    }
  nb_retur = negat(nbr, base, nb_retur);
  return (nb_retur);
}

int	limite(char *nbr)
{
  int	j;

  j = 0;
  while (nbr[j] == '-' || nbr[j] == '+')
    j++;
  if (nbr[j] >= 48 && nbr[j] <= 57 && nbr[j] != 0)
    {
      while (nbr[j] >= 48 && nbr[j] <= 57 && nbr[j] != 0)
	{
	  j++;
	}
      j--;
    }
  return (j);
}

int	negat(char *nbr, char *base, int nb_retur)
{
  int	i;

  i = 0;
  while (nbr[i] == '-' || nbr[i] == '+')
    {
      if (nbr[i + 1] != '-' && nbr[i + 1] != '+')
	{
	  if (nbr[i] == '-')
	    {
	      nb_retur = nb_retur * (-1);
	      return (nb_retur);
	    }
	}
      i++;
    }
  return (nb_retur);
}
