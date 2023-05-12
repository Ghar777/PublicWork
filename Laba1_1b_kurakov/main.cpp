#include <fstream>
#include <iostream>
using namespace std;
ifstream &read_file_chet(ifstream &file_input, int &x)
{
    while( file_input >> x && x%2==1);
    return file_input;
}
ifstream &read_file_nechet(ifstream &file_input, int &x)
{
    while( file_input >> x && x%2==0);
    return file_input;
}
void read_file(ifstream &infile)
{
    int x;
    infile >> x;
    while( !infile.eof() )
    {
        cout<<x<<endl;
        infile >> x;
    }
}
void fill_file(ofstream &infile, int n)
{
   int chet =0, nechet =0;
   for (int i =0; i<n; i++)
   {
        int x = rand()%10;
        if (x%2 ==0 && chet <=n/2){
            infile << x <<" ";
            chet++;
        }
         if (x%2 ==0 && chet > n/2)
            infile << x+1<< " ";
         if (x%2 ==1 && nechet <=n/2){
            infile << x<< " ";
            nechet++;
        }
        if (x%2 ==1 && nechet >n/2)
            infile << x+1<< " ";
   }
}
int main()
{
    int nx =0, cx=0, n =10;
    ofstream file_input ("input.txt");
    fill_file (file_input,n);
    file_input.close();
    ifstream file_input1 ("input.txt");
    ifstream file_input2 ("input.txt");
    ofstream file_output ("output.txt");

    while ( read_file_chet (file_input1, cx)&& read_file_nechet (file_input2, nx))
    {
        file_output <<nx<< "   ";
        file_output << cx<< "   ";
       /* if(read_file_nechet (file_input2, nx))
            file_output << nx<< "   ";
        if(read_file_chet (file_input1, cx))
            file_output << cx<< "   ";*/
    }
    file_output.close();
    ifstream file_out ("output.txt");
    read_file (file_out);
    return 0;
}
