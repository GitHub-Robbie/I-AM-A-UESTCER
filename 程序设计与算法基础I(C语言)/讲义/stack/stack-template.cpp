#include <iostream>
#include <initializer_list>
#include <exception>

template <typename value_type, unsigned MAX_DEPTH = 1024>
class stack
{
private:
    value_type storage[MAX_DEPTH];
    int top = 0;

public:
    bool is_full() const 
    { 
        return top == MAX_DEPTH; 
    }

    bool is_empty() const 
    { 
        return top == 0; 
    }

    void push(value_type v) try
    {
        if (is_full()) throw std::out_of_range("Push: the stack is full");
        storage[top++] = v;
    }
    catch (std::out_of_range& e)
    {
        std::cout << e.what() << std::endl;
    }

    void push(std::initializer_list<value_type>&& l) try
    {
        for (auto e : l)
        {
            if (is_full()) throw std::out_of_range("Push failed: the stack is full");
            storage[top++] = e;       
        }
    }
    catch (std::out_of_range& e)
    {
        std::cout << e.what() << std::endl;
    }

    value_type pop() try
    {
        if (is_empty()) throw std::out_of_range("Pop failed: the stack is empty");
        return storage[--top];
    }
    catch (std::out_of_range& e)
    {
        static value_type t;
        std::cout << e.what() << std::endl;
        return t;
    }
};

int main()
{
    stack<int, 4> S;

    S.push({0, 1, 2, 3, 4}); //will cause overflow exception

    auto t = S.pop();
    std::cout << t << ',' << S.pop() << std::endl;

    S.pop(); S.pop(); 
    S.pop(); S.pop(); //these will cause underflow exception

    return 0;
}