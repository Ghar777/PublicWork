#include <iostream>
#include <string.h>
using namespace std;
int wordcount(char str[]){

    int wordnum;
    char *word;
    word = strtok(_strdup(str)," .,!?");
    while (word != NULL)
    {  wordnum++;
        word = strtok(NULL," .,?!");
    }
    return wordnum;
    }
char wordarray(char* str, char** arr)
{
    char *word;
    word = strtok(str," .,!?");
    for (int i=0; word != NULL; i++)
        {
            arr[i]=word;
            word = strtok(NULL," .,?!");
        }
    }
int main()
{
    int a =200;
    char* str = new char [a];
    cin.getline(str,'\n');
    char** arr_finish = new char* [wordcount(str)];
    for (int i=0;i<20;i++)
        arr_finish[i] = new char [20];
        wordarray (str,arr_finish);
    for (int i=0;i<wordcount(str);i++){
            cout << arr_finish[i];
        cout <<'\n';
    }
    return 0;
}
