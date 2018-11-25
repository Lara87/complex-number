#include <iostream>
#include <fstream>
#include <complex>
#include <conio.h>
#include <ctime>
#include <cmath>
#include <windows.h>

using namespace std;


void title()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD cor = { 0,0 };
	cor.X = 10;
	cor.Y = 5;
	SetConsoleCursorPosition(hConsole, cor);
	cout << "    «Астраханский государственный технический университет»\n";
	cout << "                 Институт Информационных технологий и коммуникаций\n";
	cout << "\n";
	cout << " \n";
	cout << "\n";
	cout << "\n";
	cout << "\n";
	cout << "\n";
	cout << "       Кафедра Автоматизированные системы обработки информации и управления\n";
	cout << "\n";
	cout << "\n";
	cout << "                               КУРСОВОЙ ПРОЕКТ\n";
	cout << "\n";
	cout << "\n";
	cout << "             Программа - тренажёр «Действия над комплексными числами»\n";
	cout << "                    по дисциплине «Программирование и информатика»\n";
	cout << "\n";
	cout << "\n";
	cout << "\n";
	cout << "\n";
	cout << "\n";
	cout << "\n";
	cout << "             Проект выполнен cтуденткой группы ЗИНРБ - 11 Черниковой Л.В.\n";
	cout << "\n";
	cout << "\n";
	cout << "                      Руководитель работы ст.преп.Растопшина Т.С.\n";
	_getch();
}

int menu()
{
	int a;
	do
	{
		system("cls");
		cout << " Выберите пункт меню" << endl;
		cout << " 1. Теоретическая часть" << endl;
		cout << " 2. Тренажёр" << endl;
		cout << " 0. Выход" << endl;
		cin >> a;
	} while (a > 2 || a < 0);

	system("CLS");
	return a;
}

int VyborVariantaPolucheniyaChisel() //даем пользователю выбрать как будет формироваться вывод чисел
{
	int a;
	do {
		system("cls");
		cout << " Выберите вариант получения чисел" << endl;
		cout << " 1. Числа сгенерированные компьютером" << endl;
		cout << " 2. Пользовательский ввод чисел" << endl;
		cout << " 0. Выход" << endl;
		cin >> a;
	} while (a > 2 || a < 0);
	system("cls");
	return a;
}

void people(double &a1, double &b1, double &a2, double &b2)//ввод пользователем чисел
{
	cout << " Введите действительную часть первого числа: ";
	cin >> a1;
	cout << " Введите мнимую часть первого числа: ";
	cin >> b1;
	cout << " Введите действительную часть первого числа: ";
	cin >> a2;
	cout << " Введите мнимую часть первого числа: ";
	cin >> b2;
	system("pause");
}

string readfile(string filename)
{
	string line;
	string text;
	ifstream myfile(filename);

	if (myfile.is_open())
	{
		while (!myfile.eof())
		{
			getline(myfile, line);
			line += "\n";//посмотреть
			text += line;//text=text+line
		}
		myfile.close();
	}
	else cout << "не удалось открыть файл" << endl;

	return text;
}

//Вызывает чтение из файла и выводит текст на экран
void readtheory()
{
	string theoryfilename = "theory.txt";
	cout << readfile(theoryfilename);
	system("pause");
	system("cls");
}

int random(int a, int b)
{
	return a + rand() % (b - a + 1);
}

void summ(double a1, double b1, double a2, double b2, double &c1, double &c2) //сумма формула
{
	c1 = a1 + a2;
	c2 = b1 + b2;
}

void difference(double a1, double b1, double a2, double b2, double &c1, double &c2) //разность формула
{
	c1 = a1 - a2;
	c2 = b1 - b2;
}

void multiplication(double a1, double b1, double a2, double b2, double &c1, double &c2) //произведение формула
{
	c1 = ((a1*b1) - (a2*b2));
	c2 = ((a1*b2) - (a2*b1));
}

