#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <algorithm>
using namespace std;
string ConsoleReader(string msg){
    string s;
    cout<< msg << endl;
    cin>>s;
    return s;
}
bool IsNonIncreasingOrder(string str){
    bool check = true;
    int n=str.size();
    for(int i=n-2;i>0;i-=2){
        if(str[i]<str[i-2]){
            check = false;
            break;
        }
    }
    return check;
}
vector <string> FileReader(string input_file){
    string str;
    vector <string> arr;
    ifstream fin;
    fin.open(input_file);
    while (!fin.eof()){
        getline(fin, str);
        arr.push_back(str);
    }
    return arr;
}
vector <string> WordParser(vector <string> lines){
    string W1;
    vector <string> word;
    int j=0;
    for(int i=0;i<lines.size();++i){
        stringstream str;
        str.str(lines[i]);
        while (str >> W1){
            word.push_back(W1);
        }
    }
    return word;
}
vector <string> FindItems(vector <string> arrWord){
    vector <string> A;
    for(int i=0;i<arrWord.size();++i){
        if(IsNonIncreasingOrder(arrWord[i])) {
            A.push_back(arrWord[i]);
        }
    }
    return A;
}
int WordWeight (std::string str){
    int size=0;
    for (int i=0; i< str.size(); ++i) {
        int x=str[i];
        if ((x & 2) != 0 && (x & 8) != 0)
        {
            size+=str[i];
        }
    }
    return size;
}
map <string, int> word_weight_map(vector <string> arrA){
    map <string, int> mp;
        for (int i=0;i<arrA.size();++i){
            int a=WordWeight(arrA[i]);
            mp[arrA[i]] = a;
        }
    return mp;
};
void FileWriter(map<string,int> mp){
    ofstream out;
    out.open("output.txt");
    for (pair<string,int> a:mp){
        out.width(10);
        out << right << a.first;
        out.width(10);
        out << right << a.second << endl;
    }
}
void SortCollection (vector<string> &arrWord) {
    sort(arrWord.begin(), arrWord.end(), [](string word1, string word2){return WordWeight(word1) > WordWeight(word2);});
}
template <typename T, typename T2>
void FileWriter(map<T2,T> mp){
    ofstream out;
    out.open("output.txt");
    for (pair<T2,T> a:mp){
        out.width(10);
        out << right << a.first;
        out.width(10);
        out << right << a.second << endl;
    }
}
int WordWeight (vector <string> arr){
    int size=0;
    for (int i=0; i< arr.size(); ++i) {
        size += WordWeight(arr[i]);
    }
    return size;
}
void Encryption (string file_path, string key){
    vector <string> lines = FileReader(file_path);
    string text;
    for(int i=0;i<lines.size();++i){
        text+=lines[i]+'\n';
    }
    string new_text = text;
    for (int i = 0; i < text.length(); ++i) {
        new_text[i] = text[i] ^ key[i% key.length()];
    }
    file_path.erase(file_path.length()-4, 4);
    file_path +="_encr.txt";
    ofstream out(file_path);
    out << new_text;
}
int main() {
    string str;
    str = ConsoleReader("Enter a word: ");

    if(IsNonIncreasingOrder(str)){
        cout<<"Condition A is true"<<endl;
    } else {
        cout<<"Condition A is false"<<endl;
    }

    string name;
    name=ConsoleReader("Enter a name for the file: ");
    vector <string> arrStr=FileReader(name);
    vector <string> arrWord=WordParser(arrStr);
    vector <string> arrA = FindItems(arrWord);
    map <string, int> mp;
    map <string, unsigned int> mp2;
    for (int i=0;i<arrA.size();++i){
        int a=WordWeight(arrA[i]);
        mp[arrA[i]] = a;
        mp2[arrA[i]] = a;
    }
    FileWriter(mp);
    SortCollection(arrWord);
    Encryption("output.txt","k");
    Encryption("output_encr.txt","k");
    return 0;
}
