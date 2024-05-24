#include "so_long.h"

static void tex_load(t_root *root, t_img **img, char *path)
{
    int width;
    int height;

    *img = mlx_xpm_file_to_image(root->mlx, path, &width, &height);
    if (*img == 0)
        root_destroy(0, "Texure can't be loaded!", 0);
    (*img)->width = width;
    (*img)->height = height;
}

static void tex_init(t_root *root)
{
    tex_load(root, &root->player,  );//player
    tex_load(root, &root->ground,  );//ground
    tex_load(root, &root->wall,    );//wall
    tex_load(root, &root->coll,    );//collectable
    tex_load(root, &root->exit,    );//exit

}

static void render_init(t_root *root)
{
    root->mlx = mlx_init();
    if(root->mlx == 0)
        root_destroy(0, "mlx_init(): can't load", 0);

    root->mlx_win = mlx_new_window(root->mlx, root->game->width * 40, root->game->height * 40, "so_long");
    if(root->mlx_win == 0)
        root_destroy(0, "mlx_new_window(): can't load", 0);

    root->mlx_img = mlx_new_image(root->mlx, root->game->width * 40, root->game->height * 40);
    if(root->mlx_img == 0)
        root_destroy(0, "mlx_new_image(): can't load, 0");
}

t_root *root_init(char *filename)
{
    t_root *root;

    root = (t_root *)malloc(sizeof(t_root));
    if (root == 0)
        root_destroy(0, "root_init(): malloc()", errno);
    root->game = 0;
    root->mlx = 0;
    root->mlx_win = 0;
    root->mlx_img = 0;
    root->player = 0;
    root->ground = 0;
    root->coll = 0;
    root->wall = 0;
    root->exit = 0;
    game_init(root, filename);
    render_init(root);
    tex_init(root);
}