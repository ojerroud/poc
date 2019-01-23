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
// "<div role=\"article"
// "</div><div role"

void friend(char *start_bis, char *end, char cont[100001])
{
	char res[100001];

	while ((start_bis = strstr(start_bis+1, "Afficher tous les amis")))
	{
		printf("\n-amis-|");
		end = strstr(start_bis, "</a>");
		bzero(res, 100000);
		memcpy(res, start_bis + 23, end - start_bis - 23);
		printf("%s|\n", res);
	}
}

void educ(char *start_bis, char *end, char cont[100001])
{
	char res[100001];
	char *start_tris;
	char *start_quad;

	if ((start_bis = strstr(start_bis+1, "education")))
	{
		end = strstr(start_bis, "</div></div></div></div>");
		bzero(res, 100000);
		start_tris = start_bis;
		while ((start_tris = strstr(start_tris+1, "<a class=\"cl")))
		{
			printf("\netablissement scolaire: ");
			end = strstr(start_tris, "</a></span");
			memcpy(res, start_tris + 19, end - start_tris - 19);
			start_quad = res;
			while ((start_quad = strstr(start_quad+1, "\">")))
			{
				printf("%s|\n", start_quad + 2);
			}
		}
		start_tris = cont;
	}
}

void town(char *start_bis, char *end, char cont[100001])
{
	char res[100001];
	char *start_tris;

	while ((start_bis = strstr(start_bis+1, "Ville actuelle</span></div></td><td valign=")))
	{
		printf("\n-ville actuelle-|");
		end = strstr(start_bis, "</a></div></td></tr>");
		bzero(res, 100000);
		memcpy(res, start_bis + 86, end - start_bis - 86);
		start_tris = res;
		while ((start_tris = strstr(start_tris+1, "\">")))
		{
			printf("%s|\n", start_tris + 2);
		}
	}
	start_bis = cont;
	while ((start_bis = strstr(start_bis+1, "Ville d’origine</span></div></td><td valign=")))
	{
		printf("\n-ville d'origine-|");
		end = strstr(start_bis, "</a></div></td></tr>");
		bzero(res, 100000);
		memcpy(res, start_bis + 89, end - start_bis - 89);
		start_tris = res;
		while ((start_tris = strstr(start_tris+1, "\">")))
		{
			printf("%s|\n", start_tris + 2);
		}
	}
}

void sexe(char *start_bis, char *end, char cont[100001])
{
	char res[100001];

	while ((start_bis = strstr(start_bis+1, "Sexe</span></div></td>")))
	{
		printf("\n-sexe-|");
		end = strstr(start_bis, "</div></td></tr></table>");
		bzero(res, 100000);
		memcpy(res, start_bis + 66, end - start_bis - 66);
		printf("%s|\n", res);
	}
}

void citation(char *start_bis, char *end, char cont[100001])
{
	char res[100001];

	while ((start_bis = strstr(start_bis+1, "<div id=\"quote\">")))
	{
		printf("\n-citation-|");
		end = strstr(start_bis, "</div></div></div></div>");
		bzero(res, 100000);
		memcpy(res, start_bis + 267, end - start_bis - 267);
		printf("%s|\n", res);
	}
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
	fd = open(argv[1], O_RDONLY);
	read(fd, buff, 100000);
	start = buff;
	while ((start = strstr(start+1, "objects")))
	{
		printf("\n\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\n");
		printf("||||||||||||Profil:||||||||||||||||\n");
		printf("////////////////////////////////////////\n");
		end = strstr(start, "/html");
		bzero(cont, 100000);
		memcpy(cont, start, end - start);
		start_bis = cont;
		friend(start_bis, end, cont);
		start_bis = cont;
		educ(start_bis, end, cont);
		start_bis = cont;
		town(start_bis, end, cont);
		start_bis = cont;
		sexe(start_bis, end, cont);
		start_bis = cont;
		citation(start_bis, end, cont);
		start_bis = cont;
		printf("\n");
	}
	return (0);
}
