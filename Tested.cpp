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
   int a = genRand("((i<120)||(i>0))"); 

   char str[] = "ahfasdhhdajd";
   char str1[] = "a"; //3

   int c = count(str, str1);
   std::cout << a << "\v";
   std::cout << c << "\v";

   Switch sw;
   sw.Initialize();
   std::cout << sw.getFullName() <<"\v";
   std::cout << sw.getNumPort() << "\v";

   HuaweiSwitch hw("HuaweiSwitch", 48);
}







