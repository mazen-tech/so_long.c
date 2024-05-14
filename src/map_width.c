#include "so_long.h"

void map_width(t_root *root, char *file)
{
    root->game->width = 0;
    while (file[root->game->width] && file[root->game->width] != '\n')
        root->game->width++;

    /*here we checking it the loop terminated because the 
    width of the map is zero or the loop reached the end of the file */
    if (root->game->width == 0 || file[root->game->width] == 0)
    {
        free(file);
        root_destroy(root, "map is invalid", 0);
    }
}
