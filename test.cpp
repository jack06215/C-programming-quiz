#include <iostream>

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
    while (list != nullptr)
    {
        std::cout << list->data << " ";
        list = list->next;
    }
    std::cout << '\n';
}

void push_front(Node** head_, int new_data_)
{
    Node* new_node = new Node(new_data_);
    new_node->next = (*head_);
    (*head_) = new_node;
}

int main()
{
    Node* first = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    first->next = second;
    second->next = third;

    // insert to head
    push_front(&first, 5);

    print_node(first);

    return 0;
}
