#include "../includes/pipex.h"

void ft_throw_error(char *str, t_arg **arg)
{
    ft_free_struct_arg(arg);
    write(1, str, ft_strlen(str));
    exit (0);
}


void ft_free_struct_arg(t_arg **arg)
{
    if (*arg != NULL)
    {
        ft_free_map((*arg)->cmd_1);
        ft_free_map((*arg)->cmd_2);
        ft_free_str((*arg)->inflile);
        ft_free_str((*arg)->outfile);
        ft_free_str((*arg)->path_1);
        ft_free_str((*arg)->path_2);
        free(*arg);
    }
    
}

void ft_free_str(char *str)
{
    if (str != 0)
        free(str);
}

void ft_free_map(char **map)
{
    int i = 0;
    while (map[i] != NULL)
    {
        free(map[i]);
        i++;
    }
    free(map);
}

// void ft_free_map(char **map)
// {
//     int i_count;

//     if (map != NULL)
//     {
//         i_count = 0; 
//         while (map[i_count] != NULL)
//             i_count++;
//         while (i_count >= 0)
//             free(map[i_count--]);
//         free(map);
//     }
//     //map = NULL;
// }