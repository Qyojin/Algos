// Problem: 																										           |
// Define rules for magic strings 																					           |	
// a --> e 																										               |
// e --> a || i 																								               |
// i --> a || e || o || u 																							           |
// o --> u || i 																									           |
// u --> a 																											           |
// Strings that satisfy above rules are called magic strings           												           |
// Input: int n 																									           |
// Output: maximum possible number of magic string within length n 													           |
// e.g. Input = 1, Output = 5 (a, e, i, o, u)																		           |
//      Input = 2, Output = 10 (ae, ea, ei, ia, ie, io, iu, ou, oi, ua)												           |
//		Input = 3, Output = 19 (aea, aei, eae, eia, eie, eio, eiu, iae, iea, iei, iou, ioi, iua, oua, oia, oie, oio, oiu, uae) |
/*----------------------------------------------------------------------------------------------------------------------------*/



#include <iostream>
#include <string>

using namespace std;


int a = 1;
int e = 1;
int i = 1;
int o = 1;
int u = 1;
double duration2;
double duration3;
//clock_t begin = clock();


int magicString2(int a, int e, int i, int o, int u, int n);

int magicString(int n){
	//clock_t begin2 = clock();
	if(n == 1)
		return 5;
	else{
		 return magicString2(a,e,i,o,u,n);
	}

}


int magicString2(int a, int e, int i, int o, int u, int n){
	if(n == 2){

		return 1 * a + 2 * e + 4 * i + 2 * o + 1 * u;
	}
	else{
		int al, el, il, ol, ul;
		al = e + i + u;
		el = a + i;
		il = e + o;
		ol = i;
		ul = i + o;
		a = al;
		e = el;
		i = il;
		o = ol;
		u = ul;
		return magicString2(a, e, i, o, u, n - 1);
	}
}

int magicString3(int n){
	//clock_t begin3 = clock();
	int a3 = 1;
	int e3 = 1;
	int i3 = 1;
	int o3 = 1;
	int u3 = 1;
	long total = 0;
	if(n == 1)
		return 5;
	for(int j = 2; j <= n; j++){
		total = 1 * a3 + 2 * e3 + 4 * i3 + 2 * o3 + 1 * u3 ;
		int al3, el3, il3, ol3, ul3;
		al3 = e3 + i3 + u3;
		el3 = a3 + i3;
		il3 = e3 + o3;
		ol3 = i3;
		ul3 = i3 + o3;
		a3 = al3;
		e3 = el3;
		i3 = il3;
		o3 = ol3;
		u3 = ul3;
	}
	return total;
}

int main(int argc, char * argv[]){
	int num = stoi(argv[1]);
	clock_t begin3 = clock();
	cout << magicString3(num) << endl;
	duration3 = 1000 * ((std::clock() - begin3) / (double)CLOCKS_PER_SEC);
	cout << "iteration: " << duration3 << endl;
	clock_t begin2 = clock();
	cout << magicString(num) << endl;
	duration2 = 1000 * ((std::clock() - begin2) / (double)CLOCKS_PER_SEC);
	cout << "recursion: " << duration2 << endl;
}