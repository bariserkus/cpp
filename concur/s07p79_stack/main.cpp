#include <iostream>
#include <atomic>
#include <memory>
//#include <thread>

template<typename T>
class lock_free_stack{
private:
    struct node{
        std::shared_ptr<T> data;
        node * next;
        explicit node(T const & _data):data(std::make_shared<T> (_data)){}
    };

    std::atomic<int> threads_in_pop;
    std::atomic<node*> to_be_deleted;
    std::atomic<node*> head;

    void delete_nodes(node * nodes){
        while (nodes){
            node * next = nodes->next;
            delete nodes;
            nodes = next;
        }
    }
    void try_reclaim(node * old_head){
        if (threads_in_pop == 1){
            //delete node pointed old_head
            delete old_head;
            node * claimed_list = to_be_deleted.exchange(nullptr);
            if (!--threads_in_pop){
                delete_nodes(claimed_list);
            } else if (claimed_list){
                node * last = claimed_list;
                while (node * const next = last->next){
                    last =next;
                }
                last->next = to_be_deleted;
                while(!to_be_deleted.compare_exchange_weak(last->next, claimed_list));
            }
        } else {
            //add node pointed by old head to the to_be_deleted list
            old_head->next = to_be_deleted;
            while(!to_be_deleted.compare_exchange_weak(old_head->next, old_head));
            --threads_in_pop;
        }
    }



public:
    explicit lock_free_stack(T _data){
        push(_data);
    }
    ~lock_free_stack(){
        while(!head.load()->data){
            pop();
        }
        pop();
    }
    void push(T const & _data){
        node * const new_node = new node(_data);
        new_node->next = head.load();
        while(!head.compare_exchange_weak(new_node->next, new_node));
    }

/*    void pop(T& result){

        node * old_head = head.load();
        while(old_head && !head.compare_exchange_weak(old_head, old_head->next));
        result = old_head->data;
    }*/

    std::shared_ptr<T> pop(){
        ++threads_in_pop;

        node * old_head = head.load();
        while(old_head && !head.compare_exchange_weak(old_head, old_head->next));

        std::shared_ptr<T> res;
        if (old_head){
            res.swap(old_head->data);
        }

        try_reclaim(old_head);
        return res;
        //return old_head ? old_head->data : std::shared_ptr<T>();
    }


    void print_stack_head(){
        std::cout << "Head Value: " << *(head.load()->data) << '\n';
        std::cout << "Head Pointer: " << head.load() << '\n';

        if(head.load()->next) {
            std::cout << "Next Value: " << *(head.load()->next->data) << '\n';
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
    s.pop();
    s.print_stack_head();
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
