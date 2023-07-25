#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 5;

    int a[n] = {1,5,3,4,2};

    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++) {

            if(a[i]>a[j])
            {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }

    cout<<"\nArray after swapping: ";

    for(int i=0; i<n; i++)
      cout<<a[i]<<" ";

    return 0;
}