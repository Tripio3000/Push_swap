#include "../push_swap.h"

long long	ft_atoi_long(const char *nptr)
{
	int			i;
	long long	res;
	int			s;

	i = 0;
	s = 0;
	res = 0;
	while ((nptr[i] == ' ' || nptr[i] == '\n' || nptr[i] == '\t' ||
			nptr[i] == '\v' || nptr[i] == '\f' || nptr[i] == '\r') &&
		   nptr[i] != '\0')
		i++;
	if (nptr[i] == '-')
		s = 1;
	if (nptr[i] == '+' || nptr[i] == '-')
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9' && nptr[i] != '\0')
	{
		res = res * 10 + (nptr[i] - 48);
		if (res * 1000 < res)
			return (s ? 0 : -1);
		i++;
	}
	return (s ? -res : res);
}
