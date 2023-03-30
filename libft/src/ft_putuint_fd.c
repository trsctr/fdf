/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuint_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trsctr <trsctr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:31:12 by oandelin          #+#    #+#             */
/*   Updated: 2023/03/23 12:01:38 by trsctr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// ft_putuint_fd
// writes unsigned int n in ascii format to file descriptor fd
// uses ft_putchar_fd to write one digit at a time
int	ft_putuint_fd(unsigned int n, int fd)
{
	int	i;

	i = 0;
	//if (n < 0)
	//	n = UINT_MAX - n + 1;
	if (n > 9)
	{
		i += ft_putuint_fd(n / 10, fd);
		i += ft_putuint_fd(n % 10, fd);
	}
	else
		i += ft_putchar_fd(n + '0', fd);
	return (i);
}
