#include "../minishell.h"

int skip_spaces(char *str, int i)
{
    while (str[i] == ' ')
        i++;
    return (i);
}

void    trim_right(char *s)
{
    int len;

    len = ft_strlen(s);
    while (len > 0 && s[len - 1] == ' ')
    {
        s[len - 1] = 0;
        len--;
    }
}

int trim(char *s)
{
    int result;

    result = skip_spaces(s, 0);
    trim_right(s);
    return (result);
}

void	copy_then_free(char *src, int *i, char *dst)
{
	int	j;

	j = 0;
	while (dst[j])
		src[(*i)++] = dst[j++];
	free(dst);
}

char	*active_env(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == 1)
			s[i] = '$';
		i++;
	}
	return (s);
}

static int	ft_find(char *haystack, char *needle, int l, int len_i)
{
	int	i;
	int	j;
	int	count;

	j = 0;
	i = 0;
	count = 0;
	while (len_i && haystack[i] && haystack[i] == needle[j])
	{
		i++;
		j++;
		len_i--;
		count++;
	}
	if (count == l)
		return (1);
	return (0);
}

int	find_pos(const char *haystack, const char *needle, int len)
{
	int	i;
	int	l;

	i = 0;
	l = ft_strlen(needle);
	while (haystack[i] && i < len)
	{
		if (haystack[i] != needle[0])
			i++;
		else if (haystack[i] == needle[0])
		{
			if (ft_find((char *)&haystack[i], (char *)needle, l, len - i) == 1)
				return (i);
			else
				i++;
		}
	}
	return (-1);
}

char	*strjoin(char const *s1, char const *s2)
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

char	*deactive_env(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '$')
			s[i] = 1;
		i++;
	}
	return (s);
}