#include <iostream>
#include <mutex>
#include <queue>
#include <memory>
//#include <condition_variable>
#include <thread>

template <typename T>
class sequential_queue{

private:
    struct node{
        T data;
        std::unique_ptr<node> next; // pointer to the next node
       explicit node(T _data):data(std::move(_data)){} //constructor for the node
    };

    std::unique_ptr<node> head;
    node* tail{nullptr};

public:
    sequential_queue() : head(nullptr),tail(nullptr){
        //std::cout << "Head: " << head << "\n";
        //std::cout << "Tail: " << tail << "\n";
    }

    void push(T value){
        std::unique_ptr<node> new_node{new node(std::move(value))};
        node * const new_tail = new_node.get();

        if (tail) // if existing queue is not empty, i.e. id tail is not null pointer i.e. non-zero
            tail->next = std::move(new_node); //discard new_node
        else
            head = std::move(new_node);

        tail = new_tail;
    }

    std::shared_ptr<T> pop(){
        if (!head) // if the head is null, !head becomes non-zero, i.e. true.
            return std::shared_ptr<T>();

        std::shared_ptr<T> reslt{std::make_shared<T>(std::move(head->data))};
        std::unique_ptr<node> const old_head = std::move(head);
        head = std::move(old_head->next);
        return  reslt;
    }
    void print_node(node * &ptr){
        std::cout << "Pointer: " << ptr << " | Data : " << ptr->data <<
        " | Next Pointer: " << ptr->next.get() << '\n';
    }

    void print_queue(){
        node * curr_ptr{head.get()};
        int count{1};
        while(curr_ptr != tail) {
            std::cout << "Count: " << count << " | ";
            print_node(curr_ptr);
            curr_ptr = curr_ptr->next.get();
            ++count;
        }
        std::cout << "Count: " << count << " | ";
        print_node(tail);
    }


};

int main() {

    sequential_queue<int> sq;

    sq.push(10);
    sq.push(-5);
    sq.push(7);
    sq.push(20);
    sq.pop();


    sq.print_queue();

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
