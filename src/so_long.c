#include "so_long.h"

int isber(char *file)
{
    int len;

    len = ft_strlen(file);
    if (file == 0)
        return 0;
    if (len < 5)
        return (0);
    if (ft_strcmp(file + len - 4, ".ber") != 0)
        return (0);
    return (1);
}

int main(int argc, char **argv)
{
    t_root *root;

    if (argc != 2)
        die("Invalid number of arguments!", 0);
    if (isber(argv[1]) == 0)
        die("Invalid argument! (<name>.ber)", 0);
    root = root_init(argv[1]);
    draw(root);
    mlx_hook(root->mlx_win, 2, 1L << 0, key_press, root);
    mls_hook(root->mlx_win, 3, 1L << 1, key_release, root);
    mlx_hook(root->mlx_win, 17, 1L << 17, destroy_hook, root);
    mlx_loop(root->mlx);
    return (0);
}