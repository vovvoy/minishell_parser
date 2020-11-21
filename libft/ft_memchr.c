/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbach <cbach@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/23 18:49:06 by cbach             #+#    #+#             */
/*   Updated: 2020/11/04 18:18:28 by cbach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *t;
	unsigned char r;

	r = (unsigned char)c;
	t = (unsigned char *)s;
	while (n--)
		if (*t++ == r)
			return (--t);
	return (NULL);
}
