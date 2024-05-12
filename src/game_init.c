#include "so_long.h"

void game_init(t_root *root, char *filename)
{
    root->game = (t_game *)malloc(sizeof(t_game));
    if(root->game == 0)
        root_destroy(0, "game_init() malloc(): can't be loaded", errno);
    
    root->game->map = 0;
    root->game->coll = 0;
    root->game->count_collect = 0;
    root->game->count_exit = 0;
    root->game->count_player = 0;

    root->game->player_move = 0;
    root->game->player_collect = 0;
    root->game->player_up = 0;
    root->game->player_down = 0;
    root->game->player_left = 0;
    root->game->player_right = 0;
    map_init(root, filename);
}