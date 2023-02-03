#include "minilibx.h"

int count_lines(char *path)
{
	int count = 0;
	int     fd;
	char *line;

	fd = open(path, O_RDONLY);
	while ((line = get_next_line(fd)))
	{
		count++;
	}
	return (count);
}

char **read_map(char *path)
{
	char **res;
	int     fd;
	char *line;
	int i = 0;
	fd = open(path, O_RDONLY);
	res = malloc(count_lines(path) * sizeof(char *) + 1);
	while ((line = get_next_line(fd)))
	{
		res[i++]= line;
	}
	res[i] = 0;
	return res;
}
int check_wall_map(char **str)
{
	int i =0, j = 0;
	int line;
	int len = ft_strlength(str);
	while (str[0][j])
	{
		if (str[0][j] != '1' && str[0][j] != '\n')
			return 0;
		j++;
	}
	i = 1;
	while (str[i] && i < len - 1)
	{
		line = ft_strlen(str[i]);
		if (str[i][0] != '1' || str[i][line - 2] != '1')
				return 0;
		i++;
	}
	j = 0;
	while (str[len - 1][j])
	{
		if (str[len - 1][j] != '1')
				return 0;
		j++;
	}
	return 1;
}
int check_rectangle_map(char **str)
{
	int		i;
	int		j;
	int		len;
	int		len_next_line;

	i = 1;
	
	while (str[0][len] && str[0][len] != '\n')
		len++;
	while (str[i])
	{
		j = 0;
		while(str[i][j] && str[i][j] != '\n')
			j++;
		if (len != j)
			{
				return (0);
			}
		i++;
	}
	return (1);
}
int check_unique_p_e_c(char **str)
{
	int		i;
	int		j;
	int		count_p;
	int		count_e;
	int		count_c;

	i = 0;
	j = 0;
	count_p = 0;
	count_c = 0;
	count_e = 0;
	while (str[i])
	{
		j = 0;
		while(str[i][j++])
		{
			if(str[i][j]=='p')
				count_p++;
			else if(str[i][j]=='c')
				count_c++;
			else if(str[i][j]=='e')
				count_e++;
		}
		i++;
	}
	if (count_e != 1 || count_c != 1 || count_p != 1)
			return (0);
	return (1);
}
char **check_path_down(char **str)
{
	int     i;
	int     j;

	i = 0;
	j = 0;
	while (str[i])
	{
		 j = 0;
		while (str[i][j])
		{
			if (str[i][j] == 'p')
			{
				if (str[i][j + 1] != '1')
					{str[i][j + 1] = 'p';}
				if (str[i][j - 1] != '1')
					str[i][j - 1] = 'p';
				if (str[i + 1][j] != '1')
					str[i + 1][j] = 'p';
				if (str[i - 1][j] != '1')
					str[i - 1][j] = 'p';
			}
			j++;
		}
		i++;
	}
	return (str);
}
char **check_path_ahead(char **str)
{
	int     i;
	int		a,b;
	int     j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == 'p')
			{
				a = i;
				b = j;
			}
			j++;
		}
		
		i++;
	}
	i = 0;
	j = 0;
	// printf("*%d | %d*\n", a, b);
	while (a)
	{
		j = 0;
		while (j <= b)
		{
			if (str[i][j] == 'p')
			{
				// if (str[a][b - 1] != '1' && str[a][b-1] != '\n')
				// 		{str[a][b - 1] = 'p';}
				// if (str[a][b + 1] != '1')
				// 	str[a][b + 1] = 'p';
				// if (str[a - 1][b] != '1' && str[a - 1][b] != '\n')
				// 		str[a - 1][b] = 'p';
				// if (str[a + 1][b] != '1')
				// 	str[a + 1][b] = 'p';
				while (str[i])
	 {
		 j = 0;
		while (str[i][j])
		{
			if (str[i][j] == 'p')
			{
				if (str[i][j + 1] != '1')
					{str[i][j + 1] = 'p';}
				if (str[i][j - 1] != '1')
					str[i][j - 1] = 'p';
				if (str[i + 1][j] != '1')
					str[i + 1][j] = 'p';
				if (str[i - 1][j] != '1')
					str[i - 1][j] = 'p';
			}
			j++;
		}
		i++;
	}
			}
			j++;
		}
		i++;
	}
	return (str);
}
int	valid_map(char **str)
{
	char **s = str;
	if (check_rectangle_map(s) && check_wall_map(s) && check_unique_p_e_c(s))
		return (1);
	else
		return 0;
}
int main()
{
	int i = 0;
	char **str = read_map("t.txt");
	char **res = check_path_ahead(str);
	// res = check_path_down(str);
	// while(str[i])
	// {
	// 	printf("%s", str[i]);
	// 	i++;
	// }printf("\n----\n");
	// i=0;
	while(res[i])
	{
		printf("%s", res[i]);
		i++;
	}
	// printf("\n--------\n");
	// i=0;
	// while(str[i])
	// {
	// 	printf("%s", str[i]);
	// 	i++;
	// }
}