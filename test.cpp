//============================================================================
// Name        : test.cpp
// Author      : Kepler-Moment
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include<iostream>
#include<cstring>
#include<cstdio>
#include "BloomFilter.h"
using namespace std;

int main()
{
	BloomFilter bf(13);
	string str;
	while(cin >> str && str[0] != '#')
		bf.insert(str);
	while(cin >> str && str[0] != '#')
		puts(bf.search(str) ? "YES" : "NO");

	return 0;
}
