/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 17:06:57 by ugdaniel          #+#    #+#             */
/*   Updated: 2021/06/19 18:52:28 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*get_str(t_flags *flags, va_list va)
{
	char	*s;

	s = NULL;
	if (flags->specs[SPEC_CHAR])
	{
		s = ft_strdup("a");
		s[0] = va_arg(va, int);
	}
	else if (flags->specs[SPEC_STR])
		s = ft_strdup(va_arg(va, char *));
	else if (flags->specs[SPEC_PTR])
		s = ft_itoa_hex(flags, va_arg(va, unsigned long), 16);
	else if (flags->specs[SPEC_INT])
		s = ft_itoa(va_arg(va, int));
	else if (flags->specs[SPEC_HEX] == 1)
		s = ft_itoa_hex(flags, va_arg(va, unsigned int), 16);
	else if (flags->specs[SPEC_UINT] == 1)
		s = ft_itoa(va_arg(va, unsigned int));
	else if (flags->specs[SPEC_PCENT] == 1)
		s = ft_strdup("%");
	if (!s)
		s = ft_strdup("(null)");
	return (s);
}

static int	ft_conversion(t_flags *flags, va_list va)
{
	int		ret;

	if (check_prec_zero(flags, va, 0))
		return (out(flags, ft_strdup(""), STDOUT));
	ret = 0;
	ret += out(flags, get_str(flags, va), STDOUT);
	return (ret);
}

static int	ft_process_str(const char *format, va_list va)
{
	int			ret;
	t_flags		*flags;

	flags = malloc(sizeof(t_flags));
	if (!flags)
		return (0);
	init_flags(flags);
	ret = 0;
	while (*format)
	{
		if (*format != '%')
		{
			ft_putchar_fd(*format++, STDOUT);
			ret++;
		}
		else
		{
			format++;
			format = get_flags(format, flags, va);
			ret += ft_conversion(flags, va);
			format++;
		}
	}
	free(flags);
	return (ret);
}

int	ft_printf(const char *format, ...)
{
	int			ret;
	va_list		va;

	ret = 0;
	if (format)
	{
		va_start(va, format);
		ret = ft_process_str(format, va);
		va_end(va);
	}
	return (ret);
}
