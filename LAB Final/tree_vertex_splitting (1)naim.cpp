#include<bits/stdc++.h>
using namespace std;

int t = 5;
int c[10];
int pre[10];
int X[10], Y[10];
vector <int> terminal;
vector <int> result;
int nodes;
int edges;

void lastNode();
void TVS();
void printV(vector <int> v);


int main()
{
	ifstream fin;
    	fin.open("treeVertexinput.txt");

	int cost, x, y;
	fin >> nodes;
	fin >> edges;
	for(int i = 0;i < 10;++i)
		c[i]=0;

	for(int i = 0;i < edges;++i){
		fin >> x >> y >> cost;
		X[i] = x - 1; Y[i] = y - 1;
		c[y - 1] = cost;
		pre[y - 1] = x - 1;
	}
	lastNode();
//	printV(terminal);
	TVS();
	printV(result);

}

void lastNode()
{
	int k = 0;
	for(int i = 0; i < edges; i++){
		for(int j = 0; j < edges; j++){
			if(Y[i] == X[j]){
				Y[i] = 0;
			}
		}
	}
	for(int i = 0; i < 10; i++){
		if(Y[i] != 0)
			terminal.push_back(Y[i]);
	}
}

void TVS()
{
	int i = 0;
	int C;
	C = 0;
	while(i < terminal.size()){
		C += c[terminal[i]];
		if(C > t){
			result.push_back(terminal[i]);
			c[terminal[i]] = 0;
			C = 0;
			i++;
		}
		else{
			terminal[i] = pre[terminal[i]];
		}
		if(terminal[i] == 0){
			C = 0;
			i++;
		}
	}

}

void printV(vector <int> v)
{
	cout << "Booster needed at vertex: ";
	for(int i = 0; i < v.size(); i++)
		cout << v[i] + 1 << " ";
	cout << endl;
}
