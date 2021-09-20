#include <iostream>

using namespace std;
template <typename T>
class DArr
{
private:
	int size = 0;
	T* p_DArr = nullptr;
	bool initialized = false;
public:
	DArr() {};

	DArr(int size)
	{
		while (true)
		{
			try
			{
				this->size = size;
				p_DArr = new T[size];
				for (int i = 0; i < size; i++)
				{
					p_DArr[i] = i;
				}
				break;
			}
			catch (const std::bad_alloc&)
			{
				cout << "Error: bad_alloc" << endl;
			}
		}
		initialized = true;
	}

	DArr(const DArr& copmas)
	{
		while (true)
		{
			try
			{
				if (copmas.initialized)
				{
					this->size = copmas.size;
					p_DArr = new T[size];
					for (int i = 0; i < size; i++)
					{
						this->p_DArr[i] = copmas.p_DArr[i];
					}
					this->initialized = true;
				}
				else
				{
					cout << "Error: Copied array does not initialize" << endl;
				}
				break;
			}
			catch (const std::bad_alloc&)
			{
				cout << "Error: bad_alloc" << endl;
			}
		}

	}

	friend DArr operator  + (const DArr& a, const DArr& b);
	void operator = (const DArr& a);
	

	~DArr()
	{
		delete[] p_DArr;
	}


	void init(int size)
	{
		while (true)
		{
			try
			{
				this->size = size;
				p_DArr = new T[size];
				for (int i = 0; i < size; i++)
				{
					p_DArr[i] = 0;
				}
				break;
			}
			catch (const std::bad_alloc&)
			{
				cout << "Error: bad_alloc" << endl;
			}
		}
		initialized = true;
	}



	void SetArr(int index, T val)
	{
		try
		{
			if (val < -100 || val > 100)
			{
				throw std::invalid_argument("Error: invalid argument");
			}
			if (index < 0 || index >= size)
			{
				throw std::out_of_range("Error: out of range");
			}
			p_DArr[index] = val;
		}
		catch (std::out_of_range& error)
		{
			cout << error.what() << endl;
		}
		catch (std::invalid_argument& error)
		{
			cout << error.what() << endl;
		}
	}

	int GetArr(int index)
	{
		try
		{
			if (index < 0 || index >= size)
			{
				throw std::out_of_range("Error: out of range");
			}
			return p_DArr[index];
		}
		catch (std::out_of_range& error)
		{
			cout << error.what() << endl;
		}
	}

	void show()
	{
		for (int i = 1; i <= size; i++)
		{
			cout << i << "	" << p_DArr[i - 1] << endl;
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

DArr operator + (const DArr& a, const DArr& b)
{
	DArr temp;

	if (a.size < b.size)
	{
		temp.init(a.size);
		for (int i = 0; i < a.size; i++)
		{
			temp.p_DArr[i] = a.p_DArr[i] + b.p_DArr[i];
		}
	}

	else
	{
		temp.init(b.size);
		for (int i = 0; i < a.size; i++)
		{
			temp.p_DArr[i] = a.p_DArr[i] + b.p_DArr[i];
		}
	}

	return temp;
}

void DArr::operator = (const DArr& a)
{
	if (a.initialized)
	{
		this->size = a.size;
		p_DArr = new T[size];
		for (int i = 0; i < size; i++)
		{
			this->p_DArr[i] = a.p_DArr[i];
		}
		this->initialized = true;
	}
	else
	{
		cout << "Error: Copied array does not initialize" << endl;
	}
}

int main()
{
	DArr<int> array(5);
	DArr<int> array2(array);
	DArr<int> array3(5);
	array3 = array + array2;
	array3.show();
	return 0;
}