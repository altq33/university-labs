#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include <string>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
string alpha1 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ .,!";
string alpha2 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ .,!";
const int COL = 5, ROW = 6;
int capitalize(char* str) // Функция перевода в верхний регистр 
{
    int k = strlen(str);
    for (int i = 0; i < k; i++)
    {
        str[i] = toupper(str[i]);
    }
    return k;
}
void CodeMessage(char* key1, char* key2)
{
    int index_of_sym1_r, index_of_sym1_c, index_of_sym2_r, index_of_sym2_c, i1 = 0, i2 = 0, index_of_last_char = 0, index_of_last_char1 = 0; // для хранения индеков символов "пары2
    char sym1, sym2; // для хранения символов "пары"
    char user_message[255], space_add[2] = " "; // строки для хранения введенного сообщения и добавочного пробела в случае нечетности строки 
    string coded_message; // строка заданная классом string для хранения в ней закодированного сообщения 
    char Table1[ROW][COL];// таблица алфавита 1 
    char Table2[ROW][COL]; // таблица алфавита 2

    for (int i = 0; i < ROW; i++)   // заполняем 1 ключевое слово 
    {
        for (int j = 0; j < COL; j++)
        {
            if (i1 <= strlen(key1))
            {
                Table1[i][j] = key1[i1];
                i1 += 1;
                index_of_last_char = i;
                index_of_last_char1 = j;
            }
             
        }
    }
    // Заполнение первой таблицы ключом и добавочным алфавитом 
    for (int i = 0; i < strlen(key1); i++)
    {
        alpha1.erase(alpha1.find(key1[i]), 1);
    }
    for (int i = index_of_last_char; i < index_of_last_char + 1; i++)
    {
        for (int j = index_of_last_char1; j < COL; j++)
        {
            Table1[i][j] = alpha1[i2];
            i2++;
        }
    }
    for (int i = index_of_last_char + 1; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            Table1[i][j] = alpha1[i2];
            i2++;
        }
    } 
    // Заполнение второй таблицы ключом и добавочным алфавитом. 
    i1 = 0;
    for (int i = 0; i < ROW; i++)        
    {
        for (int j = 0; j < COL; j++)
        {
            if (i1 <= strlen(key2))
            {
                Table2[i][j] = key2[i1];
                i1 += 1;
                index_of_last_char = i;
                index_of_last_char1 = j;
            }   
        }
    }
    for (int i = 0; i < strlen(key2); i++)
    {
        alpha2.erase(alpha2.find(key2[i]), 1);
    }
    i2 = 0;
    for (int i = index_of_last_char ; i < index_of_last_char+1; i++)
    {
      for (int j = index_of_last_char1 ; j < COL; j++)
        {
            Table2[i][j] = alpha2[i2];
            i2++;
        }
    }
    for (int i = index_of_last_char + 1; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            Table2[i][j] = alpha2[i2];
            i2++;
        }
    }


    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            cout << Table1[i][j] << " ";
        }
        cout << endl; 
    }
    cout << endl << endl;
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            cout << Table2[i][j] << " ";
        }
        cout << endl;
    }
    cout << "Введите сообщение: ";
    cin.getline(user_message, 255);
    // Начало кодировки запроса 
    int userm_len = strlen(user_message); // Получение длины пользовательского сообщения 
    if (userm_len % 2 > 0)    //  Добавление пробела в случае нечетности строки 
    {
        strcat_s(user_message, space_add);
    }
    capitalize(user_message); // Перевод в верхний регистр 
    // Шифрование 
    for (int i = 0; i < userm_len; i += 2) // Основной цикл составления закодированной строки 
    {
        sym1 = user_message[i]; // Запись первого символа пары 
        sym2 = user_message[i + 1]; // Запись второго символа пары 
        for (int j = 0; j < ROW; j++) // Перебор массива для поиска нужных элементов 
        {
            for (int k = 0; k < COL; k++)
            {
                if (Table1[j][k] == sym1)
                {
                    index_of_sym1_r = j;
                    index_of_sym1_c = k;
                }
                if (Table2[j][k] == sym2)
                {
                    index_of_sym2_r = j;
                    index_of_sym2_c = k;
                }
            }
        }
        // Работа с индексами. "Построение условных прямоугольников"     
        if (index_of_sym1_c == index_of_sym2_c) // реализация принципов прямоугольника 
        {
            coded_message = coded_message + Table1[index_of_sym2_r][index_of_sym2_c];
            coded_message = coded_message + Table2[index_of_sym1_r][index_of_sym1_c];
        }
        else
        {
            coded_message = coded_message + Table1[index_of_sym1_r][index_of_sym2_c];
            coded_message = coded_message + Table2[index_of_sym2_r][index_of_sym1_c];
        }

    }
        cout << "Ваше преобразованное сообщение: " << coded_message << endl; // Вывод закодированного сообщения 
}
void main()
{
    int f;
    char key1[30], key2[30]; 
    SetConsoleOutputCP(1251); // Установка кодировок для корректного отоброжения русского языка в консоли 
    SetConsoleCP(1251);
    setlocale(LC_ALL, "Ru"); // Локализация русских символов 
    cout << "Введите первый ключ(ключ не должен содержать повторяющихся символов):" << endl;
    cin >> key1; 
    cout << "Введите второй ключ(ключ не должен содержать повторяющихся символов):" << endl;
    cin >> key2; 
    capitalize(key1);
    capitalize(key2);
    cout << "Какое действие выполнить, декордировать(1) или закодировать(2)?" << endl;
    cin >> f;
    cin.ignore();
    switch (f)
    {
    case 1:
        
        CodeMessage(key1, key2);
        break;
    case 2:
       
        CodeMessage(key1, key2);
        break;
    default:
        cout << "Недопустимое значение, допустимые значения: 1, 2" << endl;
        break;
    }
}