// ATestHRC++.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <algorithm>
#include <string_view>
#include <ranges>
#include <deque>
#include <charconv>
#include <cassert>
#include <random>

#include "1.h"
#include "2.h"
#include "3.h"

int main()
{
	/// 1 задание. Тесты

	char str[] = "ahfasdhhdfajdffzdjasdjsdasyzdgaszdgavszdsvdzcafsdz"; /// основная строка для поиска
	///строки, которые ищутся в основной строке:

	char str1[] = "a"; //8 - верно
	char str2[] = "f"; //5 - верно
	char str3[] = "h"; //3 - верно
	char str4[] = "z"; //6 - верно
	char str5[] = "m"; //0 - верно
	char str6[] = "o"; //0 - верно

	char str7[] = "aa"; //0 - верно
	char str8[] = "gav"; //1 - верно
	char str9[] = "jdff"; //1 - верно
	char str10[] = "sv"; //1 - верно
	char str11[] = "fs"; //1 - верно
	char str12[] = "fa"; //2 - верно

	char str13[] = "ahfasdh"; //1 - верно
	char str14[] = "hh"; //1 - верно
	char str15[] = "mm"; //0 - верно
	char str16[] = "ff"; //1 - верно
	char str17[] = "jas"; //1 - верно
	char str18[] = "hnz"; //0 - верно

	char str19[] = "mop"; //0 - верно
	char str20[] = "fuhsg"; //0 - верно
	char str21[] = "zdja"; //1 - верно
	char str22[] = "das"; //1 - верно
	char str23[] = "po"; //0 - верно
	char str24[] = "ofrp"; //0 - верно

	///

	///Применение самих функций

	int c = count(str, str1); //
	assert(c == 8);
	int c1 = count(str, str2);
	assert(c1 == 5);
	int c2 = count(str, str3);
	assert(c2 == 3);
	int c3 = count(str, str4);
	assert(c3 == 6);
	int c4 = count(str, str5);
	assert(c4 == 0);
	int c5 = count(str, str6);
	assert(c5 == 0);

	int c6 = count(str, str7);
	assert(c6 == 0);
	int c7 = count(str, str8);
	assert(c7 == 1);
	int c8 = count(str, str9);
	assert(c8 == 1);
	int c9 = count(str, str10);
	assert(c9 == 1);
	int c10 = count(str, str11);
	assert(c10 == 1);
	int c11 = count(str, str12);
	assert(c11 == 2);

	int c12 = count(str, str13);
	assert(c12 == 1);
	int c13 = count(str, str14);
	assert(c13 == 1);
	int c14 = count(str, str15);
	assert(c14 == 0);
	int c15 = count(str, str16);
	assert(c15 == 1);
	int c16 = count(str, str17);
	assert(c16 == 1);
	int c17 = count(str, str18);
	assert(c17 == 0);

	int c18 = count(str, str19);
	assert(c18 == 0);
	int c19 = count(str, str20);
	assert(c19 == 0);
	int c20 = count(str, str21);
	assert(c20 == 1);
	int c21 = count(str, str22);
	assert(c21 == 1);
	int c22 = count(str, str23);
	assert(c22 == 0);
	int c23 = count(str, str24);
	assert(c23 == 0);

	///

	/// Отображение в консоль

	std::cout << c << "\v";
	std::cout << c1 << "\v";
	std::cout << c2 << "\v";
	std::cout << c3 << "\v";
	std::cout << c4 << "\v";
	std::cout << c5 << "\v\v";

	std::cout << c6 << "\v";
	std::cout << c7 << "\v";
	std::cout << c8 << "\v";
	std::cout << c9 << "\v";
	std::cout << c10 << "\v";
	std::cout << c11 << "\v\v";

	std::cout << c12 << "\v";
	std::cout << c13 << "\v";
	std::cout << c14 << "\v";
	std::cout << c15 << "\v";
	std::cout << c16 << "\v";
	std::cout << c17 << "\v\v";

	std::cout << c18 << "\v";
	std::cout << c19 << "\v";
	std::cout << c20 << "\v";
	std::cout << c21 << "\v";
	std::cout << c22 << "\v";
	std::cout << c23 << "\v\v\v";

	///

	/// 2 Задание

	Switch sw;
	sw.Initialize();
	std::cout << sw.getFullName() << "\v";
	std::cout << sw.getNumPort() << "\v\v\v";

	HuaweiSwitch hw("HuaweiSwitch", 48);



	///


	/// 3 Задание. Тесты

	//try {
		auto a = genRand("(i>50)&&(i<100)"); //попало в предел (77 выпало)
		assert(a.right&& a.c > 50 && a.c < 100);
		std::cout << a.c << "\v";
		auto a1 = genRand("(i<50)||(i>100)"); //попало в предел (618652566 выпало)
		assert(a1.right && (a1.c < 50 || a1.c > 100));
		std::cout << a1.c << "\v";
		auto a2 = genRand("(i<10)&&(i>1000)"); //выкинет ошибку (невозможно, чтобы число было меньше 10 и одновременно больше 1000 (если бы стояло || (or) вместо && (and) - результат был бы отображен)
		assert(a2.right && a2.c < 10 && a2.c > 1000);
		auto a3 = genRand("(i<100)&&(i>50)||(i<20)"); //попало в предел (выпало 55)(может выпасть также любое число меньше 20)
		assert(a3.right&& a3.c < 100 && a3.c > 50 || a3.c < 20);
		std::cout << a3.c << "\v";
		auto a4 = genRand("((i>50)&&(i<100))||(i<79)"); // (вложенные скобки) выпало 56 (может выпасть также любое число меньше 79)
		assert(a4.right&& ((a4.c > 50 && a4.c < 100) || a4.c < 79));
		std::cout << a4.c << "\v";

		
	//}
	//catch (std::exception& e)
	//{
	//	std::cout << e.what() << "\v\v\v";
	//}
	///Отображение в консоль


	return EXIT_SUCCESS;
	///
}







