#include "parser.h"

static char	*wifi_field(char *name, char **data)
{
	int		i;
	char	*field;
	char	*pos;

	i = 0;
	field = NULL;
	while (ft_strstr(data[i], name) == 0)
		i++;
	pos = ft_strchr(data[i], '=');
	if (pos)
	{		
		field = ft_strdup(pos + 1);
		if (field == NULL)
		{
			ft_putstr("Error: malloc error\n");
			exit(EXIT_FAILURE);
		}
	}
	return (field);
}

config_t	*wifi_parser(section_t *ptr, config_t *config)
{
	char *field;

	if ((field = wifi_field("ssid", ptr->data)) != NULL)
		config->wifi.ssid = field;
	if ((field = wifi_field("password", ptr->data)) != NULL)
		config->wifi.pass = field;
	return (config);
}

static long int	one_day_field(char *name, char **data)
{
	int			i;
	char		*pos;
	long int	time;

	i = 0;
	time = -1;
	while (ft_strstr(data[i], name) == 0)
		i++;
	pos = ft_strchr(data[i], '=');
	if (pos + 1)
	{
		time = ft_atoi(pos + 1);
		pos = ft_strchr(data[i], ':');
		if (pos)
			time += ft_atoi(pos + 1);
	}
	return (time);
}

config_t	*one_day_parser(section_t *ptr, config_t *config)
{
	long int time;

	time = one_day_field("sunrise", ptr->data);
	if (time != -1)
		config->day.sunrise = time;
	time = one_day_field("sunset", ptr->data);
	if (time != -1)
		config->day.sunset = time; 
	return (config);
}

static uint32_t	pwm_field(char *name, char **data)
{
	uint32_t res;
	int		i;
	char	*pos;

	i = 0;
	res = 0xffffffff;
	while (ft_strstr(data[i], name) == 0)
		i++;
	pos = ft_strchr(data[i], '=');
	if (pos)
		res = ft_atoi(pos + 1);
	return (res);
}

config_t	*pwm_parser(section_t *ptr, config_t *config)
{
	uint32_t ch;

	if ((ch = pwm_field("ch1", ptr->data)) != 0xffffffff)
		config->pwm.ch1 = ch;
	if ((ch = pwm_field("ch2", ptr->data)) != 0xffffffff)
		config->pwm.ch2 = ch;
	if ((ch = pwm_field("ch3", ptr->data)) != 0xffffffff)
		config->pwm.ch3 = ch;
	if ((ch = pwm_field("ch4", ptr->data)) != 0xffffffff)
		config->pwm.ch4 = ch;
	if ((ch = pwm_field("ch5", ptr->data)) != 0xffffffff)
		config->pwm.ch5 = ch;
	return (config);
}