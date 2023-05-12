#include <iostream>

using namespace std;

int main()
{
    int schet_max=0;
    int chisl3=-1,chisl1=-1,chisl2=-1,schet=0;
    while (cin)
    {
      chisl1=chisl2;
      chisl2=chisl3;
      cin>>chisl3;
      if (chisl2-chisl1==chisl3-chisl2)
            schet++;
      if (chisl2-chisl1!=chisl3-chisl2)
            schet=0;
      if (schet>schet_max)
        schet_max=schet;
      if (chisl3==0)
        break;
    }
    cout << schet_max+2;
    return 0;
}
