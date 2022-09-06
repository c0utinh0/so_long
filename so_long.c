/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcoutinh <dcoutinh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 17:03:20 by dcoutinh          #+#    #+#             */
/*   Updated: 2022/09/06 20:31:52 by dcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx/mlx.h"

typedef struct s_data 
{
	void	*img;
	char	*addr;
	int	bits_per_pixel;
	int	line_length;
	int endian;
	void	*mlx;
	void	*window;

}	t_data;

void	my_mlx_pixel_put(t_data	*data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int my_close(int keycode, t_data	*obj)
{
	(void)keycode;
	my_mlx_pixel_put(obj, 5, 5, 0x00FF0000);
//	mlx_destroy_window(obj->mlx, obj->window);
	return(0);
}

int main(void)
{
	t_data	obj;

	obj.mlx = mlx_init();
	obj.window = mlx_new_window(obj.mlx, 840, 420, "MyGame");
	mlx_hook(obj.window, 2, 1L<<0, my_close, &obj);


//	obj.img = mlx_new_image(obj.mlx, 840, 420);
//	obj.addr = mlx_get_data_addr(obj.img, &obj.bits_per_pixel, &obj.line_length, &obj.endian);
//	my_mlx_pixel_put(&obj, 5, 5, 0x0000FF00);
//	mlx_put_image_to_window(obj.mlx, obj.window, obj.img, 0, 0);
	mlx_loop(obj.mlx);
    return (0);
}
