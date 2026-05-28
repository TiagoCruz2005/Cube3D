/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thde-sou <thde-sou@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 20:37:16 by thde-sou          #+#    #+#             */
/*   Updated: 2026/05/27 18:31:38 by thde-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

/**
 * Calculates the length of a string.
 *
 * This function returns the number of characters
 * in the string, excluding the null terminator.
 *
 * @param s The string to measure.
 * @return The length of the string.
 */
size_t	ft_strlen(const char *s)
{
	size_t	len;

	if(!s)
		return (0);
	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

/*int	main(void)
{
	char	*str;

	str = " bb";
	printf("%zu vs %zu", strlen(str), ft_strlen(str));
	return (0);
}*/
