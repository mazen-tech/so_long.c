#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include <mlx.h>
# include <mlx_int.h>
# include "libft.h"



typedef struct s_coordenats
{
    int x;
    int y;
} t_coordenats;


typedef struct s_root
{
    void *mlx;
    void *mlx_win;
    t_img *mlx_img;
    t_img *win;
    t_img *player;
    t_img *coll;
    t_img *wall;
    t_img *ground;
    t_img *exit;
    t_game *game;
} t_root;


typedef struct  s_game
{
    int **map;
    int height;
    int width;

    t_coordenats player;
    int player_up;
    int player_down;
    int player_left;
    int player_right;
    int player_move;
    int player_collect;

    t_coordenats exit;
    t_coordenats *coll;
    int count_collect;
    int count_exit;
    int count_player;

} t_game;

void die(char *errmsg, int errnum);


//moves
void move_up(t_root *root, int x, int y);
void move_down(t_root *root, int x, int y);
void move_left(t_root *root, int x, int y);
void move_right(t_root *root, int x, int y);

//events 
int key_press(int keycode, t_root *root);
int key_release(int keycode, t_root *root);
int destroy_hook(int keycode, t_root *root);

//update
void update(t_root *root);

//root fucntions
void root_destroy(t_root *root, char *errmsg, int errnum);
t_root *root_init(char *filename);

//mlx utils
unsigned int mlx_get_pixel(t_img * img, int x, int y);
void mlx_draw_pixel(t_img *mlx_img, int x, int y, int color);
unsigned int mlx_rgb_to_int(int o, int r, int g, int b);

//game functions
void game_init(t_root *root, char *filename);
void game_destroy(t_game *game);

//map
void map_width(t_root *root, char *file);
void map_height(t_root *root, char *file);
void map_isvalid(t_root *root, char *file);
void map_init(t_root *root, char *filename);
void map_read(t_root *root, char *file);
void map_parsing(t_root *root, char *file);

#endif
