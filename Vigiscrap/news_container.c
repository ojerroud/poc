/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   news_container.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojerroud <ojerroud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 15:54:16 by vle-gal           #+#    #+#             */
/*   Updated: 2019/03/04 12:20:06 by ojerroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

int is_clone()
{
	return (1);
}

char	*clean_str(char	*str)
{
	char	*temp;
	int 	i;
	int 	j;
	int		can_write;

	i = -1;
	j = -1;
	can_write = 1;
	temp = malloc(sizeof(char) * 500001);
	bzero(temp, 500001);
	while (str[++i])
	{
		if (str[i] == '<')
		{
			can_write = 0;
			continue;
		}
		if (str[i] == '>')
		{
			can_write = 1;
			continue;
		}
		if (str[i] == '&' && str[i + 1] == '#' && can_write != 0)
		{
			while (!isdigit(str[i]))
				i++;
			temp[++j] = atoi(str + i);
			while (isdigit(str[i]))
				i++;
			if (str[i] == ';')
				i++;
		}
		if (can_write)
			temp[++j] = str[i];
	}
	temp[++j] = str[i];
	return (temp);
}

void	remplace_str(char *str)
{
	char	*temp;

	temp = malloc(500001);
	temp = clean_str(str);
	bzero(str, 5000);
	memcpy(str, temp, strlen(temp));
	free(temp);
}	

int		proprio(char *start_bis, char *end)
{
	char res[500001];

	if ((start_bis = strstr(start_bis+1, "tn__=CH-R\">")))
	{
		// printf("\n*****proprio_du_partage|");
		end = strstr(start_bis, "</a></strong>");
		bzero(res, 500001);
		memcpy(res, start_bis + 11, end - start_bis - 11);
		remplace_str(res);
		printf("|||proprio: %s ", res);
		return (1);
	}
	else
		printf("|||proprio_no ");
	return (0);
}

void	date(char *start_bis, char *end)
{
	char res[500001];

	if ((start_bis = strstr(start_bis+1, "<abbr>")))
	{
		// printf("\n|=|date-|");
		end = strstr(start_bis, "</abbr>");
		bzero(res, 500001);
		memcpy(res, start_bis + 6, end - start_bis - 6);
		remplace_str(res);
		printf("|||date: %s ", res);
	}
	else
		printf("|||date_no ");
}

int		text(char *start_bis, char *end)
{
	char res[500001];

	if ((start_bis = strstr(start_bis+1, "<span><p>")))
	{
		end = strstr(start_bis, "</span>");
		bzero(res, 5000);
		memcpy(res, start_bis + 9, end - start_bis - 9);
		remplace_str(res);
		printf("|||text: %s ", res);
		return (1);
	}
	else
		printf("|||text_no ");
	return (0);
}

int		titre(char *start_bis, char *end)
{
	char	res[500001];

	if ((start_bis = strstr(start_bis+1, "<td class=\"t\"><")))
		{
			// printf("\n-Titre_video-|");
			end = strstr(start_bis, "</h3><div class=");
			bzero(res, 5000);
			memcpy(res, start_bis + 35, end - start_bis - 35);
			remplace_str(res);
			printf("|||title: %s ", res);
			return (1);
		}
	else
		printf("|||title_no ");
	return (0);
}

int		auteur(char *start_bis, char *end)
{
	char	res[500001];

	if ((start_bis = strstr(start_bis+1, "</h3><div")))
	{
		// printf("\n-Auteur_video-|");
		end = strstr(start_bis + 7, "<div class");
		bzero(res, 5000);
		memcpy(res, start_bis + 24, end - start_bis - 24);
		remplace_str(res);
		printf("|||%s ", res);
		return (1);
	}
	else
		printf("||| ");
	return (0);
}

int		nb_comm(char *start_bis, char *end)
{
	char	res[500001];

	if ((start_bis = strstr(start_bis+1, "__tn__=%2AW-R\" class=\"")))
	{
		// printf("\n-NB Commentaires-|");
		if((end = strstr(start_bis, "commentaires</a>")))
		{
			bzero(res, 5000);
			memcpy(res, start_bis + 26, end - start_bis - 26);
			remplace_str(res);
			printf("|||nb_comm: %s ", res);
			return (1);
		}
		else
			printf("|||nb_comm_no ");
	}
	else
		printf("|||nb_comm_else ");
	return (0);
}


int		main(int ac, char **av)
{
	char buff[500001];
	char cont[500001];
	int fd;
	char *start;
	char *start_bis;
	char *end;
	int i;
	int image;

	if (ac != 2)
	{
		printf("mauvais nombre d'argument.\n");
		exit (0);
	}
	image = 0;
	i = 0;
	fd = open(av[1], O_RDONLY);
	read(fd, buff, 500001);
	start = buff;
	printf("Container, Proprio, Date, Text, Lien, Titre, Auteur, Nb_comm, Image_profil\n");
 	while ((start = strstr(start+1, "role=\"presentation\"><tbody><tr><td class=\"m\"><div ")))
	{
		// if (is_clone())
		// 	continue;
		printf("\ncontainer %d:", ++i);
		end = strstr(start, "avis sur cette publication</a>");

		bzero(cont, 500001);
		memcpy(cont, start, end - start);

		start_bis = cont;
		image = (proprio(start_bis, end) == 1) ? 1 : 0;

		start_bis = cont;
		date(start_bis, end);

		start_bis = cont;
		image = (text(start_bis, end) == 1) ? 1 : 0;

		start_bis = cont;
		image = (titre(start_bis, end) == 1) ? 1 : 0;

		start_bis = cont;
		image = (auteur(start_bis, end) == 1) ? 1 : 0;

		start_bis = cont;
		nb_comm(start_bis, end);

		if (image == 0)
			printf("|||1");
		else
			printf("||| ");
		image = 0;
		// printf("passage %d\n", i);
		// if (i == 2)
		// 	printf("\n\n%s\n" ,strstr(start+1, "role=\"presentation\"><tbody><tr><td class=\"m\"><div"));
	}
	return (0);
}
