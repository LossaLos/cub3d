
#include "../inc/cub3D.h"

/*
this function checks if the map is surrounded by walls.
*/
static int	inside_loop(t_pos *stack, int top, t_map *map, int heading[4][2])
{
	size_t	i;
	size_t	nr;
	size_t	nc;
	int		row;
	int		col;

	i = -1;
	row = stack[top].row;
	col = stack[top].col;
	while (++i < 4)
	{
		nr = row + heading[i][0];
		nc = col + heading[i][1];
		if (nr < 0 || nr >= map->height || nc < 0 || nc >= map->width)
			return (ERROR);
		else if (map->grid[nr][nc] == '0')
		{
			stack[top].row = nr;
			stack[top].col = nc;
			top++;
		}
		else if (map->grid[nr][nc] != '1' && map->grid[nr][nc] != '2')
			return (ERROR);
	}
	return (SUCCESS);
}

/*
this function initializes the heading map helper for the flood fill algorithm.
*/
static void	init_heading_map(int heading[4][2])
{
	heading[0][0] = -1;
	heading[0][1] = 0;
	heading[1][0] = 1;
	heading[1][1] = 0;
	heading[2][0] = 0;
	heading[2][1] = -1;
	heading[3][0] = 0;
	heading[3][1] = 1;
}

/*
this function performs a flood fill algorithm to check if the map is surrounded
by walls.
*/
static int	flood_fill(t_map *map, int start_row, int start_col)
{
	int		top;
	int		heading[4][2];
	t_pos	*stack;

	top = 0;
	init_heading_map(heading);
	stack = (t_pos *)ft_calloc(map->height * map->width, sizeof(t_pos));
	if (!stack)
		return (free(stack), ft_eprintf(ERR ALLOC_ERR" for stack\n"), ERROR);
	stack[top].row = start_row;
	stack[top].col = start_col;
	top++;
	while (top > 0)
	{
		top--;
		if (map->grid[stack[top].row][stack[top].col] != '0')
			continue ;
		map->grid[stack[top].row][stack[top].col] = '2';
		if (!inside_loop(stack, top, map, heading))
			return (free(stack), ERROR);
	}
	return (free(stack), SUCCESS);
}

/*
this function replaces back the '2' by '0' in the map grid after the flood fill
algorithm.
*/
void	replace_two_by_zeros(t_map *map)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->grid[i][j] == '2')
				map->grid[i][j] = '0';
			j++;
		}
		i++;
	}
}

/*
this function checks if the map is surrounded by walls and returns an error if
it's not then replaces back the '2' by '0' in the map grid after the flood fill.
*/
int	check_map_validity(t_map *map)
{
	size_t	row;
	size_t	col;

	row = -1;
	while (++row < map->height)
	{
		col = -1;
		while (++col < map->width)
		{
			if (map->grid[row][col] != '0')
				continue ;
			if (!flood_fill(map, row, col))
			{
				ft_printf(ERR"Map is not surrounded by walls\n");
				ft_free_double_int_array(map->grid, map->height);
				return (ERROR);
			}
		}
	}
	replace_two_by_zeros(map);
	return (SUCCESS);
}
