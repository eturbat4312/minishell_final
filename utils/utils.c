#include "../minishell.h"

size_t	ft_strlen(const	char *s)
{
	size_t	i;

	i = 0;
	if (s)
	{
		while (s[i])
			i++;
	}
	return (i);
}

int	ft_countword(char const *s1, char del)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	while (*s1)
	{
		if (*s1 != del && word == 0)
		{
			word = 1;
			i++;
		}
		else if (*s1 == del)
			word = 0;
		s1++;
	}
	return (i);
}

char	*ft_putstr(char const *str, size_t start, size_t end)
{
	int			i2;
	char		*str1;

	i2 = 0;
	str1 = malloc(sizeof(char) * (end - start + 1));
	while (start < end)
		str1[i2++] = str[start++];
	str1[i2] = '\0';
	return (str1);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	size_t	index;
	size_t	itab;
	int		isword;

	itab = ft_countword(s, c);
	tab = malloc(sizeof(char *) * itab + 1);
	if (!tab)
		return (NULL);
	itab = 0;
	index = 0;
	isword = -1;
	while (index <= ft_strlen(s))
	{
		if (s[index] != c && isword < 0)
			isword = index;
		else if ((s[index] == c || index == ft_strlen(s)) && (isword >= 0))
		{
			tab[itab++] = ft_putstr(s, isword, index);
			isword = -1;
		}
		index++;
	}
	tab[itab] = NULL;
	return (tab);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n)
	{
		if ((*s1 != *s2 && s1 && s2) || (*s1 == '\0' || *s2 == '\0'))
		{
			return ((unsigned char)*s1 - (unsigned char)*s2);
		}
		s1++;
		s2++;
		n--;
	}
	return (0);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s || fd < 0)
		return ;
	while (s[i] != '\0')
	{
		write (fd, &s[i], 1);
		i++;
	}
}

void	ft_putendl_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s || fd < 0)
		return ;
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
	}
	write (fd, "\n", 1);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	c;
	size_t	n_len;
	char	*hay;

	i = 0;
	hay = (char *)haystack;
	n_len = ft_strlen(needle);
	if ((n_len == 0) || (haystack == needle && n_len == len))
		return (hay);
	while (hay[i] != '\0' && i < len)
	{
		c = 0;
		while (hay[i + c] != '\0' && needle[c] != '\0' \
				&& hay[i + c] == needle[c] && i + c < len)
			c++;
		if (c == n_len)
			return (hay + i);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*res;
	size_t			i;
	unsigned int	length;

	if (!s1 || !s2)
		return (0);
	length = ft_strlen(s1) + ft_strlen(s2);
	res = (char *)malloc(sizeof(char) * (length + 1));
	if (!res)
		return (0);
	i = 0;
	while (*s1)
	{
		res[i] = *s1++;
		i++;
	}
	while (*s2)
	{
		res[i] = *s2++;
		i++;
	}
	res[i] = '\0';
	return (res);
}
