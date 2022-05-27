#include <iostream>
#include <mutex>
#include <queue>
#include <memory>
//#include <condition_variable>
//#include <thread>

template <typename T>
class sequential_queue{

private:
    struct node{
        std::shared_ptr<T> ptr_data;
        std::unique_ptr<node> next; // pointer to the next node
        node():ptr_data(nullptr){};
        explicit node(std::shared_ptr<T> _ptr_data) : ptr_data(std::move(_ptr_data)){}   //constructor for the node.
    };

    std::unique_ptr<node> head;
    node* tail;

    std::mutex head_mutex;
    std::mutex tail_mutex;

public:
    sequential_queue() : head{new node}, tail{nullptr}{
        //std::cout << "Head: " << head << "\n";
        //std::cout << "Tail: " << tail << "\n";
    }

    void push(T value) {
        std::unique_ptr<node> new_node{new node(std::make_shared<T>(value))};
        //std::cout << new_node.get() << "  |  " << *(new_node->ptr_data) << '\n';
        node *const new_tail = new_node.get();

        std::lock_guard<std::mutex> tlg(tail_mutex);
        if (tail) { // if existing queue is not empty, i.e. id tail is not null pointer i.e. non-zero
            tail->next = std::move(new_node); //discard new_node
        } else {
            std::lock_guard<std::mutex> hlg(head_mutex);
            head = std::move(new_node);
        }
        tail = new_tail;
    }

    std::shared_ptr<T> pop(){
        std::lock_guard<std::mutex> hlg(head_mutex);
        if (!head) // if the head is null, !head becomes non-zero, i.e. true.
            return std::shared_ptr<T>{nullptr};

        std::shared_ptr<T> reslt{std::move(head->ptr_data)};
        std::unique_ptr<node> const old_head = std::move(head);
        head = std::move(old_head->next);
        return  reslt;
    }

    void print_node(node * &ptr){
        std::cout << "Pointer of Node: " << ptr <<
        " | Pointer of Data : " << ptr->ptr_data.get() <<
        " | Data : " << *(ptr->ptr_data.get()) <<
        " | Next Pointer: " << ptr->next.get() << '\n';
    }

    void print_queue(){
        if (head.get() == nullptr || tail == nullptr) {
            std::cout << "Queue is empty!" << '\n';
        }
        else {
            node * curr_ptr{head.get()};
            int count{1};
            while (curr_ptr != tail) {
                std::cout << "Count: " << count << " | ";
                print_node(curr_ptr);
                curr_ptr = curr_ptr->next.get();
                ++count;
            }
            std::cout << "Count: " << count << " | ";
            print_node(tail);
        }
    }


};

int main() {

    sequential_queue<int> sq;
    sq.print_queue();


    sq.push(10);
    sq.push(-5);
    sq.push(7);
    sq.push(20);
    sq.pop();

    sq.print_queue();

    std::cout << "Hello, World!" << std::endl;
    return 0;
}