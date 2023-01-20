/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msekhsou <msekhsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 19:14:28 by msekhsou          #+#    #+#             */
/*   Updated: 2023/01/16 16:25:36 by msekhsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_img(t_infos *my)
{
	mlx_clear_window(my->mlx_ptr, my->mlxp_win);
	print_wall1(my);
	print_collectc(my);
	print_playerp(my);
	print_exite(my);
	print_floor0(my);
}

void	print_map(t_infos *my)
{
	my->i = 0;
	my->j = 0;
	my->mv_count = 0;
	my->mlx_ptr = mlx_init();
	my->mlxp_win = mlx_new_window(my->mlx_ptr, ft_strlen(my->map[my->i]) * 64,
	maplines(my->map) * 64, "so_long");
	// printf("%zu\n %d\n",ft_strlen(my->map[my->i]) , maplines(my->map));
	// printf("%s",my->map[0]);
	my->img_1 = mlx_xpm_file_to_image(my->mlx_ptr, "./image/wall.xpm", &my->i,&my->j);
	my->img_c = mlx_xpm_file_to_image(my->mlx_ptr, "./image/collectible.xpm", &my->i,&my->j);
	my->img_p = mlx_xpm_file_to_image(my->mlx_ptr, "./image/player.xpm", &my->i,&my->j);
	my->img_e = mlx_xpm_file_to_image(my->mlx_ptr, "./image/door.xpm", &my->i,&my->j);
	my->img_0 = mlx_xpm_file_to_image(my->mlx_ptr, "./image/floor.xpm", &my->i,&my->j);
	print_img(my);
	mlx_loop(my->mlx_ptr);
}