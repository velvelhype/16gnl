#include "get_next_line.h"
#include <stdio.h>

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	nl_find(char *save)
{
	char	*ori;

	ori = save;
	while (*save)
	{
		if (*save == '\n')
			return (save - ori);
		save++;
	}
	return (-1);
}

int	split(char **save, char **line, int nl_pos)
{
	char	*tmp;

	(*save)[nl_pos] = '\0';
	*line = ft_strdup(*save);
		// int len;
        // len = ft_strlen(*save + nl_pos + 1);
        // if (len == 0)
        // {
        //         free(*save);
        //         *save = 0;
        //         return (1);
        // }
	tmp = ft_strdup(*save + nl_pos + 1);

	free(*save);
	*save = tmp;

	return (1);
}

int	get_next_line(int	fd, char	**line)
{
	static char	*save[32];
	char		buf[BUFFER_SIZE + 1];
	int			read_ret;

	if ((fd < 0) || (!line) || (BUFFER_SIZE <= 0))
		return (-1);
	while (1)
	{
		read_ret = read(fd, buf, BUFFER_SIZE);

		if (read_ret < 0)
			return (-1);
		if(read_ret != 0)
		{
			buf[read_ret] = '\0';
			save[fd] = ft_strjoin(save[fd], buf);
		}
		if (nl_find(save[fd]) != -1)
		{
			return (split(&save[fd], line, nl_find(save[fd])));
		}
		if (read_ret < BUFFER_SIZE)
		{
			if (*save[fd])
			{
				*line = save[fd];
			}
			else
			{
				*line = ft_strdup("");
			}
			return (0);
		}
	}
}
