#include "get_next_line.h"
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

int	main(int argc, char *argv[])
{
	int		fd;
	char	*str;

	if (argc == 1)
		return (0);
	fd = open(argv[1], O_RDONLY);
	while (1)
	{
		str = get_next_line(fd);
		if (str == NULL)
			break ;
		printf("%s", str);
		free(str);
	}
	free(str);
	return (0);
}
