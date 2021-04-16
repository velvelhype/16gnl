#include "get_next_line.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize == 0)
	{
		while (src[i])
			i++;
		return (i);
	}
	while (i < dstsize - 1 && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	if (i < dstsize)
		dst[i] = '\0';
	while (src[i])
		i++;
	return (i);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	elen;
	size_t	ori;

	elen = 0;
	while (dst[elen] && elen < dstsize)
		elen++;
	ori = elen;
	while (src[elen - ori] && elen + 1 < dstsize)
	{
		dst[elen] = src[elen - ori];
		elen++;
	}
	if (ori < dstsize)
		dst[elen] = '\0';
	return (ori + ft_strlen(src));
}

char	*ft_strdup(char *s)
{
	int		len;
	char	*cpy;
	int		i;

	i = 0;
	len = ft_strlen(s);
	cpy = (char *)malloc(sizeof(char) * (len + 1));
	if (!cpy)
		return (NULL);
	while (s[i])
	{
		cpy[i] = s[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}

// char            *ft_strdup(char *s1)
// {
//         char    *result;
//         int             i;

//         i = ft_strlen(s1);
//         result = (char *)malloc(sizeof(char) * (i + 1));
//         if (!result)
//                 return (0);
//         i = 0;
//         while (s1[i])
//         {
//                 result[i] = s1[i];
//                 i++;
//         }
//         result[i] = '\0';
//         return (result);
// }

char	*strjoin_end(char *s1, char *s2, char*cpy)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s1[i])
	{
		cpy[j++] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		cpy[j++] = s2[i];
		i++;
	}
	cpy[j] = '\0';
	free(s1);
	s1 =  NULL;
	return (cpy);
}
// char            *ft_strjoin(char *s1, char *s2)
// {
//         char    *newstr;
//         int             s1_len;
//         int             s2_len;

//         if (!(s1) && !(s2))
//                 return (NULL);
//         else if (!(s1) || !(s2))
//                 return (!(s1) ? ft_strdup(s2) : ft_strdup(s1));
//         s1_len = ft_strlen(s1);
//         s2_len = ft_strlen(s2);
//         if (!(newstr = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1))))
//                 return (NULL);
//         ft_strlcpy(newstr, s1, s1_len + 1);
//         free(s1);
//         ft_strlcat(newstr + (s1_len), s2, s2_len + 1);
//         return (newstr);
// }

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	one;
	size_t	two;
	char	*cpy;

	if (!s1 || !s2)
	{
		if (!s1 && !s2)
			return (NULL);
		if (!s1)
			return (ft_strdup(s2));
		if (!s2)
			return (ft_strdup(s1));
	}
	one = ft_strlen(s1);
	two = ft_strlen(s2);
	cpy = (char *)malloc(sizeof(char) * (one + two + 1));
	if (!cpy)
		return (NULL);
	return (strjoin_end(s1, s2, cpy));
}
