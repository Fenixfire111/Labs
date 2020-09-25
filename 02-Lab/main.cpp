#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <cmath>
///Вариант 4
using namespace std;
int main() {
    srand (time (nullptr));
    const int size = 100;
    int n,v;
    double a[size];
    cout << "Enter the number of array elements (from 1 to 100):" << endl;
    cin >> n;
    if (n<1 || n>100){
        cout << "Incorrect data entered." << endl;
        exit(0);
    }
    cout << "If you want to enter massive elements by yourself, press 1" << endl;
    cout << "If you want to have random elements, press 2" << endl;
    cin >> v;
    switch (v) {
        case 1:
            cout << "Array elements:" << endl;
            for (int i = 0; i < n; ++i){
                cin >> a[i];
            }
            break;
        case 2:
            cout << "Enter interval boundaries (the boundaries are included in the interval)"<< endl;
            double xz1, xz2;
            cin >> xz1;
            cin >> xz2;
            cout << "Array elements:" << endl;
            if (xz1>xz2){
                for (int i = 0; i < n; ++i){
                    double X=((double)rand()/(double)RAND_MAX);
                    a[i]=(xz1-xz2)*X+xz2;
                    cout << a[i] << " / ";
                }
            }
            else {
                for (int i = 0; i < n; ++i){
                    double X=((double)rand()/(double)RAND_MAX);
                    a[i]=(xz2-xz1)*X+xz1;
                    cout << a[i] << " / ";
                }
            }
            cout << " " << endl;
            break;
        default:
            cout << "Incorrect data entered." << endl;
            exit(0);
    }
    double min=a[0];
    int nmn=0;
    for (int i = 1; i < n; ++i){
       if (a[i]<=min){
           nmn=i;
           min=a[i];
       }
    }
    cout << "The minimum element number of the array = "<<nmn<< endl;
    int l=0;
    int t1,t2;
    for (int i = 0; i < n; ++i){
        if (a[i]<0 && l==0){
            t1=i;
            ++l;
            continue;
        }
        if (a[i]<0 && l>0){
            t2=i;
            ++l;
        }
    }
    double s=0;
    for (int i = t1+1; i < t2; ++i){
        s+=a[i];
    }
    if (l==0){
        cout << "There are no negative elements in the array."<< endl;
    }
    if (l==1){
        cout << "There is only one negative element in the array."<< endl;
    }
    if (l>1){
        cout << "The sum of the array elements located between the first and last negative elements = "<<s<< endl;
    }
    cout << "Enter X:" << endl;
    double x;
    int c=0;
    cin >> x;
    for (int i = 0; i < n; ++i){
        if (fabs(a[i])<=x){
            for (int j = 0; j < i-c; ++j){
                swap(a[i-j],a[i-j-1]);
            }
            ++c;
        }
    }
    cout << "The transformed array: "<<endl;
    for (int i = 0; i < n; ++i){
        cout << a[i] << " / ";
    }
    return 0;
}
