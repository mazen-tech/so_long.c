#include "so_long.h"

void map_read(t_root *root, char *file)
{
    map_width(root, file);
    map_height(root, file);
    map_isvalid(root, file);
    root->game->coll = (t_coordenats *)malloc(sizeof(t_coordenats) * root->game->count_collect);

    if(root->game->coll == 0)
    {
        free(file);
        root_destroy(root, "map_parsing(): malloc()", errno);
    }

    root->game->map = (int **)malloc(sizeof(int *) * root->game->height);
    if (root->game->map == 0)
    {
        free(file);
        root_destroy(root. "map_parsinf (): malloc(): ", errno);
    }
    map_parsing(root, file);
}