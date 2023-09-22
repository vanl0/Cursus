/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilorenzo <ilorenzo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 17:13:53 by ilorenzo          #+#    #+#             */
/*   Updated: 2023/09/22 19:15:08 by ilorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>

int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_tolower(int c);
int				ft_toupper(int c);
void			*ft_memset(void *str, int c, size_t n);
void			*ft_memchr(const void *str, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memcpy(void *restrict dest, const void *restrict src, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t len);
void			ft_bzero(void *s, size_t n);
size_t			ft_strlen(const char *str);
char			*ft_strchr(const char *str, int c);
char			*ft_strdup(const char *s);
size_t	        ft_strlcat(char *restrict dest, const char *restrict src, size_t size);
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);
int				ft_strncmp(char *s1, char *s2, unsigned int n);
char			*ft_strnstr(const char *str, const char *find, size_t len);
char			*ft_strrchr(const char *str, int c);
int				ft_atoi(char *str);
void			*ft_calloc(size_t nmemb, size_t size);

char			*ft_substr(char const *s, unsigned int start, size_t len);
char            *ft_strjoin(char const *s1, char const *s2);
char			*strtrim(char const *s1, char const *set);
#endif
