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

int proprio(char *start_bis, char *end, char cont[500001])
{
	char res[500001];
	if ((start_bis = strstr(start_bis+1, "tn__=CH-R\">")))
	{
		// printf("\n*****proprio_du_partage|");
		end = strstr(start_bis, "</a></strong>");
		bzero(res, 500001);
		memcpy(res, start_bis + 11, end - start_bis - 11);
		printf("|||%s", res);
		return (1);
	}
	else
		printf("||| ");
	return (0);
}
void date(char *start_bis, char *end, char cont[500001])
{
	char res[500001];
	if ((start_bis = strstr(start_bis+1, "<abbr>")))
		{
			// printf("\n|=|date-|");
			end = strstr(start_bis, "</abbr>");
			bzero(res, 500001);
			memcpy(res, start_bis + 6, end - start_bis - 6);
			printf("|||%s", res);
		}
	else
		{
			printf("||| ");
		}

}
//
// void text_lien(char *start_bis, char *end, char cont[500001])
// {
// 	char res[500001];
//
//
// }

int text(char *start_bis, char *end, char cont[500001])
{
	char res[500001];
	char *test;
	char *test2;
	if ((start_bis = strstr(start_bis+1, "<span><p>")))
		{
			// if (strstr(start_bis, "<a href"))
			// {
			// 	text_lien(start_bis, end, cont);
			// 	return (1);
			// }
			end = strstr(start_bis, "</p>");
			bzero(res, 5000);
			memcpy(res, start_bis + 9, end - start_bis - 9);
			printf("|||%s", res);
			// test = res + 10;
			// printf("\n\n\n\n\n\n\n1%s\n", test);
			// test2 = test + 2;
			// printf("2%s\n", test2);
			// test = test + 3;
			// printf("3%s\n\n\n\n\n\n", test);
			return (1);
		}
	else
		{
			printf("||| ");
		}
	return (0);
}
int titre(char *start_bis, char *end, char cont[500001])
{
	char res[500001];
	if ((start_bis = strstr(start_bis+1, "<td class=\"t\"><")))
		{
			// printf("\n-Titre_video-|");
			end = strstr(start_bis, "</h3><div class=");
			bzero(res, 5000);
			memcpy(res, start_bis + 35, end - start_bis - 35);
			printf("|||%s", res);
			return (1);
		}
	else
	{
		printf("||| ");
	}
	return (0);
}
int auteur(char *start_bis, char *end, char cont[500001])
{
	char res[500001];
	if ((start_bis = strstr(start_bis+1, "</h3><div")))
		{
			// printf("\n-Auteur_video-|");
			end = strstr(start_bis + 7, "<div class");
			bzero(res, 5000);
			memcpy(res, start_bis + 24, end - start_bis - 24);
			printf("|||%s", res);
			return (1);
		}
	else
	{
		printf("||| ");
	}
	return (0);
}
int nb_comm(char *start_bis, char *end, char cont[500001])
{
	char res[500001];
	if ((start_bis = strstr(start_bis+1, "__tn__=%2AW-R\" class=\"")))
		{
			// printf("\n-NB Commentaires-|");
			if((end = strstr(start_bis, "commentaires</a>")))
			{
				bzero(res, 5000);
				memcpy(res, start_bis + 26, end - start_bis - 26);
				printf("|||%s", res);
				return (1);
			}
			else
			{
				printf("||| ");
			}
		}
	else
		{
			printf("||| ");
		}
		return (0);
}


int main(int argc, char **argv)
{
	char buff[500001];
	char res[500001];
	char cont[500001];
	int fd;
	char *start;
	char *start_bis;
	char *end;
	int i;
	i = 1;
	int image;
	image = 0;
	fd = open(argv[1], O_RDONLY);
	read(fd, buff, 500001);
	start = buff;
	printf("Container, Proprio, Date, Text, Lien, Titre, Auteur, Nb_comm, Image_profil\n");
 	while ((start = strstr(start+1, "role=\"presentation\"><tbody><tr><td class=\"m\"><div ")))
	{
		printf("\ncontainer %d:", i);
		end = strstr(start, "avis sur cette publication</a>");
		bzero(cont, 500001);
		memcpy(cont, start, end - start);
		// printf("%s\n", cont);
		start_bis = cont;
		// printf("%s\n", start_bis);
		// printf("\n%s\n", end);
		proprio(start_bis, end, cont) == 1 ? image++ : 0;
		// printf("la");
		start_bis = cont;
		date(start_bis, end, cont);
		// printf("le");
		start_bis = cont;
		text(start_bis, end, cont) == 1 ? image++ : 0;
		// printf("li");
		start_bis = cont;
		titre(start_bis, end, cont) == 1 ? image++ : 0;
		// printf("lo");
		start_bis = cont;
		auteur(start_bis, end, cont) == 1 ? image++ : 0;
		// printf("lu");
		start_bis = cont;
		nb_comm(start_bis, end, cont);
		// printf("let");
		i++;
		if (image == 0)
		{
			printf("|||1");
		}
		else
		{
			printf("||| ");
		}
		image = 0;
	}
	return (0);
}
