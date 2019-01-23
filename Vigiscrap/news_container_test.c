/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   news_container.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vle-gal <vle-gal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 15:54:16 by vle-gal           #+#    #+#             */
/*   Updated: 2018/09/06 16:32:13 by vle-gal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>

int proprio(char *start_bis, char *end, char cont[100001])
{
	char res[100001];
	if ((start_bis = strstr(start_bis+1, "tn__=CH-R\">")))
		{
			printf("\n*****proprio_du_partage|");
			end = strstr(start_bis, "</a></strong>");
			bzero(res, 100000);
			memcpy(res, start_bis + 11, end - start_bis - 11);
			printf("%s|\n", res);
			return (1);
		}
	// else
	// 	{
	// 		printf(" ");
	// 	}
	return (0);
}
void date(char *start_bis, char *end, char cont[100001])
{
	char res[100001];
	while ((start_bis = strstr(start_bis+1, "<abbr>")))
		{
			printf("\n|=|date-|");
			end = strstr(start_bis, "</abbr>");
			bzero(res, 100000);
			memcpy(res, start_bis + 6, end - start_bis - 6);
			printf("%s| - 1 HEURE|\n", res);
		}
}
int text(char *start_bis, char *end, char cont[100001])
{
	char res[100001];
	while ((start_bis = strstr(start_bis+1, "<span><p>")))
		{
			printf("\n-text_DU_CONTAINER-|");
			end = strstr(start_bis, "</p>");
			bzero(res, 5000);
			memcpy(res, start_bis + 9, end - start_bis - 9);
			printf("%s|", res);
			return (1);
		}
	return (0);
}
int titre(char *start_bis, char *end, char cont[100001])
{
	char res[100001];
	while ((start_bis = strstr(start_bis+1, "<td class=\"t\"><")))
		{
			printf("\n-Titre_video-|");
			end = strstr(start_bis, "</h3><div class=");
			bzero(res, 5000);
			memcpy(res, start_bis + 35, end - start_bis - 35);
			printf("%s|", res);
			return (1);
		}
	return (0);
}
int auteur(char *start_bis, char *end, char cont[100001])
{
	char res[100001];
	while ((start_bis = strstr(start_bis+1, "</h3><div")))
		{
			printf("\n-Auteur_video-|");
			end = strstr(start_bis + 7, "<div class");
			bzero(res, 5000);
			memcpy(res, start_bis + 24, end - start_bis - 24);
			printf("%s|", res);
			return (1);
		}
	return (0);
}
int nb_comm(char *start_bis, char *end, char cont[100001])
{
	char res[100001];
	while ((start_bis = strstr(start_bis+1, "class=\"du\"")))
		{
			printf("\n-NB Commentaires-|");
			end = strstr(start_bis, "commentaires</a>");
			bzero(res, 5000);
			memcpy(res, start_bis + 11, end - start_bis - 11);
			printf("%s|", res);
			return (1);
		}
		return (0);
}


int main(int argc, char **argv)
{
	printf("ds");
	char buff[100001];
	char res[100001];
	char cont[100001];
	int fd;
	char *start;
	char *start_bis;
	char *end;
	int i;
	i = 1;
	int image;
	image = 0;
	fd = open(argv[1], O_RDONLY);
	read(fd, buff, 100000);
	start = buff;
 	while ((start = strstr(start+1, "role=\"presentation\"><tbody><tr><td class=\"m\"><div ")))
	{
		printf("\n\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\n");
		printf("||||||||||||container %d:||||||||||||||||\n", i);
		printf("////////////////////////////////////////\n");
		end = strstr(start, "avis sur cette publication</a>");
		bzero(cont, 100000);
		memcpy(cont, start, end - start);
		// printf("%s\n", cont);
		start_bis = cont;
		// printf("%s\n", start_bis);
		// printf("\n%s\n", end);
		proprio(start_bis, end, cont) == 1 ? image++ : 0;
		start_bis = cont;
		date(start_bis, end, cont);
		start_bis = cont;
		text(start_bis, end, cont) == 1 ? image++ : 0;
		start_bis = cont;
		titre(start_bis, end, cont) == 1 ? image++ : 0;
		start_bis = cont;
		auteur(start_bis, end, cont) == 1 ? image++ : 0;
		start_bis = cont;
		nb_comm(start_bis, end, cont) == 1 ? image++ : 0;
		i++;
		printf("\n");
		if (image == 0)
		{
			printf("Nouvelle image de profil\n");
		}
	}
	return (0);
}
