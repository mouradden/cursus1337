#include "philo.h"

int	ft_atoi(char *str)
{
	int		sign;
	int		res;

	sign = 1;
	res = 0;
	while ((*str >= 9 && *str <= 13) || (*str == ' '))
	{
		str++;
	}
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str <= 9 && *str >= 0)
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	return (res * sign);
}
