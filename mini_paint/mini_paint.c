#include "micro_paint.h"

int		ft_strlen(char *str)
{
	int	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		ft_perror(char *str)
{
	write(1, str, ft_strlen(str));
	return (1);
}

int		check_pos(float x, float y, float id_x, float id_y, float radius)
{
	float distance = sqrtf(powf(x - id_x, 2) + powf(y - id_y, 2));
	if (distance <= radius)
	{
		if ((radius - distance) < 1)
			return (0);
		return (1);
	}
	return (2);
}

int		main(int argc, char *argv[])
{
	FILE	*file;
	char	*paper, background, id, color;
	int		read, pos, x, y, b_width, b_height;
	float	id_x, id_y, radius;

	if (argc != 2)
		return (ft_perror(ERR1));
	if (!(file = fopen(argv[1], "r")) ||
		(fscanf(file, "%i %i %c\n", &b_width, &b_height, &background) != 3) ||
		(!(b_width > 0 && b_width <= 300 && b_height > 0 && b_height <= 300)) ||
		(!(paper = (char *)malloc(sizeof(char) * (b_width * b_height)))))
		return (ft_perror(ERR2));
	memset(paper, background, b_width * b_height);
	while ((read = fscanf(file, "%c %f %f %f %c\n", &id, &id_x, &id_y, &radius, &color)) == 5)
	{
		if (!(radius > 0) || !(id == 'C' || id == 'c'))
			break;
		x = -1;
		while (++x < b_width)
		{
			y = -1;
			while (++y < b_height)
			{
				pos = check_pos((float)x, (float)y, id_x, id_y, radius);
				if (pos == 0 || (pos == 1 && id == 'C'))
					paper[y * b_width + x] = color;
			}
		}
	}
	if (read != -1)
	{
		free(paper);
		return (ft_perror(ERR2));
	}
	y = -1;
	while (++y < b_height)
	{
		write(1, paper + y * b_width, b_width);
		write(1, "\n", 1);
	}	
	free(paper);
	fclose(file);
	return (0);
}