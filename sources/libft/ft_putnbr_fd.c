/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-koni <nde-koni@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 18:15:29 by nde-koni          #+#    #+#             */
/*   Updated: 2020/09/05 23:09:04 by nde-koni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	nr;

	nr = n;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		nr = n * -1;
	}
	if (nr > 9)
		ft_putnbr_fd(nr / 10, fd);
	ft_putchar_fd(nr % 10 + '0', fd);
}
