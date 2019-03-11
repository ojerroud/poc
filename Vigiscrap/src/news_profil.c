/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   news_profil.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojerroud <ojerroud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 15:54:16 by vle-gal           #+#    #+#             */
/*   Updated: 2019/03/11 14:10:13 by ojerroud         ###   ########.fr       */
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

	if ((start_bis = strstr(start_bis+1, "Afficher tous les amis")))
	{
		// printf("\n-amis-|");
		end = strstr(start_bis, "</a>");
		bzero(res, 100000);
		memcpy(res, start_bis + 24, end - start_bis - 25);
		printf("%s", res);
	}
	else
	{
		printf("");
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
		// <a class=\"cl
		while ((start_tris = strstr(start_tris+1, "alt=")))
		{
			// printf("\netablissement scolaire: ");
			end = strstr(start_tris, "</a></span");
			memcpy(res, start_tris + 0, end - start_tris - 0);
			start_quad = res;
			while ((start_quad = strstr(start_quad+1, "\">")))
				printf(",%s", start_quad + 2);
		}
		start_tris = cont;
	}
	else
		printf(",");
}

void town(char *start_bis, char *end, char cont[100001])
{
	char res[100001];
	char *start_tris;

	if ((start_bis = strstr(start_bis+1, "Ville actuelle</span></div></td><td valign=")))
	{
		// printf("\n-ville actuelle-|");
		end = strstr(start_bis, "</a></div></td></tr>");
		bzero(res, 100000);
		memcpy(res, start_bis + 86, end - start_bis - 86);
		start_tris = res;
		if ((start_tris = strstr(start_tris+1, "\">")))
			printf(",%s", start_tris + 2);
		else
			printf(",");
	}
	else
		printf(",");
	start_bis = cont;
	if ((start_bis = strstr(start_bis+1, "Ville d’origine</span></div></td><td valign=")))
	{
		// printf("\n-ville d'origine-|");
		end = strstr(start_bis, "</a></div></td></tr>");
		bzero(res, 100000);
		memcpy(res, start_bis + 89, end - start_bis - 89);
		start_tris = res;
		if ((start_tris = strstr(start_tris+1, "\">")))
			printf(",%s", start_tris + 2);
		else
			printf(",");
	}
	else
		printf(",");
}

void sexe(char *start_bis, char *end, char cont[100001])
{
	char res[100001];

	if ((start_bis = strstr(start_bis+1, "Sexe</span></div></td>")))
	{
		// printf("\n-sexe-|");
		end = strstr(start_bis, "</div></td></tr></table>");
		bzero(res, 100000);
		memcpy(res, start_bis + 66, end - start_bis - 66);
		printf(",%s", res);
	}
	else
	{
		printf(",");
	}
}

char	*clean_str(char *str)
{
	char	*tmp;
	int		i = -1;
	int		j = -1;
	int		k;
	char	*to_check;

	to_check = malloc(100001);
	tmp = malloc(100001);
	to_check = strcpy(to_check, "<br />");
	while (str[++i])
	{
		if (str[i] == to_check[0])
		{
			k = 0;
			while (to_check[k] == str[i + k] && str[i])
			{
				if (!to_check[k + 1])
				{
					tmp[++j] = '\\';
					tmp[++j] = 'n';
					i += k + 1;
					break ;
				}
				k++;
			}
		}
		tmp[++j] = str[i];
		if (str[i] == ',')
			tmp[j] = ';';
	}
	return (tmp);
}

void	line_break(char *str)
{
	char	*temp;

	temp = malloc(100001);
	temp = clean_str(str);
	bzero(str, 100001);
	memcpy(str, temp, strlen(temp));
	free(temp);
}

void citation(char *start_bis, char *end, char cont[100001])
{
	char res[100001];

	if ((start_bis = strstr(start_bis+1, "<div id=\"quote\">")))
	{
		// printf("\n-citation-|");
		end = strstr(start_bis, "</div></div></div></div>");
		bzero(res, 100000);
		memcpy(res, start_bis + 267, end - start_bis - 267);
		line_break(res);
		printf(",%s", res);
	}
	else
		printf(",");
}

int main(int argc, char **argv)
{
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
		printf("Profil\nAmis, Ville actuel, Ville d'origine, Sexe, Citation\n");
		end = strstr(start, "/html");
		bzero(cont, 100000);
		memcpy(cont, start, end - start);
		start_bis = cont;
		friend(start_bis, end, cont);
		start_bis = cont;
		// educ(start_bis, end, cont);
		// start_bis = cont;
		town(start_bis, end, cont);
		start_bis = cont;
		sexe(start_bis, end, cont);
		start_bis = cont;
		citation(start_bis, end, cont);
		start_bis = cont;
	}
	return (0);
}
