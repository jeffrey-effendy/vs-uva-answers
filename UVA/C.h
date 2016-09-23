#pragma once
#ifndef _GUARD_C_H
#define _GUARD_C_H

#include <ctime>
#include <fstream>
#include <iostream>
#include <string>

class Test
{
private:
	std::ifstream in;
	std::ofstream out;
	std::streambuf *defIn, *defOut;
	std::string inS, outS, outUVA, l;
	bool outputTrue;
	time_t timeStart;

	Test() {}

public:
	Test(std::string title);
	~Test();
	bool Test::compare();
	void Test::begin();
	void Test::log(std::string str);
	void Test::showTrue();
	void Test::hideTrue();
};

#endif