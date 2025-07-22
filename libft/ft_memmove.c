/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waissi <waissi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:34:31 by waissi            #+#    #+#             */
/*   Updated: 2024/11/06 15:34:32 by waissi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*s;
	unsigned char	*d;

	s = (unsigned char *)src;
	d = (unsigned char *)dest;
	if (!d && !s)
		return (NULL);
	if ((d > s))
	{
		while (n > 0)
		{
			d[n - 1] = s[n - 1];
			n--;
		}
	}
	else
	{
		ft_memcpy(dest, src, n);
	}
	return ((void *)dest);
}

// int	main(void)
// {
// 		char s[] = "baysal";
// 		char z[] = "baysal";
// 		char d[6];
// 		char f[6];

// 		printf("%s\n",(char *) ft_memmove(s + 3,s,4));
// 		printf("%s\n",(char *)    memmove(z + 3,z,4));
// }
