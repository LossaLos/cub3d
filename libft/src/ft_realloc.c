
#include "../inc/libft.h"

void	*ft_realloc(void *ptr, size_t original_size, size_t new_size)
{
	size_t	size_to_copy;
	void	*new_ptr;

	if (new_size == 0)
		return (free(ptr), ptr = NULL, NULL);
	new_ptr = malloc(new_size);
	if (!new_ptr)
		return (NULL);
	ft_memset(new_ptr, 0, new_size);
	if (ptr)
	{
		if (original_size < new_size)
			size_to_copy = original_size;
		else
			size_to_copy = new_size;
		ft_memcpy(new_ptr, ptr, size_to_copy);
		free(ptr);
		ptr = NULL;
	}
	return (new_ptr);
}
