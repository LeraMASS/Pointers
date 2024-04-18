#include <iostream>

void myswap(int num1, int num2) {// копируется и сразу удаляется
	int tmp = num1;
	num1 = num2;
	num2 = tmp;
}
void pswap(int* pointer1, int* pointer2) {// копирует адреса
	int tmp = *pointer1;
	*pointer1 = *pointer2;
	*pointer2 = tmp; // у tmp * не пишем
}

void p_sum_arr(int arr[], const int length, int* var);


int main() {
	setlocale(LC_ALL, "Russian");
	int n, m;

	// Указатели на переменные
	n = 7;
	std::cout << "n = " << n << std::endl;
	std::cout << "&n = " << &n << std::endl;//&(амперсант) ставится для того чтоб вывести адрес переменной.

	int* pn = &n;// создание указателя на обл памяти типа int и присваевания ему значения в виде адреса n
	std::cout << "pn = " << pn << std::endl;// вывод значения указателя (шеснадцатиричный адрес)
	std::cout << "*pn = " << *pn << std::endl; //* разименнование указателя, вывод значения 

	*pn = 15;// изменение значения n через раименование указателя
	std::cout << "n = " << n << std::endl;

	std::cout << "---------------------\n";

	m = 42;

	std::cout << "m = " << m << std::endl;
	std::cout << "&m = " << &m << std::endl;//& ставится для того чтоб узнвть адрес переменной.

	pn = &m;// "перенаправление" указателя на переменную m.
	std::cout << "pn = " << pn << std::endl;
	std::cout << "*pn = " << *pn << std::endl; //* разименнование, показ сохраненного значения в переменной

	int* pm = &m;
	std::cout << "pm = " << pm << std::endl;

	// Указатели и массивы
	const int size = 5;
	int arr[size]{ 30, 40, 50, 60, 70 };

	int* parr2 = &arr[2]; // arr можно написать просто
	std::cout << parr2 << std::endl;
	std::cout << *parr2 << std::endl;

	parr2++;
	std::cout << parr2 << std::endl;
	std::cout << *parr2 << std::endl;

	parr2 = &arr[0];// нельзя перенаправлять указатели массивов
	for (int i = 0; i < size; i++)
		std::cout << *(parr2 + i) << ' ';// упращенный поиск по массиву, можно писать просто arr (- +) сдвиг по памяти
	std::cout << std::endl;

	//Указатели и функции
	n = 19;
	m = 15;
	
	std::cout << n << ' ' << m << std::endl;
	//myswap(n, m); // не работает, тк параметры - это копии передаваемых значений 
	std::cout << "Перевернутый ответ:\n";
	pswap(&n, &m); // & чтоб передать значение из функции
	std::cout << n << ' ' << m << std::endl;
	
	// Задача 1. Сумма массива в указатель
	
	std::cout << "Задача 1.\nМассив:\n";

	const int size1 = 5;
	int arr1[size1]{ 15, 5, 6, 7, 10 };
	for (int i = 0; i < size1; i++)
		std::cout << arr1[i] << ' ';
	std::cout << std::endl;

	int sum;
	p_sum_arr(arr1, size1, &sum);
	std::cout << "Сумма элементов = " << sum << std::endl;



	return 0;
}

void p_sum_arr(int arr[], const int length, int* var) {
	*var = 0;
	for (int i = 0; i < length; i++)
		*var += arr[i];
}