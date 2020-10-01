#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;
int GetEl(vector<vector<int> > &a, int i, int j, int m){
    if (i<m)
        return a[i][j];
    else
        return a[i-m][j];
}
int main() {
    int n,m2,v,m;
    srand (time (nullptr));
    cout << "Enter the number of Lines[2;10](The number is even !!!):" << endl;
    cin >> m2;
    cout << "Enter the number of Columns[1;10]:" << endl;
    cin >> n;
    m=m2/2;
    if (m2<1 || n<1 || m2>10 || n>10 || (m2%2==1)){
        cout << "Incorrect data entered." << endl;
        exit(1);
    }
    vector<vector<int> > a(m, vector<int>(n));
    cout << "If you want to enter massive elements by yourself, press 1" << endl;
    cout << "If you want to have random elements, press 2" << endl;
    cin >> v;
    switch (v) {
        case 1:
            cout << "Only half of the array elements are entered!" << endl;
            for (int i = 0; i < m; ++i){
                for (int j = 0; j < n; ++j){
                    cin>>a[i][j];
                }
            }
            break;
        case 2:
            cout << "Enter interval boundaries (the boundaries are included in the interval)"<< endl;
            int xz1, xz2;
            cin >> xz1;
            cin >> xz2;
            cout << "Array elements:" << endl;
            if (xz1>xz2) {
                for (int i = 0; i < m; ++i) {
                    for (int j = 0; j < n; ++j) {
                        a[i][j] = rand() % (xz1 - xz2 + 1) + xz2;
                    }
                }
            }
            else {
                for (int i = 0; i < m; ++i) {
                    for (int j = 0; j < n; ++j) {
                    a[i][j] = rand() % (xz2 - xz1 + 1) + xz1;
                    }
                }
            }
            break;
        default:
            cout << "Incorrect data entered." << endl;
            exit(1);
    }
    for (int i = 0; i < m2; i++){
        for (int j = 0; j < n; j++){
            cout << GetEl(a,i,j,m) << ' ';
        }
        cout << endl;
    }
    int s=0;
    for (int j = 0; j < n; j++) {
        int l=0;
        for (int i = 0; i < m; i++) {
            if (a[i][j]==0)
                ++l;
            if (i==m-1 && l==0)
                ++s;
        }
    }
    cout << "The amount of columns not containing zeros: "<< s<< endl;
    int max=1,t, mst=0;
    for (int i = 0; i < m; i++){
        t=1;
        for (int j = 1; j < n; j++){
            if (a[i][j-1]<a[i][j]){
               ++t;
            }
            else{
                if(t>max) {
                    max = t;
                    mst = i;
                }
                t=1;
            }
        }
    }
    cout << "The number of the first line containing the longest strictly ascending sequence of elements: "<< mst<< endl;
    return 0;
}
