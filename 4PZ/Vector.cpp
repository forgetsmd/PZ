#include <iostream>
#include <vector>
#include <random>

using namespace std;

ostream& operator << (ostream& out, const vector<int>& v)
{
	for (int i = 0; i < v.size(); i++)
	{
		out << v[i]<< " ";
	}
	return out;
}

double aver(vector<int> v){
	double buf = 0;

	for (int i = 0; i < v.size(); i++) 
		buf += (double)v[i];

	return buf / v.size();
}

vector<int> cross(vector<int> v1, vector<int> v2) {
	vector<int>buf;
	for (int i = 0; i < v1.size(); i++)
	{
		for (int j = 0; j < v2.size(); j++)
		{
			if (v1[i] == v2[j])
				buf.push_back(v2[j]);
		}
	}
	return buf;
}

int main()
{
	int v1_size = 0;
	int v2_size = 0;

	cout << "Enter a vector size:";
	cin >> v1_size >> v2_size;

	random_device rd;
	mt19937 generator(rd());
	uniform_int_distribution<> distribution(-100, 100);

	vector<int> v1;
	vector<int> v2;

	for (int i = 0; i < v1_size ; i++)
		v1.push_back(distribution(generator));

	for (int i = 0; i < v2_size; i++)
		v2.push_back(distribution(generator));

	cout << v1 << endl << v2 << endl << aver(v1) << endl << aver(v2) << endl << cross(v1, v2);

	return 0;
}