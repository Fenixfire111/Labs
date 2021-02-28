#include <iostream>
using namespace std;
char *Strcpy (char *strDestination, const char *strSource){
    char *a=strDestination;
    while(*strSource!='\0'){
        *strDestination=*strSource;
        strDestination++;
        strSource++;
    }
    while(*strDestination!='\0'){
        *strDestination=' ';
        strDestination++;
    }
    strDestination=a;
    return strDestination;
}
int main() {
    char a[300];
    char  b[300];
    cout <<"Enter line A: "<<endl;
    cin>>a;
    cout <<"Enter line B: "<<endl;
    cin>>b;
    Strcpy(a,b);
    cout <<"Line output A: "<<endl;
    cout <<a<<endl;
    return 0;
}

