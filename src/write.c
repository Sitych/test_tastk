#include "parser.h"
#include "write.h"

int		write_wifi(int fd, const wifi_t wifi)
{

	if (write(fd, WIFI , ft_strlen(WIFI)) == -1)
		return (-1);
	if (write(fd, ENDLx2, ft_strlen(ENDLx2)) == -1)
		return (-2);
	if (write(fd, SSID, ft_strlen(SSID)) == -1)
		return (-3);
	if (write(fd, wifi.ssid, ft_strlen(wifi.ssid)) == -1)
		return (-4);
	if (write(fd, ENDLx2, ft_strlen(ENDLx2)) == -1)
		return (-2);
	if (write(fd, PASSWORD, ft_strlen(PASSWORD)) == -1)
		return (-6);
	if (write(fd, wifi.pass, ft_strlen(wifi.pass)) == -1)
		return (-7);
	if (write(fd, ENDLx2, ft_strlen(ENDLx2)) == -1)
		return (-2);
	return (1);
}

int		write_one_day(int fd, const one_day_t day)
{
	char	*data;
	char	*time;

	if (write(fd, DAY, ft_strlen(DAY)) == -1)
		return (-1);
	if (write(fd, ENDLx2, ft_strlen(ENDLx2)) == -1)
		return (-2);
	if (write(fd, SUNRISE, ft_strlen(SUNRISE)) == -1)
		return (-3);
	data = ctime(&(day.sunrise));
	time = ft_strchr(data, ':') + 1;
	if (write(fd, time, 5) == -1)
		return (-4);
	if (write(fd, ENDLx2, ft_strlen(ENDLx2)) == -1)
		return (-2);
	if (write(fd, SUNSET, ft_strlen(SUNSET)) == -1)
		return (-5);
	data = ctime(&(day.sunset));
	time = ft_strchr(data, ':') + 1;
	if (write(fd, time, 5) == -1)
		return (-6);
	if (write(fd, ENDLx2, ft_strlen(ENDLx2)) == -1)
		return (-2);
	return (1);
}

int		write_pwm(int fd, const pwm_t pwm)
{
	int		i;
	char	*number;

	if (write(fd, PWM, ft_strlen(PWM)) == -1)
		return (-1);
	if (write(fd, ENDLx2, ft_strlen(ENDLx2)) == -1)
		return (-1);
	i = 0;
	while (i < 5)
	{
		if (write(fd, CH, ft_strlen(CH)) == -1)
			return (-1);
		number = ft_itoa(i + 1);
		if (number == NULL)
		{
			ft_putstr("Error: malloc error\n");
			exit(EXIT_FAILURE);
		}
		if (write(fd, number, ft_strlen(number)) == -1)
			return (-1);
		ft_strdel(&number);
		if (write(fd, EQUAL, ft_strlen(EQUAL)) == -1)
			return (-1);
		number = ft_itoa(pwm.ch1);
		if (number == NULL)
		{
			ft_putstr("Error: malloc error\n");
			exit(EXIT_FAILURE);
		}
		if (write(fd, number, ft_strlen(number)) == -1)
			return (-1);
		if (write(fd, ENDLx2, ft_strlen(ENDLx2)) == -1)
			return (-1);
		ft_strdel(&number);
		i++;
	}
	return (1);
}