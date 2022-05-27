#include <iostream>
#include <mutex>
#include <queue>
#include <memory>
#include <condition_variable>
#include <thread>

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
    node * tail;


    std::mutex head_mutex;
    std::mutex tail_mutex;

    std::condition_variable cv;

public:
    sequential_queue() : head(new node()), tail(head.get()) {}

    void push(T value) {
        std::shared_ptr<T> new_ptr_data{std::make_shared<T>(std::move(value))};
        std::unique_ptr<node> dummy(new node);
        node* const new_tail = dummy.get();

        std::lock_guard<std::mutex> lgt(tail_mutex);
        tail->ptr_data = new_ptr_data;
        tail->next = std::move(dummy);
        tail = std::move(new_tail);
    }

    std::shared_ptr<T> pop(){
        std::lock_guard<std::mutex> hlg(head_mutex);
        if (head->ptr_data == nullptr) {
            std::cout << "Empty queue. Nothing to pop." << '\n';
            return std::shared_ptr<T>{nullptr};
        }

        std::shared_ptr<T> reslt{std::move(head->ptr_data)};
        std::unique_ptr<node> const old_head = std::move(head);
        head = std::move(old_head->next);
        return  reslt;
    }

    void print_node(node * &ptr) {
        std::cout << "Pointer of Node: " << ptr <<
                  " | Pointer of Data : " << ptr->ptr_data.get();

        if (ptr->ptr_data.get() == nullptr)
            std::cout << " | Data : " << "Empty Data";
        else
            std::cout << " | Data : " << *(ptr->ptr_data.get());

        std::cout << " | Next Pointer: " << ptr->next.get() << '\n';
    }

    void print_queue(){
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
};

template<class T>
void write_to_sq1(sequential_queue<T> & sq){


    sq.pop();
    sq.push(5);
    sq.push(10);

}

template<class T>
void write_to_sq2(sequential_queue<T> & sq){

    sq.push(20);
    sq.pop();
    sq.pop();
    sq.push(15);
    sq.push(-8);
    sq.pop();
}

void temp(){
    std::cout << "Deneme\n";
}


int main() {
    sequential_queue<int> sq;

    sq.push(5);
    sq.pop();

    std::thread t1(write_to_sq1<int>, std::ref(sq));
    std::thread t2(write_to_sq2<int>, std::ref(sq));
    std::thread t3(write_to_sq2<int>, std::ref(sq));
    std::thread t4(write_to_sq2<int>, std::ref(sq));
    std::thread t5(write_to_sq2<int>, std::ref(sq));

    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();

    sq.print_queue();

    return 0;
}




/*
    sq.pop();
    sq.pop();
    sq.push(10);
    sq.push(-5);
    sq.push(20);
    sq.print_queue();
    auto a = sq.pop();
    sq.print_queue();

    std::cout << "a = " << a << '\n';
    std::cout << "b = " << sq.pop() << '\n';

    std::cout << "Hello, World!" << std::endl;

 */
