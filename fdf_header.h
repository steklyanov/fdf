#ifndef FDF_HEADER
# define FDF_HEADER

#include "minilibx_macos/mlx.h"
#include "libft/libft.h"
#include <unistd.h>


typedef struct  s_point
{
    int         x;
    int         y;
    int         z;
    int         color;
    int         sin;
    
}               t_point;



typedef struct  s_map
{
    int         count_col;
    int         count_line;
    t_point     **line;
}               t_map;

typedef struct  s_main
{
    int         image_hight;
    int         image_weight;
    void        *mlx_ptr;
	void	    *win_ptr;
    t_map       *map;
    t_point     **point;
    void        *img_ptr;
	char        *data;
}               t_main;

typedef struct s_angle
{
    double      a_x;
    double      a_y;
    double      a_z;
    
}               t_angle;


void            ft_pridumat_name(char *str, t_map *map);
int			    ft_abs(int a);
void		    draw_line(t_map *map, int x1, int y1, int x2, int y2, t_main *main);
void            put_point_to_image(char *image_data, int x, int y, int color, t_main *main);
void		    draw_map(t_map *map, char *image_data);
t_point	        rotate(t_point p);
void		calc_point_position(t_main *main);
void	demo_print_map(t_main	*main);

#endif