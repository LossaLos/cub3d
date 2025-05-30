
#include "../inc/cub3D.h"

/*
this function stores the player position in the t_cub structure and replaces the
player character by a '0' in the map.
*/
static void	store_player_position(t_cub *cub, size_t i, size_t j, char heading)
{
	cub->player.x = j;
	cub->player.y = i;
	cub->player.heading = heading;
	cub->map.grid[i][j] = '0';
}

/*
thid function stores the right values of the cell in the map grid. If the cell
is out of bounds, it stores a space.
*/
static void	store_grid_cell_value(t_cub *cub, size_t i, size_t j, char **lines)
{
	if (j < ft_strlen(lines[i]))
	{
		if (lines[i][j] == 'N'
			|| lines[i][j] == 'S'
			|| lines[i][j] == 'E'
			|| lines[i][j] == 'W')
			store_player_position(cub, i, j, lines[i][j]);
		else if (lines[i][j] == '\n')
			cub->map.grid[i][j] = ' ';
		else
			cub->map.grid[i][j] = lines[i][j];
	}
	else
		cub->map.grid[i][j] = ' ';
}

/*
this function finds the longest line in the map grid to set the least width of
the map.
*/
size_t	find_longest_line(char **lines)
{
	size_t	i;
	size_t	j;
	size_t	max;

	i = 0;
	max = 0;
	while (lines[i])
	{
		j = ft_strlen(lines[i]);
		if (lines[i][j - 1] == '\n')
			j--;
		while (j > 0 && lines[i][j - 1] == ' ')
			j--;
		if (j > max)
			max = j;
		i++;
	}
	return (max);
}

/*
this function parses the lines from the .cub file and stores the map grid in the
t_cub structure.
*/
int	parse_lines(t_cub *cub, char **lines)
{
	size_t	i;
	size_t	j;

	cub->map.width = find_longest_line(lines);
	cub->map.grid = ft_calloc(cub->map.height, sizeof(int *));
	if (!cub->map.grid)
		return (ft_eprintf(ERR ALLOC_ERR" for map\n"), ERROR);
	i = -1;
	while (++i < cub->map.height)
	{
		cub->map.grid[i] = ft_calloc(cub->map.width, sizeof(int));
		if (!cub->map.grid[i])
			return (ft_free_double_int_array(cub->map.grid, i), \
			ft_eprintf(ERR ALLOC_ERR" for map\n"), ERROR);
		j = -1;
		while (++j < cub->map.width)
			store_grid_cell_value(cub, i, j, lines);
	}
	return (SUCCESS);
}
