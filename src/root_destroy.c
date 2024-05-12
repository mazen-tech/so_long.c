#include  "so_long.h"

void root_destroy(t_root *root, char *errmsg, int errnum)
{
    if (root != 0)
    {
        if (root->ground != 0)
            mlx_destroy_image(root->mlx, root->ground);
        if (root->wall != 0)
            mlx_destroy_image(root->mlx, root->wall);
        if (root->coll != 0)
            mlx_destroy_image(root->mlx, root->coll);
        if (root->exite != 0)
            mlx_destroy_image(root->mlx, root->exit);
        if (root->player != 0)
            mlx_destroy_image(root->mlx, root->player);
        if (root->mlx_img != 0)
            mlx_destroy_image(root->mlx, root->mlx_img);
        if (root->mlx_win)
            mlx_destroy_window(root->mlx, root->mlx_win);
        if (root->mlx_img)
            mlx_destroy_display(root->mlx);
        free(root);
    }
    die(errmsg, errnum);
}