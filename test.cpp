#include <iostream>
#include <cstdlib>

class Node
{
public:
    int data;
    Node* next;

    Node(int data_) : data(data_), next(nullptr) {}
    ~Node();
};

void print_node(Node* list)
{
    // print the data,
    // go to the next one till it reaches the last one
    while (list != nullptr)
    {
        std::cout << list->data << " ";
        list = list->next;
    }
    std::cout << '\n';
}

void push_front(Node** head_, int new_data_)
{
    // 1. create new node with data
    Node* new_node = new Node(new_data_);
    
    // 2. new node is change to head
    new_node->next = (*head_);

    // 3. the previous head is now after the second node
    (*head_) = new_node;
    return;
}

void delete_list(Node** head_)
{
    // assign the next node before deleting
    Node* current = *head_;
    Node* next_delete;

    while (current->next != nullptr)
    {
        next_delete = current->next;
        std::free(current);
        current = next_delete;
    }
    *head_ = nullptr;

}

void push_back(Node** head_, int new_data_)
{
    // 1. create new node with data
    Node* new_node = new Node(new_data_);

    // 2. if there isn't any node, set the new node as head
    if (*head_ == nullptr)
    {
        *head_ = new_node;
        return;
    }

    // 3. traverse the entire node to the last one
    Node* current = *head_;
    while (current->next != nullptr) current = current->next;
    
    // 4. append the new node 
    current->next = new_node;
    return;
}

int node_size_iterative(Node* head_)
{
    int count = 0;
    Node* current = head_;
    
    while (current != nullptr)
    {
        count = count + 1;
        current = current->next;
    }
    return count;
}

int node_size_recursive(Node* head_)
{
    if (head_ == nullptr)
        return 0;
    return 1 + node_size_recursive(head_->next);
}

int main()
{
    Node* first = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    first->next = second;
    second->next = third;

    // push_front
    push_front(&first, 5);
    
    // push_back
    push_back(&first, 10);

    // count the node size
    std::cout << node_size_iterative(first) << std::endl;


    // delete the entire node
    delete_list(&first);

    // print the result
    print_node(first);

    return 0;
}
