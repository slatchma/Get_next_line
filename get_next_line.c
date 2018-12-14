/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: slatchma <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/15 15:24:43 by slatchma     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/23 17:17:00 by slatchma    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"

t_gnl	*ft_lstgnl(t_gnl **lstsave, int fd)
{
	t_gnl *tmp;
	t_gnl *maillon;

	maillon = (t_gnl*)malloc(sizeof(t_gnl));
	maillon->fdd = fd;
	maillon->save = NULL;
	maillon->next = NULL;
	tmp = *lstsave;
	if (*lstsave == NULL)
	{
		*lstsave = maillon;
		return (*lstsave);
	}
	while (tmp->next != NULL)
	{
		if (tmp->fdd == fd)
			return (tmp);
		tmp = tmp->next;
	}
	if (tmp->fdd == fd)
		return (tmp);
	tmp->next = maillon;
	return (maillon);
}

int		ft_gnl_save(int position, char **line, char **save)
{
	char *tmp;
	char *tmpfree;

	if ((position = ft_strsupchr(*save, '\n')) >= 0)
	{
		tmp = ft_strsub(*save, 0, (size_t)position);
		tmpfree = *line;
		*line = ft_strjoin(*line, tmp);
		free(tmpfree);
		free(tmp);
		*save = ft_strsub(*save, (size_t)position + 1, ft_strlen(*save));
		return (1);
	}
	else
	{
		*line = ft_strjoin(*line, *save);
		*save = ft_strnew(0);
	}
	return (0);
}

int		ft_gnl_write(int position, char buf[BUFF_SIZE + 1],
		char **line, char **save)
{
	char *tmp;
	char *tmpfree;

	tmp = NULL;
	if ((position = ft_strsupchr(buf, '\n')) >= 0)
	{
		tmp = ft_strsub(buf, 0, (size_t)position);
		tmpfree = *line;
		*line = ft_strjoin(*line, tmp);
		free(tmpfree);
		free(tmp);
		*save = ft_strsub(buf, (size_t)position + 1, ft_strlen(buf));
		return (1);
	}
	else
	{
		tmpfree = *line;
		*line = ft_strjoin(*line, buf);
		free(tmpfree);
		return (0);
	}
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	static t_gnl	*lstsave = NULL;
	t_gnl			*lsttmp;
	char			buf[BUFF_SIZE + 1];
	int				position;
	int				ret;

	if ((fd < 0 || line == NULL || read(fd, buf, 0) < 0))
		return (-1);
	lsttmp = ft_lstgnl(&lstsave, fd);
	*line = ft_strnew(0);
	position = 0;
	if (lsttmp->save != NULL)
	{
		if (ft_gnl_save(position, line, &lsttmp->save) == 1)
			return (1);
	}
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if ((ft_gnl_write(position, buf, line, &lsttmp->save)) == 1)
			return (1);
	}
	if (ft_strlen(*line) != 0)
		return (1);
	return (0);
}
