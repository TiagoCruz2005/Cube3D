# include "cube3d.h"

int is_blank_line(char *line)
{
    if (!line)
        return (1);
    if (line[0] == '\n' && line[1] == '\0')
        return (1);
    if (line[0] == '\0')
        return (1);
    return (0);
}

void    free_line_close_fd(char *line, int *fd)
{
    if (line)
        free(line);
    if (*fd != -1)
    {
        close(*fd);
        *fd = -1;
    }
}
