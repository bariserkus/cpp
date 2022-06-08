#include <iostream>
#include <atomic>
#include <thread>

template<typename T>
class lock_free_stack{
private:
    struct node{
        T data;
        node * next;

        node(){}
        node(T const & _data):data(_data){}
    };

    std::atomic<node*> head;

public:
    lock_free_stack(T _data){
        push(_data);
    }
    ~lock_free_stack(){
        T result;
        while(!head.load()->data){
            pop(result);
        }
        pop(result);
    }
    void push(T const & _data){
        node * const new_node = new node(_data);
        new_node->next = head.load();
        while(!head.compare_exchange_weak(new_node->next, new_node));
    }

    void pop(T& result){

        node * old_head = head.load();
        while(!head.compare_exchange_weak(old_head, old_head->next));
        result = old_head->data;
    }
    void print_stack_head(){
        std::cout << "Head Value: " << head.load()->data << '\n';
        std::cout << "Head Pointer: " << head << '\n';

        if(head.load()->next) {
            std::cout << "Next Value: " << head.load()->next->data << '\n';
            std::cout << "Next Pointer: " << head.load()->next << '\n';
        } else {
            std::cout << "This is the last node" << '\n';
        }
    }
};


int main() {
    lock_free_stack s(10);
    s.push(20);
    s.push(30);
    int result;
    s.pop(result);
    s.print_stack_head();
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
