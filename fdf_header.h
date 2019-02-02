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
}               t_point;

typedef struct  s_map
{
    int         col;
    int         line;
}               t_map;



typedef struct  s_main
{
    void        *mlx_ptr;
	void	    *win_ptr;
}               t_main;



// Init some global var

t_main          *g_main;

#endif