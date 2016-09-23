#include "C.h"
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Box
{
public:
	vector<int> attrs;
	int id;
	int nparent;
	int parent;

	Box() {}

	void insert(vector<int> attrs, int id)
	{
		this->id = id;
		this->attrs = attrs;
		sort(this->attrs.begin(), this->attrs.end());
		nparent = 0;
		parent = -1;
	}

	bool fitInto(const Box& other)
	{
		int size = this->attrs.size() < other.attrs.size() ? this->attrs.size() : other.attrs.size();
		for (int i = 0; i < size; i++)
		{
			if (this->attrs[i] >= other.attrs[i])
			{
				return false;
			}
		}
		return true;
	}

	bool lessThan(const Box& other)
	{
		int size = this->attrs.size() < other.attrs.size() ? this->attrs.size() : other.attrs.size();
		for (int i = 0; i < size; i++)
		{
			if (this->attrs[i] > other.attrs[i])
			{
				return false;
			}
			if (this->attrs[i] < other.attrs[i])
			{
				return true;
			}
		}
		return true;
	}
};

int main()
{
	Test *t = new Test("UVA103");
	t->begin();
	int n, d, a;
	while (cin >> n >> d)
	{
		vector<Box> box(30);
		for (int i = 0; i < n; i++)
		{
			vector<int> attrs;
			for (int j = 0; j < d; j++)
			{
				cin >> a;
				attrs.push_back(a);
			}
			box[i].insert(attrs, i + 1);
		}
		bool sorted = false;
		while (!sorted)
		{
			sorted = true;
			for (int i = 0; i < n -1; i++)
			{
				if (!box[i].lessThan(box[i + 1]))
				{
					Box temp = box[i];
					box[i] = box[i + 1];
					box[i + 1] = temp;
					sorted = false;
				}
			}
		}
		for (int i = n-1; i >= 0; i--)
		{
			for (int j = i + 1; j < n; j++)
			{
				if (box[i].fitInto(box[j]) && box[i].nparent < box[j].nparent + 1)
				{
					box[i].nparent = box[j].nparent + 1;
					box[i].parent = j;
				}
			}
		}
		Box maxBox = box[0];
		for (int i = 1; i < n; i++)
		{
			if (maxBox.nparent < box[i].nparent)
			{
				maxBox = box[i];
			}
		}
		int nbox = maxBox.nparent + 1;
		cout << nbox << endl;
		cout << maxBox.id;
		for (int i = 0; i < nbox - 1; i++)
		{
			maxBox = box[maxBox.parent];
			cout << " " << maxBox.id;
		}
		cout << endl;
	}
	delete t;
	return 0;
}