#include <libft.h>
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*temp;

	if (!s1 || !s2)
		return (NULL);
	temp = (char *)malloc(sizeof(*temp)\
		* (ft_strlen(s1) + (ft_strlen(s2) + 1)));
	if (!temp)
		return (NULL);
	ft_strcpy(temp, s1);
	ft_strcat(temp, s2);
	return (temp);
}