#include <iostream>
using namespace std;
int n;
        
int main() {
    cin >> n;
    int* a = new int[n];
    int* b = new int[n];
    b[0] = 1;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 1; i < n; i++) {
        b[i] = 0;
        for (int j = 0; j < i; j++) {
            if (a[j] < a[i] && b[j] > b[i]) {
                b[i] = b[j];
            }        
       }
       b[i] ++;
   }
   int m = b[0];
   for (int i = 1; i < n; i++) {
       if (b[i] > m) {
           m = b[i];
       }
    
   }
    cout << m;
    delete a, b;
    return 0;
}
