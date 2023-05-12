#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;
int main () {
    const int sizestr = 80;
 char str[sizestr];
 cout << "\nInput the string ";
 cin.getline(str,sizestr);
 char c;
 int i =0 ,len = strlen (str);
 while (i<len) {
  c=str[i];
  int k=1;
  for (int j=0; j<len; j++)
    if (j!=i && str[j]==c) k++;
  if (k==1) {
    for (int j=i; j<len; j++)
        str[j]=str[j+1];
   len--; i--;
  }
  i++;
 }
 cout << "\nRESULT IS: ";
 puts (str);
 return 0;
}
