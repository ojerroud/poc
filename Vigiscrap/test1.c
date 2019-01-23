/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vle-gal <vle-gal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 15:54:16 by vle-gal           #+#    #+#             */
/*   Updated: 2018/09/03 16:43:51 by vle-gal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>

int main(void)
{
	// char buff[80000];
	// char res[5000];
	// int fd;
	char *start;
	char *end;
	char res[100] = "je suis la ou pas je suis la juste la zut /0";
	printf("le\n");
	while ((start = strstr(res+1, "je")))
	{
		printf("dedans\n");
		end = (strstr(start, "la"));
		memcpy(res, start, end - start);
		printf("%s\n", res);
	}
	// fd = open("100001596874228.1.timeline", O_RDONLY);
	// read(fd, buff, 80000);

	// start = strstr(buff, "<span><p>");
	// end = strstr(buff, "</p>");
	//
	// bzero(res, 5000);
	// memcpy(res, start, end - start);
	// printf("%s\n", res);


// 	start = buff;
// // <span><p>bla</p></span><span><p></p></span>
// 	while ((start = strstr(start+1, "<span><p>")))
// 	{
// 		end = strstr(start, "</p>");
// 		bzero(res, 5000);
// 		memcpy(res, start + 9, end - start - 9);
// 		printf("%s \n\n", res);
// 	}

	// printf("%d   %d   %d\n", start, end, end - start);






	return (0);
}
