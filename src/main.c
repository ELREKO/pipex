#include "../includes/pipex.h"


int main(int ac, char **ag, char **envp) 
{
    t_arg *argument;

    // Argument Reading! 
    argument = NULL;
    if (ac != 5)
        ft_throw_error("Missing arguments \n", &argument);
    else
        argument = ft_read_arg(ag, envp);

    


    //printf ("Arguments\n-------\nInfile|%s|\ncmd 1 |%s|\ncmd 1 flag |%s|\ncmd 2 |%s|\ncmd 2 flag |%s|\nOutfile |%s|\nPath 1 |%s|\nPath 2 |%s|\n", 
      //  argument->inflile, argument->cmd_1[0], argument->cmd_1[1], argument->cmd_2[0], argument->cmd_2[1], argument->outfile, argument->path_1, argument->path_2);
    printf ("Arguments\n-------\nInfile|%s|\ncmd 1 |%s|\ncmd 1 flag |%s|\ncmd 2 |%s|\ncmd 2 flag |%s|\nOutfile |%s|\n", 
        argument->inflile, argument->cmd_1[0], argument->cmd_1[1], argument->cmd_2[0], argument->cmd_2[1], argument->outfile);
    




    ft_free_struct_arg(&argument);
    



}