void division(double a1, double b1, double a2, double b2, double &c1, double &c2) //деление формула
{
	double q = (a2*a2 + b2*b2);
	if (q == 0)
	{
		cout << "Деление на ноль невозможно!" << endl;
	}
	else
		c1 = (a1*a2 + b1*b2) / q;
	c2 = (b1*a2 - a1*b2) / q;
}

void output_answer(double c1, double c2) //вывод результата
{
	cout << c1 << (c2 >= 0.0 ? "+" : "-") << abs(c2) << "i\n";
}

//выбор действия с комплексными числами
int choiseaction()
{
	int a;
	cout << " Выберите действия с комплексными числами" << endl;
	cout << "1. Сложение" << endl;
	cout << "2. Вычитание" << endl;
	cout << "3. Умножение" << endl;
	cout << "4. Деление" << endl;
	cout << "0. Выход" << endl;
	cin >> a;
	return a;
}

bool proverka(double a1, double b1, double a2, double b2)
{
	const double eps = 0.00001;
	return (fabs(a1 - a2) < eps && fabs(b1 - b2) < eps);
}

bool VvodOtveta(double a1, double b1, int &k)//a1 и b1 - эталонный ответ, k - счетчик неправильных ответов
{
	double a2, b2;//ответ пользователя
	bool res = false;
	do
	{
		cout << "Введите свой ответ:" << endl;
		cout << "действительная часть= ";
		cin >> a2;
		cout << "мнимая часть= ";
		cin >> b2;
		res = proverka(a1, b1, a2, b2);
		if (res)
			return true;
		else
		{
			cout << "Ответ неверный" << endl;
			k++;
		}
	} while (k < 3);
	return false;
}

void SozdanieKomplChisel(double &a1, double &b1, double &a2, double &b2)
{
	int d1 = 1, d2 = 9;
	a1 = random(d1, d2);
	a2 = random(d1, d2);
	b1 = random(d1, d2);
	b2 = random(d1, d2);
}

int do_practice(int &k)
{
	bool res = false;
	double a1 = 0, b1 = 0, a2 = 0, b2 = 0;
	do
	{
		int d1 = 1, d2 = 9;
		double c1 = 0.0, c2 = 0.0;
		int m = VyborVariantaPolucheniyaChisel();
		switch (m)
		{

		case 1:
			SozdanieKomplChisel(a1, b1, a2, b2);
			cout << "Первое комплексное число: " << a1 << "+" << b1 << "i" << endl;
			cout << "Второе комплексное число: " << a2 << "+" << b2 << "i" << endl;
			break;
		case 2:
			people(a1, b1, a2, b2);
			break;
		case 0:
			return 0;
			break;
		}
		int j = choiseaction();
		switch (j)
		{
		case 1:
			summ(a1, b1, a2, b2, c1, c2);
			res = VvodOtveta(c1, c2, k);
			break;
		case 2:
			difference(a1, b1, a2, b2, c1, c2);
			res = VvodOtveta(c1, c2, k);
			break;
		case 3:
			multiplication(a1, b1, a2, b2, c1, c2);
			res = VvodOtveta(c1, c2, k);
			break;

		case 4:
			division(a1, b1, a2, b2, c1, c2);
			res = VvodOtveta(c1, c2, k);
			break;
		case 0:
			return 0;
			break;
		}
		if (res)
		{
			char l;
			cout << "Вы ответили верно!Решите еще пример (y/n)?\n";
			cin >> l;
			if (l != 'y')
				return 0;
		}
	} while (res);
	cout << "Эталонный ответ";
	output_answer(a1, b1);
	cout << "Повторите теорию! Вы ответили неверно три раза!" << endl;
	return 1;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	title();
	srand((unsigned int)time(0)); //автоматическая рандомизация каждый раз новое число
	int schet = 0;
	do
	{
		int k = menu();
		int p;
		switch (k)
		{
		case 1:
			readtheory();
			break;
		case 2:
			p = do_practice(schet);
			if (p == 1)
			{
				schet = 0;
				readtheory();
			}
			break;
		case 0:
			return 0;
			break;
		}
	} while (true);
	return 0;
}
