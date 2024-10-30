#include "ft_printf.h"

int	ft_putptr(void *ptr)
{
	int	len;

	len = 0;
	if (!ptr)
		return (ft_putstr("(nil)"));
	len += ft_putstr("0x");
	len += ft_puthex((unsigned long)ptr, 'x');
	return (len);
}