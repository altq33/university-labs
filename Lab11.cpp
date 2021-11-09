#include <stdio.h>
#include <locale>
#include <conio.h>

int main()
{
	FILE* Input; 
	FILE* Output;
	fopen_s(&Input, "D:\\lab11.txt", "rt");
	fopen_s(&Output, "D:\\Lab11.html", "wt");
	char str[256];
	int iter = 0, c = 0;
	bool flag = false;
	// building 
	fprintf(Output, "%s", "<!DOCTYPE html>\n<html>\n<head>\n<title>Lab11</title>\n</head>\n<body>\n");
	while (!feof(Input))
	{
		if (fgetc(Input) == '\n')
			c++;
	}
	fclose(Input);
	fopen_s(&Input, "D:\\lab11.txt", "rt");
	while (!feof(Input))
	{	
		if (iter == 0)
		{
			fgets(str, 256, Input);
			str[strlen(str) - 1] = 0;
			fprintf(Output, "%s", "<h1>");
			fprintf(Output, "%s", str);
			fprintf(Output, "%s", "</h1>\n");
		}
		else
		{
			fgets(str, 256, Input);
			flag = false; 
			for (int i = 0; i < strlen(str) - 1; i++)
			{
				if (str[i] == 'a' || str[i] == 'A')
				{
					flag = true; 
					str[i] = '*';
				}					
			}
			if (flag == true)
			{
				str[strlen(str) - 1] = 0;
				fprintf(Output, "%s", "<b><i>");	
				fprintf(Output, "%s", str);
				fprintf(Output, "%s", "</b></i><br>\n");
			}
			else
			{		
				if (iter != c)
				{
					str[strlen(str) - 1] = 0;
				}		
				fprintf(Output, "%s<br>\n", str);
			}	
		}		
		iter++;
	}
	fprintf(Output, "%s", "\n</body>\n</html>");
	fclose(Input);
	fclose(Output);
	return 0;
}

