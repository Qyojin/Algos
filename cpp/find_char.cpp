/*
Write a function without using any library to return
the first alone character in a given string.
e.g. given string "ddffiijkkl", the function should return 'j'
*/

#include <iostream>


using namespace std;


char find_char(char * str);
int main(){
    char * a = "ddffiijkkl\0";
    cout << find_char(a) << endl;
}


char find_char(char * str){
  char arr[128];
  for(int i = 0 ; i < 128 ; ++i){
      arr[i] = 0;
  }
  char * tmp = str;
  while(*str != '\0'){
      arr[(int)*str]++;
      str++;
  }
  while(*tmp != '\0'){
      if(arr[*tmp] == 1){
          return *tmp;
      }
      tmp++;
  }
}
