#include "get_next_line.h"
#include <stdio.h>
int main(int ac, char **av)
{
    char *line;
    int fd;
    if(ac == 10)
        write(1,"hello",1);
    fd = open(av[1], O_RDONLY);
   int i = 0;
    while(i++ < 100)
    {

        get_next_line(fd, &line);
        printf("pf_back:%s\n",line);
        //free(line);
        // get_next_line(fd, &line);
        // printf("pf_back:%s\n",line);
        // free(line);
    }
//     printf("pf_back:%s\n",line);
//    free(line);
// get_next_line(fd, &line);
// printf("pf_back:%s\n",line);
// free(line);
// get_next_line(fd, &line);
// printf("pf_back:%s\n",line);
// free(line);
// get_next_line(fd, &line);
// printf("pf_back:%s\n",line);
// free(line);
// get_next_line(fd, &line);
// printf("pf_back:%s\n",line);
// free(line);

    // get_next_line(fd, &line);
    // printf("pf_back:%s\n",line);
    // free(line);
    // get_next_line(fd, &line);
    // printf("pf_back:%s\n",line);
    // free(line);
    // get_next_line(fd, &line);
    // printf("pf_back:%s\n",line);
    // free(line);
    
    
    
//   system("leaks a.out");
    return (0);
}