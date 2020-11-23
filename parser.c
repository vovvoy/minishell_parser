#include "minishell.h"
#include "libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

char		*strj(char *s1, char s2)
{
	unsigned int	i;
	char			*out_str;

	if (!s1 || !s2)
		return (NULL);
	i = -1;
	if (!(out_str = malloc(sizeof(char) * (ft_strlen(s1) + 2))))
		return (NULL);
	while (s1[++i])
		out_str[i] = s1[i];
	free(s1);
	out_str[i++] = s2;
	out_str[i] = '\0';
	return (out_str);
}

int cmd_count(char *line, t_info *info)
{
	int i;
	int j;
	int cnt;
	char *str;
	int len;
	t_cmd	*cmd;
	t_arg	*arg;

	len = ft_strlen(line);
	cnt = 0;
	cmd = malloc(sizeof(t_cmd));
	arg = malloc(sizeof(t_arg));
	str = malloc(sizeof(char ));
	ft_lstadd_back(&cmd->args, ft_lstnew(arg));
	ft_lstadd_back(&info->cmd, ft_lstnew(cmd));
	*str = '\0';
	i = -1;

	while (line[++i])
	{
		if (line[i] == 39)
		{
			i++;
			while (line[i] != 39 && i < len)
			{
				str = strj(str, line[i++]);
			}
			if (!cmd->name)
				cmd->name = ft_strdup(str);
			else
				ft_lstadd_back(&cmd->args, ft_lstnew(new_arg(ft_strdup(str), 0)));
			// printf("\t\t\t|%s|\n", str);
			if (line[i + 1] == 32 && cmd->args)
				ft_lstadd_back(&cmd->args, ft_lstnew(new_arg(ft_strdup(str), 0)));
				// printf("\t\t\t| |\n");
			free(str);
			if (i == len)
				return (-1);
			str = malloc(sizeof(char) * 1);
			*str = '\0'; 
			cnt++;
		}

		if (line[i] == 34)
		{
			i++;
			while(1)
			{
				while (line[i] != 34 && i < len && line[i] != 36)
				{
					str = strj(str, line[i++]);
				}
				if (!cmd->name)
					cmd->name = ft_strdup(str);
				else
					ft_lstadd_back(&cmd->args, ft_lstnew(new_arg(ft_strdup(str), 0)));
				// printf("\t\t\t|%s|\n", str);
				free(str);
				if (i == len)
					return (-1);
				if (line[i] == 34)
					if (line[i + 1] == 32 && cmd->args)
						ft_lstadd_back(&cmd->args, ft_lstnew(new_arg(ft_strdup(str), 0)));
						// printf("\t\t\t| |\n");
				str = malloc(sizeof(char) * 1);
				*str = '\0';
				cnt++;
				if (line[i] == 34)
					break ;
				i++;
				while (line[i] != 39 && line[i] != 34 && line[i] != 32 && line[i] != 36 && i < len)
					str = strj(str, line[i++]);
				ft_lstadd_back(&cmd->args, ft_lstnew(new_arg(ft_strdup(str), 0)));
				// printf("\t\t\t|%s|\n", str);
				free(str);
				str = malloc(sizeof(char) * 1);
				*str = '\0';
				cnt++;
			}
		}
		
		if (line[i] == 36)
		{
			i++;
			while (line[i] != 39 && line[i] != 34 && line[i] != 32 &&
				   line[i] != 36 && i < len && line[i] != 124 && line[i] != 59)
					str = strj(str, line[i++]);
			if (!cmd->name)
				cmd->name = ft_strdup(str);
			else
				ft_lstadd_back(&cmd->args, ft_lstnew(new_arg(ft_strdup(str), 0)));
			// printf("\t\t\t|%s|\n", str);
			free(str);
			str = malloc(sizeof(char) * 1);
			*str = '\0';
			if (line[i + 1] == 32 && cmd->args)
				ft_lstadd_back(&cmd->args, ft_lstnew(new_arg(ft_strdup(str), 0)));
				// printf("\t\t\t| |\n");
			cnt++;
			i--;
			continue ;
		}

		if (line[i] == 124)
		{
			str = strj(str, line[i++]);
			while (line[i] == 32 || line[i] == 124)
				if (line[i++] == 124)
					return (-1);
			if (!cmd->name)
				cmd->name = ft_strdup(str);
			else
				ft_lstadd_back(&cmd->args, ft_lstnew(new_arg(ft_strdup(str), 0)));
			// printf("\t\t\t|%s|\n", str);
			free(str);
			str = malloc(sizeof(char) * 1);
			*str = '\0';
			if (line[i - 1] == 32 && cmd->args)
				ft_lstadd_back(&cmd->args, ft_lstnew(new_arg(ft_strdup(str), 0)));
				// printf("\t\t\t| |\n");
			cnt++;
			i--;
			continue ;
		}

		if (line[i] == 59)
		{
			str = strj(str, line[i++]);
			while (line[i] == 32 || line[i] == 59)
				if (line[i++] == 59)
					return (-1);
			if (!cmd->name)
				cmd->name = ft_strdup(str);
			else
				ft_lstadd_back(&cmd->args, ft_lstnew(new_arg(ft_strdup(str), 0)));
			// printf("\t\t\t|%s|\n", str);
			free(str);
			str = malloc(sizeof(char) * 1);
			*str = '\0';
			if (line[i - 1] == 32 && cmd->args)
				ft_lstadd_back(&cmd->args, ft_lstnew(new_arg(ft_strdup(str), 0)));
				// printf("\t\t\t| |\n");
			cnt++;
			i--;
			continue ;
		}

		if (line[i] == 60)
		{
			str = strj(str, line[i++]);
			while (line[i] == 32 || line[i] == 60)
				if (line[i++] == 60)
					return (-1);
			if (!cmd->name)
				cmd->name = ft_strdup(str);
			else
				ft_lstadd_back(&cmd->args, ft_lstnew(new_arg(ft_strdup(str), 0)));
			// printf("\t\t\t|%s|\n", str);
			free(str);
			str = malloc(sizeof(char) * 1);
			*str = '\0';
			if (line[i - 1] == 32 && cmd->args)
				ft_lstadd_back(&cmd->args, ft_lstnew(new_arg(ft_strdup(str), 0)));
				// printf("\t\t\t| |\n");
			cnt++;
			i--;
			continue ;
		}

		if (line[i] == 62)
		{
			str = strj(str, line[i++]);
			if (line[i] == 62)
				str = strj(str, line[i++]);
			while (line[i] == 32 || line[i] == 62)
				if (line[i++] == 62)
					return (-1);
			if (!cmd->name)
				cmd->name = ft_strdup(str);
			else
				ft_lstadd_back(&cmd->args, ft_lstnew(new_arg(ft_strdup(str), 0)));
			// printf("\t\t\t|%s|\n", str);
			free(str);
			str = malloc(sizeof(char) * 1);
			*str = '\0';
			if (line[i - 1] == 32 && cmd->args)
				ft_lstadd_back(&cmd->args, ft_lstnew(new_arg(ft_strdup(str), 0)));
				// printf("\t\t\t| |\n");
			cnt++;
			i--;
			continue ;
		}

		if (line[i] != 34 && line[i] != 39 && line[i] != 32 && line[i] != 36 &&
			line[i] != 124 && line[i] != 59 && line[i] != 60 && line[i] != 62)
		{
			while (line[i] != 32 && line[i] && line[i] != 34 && line[i] != 39 && line[i] != 36 &&
				   line[i] != 124 && line[i] != 59 && line[i] != 60 && line[i] != 62)
				str = strj(str, line[i++]);
			if (!cmd->name)
				cmd->name = ft_strdup(str);
			else
				ft_lstadd_back(&cmd->args, ft_lstnew(new_arg(ft_strdup(str), 0)));
			// printf("\t\t\t|%s|\n", str);
			free(str);
			if (line[i] == 32 && cmd->args)
				ft_lstadd_back(&cmd->args, ft_lstnew(new_arg(ft_strdup(str), 0)));
				// printf("\t\t\t| |\n");
			str = malloc(sizeof(char) * 1);
			*str = '\0';
			cnt++;
			if (line[i] != 36)
			{
				i--;
				continue ;
			}
			while (line[i] != 39 && line[i] != 34 && line[i] != 32 && line[i] != 36 && i < len)
					str = strj(str, line[i++]);
			if (!cmd->name)
				cmd->name = ft_strdup(str);
			else
				ft_lstadd_back(&cmd->args, ft_lstnew(new_arg(ft_strdup(str), 0)));
			// printf("\t\t\t|%s|\n", str);
			free(str);
			str = malloc(sizeof(char) * 1);
			*str = '\0';
			if (line[i] == 32 && cmd->args)
				ft_lstadd_back(&cmd->args, ft_lstnew(new_arg(ft_strdup(str), 0)));
				// printf("\t\t\t| |\n");
			cnt++;
			i--;
		}
	}
	free(str);
	return (cnt);
}

void	parser(char *command, t_info *info)
{
	int cmnd;

	if (!command)
		return ;
	printf("count = %d\n" , cmd_count(command, info));

}