
#include "../inc/cub3D.h"

/*
this function frees the images used for the textures.
*/
void	free_textures(t_ray *rc, int i)
{
	while (i < 4)
	{
		if (rc->texture[i].img)
			mlx_destroy_image(rc->mlx, rc->texture[i].img);
		i++;
	}
}

/*
this function frees the mlx pointers.
*/
void	free_mlx(t_ray *rc)
{
	free_textures(rc, 0);
	if (rc->win)
		mlx_destroy_window(rc->mlx, rc->win);
	if (rc->mlx)
		mlx_destroy_display(rc->mlx);
	if (rc->mlx)
		ft_free(rc->mlx);
}

/*
this function frees all the pointers used by the execution of the program.
*/
void	free_all(t_ray *rc)
{
	free_mlx(rc);
	ft_free(rc);
}
