#include <iostream>
#include <map>
#include <sstream>
#include <cstdlib>
#include <stack>
#include <cmath>
#include <vector>
template <class T>
class Stack {
private:

    T *stack;
    int top;
    int capacity;

    void extendDataArray() {
        T* newArray = new T[capacity * 2];
        for(int i = 0; i < capacity; ++i){
            newArray[i] = stack[i];
        }
        delete[]stack;
        stack = newArray;
        capacity *= 2;
    }

public:

    Stack() {
        capacity = 1024;
        stack = new T[capacity];
        top = -1;
    }

    Stack(const Stack &st)
    {
        top = st.top;
        capacity = st.capacity;
        stack = new T[capacity];
        for (int i=0; i<=st.top; i++)
        {
            stack[i]=st.stack[i];
        }
    }

    int Size() const
    {
        return top + 1;
    }

    bool isEmpty() const
    {
        return top == -1;
    }

    void Push(const T &value) {
        if (top+1 == capacity) {
            extendDataArray();
        }
        stack[++top]= value;
    }

    T Top()
    {
        if (!isEmpty())
            return stack[top];
        else
            exit(EXIT_FAILURE);
    }

    T Pop()
    {
        if (isEmpty())
        {
            std::cout << "UnderFlow\nProgram Terminated\n";
            exit(EXIT_FAILURE);
        }
        T pastTop=stack[top];
        --top;
        return pastTop;
    }

    bool operator== (const Stack &a)
    {
        if (a.Size()==Size()){
            for (int i=0; i<a.Size(); i++){
                if(a.stack[i] != stack[i])
                    return false;
            }
        }
        else{
            return false;
        }
        return true;
    }

    Stack& operator= (const Stack &st){
        if (this == &st)
        {
            return *this;
        }
        delete[] stack;
        top = st.top;
        capacity = st.capacity;
        stack = new T[st.capacity];
        for (int i=0; i<=st.top; i++)
        {
            stack[i]=st.stack[i];
        }
        return *this;
    }

    void operator>> (T value){
        Push(value);
    }

    void operator<< (T& value){
        value = Pop();
    }

    int operator[] (int i){
        return stack[i];
    }

    bool operator< (const Stack &a)
    {
        return Size()<a.Size();
    }

    bool operator> (const Stack &a)
    {
        return Size()>a.Size();
    }

    ~Stack() {
        delete [] stack;
    }
};
class Calculator{
 public:
  std::string ExpressionHandling(std::string inputString)
  {
    std::string outputString;
    std::string::size_type ind;
    while ((ind = inputString.find(' ')) != std::string::npos)
    {
      inputString.erase(ind, 1);
    }

    std::map<char, int> map;
    map.insert(std::make_pair('^', 4));
    map.insert(std::make_pair('*', 3));
    map.insert(std::make_pair('/', 3));
    map.insert(std::make_pair('+', 2));
    map.insert(std::make_pair('-', 2));
    map.insert(std::make_pair('(', 1));

    Stack<char> container;
    bool globalFlag = true;
    bool flag = true;
    bool bracketFlag = false;
    for (auto c : inputString)
    {
      if (!isalnum(c))
      {
        if (((globalFlag) || (bracketFlag)) && (c == '-')){
          outputString += c;
          continue;
        }
        if (c=='.'){
          outputString += c;
          continue;
        }
        if (flag){
          outputString += ' ';
          flag = false;
        }

        if (')' == c)
        {
          while (container.Top() != '(')
          {
            outputString += container.Top();
            container.Pop();
            outputString += ' ';
          }
          container.Pop();
        }
        else if ('(' == c)
        {
          container.Push(c);
          bracketFlag = true;
        }
        else if (container.isEmpty() || (map[container.Top()] < map[c]))
        {
          container.Push(c);
        }
        else
        {
          do
          {
            outputString += container.Top();
            outputString += ' ';
            container.Pop();
          } while (!(container.isEmpty() || (map[container.Top()] < map[c])));
          container.Push(c);
        }
      }
      else
      {
        flag = true;
        bracketFlag = false;
        outputString += c;
      }
      if(globalFlag) {globalFlag = false;}
    }

    if (flag) {outputString += ' ';}
    while (!container.isEmpty())
    {
      outputString += container.Top();
      outputString += ' ';
      container.Pop();
    }
    return outputString;
  }

  bool Check (const std::string &string){
    Stack<int> stack;

    for(auto c : string){
      if (c=='('){
        stack.Push(1);
      } else if((c==')') && (stack.Size()>0)){
        stack.Pop();
      } else if ((c==')') && (stack.Size()<=0)){
        return false;
      }
    }
    if (stack.Size()>0){
      return false;
    }

    for(int i=0; i<string.size()-1; ++i){
      if (((!isdigit(string[i])) && (string[i]!=')') && (string[i]!='(')) &&
      ((!isdigit(string[i+1])) && (string[i+1]!=')') && (string[i+1]!='('))){
        return false;
      }
    }

    for(int i=string.size()-1; (i>=0) && (!isdigit(string[i])); --i){
      if ((string[i]!=')') && (string[i]!='(')){
        return false;
      }
    }

    for(auto c : string){
      if((c!='+') && (c!='-') && (c!='/') && (c!='*') && (c!='^') && (c!='.') && (!isdigit(c)) && (c!=')') && (c!='(')){
        return false;
      }
    }
    return true;
  }

  double Calculating(const std::string &opz){
    if (opz.empty()){
      std::cout<< "There is no expression!"<<std::endl;
      return 0;
    }

    Stack<double> container;
    std::string numberString;
    double number;
    std::stringstream stringStream(opz);
    while (stringStream>>numberString){
      if((numberString=="+") || (numberString=="-")|| (numberString=="/")|| (numberString=="*")|| (numberString=="^")){
        double b=container.Top();
        container.Pop();
        double a=container.Top();
        container.Pop();
        if (numberString == "+"){
          a=a+b;
          container.Push(a);
        } else if (numberString == "-"){
          a=a-b;
          container.Push(a);
        } else if (numberString == "*"){
          a=a*b;
          container.Push(a);
        } else if (numberString == "/"){
          a=a/b;
          container.Push(a);
        } else if (numberString == "^"){
          a = std::pow(a,b);
          container.Push(a);
        }
      } else {
          number = std::stod(numberString);
          container.Push(number);
          numberString.clear();
      }
    }
    return container.Top();
  }
};

int main() {
  return 0;
}
