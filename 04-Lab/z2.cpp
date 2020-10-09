#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;
int main() {
    ifstream myFile;
    if(!myFile) {
        cout << endl << "Failed to open file";
        return 1;
    }
    char a[300],b[300];
    ifstream fin("qwer.txt");
    int f=0;
    while (fin.getline(a,1024)){
        int q=0;
        //cout <<"A : "<<a<<endl;
        int index = 0;
        for (int i = 0; i < strlen(a); ++i) {
            if (a[i] == ' ') {
                b[index] = '\0';
                index = 0;
                f = 0;
                for(int j=0; j<strlen(b)-1; ++j){
                    if (b[j]>=b[j+1]){
                        f++;
                        break;
                    }
                }
                if (f==0){
                    cout <<"A word in which the characters are in strict ascending order of their codes: "<<b<<endl;
                    q++;
                    break;
                }
                continue;
            }

            b[index] = a[i];
            index++;
        }

        f = 0;
        b[index] = '\0';
        for(int i=0; i<strlen(b)-1; ++i){
            if (b[i]>=b[i+1]){
                f++;
                break;
            }
        }
        if (f==0){
            cout <<"A word in which the characters are in strict ascending order of their codes: "<<b<<endl;
        } else if (q == 0){
            cout <<"No such word "<<endl;
        }
    }
    fin.close();
    return 0;
}