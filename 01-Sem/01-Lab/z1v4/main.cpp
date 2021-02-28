#include <iostream>
#include <cmath>
///Индивидуальное задание № 1 (вариант 4)
using namespace std;
int main() {
    double x,a,s,ep,s1;
    int k,l;
    cout << "Enter x" << endl;
    cin >> x;
    cout << "Enter k" << endl;
    cin >> k;
    if (x<-1 || x>=1 || k<=1){
        cout << "Incorrect data entered" << endl;
        exit(0);
    }
    ep=1;
    for(int i=0;i<k;++i){
        ep/=10;
    }
    l=0;
    s=0;
    a=-(pow(x,1)/1);
    s1=log(1-x);
    while(fabs(a)>=ep){
        ++l;
        a=-(pow(x,l)/l);
        s+=a;
    }
    cout << fixed;
    cout.precision(k);
    cout <<"The result is "<< s << endl;
    cout <<"The result from std is "<< s1 << endl;
    return 0;
}
