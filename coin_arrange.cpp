#include <iostream>
#include <vector>

using namespace std;

int main(){
	vector<int> a;
	for(int i = 0; i < 20; i++)
		a.push_back(i);

	for(int i = 0; i < 20; i++){
		int line = 1;
		int decrement = 1;
		while(a[i] >= 0){
			a[i] -= decrement;
			decrement++;
			line++;
		}
		cout << line-1 << endl;
	}
}
