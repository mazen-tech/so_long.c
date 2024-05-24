#include "so_long.h"

static int isborded(t_root *root, int i)
{
    /*first we check if i is in the first row
     second we check if i is in the bottom border
     third if i is in the left most edge
     fourth if i is in the right most edge*/
    if (i < root->game->width 
        || i > (root->game->width + 1) * (root->game->height -1) 
        || i % (root->game->width + 1) == 0
        || i % (root->game->width + 1) == root->game->width - 1)
        return (1);
    return (0);
}

static int isvalid(t_root *root, char *file, int i)
{
    if(file[i] == 'P')
        root->game->count_player++;
    else if (file[i] == 'E')
        root->game->count_exit++;
    else if (file[i] == 'C')
        root->game->count_collect++;
    else if (file[i] == '1' || file[i] == '0')
        return ;
    
    else 
    {
        free(file);
        root_destroy(root, "Map is invalid!", 0);
    }
}

void map_isvalid(t_root *root, char *file)
{
    int i;

    i = -1;
    /*in summary this loop processes each charcter of the file string checks
    if it's at a border and validates the map accordengly*/
    while (file[i++] != 0)
    {
        if(file[i] == '\n')
            continue ;
        if(isborded(root, i))
        {
            if(file[i] != '1')
            {
                free(file);
                root_destroy(root, "map need to be surrounded by walls", 0);
            }
        }
        else
            isvalid(root, file, i);
    }

    if(root->game->count_player != 1
        || root->game->count_exit != 1
        || root->game->count_collect < 1)
        {
            free(file);
            root_destroy(root, "map is invaled", 0);
        }

}