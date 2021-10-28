#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int to_dec(string bin) 
{
	int num = 0;
	int k = 0;
	for (int i = size(bin) - 1 ; i >= 0; i--)
	{
		if (bin[i] == '1')
		{
			num += pow(2, k);
		}
		k += 1;
	}
	return num;
}

string to_bin(int a) // Перевод в двоичную систему целой части
{
	string new_bin;
	do
	{
		new_bin = to_string(a % 2) + new_bin;
		a /= 2;
	} while (a > 0);
	return new_bin;
} 

string to_bin_float(double a) // перевод в двоичную систему дробной части
{
	string new_bin;
	while (a - (int)a > 0)
	{
		a *= 2; 
		new_bin += to_string((int)a);
		a -= (int)a; 
	}
	return new_bin; 
}

string dec_to_hex(int ten_num) //перевод в 16-ную систему десятичного числа
{
	string sixt_num;
	do
	{
		switch (ten_num % 16)
		{
		case 10:
			sixt_num += "A";
			break;
		case 11:
			sixt_num = "B" + sixt_num;
			break;
		case 12:
			sixt_num = "C" + sixt_num;
			break;
		case 13:
			sixt_num = "D" + sixt_num;
			break;
		case 14:
			sixt_num = "E" + sixt_num;
			break;
		case 15:
			sixt_num = "F" + sixt_num;
			break;
		default:
			sixt_num = to_string(ten_num % 16) + sixt_num;
		}
		ten_num /= 16;
	} while (ten_num % 16 > 0);
	return sixt_num; 
}

string exponent_calc(string bin)  // Получение  показателя
{
	int exponent = 0; 
	for (int i = 1; i < size(bin); i++)
	{
		if (bin[i] != '.')
		{
			exponent += 1;
		}
		else
		{
			break;
		}
	}
	return to_bin(exponent); 
}

string sign_calc(int num)
{
	if (num > 0)
		return "0";
	if (num < 0)
		return "1";
}

string remove_point(string bin) // сдвиг точки к нормализованному виду
{
	bin.erase(bin.find_first_of('.'), 1);
	bin.erase(0, 1);
	bin = "1." + bin; 
	return bin; 
}

string bin_result_build(string mantis, string exponent, string sign)
{
	string result; 
	exponent = to_bin(to_dec(exponent) + 1023);
	mantis.erase(0, 2);
	while (size(mantis) > 52)
	{
		mantis.erase(size(mantis) - 1, 1);
	}
	for (int i = size(mantis); i < 52; i++)
	{
		mantis += "0";
	}
	result = sign + exponent + mantis;
	return result;
}

string bin_result_to_hex(string bin)
{
	string hex; 
	for (int i = 0; i < 16; i++)
	{
		hex += dec_to_hex(to_dec(bin.substr(0, 4)));
		bin.erase(0, 4);
	}
	return hex;
}

// main 

void main()															
{																		// 1 знак 11 порядок  52 мантиса 
	setlocale(LC_ALL, "ru");
	// 10 -> 16 
	int ten_num;
	cout << "Enter a number in decimal notation: ";
	cin >> ten_num; 
	cout << "The above number is in hexadecimal notation: ";
	cout << dec_to_hex(ten_num) << endl << endl << endl;

		//  IEEE754 format
	double  number = -1231.12345;

	string bin, mantis,exponent, final_result_bin, sign, final_result_hex;
	// mantis, exponent and sign building
	bin = to_bin((int)abs(number)) + "." + to_bin_float(stod(to_string(abs(number) - (int)abs(number)))); // выделяем целую часть числа и переводим в 2-ю систему
	exponent = exponent_calc(bin);                                            
	mantis = remove_point(bin);
	sign = sign_calc(number);
	cout << "THE ORIGINAL NUMBER:  " << "- 1231.12345" << endl << endl;
	cout << "STANDART:  IEEE Standard for Binary Floating-Point Arithmetic (ANSI/IEEE Std 754-2008)" << endl << endl;
	cout << "BIN VIEW OF ORIGINAL NUMBER:  " << bin << endl << endl;
	cout << "EXPONENT:  " << exponent << endl << endl;
	cout << "MANTIS:  " << mantis << endl << endl;
	cout << "SIGN:  " << sign << endl << endl;
	 
	// Запись окончательного представления
	final_result_bin = bin_result_build(mantis, exponent, sign); 
	cout << "IEEE754 BIN VIEW OF ORIGINAL NUMBER:  " << final_result_bin << endl << endl;

	final_result_hex = bin_result_to_hex(final_result_bin);
	cout << "IEEE754 HEX VIEW OF ORIGINAL NUMBER:  " << final_result_hex << endl << endl;
 }													 
