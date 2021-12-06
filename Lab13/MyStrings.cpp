int mystrlen(char* s)
{
	int len = 0;
	while (s[len] != 0)
	{
		len++;
	}
	return len;
}

void mystrcy(char* s, char* s2)
{
	for (int i = 0; i < mystrlen(s); i++)
	{
		s2[i] = s[i];
	}
	s2[mystrlen(s)] = 0;
}
void mystrcat(char* s, char* s2)
{
	int len = mystrlen(s), j = 0;
	for (int i = len; i < len + mystrlen(s2); i++)
	{
		s[i] = s2[j];
		j++;
	}
	s[len + j] = 0; 
}
int mystrcmp(char* s, char* s2)
{
	int i = 0;
	while (s[i] == s2[i] && s[i] != '\0' && s2[i] != '\0')
	{
		i++;
	}
	return (s[i] - s2[i]);
}
char* mystrchr(char* s, char c)
{
	for (int i = 0; i < mystrlen(s); i++)
	{
		if (s[i] == c)
		{
			return &s[i];
		}			
	}
	return nullptr; 
}
