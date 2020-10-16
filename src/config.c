#include "parser.h"
#include "funforparse.h"

void	print_config(config_t *config)
{
	ft_printf("Wifi:\n%s\n%s\n",config->wifi.ssid, config->wifi.pass);
	ft_printf("One_day:\n%d\n%d\n",config->day.sunrise, config->day.sunset);
	ft_printf("PWM:\n%d\n%d\n%d\n%d\n%d\n",config->pwm.ch1, config->pwm.ch2, config->pwm.ch3, config->pwm.ch4, config->pwm.ch5);
}

config_t	*config_create(void)
{
	config_t	*tmp;

	tmp = (config_t*)ft_malloc(sizeof(config_t));
	tmp->day.sunrise = LONG_MAX;
	tmp->day.sunset = LONG_MAX;
	tmp->wifi.ssid = NULL;
	tmp->wifi.pass = NULL;
	tmp->pwm.ch1 = INT32_MAX;
	tmp->pwm.ch2 = INT32_MAX;
	tmp->pwm.ch3 = INT32_MAX;
	tmp->pwm.ch4 = INT32_MAX;
	tmp->pwm.ch5 = INT32_MAX;
	return (tmp);
}

int	config_read(const char* __ini_data, config_t* __out_config)
{
	int 	fd;
	char	*str;
	char	**lines;
	section_t *ptr;

	__out_config = config_create();
	fd = open(__ini_data, O_RDONLY);
	if (fd == -1)
	{
		perror("open failed on input file");
		return (0);
	}
	str = read_file(fd);
	lines = ft_strsplit(str, '\n');
	if (lines == NULL)
	{
		ft_putstr("Error: malloc error\n");
		exit(EXIT_FAILURE);
	}
	ptr = sections_parse(lines);
	section_t *tmp;
	tmp = ptr;
	funforparse_t	*ptr1;
	while (tmp)
	{
		ptr1 = parse_g;
		while (ptr1->str)
		{
			if (!ft_strcmp(tmp->name, ptr1->str))
				break ;
			ptr1++;
		}
		if (!ptr1->str)
		{
			ft_printf("Unknown name section %s\n", ptr->name);
			return (0);
		}
		__out_config = ptr1->fun(tmp, __out_config);
		tmp = tmp->next;
	}
	int i = 0;
	while (lines[i])
		i++;
	ft_free((void**)lines, i);
	lines = NULL;
	print_config(__out_config);
	// ft_printf("%s %s", __out_config->wifi.pass, ptr->name);
	close(fd);
	return (1);
}
