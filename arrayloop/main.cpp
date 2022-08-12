#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N;

        cin >> N;

    int arr[N];

      int i;

      int j;

         for (i = 0; i < N; i++){

            cin >> arr[i];
    }

            for (j=N-1; j>=0; j--){

                cout << arr[j] << " ";
            }

    return 0;
}
