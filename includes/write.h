#ifndef WRITE_H
# define WRTIE_H

# define ENDLx2		"\n\n"
# define WIFI		"[Wifi]"
# define SSID		"ssid="
# define PASSWORD	"password="

# define PWM		"[PWM]"
# define CH			"ch"
# define EQUAL		"="

# define DAY		"[One_day]"
# define SUNRISE	"sunrise="
# define SUNSET		"sunset="

# define FILENAME	"config.ini"

int		write_pwm(int fd, const pwm_t pwm);
int		write_wifi(int fd, const wifi_t wifi);
int		write_one_day(int fd, const one_day_t day);

#endif