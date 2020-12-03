#include <iostream>
#include <stack>

class Stack {
private:

    int *stack;
    int top;
    int capacity;

    void extendDataArray() {
        int* newArray = new int[capacity * 2];
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
        stack = new int[capacity];
        top = -1;
    }

    Stack(const Stack &st)
    {
        top = st.top;
        capacity = st.capacity;
        stack = new int[capacity];
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

    void Push(const int &value) {
        if (top+1 == capacity) {
            extendDataArray();
        }
        std::cout << "Inserting " << value << std::endl;
        stack[++top]= value;
    }

    int Top()
    {
        if (!isEmpty())
            return stack[top];
        else
            exit(EXIT_FAILURE);
    }

    int Pop()
    {
        if (isEmpty())
        {
            std::cout << "UnderFlow\nProgram Terminated\n";
            exit(EXIT_FAILURE);
        }
        int pastTop=stack[top];
        --top;
        std::cout << "Removing " << pastTop << std::endl;
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

        delete[] stack;
        top = st.top;
        capacity = st.capacity;
        stack = new int[st.capacity];
        for (int i=0; i<=st.top; i++)
        {
            stack[i]=st.stack[i];
        }
        return *this;
    }

    void operator>> (int value){
        Push(value);
    }

    void operator<< (int& value){
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

};

int main() {
    Stack a;
    Stack c;
    a.Push(0);
    a.Push(1);
    a.Push(99);
    c.Push(2);
    c.Push(1);
    c.Push(99);
    c>>1;
    int x;
    c<<x;
    if (a>c){
        std::cout << "tr1" << std::endl;
    } else {
        std::cout << "fal1" << std::endl;
    }

    if (a<c){
        std::cout << "tr2" << std::endl;
    } else {
        std::cout << "fal2" << std::endl;
    }

    if (a==c){
        std::cout << "tr3" << std::endl;
    } else {
        std::cout << "fal3" << std::endl;
    }

    Stack d;
    d=a;

    if (a==d){
        std::cout << "tr4" << std::endl;
    } else {
        std::cout << "fal4" << std::endl;
    }

    return 0;
}
