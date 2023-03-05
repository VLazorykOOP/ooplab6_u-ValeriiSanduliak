// OOPLab3Tpl.cpp : Цей файл містить є шаблоном для 
// виконання лаб. роботи №6. 
// Він містинь функцію "main" з якої починається та закінчується виконання програми.
//

#include <iostream>
using namespace std;


// Ваші файли загловки 
//
#include "Lab6Example.h"
#include"Task1.h"
#include"Task2.h"
#include"Task3.h"
int main()
{
    std::cout << " Lab #6  !\n";
    char ch = '5';
    do {
        cout << "Chose task 1-3 (4-exit):" << endl;
        cout << " >>> ";
        ch = cin.get();

        cin.get();

        switch (ch) {
        case '1': Task1();  break;
        case '2': Task2();  break;
        case '3': Task3();  break;
        case '4': return 0;
        }
        cout << " Press any key and enter\n";
        ch = cin.get();
    } while (ch != '5');

}