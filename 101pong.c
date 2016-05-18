/*
** 101pong.c in /home/nakholz/rendu/perso/101pong
** 
** Made by Arnholz Martin
** Login : arnhol_m
** 
** Started on  Mon Apr 25 14:35:19 2016 
** Last update Mon Apr 25 14:35:22 2016 
*/

#include <math.h>
#include <stdio.h>

double	normes(double x3, double y3, double z3)
{
  double	result;

  result = sqrt(pow(x3, 2) + pow(y3, 2) + pow(z3, 2));
  return (result);
}

double	my_angle(int x3, int y3, int z3)
{
  double	v;
  double	r;
  double	result;

  v = normes(x3, y3, z3);
  r = normes(x3, y3, 0);
  if (v == 0)
    {
      printf("Il faut que vecteur vitesse soit différent de (0;0;0).\n");
      return (1);
    }
  result = r / v;
  result = acos(result);
  result = result * 57,2957795131;
  printf("L'ange d'incidence est de %.2f degré.\n", result);
}

int	my_position(int x2, int y2, int z2, int n, int x3, int y3, int z3)
{
  int	x4;
  int	y4;
  int	z4;

  x4 = x2+n*x3;
  y4 = y2+n*y3;
  z4 = z2+n*z3;
  printf("A l'instant t+ %d les coordonnées de la balle seront (%d ; %d ; %d );\n", n, x4, y4, z4);
  my_angle(x3, y3, z3);
}

int	my_coord(int x1, int x2, int y1, int y2, int z1, int z2, int n)
{
  int	x3;
  int	y3;
  int	z3;

  x3 = x2 - x1;
  y3 = y2 - y1;
  z3 = z2 - z1;
  printf("Les coordonées du vecteur vitesse sont (%d;%d;%d).\n",x3, y3, z3);
  my_position(x2, y2, z2, n, x3, y3, z3);
}

int	main(int ac, char **av)
{
  int	x1;
  int	x2;
  int	y1;
  int	y2;
  int	z1;
  int	z2;
  int	n;

  if (ac == 8)
    {
      x1 = my_getnbr(av[1]);
      y1 = my_getnbr(av[2]);
      z1 = my_getnbr(av[3]);
      x2 = my_getnbr(av[4]);
      y2 = my_getnbr(av[5]);
      z2 = my_getnbr(av[6]);
      n = my_getnbr(av[7]);
      my_coord(x1, x2, y1, y2, z1, z2, n);
    }
  else
    return (1);  
}
