/*
/ Given 2 arrays that are sorted and distinct, write a function
/ to return the number of common elements in the 2 arrays.
*/



#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;


int main(){
    return 0;
}

int num_of_common_element(vector<int> &arr1, vector<int> &arr2){
    int count = 0;
    unordered_map<int, int> map;
    for(auto a = arr1.begin(), a != arr1.end(); ++a){
        if(map.find(*a) == map.end())
            map.insert(*a,1);
        else
            continue;
    }
    for(auto b = arr2.begin(); b != arr2.end(); ++b){
        if(map.at(*b) == 1)
            count++;
        else
            continue;
    }

}
