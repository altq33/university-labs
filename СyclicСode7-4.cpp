#include <iostream>
#include <string>
using namespace std;
string div(string del, string delt);
void encode();
void decode();
int sym(string s, string s1);
void main()
{
	setlocale(LC_ALL, "ru");
	int c;
	cout << "Циклический код 7-4\n" << endl << endl;
	while (true)
	{
		cout << "________________________________________________\n\n1 - Закодировать" << endl;
		cout << "2 - Декодировать" << endl;
		cout << "________________________________________________" << endl << endl;
		cout << "Выберите действие: ";
		cin >> c;
		if (c != 1 && c != 2)
		{
			cout << "\nПожалуйста введите корректный номер!" << endl;
		}
		else
		{
			switch (c)
			{
			case 1:
				encode();
				break;
			case 2:
				decode();
				break;
			}
			break;
		}
	}
	
}
string div(string del, string delt) 
{
	string  temp, temp2;
	int lenDel = del.size(), lenDelt = delt.size(), k = 0;
	for (int i = 0; i < lenDel; i++)
	{
		if (del[0] == '0')
		{
			del.erase(0, 1);
		}
		else
		{
			break;
		}
	}
	while (del.size() >= lenDelt)
	{
		temp2 = "";
		temp = del.substr(0, lenDelt);
		for (int i = 0; i < lenDelt; i++)
		{
			if (temp[i] == delt[i])
			{
				temp2 += "0";
			}
			else
			{
				temp2 += "1";
			}
		}
		for (int i = 0; i < temp2.size(); i++)
		{
			if (temp2[0] == '0')
			{
				temp2.erase(0, 1);
			}
			else
			{
				break;
			}
		}
		del.erase(0, lenDelt);
		del = temp2 + del;
	}
	if (del.find("1") == -1)
	{
		del = "0";
	}
	return del;
}
void encode()  //  Кодировка
{
	string user_code, polynomial, R; 
	int c;
	while (true) 
	{
		cout << "________________________________________________\n\n1 - x3 + x  + 1 || 1011" << endl;
		cout << "________________________________________________" << endl << endl;
		cout << "Выберите образующий полином: ";
		cin >> c;
		if (c != 1)
		{
			cout << "\nПожалуйста введите корректный номер полинома!" << endl;
		}
		else
		{
			switch (c)
			{
			case 1:
				polynomial = "1011";
				break;
			case 2:
				polynomial = "1011";
				break;
			case 3:
				polynomial = "1011";
				break;
			}
			break;
		}
	}

	while (true)
	{
		cout << "Введите сообщение: ";
		cin >> user_code;
		if (user_code.size() != 4)
		{
			cout << "Пожалуйста, введите сообщение длиной 4 символа!!!" << endl;
		}
		else
		{
			break;
		}
	}
	// начало кодировки
	while (user_code.size() != 7) 
	{
		user_code += "0";
	}
	R = div(user_code, polynomial); 
	for (int i = 0; i < R.size(); i++)    
	{
		user_code.erase(user_code.size() - 1, 1);
	}
	user_code += R;

	cout << "Закодированное сообщение: " << user_code << endl;
}
void decode() 
{
	string user_code, polynomial, R, final_result;      
	int c, count = 0;
	while (true)
	{
		cout << "________________________________________________\n\n1 - x3 + x  + 1 || 1011" << endl;
		cout << "________________________________________________" << endl << endl;
		cout << "Выберите образующий полином: ";
		cout << "Выберите образующий полином: ";
		cin >> c;
		if (c != 1 && c != 2 && c != 3)
		{
			cout << "\nПожалуйста введите корректный номер полинома!" << endl;
		}
		else
		{
			switch (c)
			{
			case 1:
				polynomial = "1011";
				break;
			case 2:
				polynomial = "1011";
				break;
			case 3:
				polynomial = "1011";
				break;
			}
			break;
		}
	}

	while (true)
	{
		cout << "Введите сообщение с ошибкой: ";
		cin >> user_code;
		if (user_code.size() != 7)
		{
			cout << "Пожалуйста, введите сообщение длиной 7 символов, вместе с проверочными битами!!!" << endl;
		}
		else
		{
			break;
		}
	}
	R = div(user_code, polynomial);
	c = sym(R, "1"); 
	while (c > 1)
	{
		user_code = user_code + user_code[0];  
		user_code.erase(0, 1);  
		count++;  
		R = div(user_code, polynomial);
		c = sym(R, "1"); 	
	}

	while (R.size() != user_code.size()) 
	{
		R = "0" + R; 
	}

	for (int i = 0; i < R.size(); i++)  
	{
		if (R[i] == user_code[i])
		{
			final_result += "0";
		}
		else
		{
			final_result += "1";
		}
	}

	for (int i = 0; i < count; i++) 
	{
		final_result = final_result[final_result.size() - 1] + final_result;
		final_result.erase(final_result.size() - 1, 1);
	}  
	final_result.erase(final_result.size() - 3, 3);
	cout << "Исходное сообщение:" << final_result << endl;
}
int sym(string s, string s1)// это по фастику накидал функцию которая считает количество символов в строке
{
	int c = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == s1[0])
		{
			c++;
		}
	}
	return c;
}
