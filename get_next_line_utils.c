/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llegrand <llegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 15:33:21 by llegrand          #+#    #+#             */
/*   Updated: 2023/05/11 15:33:21 by llegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/** 
 * @brief  Return a pointer to a new string which
 * is a duplicate of [s].
 * @note   Memory for the new string is obtained 
 * with malloc and can be freed with free
 * @param  char *c
 * @retval char*
 */
char	*ft_strdup(const char *c)
{
	void	*p;

	p = ft_calloc(ft_strlen((char *)c) + 1, sizeof(char));
	if (!p)
		return (0);
	ft_strlcpy(p, c, ft_strlen((char *)c) + 1);
	return (p);
}

/** 
 * @brief  Return a pointer to a new string which is
 * the result of the concatenation of [s1] and [s2]
 * @note   Memory for the new string is obtained 
 * with malloc and can be freed with free
 * @param  char *s1
 * @param  char *s2
 * @retval char*
 */
char	*ft_strjoin(char const *s1, char const *s2)
{
	void	*p;
	size_t	s;

	s = ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1;
	p = ft_calloc(sizeof(char), s);
	if (!p)
		return (0);
	ft_strlcpy(p, s1, ft_strlen((char *)s1) + 1);
	ft_strlcat(p, s2, s);
	return (p);
}

/** 
 * @brief  Allocates memory for an array of [nmemb] elements 
 * of [size] bytes each and returns a pointer to the allocated memory
 * @param  size_t nmemb
 * @param  size_t size
 * @retval void*
 */
void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*p;

	p = (void *)malloc(nmemb * size);
	if (!p)
		return (0);
	ft_bzero(p, nmemb * size);
	return (p);
}

/** 
 * @brief  Appends the [src] string to the [dst] string, overwriting 
 * the [dst] terminator and adding one at the end of the result.
 * @note   The strings may not overlap, and the [dst] string
 * must have enough space for the result.
 * @param  char *dst
 * @param  char *src
 * @param  size_t dstsize
 * @retval size_t
 */
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	l;

	l = ft_strlen(dst) + ft_strlen((char *)src);
	if (dstsize == 0)
		return (ft_strlen((char *)src));
	if (ft_strlen(dst) >= dstsize)
		return (ft_strlen((char *)src) + dstsize);
	i = 0;
	while (*dst)
		dst++;
	while ((i < dstsize - (l - ft_strlen((char *)src)) - 1) && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (l);
}

/** 
 * @brief  Copies the [src] string to the [dst] buffer, 
 * including the terminator.
 * @note   The strings may not overlap, and the [dst]
 * string must have enough space to receive the copy.
 * @param  char *dst
 * @param  char *src
 * @param  size_t dstsize
 * @retval size_t
 */
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	dsti;
	size_t	srci;

	dsti = 0;
	srci = 0;
	if (!dst || !src)
		return (0);
	while (src[srci] != '\0')
		srci++;
	while (src[dsti] && dsti + 1 < dstsize)
	{
		dst[dsti] = src[dsti];
		dsti++;
	}
	if (dstsize)
		dst[dsti] = '\0';
	return (srci);
}

/** 
 * @brief  Calculates the length of the string pointed 
 * to by [str], excluding the terminator.
 * @param  char *str
 * @retval size_t
 */
size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str && str[i] && str[i] != '\0')
		i++;
	return (i);
}

/** 
 * @brief  Zero data in n bytes of memory starting at the location pointed by s
 * @param  void *s
 * @param  size_t n
 */
void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	if (!s || !n)
		return ;
	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = 0;
		i++;
	}
}

/** 
 * @brief  Scan the string [s] for the first occurence of [c]
 * @param  char *s
 * @param  int *c
 * @retval char*
 */
char	*ft_strchr(const char *s, int c)
{
	char	*ptr;

	if (!s)
		return (0);
	ptr = (char *)s;
	while (*ptr)
	{
		if (*ptr == (char)c)
			return (ptr);
		ptr++;
	}
	if (*ptr == (char)c)
		return (ptr);
	return (0);
}

/** 
 * @brief  Returns a substring from [s]. The substring begins
 * at index [start] and is of maximum size [len].
 * @note   Memory for the new string is obtained
 * with malloc and can be freed with free
 * @param  char *s
 * @param  int start
 * @param  size_t len
 * @retval char*
 */
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;

	if (!s)
		return (0);
	if (start > ft_strlen((char *)s))
		return (ft_strdup(""));
	if (start + len > ft_strlen(s))
		len = ft_strlen(s) - start;
	p = (char *)ft_calloc(sizeof(char), (len + 1));
	if (!p)
		return (0);
	s += start;
	if (s)
		ft_strlcpy(p, s, len + 1);
	return (p);
}

/** 
 * @brief  Scan the string [s] for the first occurence of [c]
 * @param  char *s
 * @param  int *c
 * @retval char*
 */
int	ft_strichr(const char *s, int c)
{
	char	*ptr;
	int	i;

	if (!s)
		return (-1);
	ptr = (char *)s;
	while (ptr[i])
	{
		if (ptr[i] == (char)c)
			return (i);
		i++;
	}
	if (ptr[i] == (char)c)
		return (i);
	return (-1);
}
