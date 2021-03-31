#ifndef MINI_PAINT_H
# define MINI_PAINT_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int		ft_strlen(char *str);
int		ft_error(char *str);
int		check_pos(float x, float y, float id_x, float id_y, float radius);
int		main(int argc, char *argv[]);

#define ERR1 "Error: argument\n"
#define ERR2 "Error: Operation file corrupted\n"

#endif

