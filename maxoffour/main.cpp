#include <iostream>

using namespace std;
//Function.........
int max (int x, int y){
  if (x>y){
    return x;
  }
else {
    return y;
}
}
int main()
{
    cout << "FINDING THE MAX BETWEEN FOUR NUMBERS" << endl;

    int a, b, c, d;

    cout << "Input the first number:";
    cin >> a;
    cout << "Input the second number:";
    cin >> b;
    cout << "Input the third number:";
    cin >> c;
    cout << "Input the fourth number:";
    cin >> d;

    int leftmax = max (a, b);
    int rightmax = max (c, d);
    int finalmax = max(leftmax, rightmax);

    cout << "the maximum number is: " << finalmax;
    return 0;
}
