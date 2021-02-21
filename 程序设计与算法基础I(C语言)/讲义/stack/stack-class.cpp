#include <iostream>
#include <cstdlib>

//type alias
//you can substitute 'int' with any type, such as float
using value_type = int;

const unsigned MAX_DEPTH = 1024;

class stack
{
private:
    value_type storage[MAX_DEPTH];
    int top = 0;

public:
    bool is_full() { return top == MAX_DEPTH; }
    bool is_empty() { return top == 0; }

    void overflow() 
    {
        std::cout << "Push failed: the stack is full." << std::endl;
        exit(EXIT_FAILURE);
    }

    void underflow() 
    {
        std::cout << "Pop failed: the stack is empty." << std::endl;
        exit(EXIT_FAILURE);
    }

    void push(value_type e)
    {
        if (is_full())
            overflow();
        else
            storage[top++] = e;
    }

    value_type pop()
    {
        if (is_empty())
            underflow();
        else
            return storage[--top];
    }
};

int main()
{
    stack S;

    for (int i = 0; i <=4; ++i) S.push(i);

    auto t = S.pop();
    std::cout << t << ',' << S.pop() << std::endl;

    S.pop(); S.pop(); S.pop(); 
    S.pop(); //this will cause underflow

    return 0;
}