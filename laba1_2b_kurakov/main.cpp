#include <fstream>
#include <iostream>
#include <random>
#include <time.h>
using namespace std;
ifstream &read_file_chet(ifstream &file_input, int &x)
{
    while( file_input.read(reinterpret_cast<char*>(&x),sizeof (int)) && x%2==1);
    return file_input;
}
ifstream &read_file_nechet(ifstream &file_input, int &x)
{
    while( file_input.read(reinterpret_cast<char*>(&x),sizeof (int)) && x%2==0);
    return file_input;
}
void read_file(ifstream &infile)
{
	int v;
	infile.read(reinterpret_cast<char*>(&v),sizeof (int));
	while( !infile.eof())
	{
		cout<<v<<" ";
	infile.read(reinterpret_cast<char*>(&v),sizeof (int));
	}
	cout<<endl;
}

void fill_file(ofstream &infile, int n)
{
   int chet =0, nechet =0;
   for (int i =0; i<n; i++)
   {
        int x = rand()%10;
        if (x%2 ==0 && chet <=n/2){
            infile.write(reinterpret_cast <char*> (&x), sizeof (int));
            chet++;
            continue;
        }
        if (x%2 ==0 && chet > n/2){
                x++;
            infile.write(reinterpret_cast <char*> (&x), sizeof (int));
            continue;
         }
        if (x%2 ==1 && nechet <=n/2){
            infile.write(reinterpret_cast <char*> (&x), sizeof (int));
            nechet++;
            continue;
        }
        if (x%2 ==1 && nechet >n/2){
                x++;
            infile.write(reinterpret_cast <char*> (&x), sizeof (int));
            continue;
   }
   }
}
int main()
{
    srand(time(NULL));
    int nx =0, cx=0, n =10;
    ofstream file_input ("input.bin", ios:: binary);
    fill_file (file_input,n);
    file_input.close();
    ifstream file_input1 ("input.bin", ios:: binary);
    ifstream file_input2 ("input.bin", ios:: binary);
    ofstream file_output ("output.bin",  ios:: binary);

    while ( read_file_chet (file_input1, cx)&& read_file_nechet (file_input2, nx))
    {
        file_output.write(reinterpret_cast <char*> (&nx), sizeof (int));
        file_output.write(reinterpret_cast <char*> (&cx), sizeof (int));
       /* if(read_file_nechet (file_input2, nx))
            file_output << nx<< "   ";
        if(read_file_chet (file_input1, cx))
            file_output << cx<< "   ";*/
    }
    file_output.close();
    file_input.close();
    cout << "input data:  ";
    ifstream file_in ("input.bin");
    read_file (file_in);
    cout <<'\n';
    cout << "output data: ";
    ifstream file_out ("output.bin");
    read_file (file_out);
    return 0;
}
