#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <sstream>
using namespace std;

class Graph
{
public:
    Graph(int numVer)
    {
        this->numVer = numVer;
        links.assign(numVer, vector<int>(numVer));
    }

    void full() 
    {
        for (int i = 0; i < numVer; i++)
        {
            cout << "Enter links for " << i+1 << ": ";

            getline(cin, line);
            stringstream ss(line);
            while (getline(ss, n, ' '))
            {
                this->links[i][stoi(n)] = 1;
            }
        }
        cout << endl;
    }

    void DFS(int ver)
    {
        for (int j = 0; j < numVer; j++)
        {
            if (links[ver][j] == 1)
            {
                stk.push(j);
                DFS(j);
            }
        }
        
    }

    void DFSTable()
    {
        for (int i = 0; i < numVer; i++)
        {
            DFS(i);
            for (int s = 0; s < stk.size(); s++)
            {
                links[i][stk.top()] = 1;
                stk.pop();
            }
        }
    }

    void show()
    {
        for (int i = 0; i < numVer; i++)
        {
            for (int j = 0; j < numVer; j++)
            {
                cout << links[i][j] << " ";
            }
            cout << endl;
        }
    }

private:
    int numVer;
    string line;
    string n;
    stack <int> stk;
    vector<vector<int> > links;
};





int main()
{   
    int n = 0;
    cout << "Enter a num of vertex: ";
    cin >> n;
    cin.ignore(256, '\n');
    Graph graph(n);
    graph.full();
    graph.DFSTable();
    graph.show();
    return 0;
}