
#include "../inc/libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s && s[i])
		i++;
	return (i);
}
