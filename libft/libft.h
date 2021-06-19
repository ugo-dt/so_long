/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 12:12:35 by ugdaniel          #+#    #+#             */
/*   Updated: 2021/06/19 18:26:52 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}t_list;

int			ft_atoi(const char *nptr);
long		ft_atol(char *nptr);
void		ft_bzero(void *s, size_t n);
void		*ft_calloc(size_t nmemb, size_t size);
int			ft_isalnum(int c);
int			ft_isalpha(int c);
int			ft_isascii(int c);
int			ft_isdigit(int c);
int			ft_isprint(int c);
char		*ft_itoa(int n);
void		ft_lstadd_back(t_list **alst, t_list *new);
void		ft_lstadd_front(t_list **alst, t_list *new);
void		ft_lstclear(t_list **lst, void (*del)(void*));
void		ft_lstdelone(t_list *lst, void (*del)(void*));
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstlast(t_list *lst);
t_list		*ft_lstmap(t_list *l, void *(*f)(void *), void (*d)(void *));
t_list		*ft_lstnew(void *content);
int			ft_lstsize(t_list *lst);
void		*ft_memccpy(void *dest, void *src, int c, size_t n);
void		*ft_memchr(void *s, int c, size_t n);
int			ft_memcmp(void *s1, void *s2, size_t n);
void		*ft_memcpy(void *dest, void *src, size_t n);
void		*ft_memmove(void *dest, void *src, size_t n);
void		*ft_memset(void *s, int c, size_t n);
void		ft_putchar_fd(char c, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
void		ft_putstr_fd(char *s, int fd);
char		**ft_split(char *s, char c);
char		*ft_strchr(char *s, int c);
char		*ft_strdup(char *s);
char		*ft_strjoin(char *s1, char *s2);
size_t		ft_strlcat(char *dst, char *src, size_t size);
size_t		ft_strlcpy(char *dst, char *src, size_t size);
size_t		ft_strlen(char *s);
char		*ft_strmapi(char *s, char (*f)(unsigned int, char));
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strncpy(char *dest, char *src, unsigned int n);
char		*ft_strnstr(char *big, char *little, size_t len);
char		*ft_strrchr(char *s, int c);
char		*ft_strtrim(char *s1, char *set);
char		**ft_strsplit(char const *s, char c);
char		*ft_substr(char *s, unsigned int start, size_t len);
int			ft_tolower(int c);
int			ft_toupper(int c);

# define STDOUT		1

# define NB_SPECS	8
# define NB_FLAGS	8

# define SPEC_CHAR	0
# define SPEC_STR	1
# define SPEC_PTR	2
# define SPEC_INT	3
# define SPEC_UINT	4
# define SPEC_HEX	5
# define SPEC_PCENT	6
# define SPEC_NONE	7
# define FLAG_ZERO	0
# define FLAG_MINUS	1
# define FLAG_PLUS	2
# define FLAG_SPACE	3
# define FLAG_HASH	4
# define FLAG_LEFT	5
# define FLAG_PREC	6
# define FLAG_UPPER	7

typedef struct s_flags
{
	unsigned int	specs[NB_SPECS];
	unsigned int	flags[NB_FLAGS];
	int				width;
	int				precision;
}t_flags;

void		init_flags(t_flags *flags);
void		check_flags(t_flags *flags);

const char	*get_flags(const char *f, t_flags *flags, va_list va);

char		*ft_itoa_hex(t_flags *flags, long value, int base);
int			check_prec_zero(t_flags *flags, va_list args, int temp);

void		join(char *s1, char *s2);
void		join2(char *s1, char *s2);

char		*add_zeros_int(t_flags *flags, char *s);
int			out(t_flags *flags, char *s, int fd);

int			ft_printf(const char *format, ...);
int			ft_fprintf(int fd, const char *format, ...);

#endif
