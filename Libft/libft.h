/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilorenzo <ilorenzo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 14:47:03 by ilorenzo          #+#    #+#             */
/*   Updated: 2023/09/18 12:09:41 by ilorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef LIBFT_H
#define LIBFT_H

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
int				ft_isalpha(char c);
int				ft_isdigit(char c);
int				ft_isalnum(char c);
int				ft_isascii(char c);
int				ft_isprint(char c);

char			ft_tolower(char c);
char			ft_toupper(char c);

void			*ft_memset(void *str, int c, size_t n);
void			*ft_memchr(const void *str, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memmove(void *dest, const char *src, size_t len);
void			ft_bzero(void *s, size_t n);

size_t			ft_strlen(const char *str);
char			*ft_strchr(char *str, int c);
char			*ft_strdup(const char *s);
unsigned int	ft_strlcat(char *dest, char *src, unsigned int size);
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);
int				ft_strncmp(char *s1, char *s2, unsigned int n);
char			*ft_strnstr(const char *str, const char *find, size_t len);
char			*ft_strrchr(const char *str, int c);

int				ft_atoi(char *str);
//-------------------------------TESTERS---------------------------------------//
int	char_checker(char res1, char res2);
int 	int_checker(int res1, int res2);

void	atoitest(char *data[5]);

void	isalphatest(char data[5]);
void	isasciitest(char data[5]);

#endif
