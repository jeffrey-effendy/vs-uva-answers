#include "C.h"	

using namespace std;

Test::Test(string title)
{
	l = "";
	inS = title + "in.txt";
	outS = "out.txt";
	outUVA = title + "out.txt";
	defIn = cin.rdbuf();
	defOut = cout.rdbuf();
	in.open(inS);
	out.open(outS);
}

Test::~Test()
{
	cout.flush();
	cin.rdbuf(defIn);
	cout.rdbuf(defOut);
	cout << "LOG STARTS" << endl;
	cout << l << "LOG ENDS" << endl;
	cout << "TEST END (time taken: " << clock() - timeStart << "ms)" << endl;
	bool result = compare();
	if (!result)
		cout << "FAIL TEST" << endl;
	else
		cout << "PASS TEST" << endl;
	cout << "System will delete all test output files" << endl;
	system("pause");
	remove("out.txt");
	in.close();
	out.close();
}

bool Test::compare()
{
	string lineA, lineB;
	ifstream isA(outS);
	ifstream isB(outUVA);
	bool result = true;
	string res = "";
	cout << "Results: " << endl;
	while (!isA.eof() && !isB.eof())
	{
		getline(isA, lineA);
		getline(isB, lineB);
		bool curResult = lineA.compare(lineB) == 0;
		res += lineA + "\n<===>\n" + lineB + "\n";
		res += curResult ? "[TRUE]\n\n" : "[FALSE]\n\n";
		result &= curResult;
	}
	/*if (!isA.eof() || !isB.eof())
	{
		cout << "Number of line is not matching [FALSE]" << endl;
		return false;
	}*/
	cout << res;
	return result;
}

void Test::begin()
{
	streambuf *inBuf, *outBuf;
	inBuf = in.rdbuf();
	outBuf = out.rdbuf();
	timeStart = clock();
	cin.rdbuf(inBuf);
	cout.rdbuf(outBuf);
}

void Test::log(string str)
{
	l += str;
	l += "\n";
}