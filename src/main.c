#include "parser.h"

char	*read_file(const int fd)
{
	char	*result;
	char	*buf;
	char	read_str[BUF_READ + 1];
	int		len;

	len = read(fd, read_str, BUF_READ);
	read_str[len] = 0;
	result = ft_strdup(read_str);
	if (result == NULL)
	{
		ft_putstr("Error: malloc error\n");
		exit(EXIT_FAILURE);
	}
	while (BUF_READ - len == 0)
	{
		len = read(fd, read_str, BUF_READ);
		read_str[len] = 0;
		buf = ft_strjoin(result, read_str);
		ft_strdel(&result);
		result = buf;
		if (result == NULL)
		{
			ft_putstr("Error: malloc error\n");
			exit(EXIT_FAILURE);
		}
	}
	return (result);
}

int main(int argc, char **argv)
{
	config_t	*config = NULL;

	if (argc < 2)
	{
		ft_printf("Usage: %s <sourcefile.ini>\n", argv[0]);
		return (0);
	}
	if (config_read(argv[1], config) == -1)
	{
		ft_printf("Error: read config file");
		return (-1);
	}
	return (0);
}
