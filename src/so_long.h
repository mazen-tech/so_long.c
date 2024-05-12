#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include <mlx.h>
# include <mlx_mini.h>
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


//moves
void move_up(t_root *root, int x, int y);
void move_down(t_root *root, int x, int y);
void move_left(t_root *root, int x, int y);
void move_right(t_root *root, int x, int y);

//root fucntions
void root_destroy(t_root *root, char *errmsg, int errnum);
t_root *root_init(char *filename);

//game functions
void game_init(t_root *root, char *filename);
void game_destroy(t_game *game);
#endif