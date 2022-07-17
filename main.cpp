#include <iostream>

using namespace std;

int main()
{
   const int nosurveyed = 16500;

   float
   per1 =.15,
   percitrus =.58,
   total = nosurveyed * per1,
   grandtotal = total * percitrus;

   cout << "\n";
   cout << "The approximate number of customer in the survey who\n";
   cout << "purchased one or more energy drink per week is ";
   cout << grandtotal << endl;

   return 0;
}
