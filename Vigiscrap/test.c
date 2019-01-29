int		text(char *start_bis, char *end)
{
	char res[500001];
	char	*temp;

	if ((start_bis = strstr(start_bis+1, "<span><p>")))
	{
		end = strstr(start_bis, "</p></span>");
		bzero(res, 5000);
		memcpy(res, start_bis + 9, end - start_bis - 9);
		temp = malloc (500001);
		temp = clean_str(res);
		bzero(res, 5000);
		memcpy(res, temp, strlen(temp));
		free(temp);
		printf("|||text: %s ", res);
		return (1);
	}
	else
		printf("|||text_no ");
	return (0);
}

int		text(char *start_bis, char *end)
{
	char res[500001];

	if ((start_bis = strstr(start_bis+1, "<span><p>")))
	{
		end = strstr(start_bis, "</p>");
		bzero(res, 5000);
		memcpy(res, start_bis + 9, end - start_bis - 9);
		printf("|||%s", res);
		return (1);
	}
	else
	{
		printf("||| ");
	}
	return (0);
}