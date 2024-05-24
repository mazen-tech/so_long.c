#include "so_long.h"

void map_height(t_root *root, char *file)
{
    int i;
    int j;

    root->game->height = 1;
    i = root->game->width + 1;//to count width od the first row

    while (file[i] != 0)//if the width of the map not = 0
    {
        j = 0;
        while (file[i + j] != 0 && file[i + j] != '\n')
           j++;
           /*if the width value not matching the prevois claculated width
           that means there is in consistancy in map dimensions*/
        if (root->game->width != j)
        {
            free(file);
            root_destroy(root, "map is invaled", 0);
        }
        i = i + root->game->width + 1;//move to the next row in the file
        root->game->height++;
    }
    
}