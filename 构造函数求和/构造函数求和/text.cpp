#include<iostream>
#include<time.h>
using namespace std;
static size_t i=1;
static size_t  sum=0;
namespace wy
{
    class Sum
    {
    public:
        Sum()
        {
            sum += i;
            i++;
        }
    };
}
int Rand()
{
    srand((unsigned int)time(nullptr));
    return rand() % 200 + 1;
}
int main()
{
  /* int n = Rand();
   cout << n << endl;*/
   wy:: Sum arry[100];
  
   cout << sum<<endl;
}