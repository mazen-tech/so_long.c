#include "so_long.h"

static void free_matrix(t_root *root, char *file, int **matrix, int size)
{
    int i;
    i = 0;

    while (i < size)
        free(matrix[i++]);
    free(matrix);
    root->game->map = 0;//set the map pointer to null indecats it's no longer valid
    free(file);
    root_destroy(root, "map_parsing(): malloc():", errno);
}

/*k -> is index of the current charcter in the file string 
int *obj is a pointer to an integer that tracks the number of collectibles*/
static void get_coord(t_root *root, char *file, int k, int *obj)
{
    if (file[k] == 'P')
    {
        root->game->player.x = k % (root->game->width + 1);
        root->game->player.y = k / (root->game->width + 1);
        file[k] = '0';
    }

    if (file[k] == 'E')
    {
        root->game->exit.x = k % (root->game->width + 1);//column position by finding reminder of k
        root->game->exit.y = k / (root->game->width + 1);//row position by finding integer division
        file[k] = '0';
    }

    else if (file[k] == 'C')
    {
        root->game->coll[*obj].x = k % (root->game->width + 1);
        root->game->coll[*obj].y = k / (root->game->width + 1);
        file[k] = '0';
        (*obj)++;
    }
}

void map_parsing(t_root *root, char *file)
{
    int i;//row
    int j;//column
    int k;//charcter
    int obj;//counter for number of collectibles

    i = 0;
    j = -1;
    k = 0;
    obj = 0;

    //we will iterate throw each row of the map
    while (++j < root->game->height)
    {
        root->game->map[j] = (int *)malloc(sizeof(int) * root->game->width);
        if (root->game->map[j] == 0)
            free_matrix(root, file, root->game->map, j);
        
        while ( i < root->game->width)
        {
            get_coord(root, file, k, &obj);
            root->game->map[j][i++] = file[k++] - 48;
        }
        k++;
    }

}