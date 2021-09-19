#include <iostream>

using namespace std;

class DArr
{
private:
	int size;
	int* p_DArr;
public:
	DArr(int size) 
	{
		this->size = size;
		p_DArr = new int[size];
		for (int i = 0; i < size; i++)
		{
			p_DArr[i] = 0;
		}
	}

	DArr(DArr& copmas)
	{

		this->size = copmas.size;
		p_DArr = new int[size];
		for (int i = 0; i < size; i++)
		{
			p_DArr[i] = copmas.GetArr(i);
		}
	}

	~DArr()
	{
		delete [] p_DArr;
	}

	void SetArr(int num, int val) 
	{
		if (num >= 0 && num < size && val > -100 && val < 100) {
			p_DArr[num] = val;
		}
		else
		{
			cout << "Error with setting" << endl;
		}
		
	}

	int GetArr(int num)
	{
		return p_DArr[num];
	}

	void show()
	{
		for (int i = 0; i < size; i++)
		{
			cout << i << "	" << p_DArr[i] << endl;
		}
	}

	void add(DArr& oper)
	{
		if (size < oper.size)
		{
			for (int i = 0; i < size; i++)
			{
				p_DArr[i] += oper.GetArr(i);
			}
		}

		else
		{
			for (int i = 0; i < oper.size; i++)
			{
				p_DArr[i] += oper.GetArr(i);
			}
		}
	}

	void sub(DArr& oper)
	{
		if (size < oper.size)
		{
			for (int i = 0; i < size; i++)
			{
				p_DArr[i] -= oper.GetArr(i);
			}
		}

		else
		{
			for (int i = 0; i < oper.size; i++)
			{
				p_DArr[i] -= oper.GetArr(i);
			}
		}
	}
};

int main()
{
	return 0;
}