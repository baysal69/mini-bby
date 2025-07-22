/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sara <sara@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 10:34:32 by waissi            #+#    #+#             */
/*   Updated: 2025/07/22 13:44:41 by sara             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>

int	ft_strcmp(char *s1, const char *s2);
int		ft_isdigit(int c);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_strrchr(const char *str, char c);
char	*ft_strchr(const char *str, char c);
int		ft_atoi(const char *str);
int		ft_isprint(int c);
char	*ft_strdup(const char *s);
char	ft_tolower(int c);
void	ft_bzero(void *s, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_strlcat(char *dst, const char *src, size_t s);
char	ft_toupper(int c);
void	*ft_calloc(size_t nmemb, size_t size);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
int		ft_strlcpy(char *dst, const char *src, size_t size);
int		ft_isalnum(int c);
void	*ft_memcpy(void *dest, const void *src, size_t n);
int		ft_isalpha(char c);
void	*ft_memmove(void *dest, const void *src, size_t n);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_isascii(int c);
void	*ft_memset(void *s, int c, size_t n);
char	*ft_strnstr(const char *big, const char *little, size_t len);
size_t	ft_strlen(const char *str);
int		ft_strlcat(char *src, const char *dst, size_t s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strcat(char *dest, char *src);
void	ft_strcpy(char *dest, const char *src);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_itoa(int n);
char	**ft_split(char const *s, char c);
#endif
