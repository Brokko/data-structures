#include <iostream> 

using namespace std; 

template<typename T>
struct Node {
    Node<T>* child = nullptr;
    T value;
};

template<typename T>
class SingleLinkedList {

private:
    Node<T>* head;
    Node<T>* tale;
    int size = 0;

public:
    SingleLinkedList() {
        head = nullptr;
    }

    ~SingleLinkedList() {
        clear();
    }

    void add(T value) {
        Node<T> *node = new Node<T>;
        node -> value = value;

        if (head == nullptr) {
            head = node;
        } else {
            tale -> child = node;
        }

        size++;
        tale = node;
    }

    void add(int pos, T value) {
        Node<T> *node = new Node<T>;
        node -> value = value;

        if (pos == 0) {
            node -> child = (head);
            head = node;
        } else {
            Node<T> *last = head;
            Node<T> *child = last -> child;
            for (int i = 0; i <= pos - 2; i++) {
                if (child != nullptr)
                    last = child;

                child = last -> child;
            }

            if (child != nullptr) 
                node -> child = (child);

            last -> child = node;
        }
    }

    void remove(Node<T> *parentNode) {
        if (parentNode == nullptr) {
            Node<T> *temp = head -> child;
            delete head;
            head = temp;
        } else {
            Node<T> *deleteNode = parentNode -> child;
            if (deleteNode == nullptr) 
                return;

            Node<T> *replaceNode = deleteNode -> child;
            delete deleteNode;
            parentNode -> child = replaceNode;
        }

        size--;
    }

    void remove(int pos) {
        if (pos == 0) {
            remove(nullptr);
        } else {
            if(pos >= size) 
                return;

            Node<T> *last = head;
            for (int i = 0; i <= pos - 2; i++) 
                last = last -> child;

            remove(last);
        }
    }

    void remove(int start, int end) {
        end = end > size ? size : end;

        for (int i = start - 1; i <= end - 1; i++) 
            remove(start);
    }

    T get(int pos) {
        Node<T> *last = head;
        for (int i = 0; i < pos; i++) {
            if ((last = last -> child) == nullptr) 
                return 0;  // TODO Null / 0 not valid
        }

        return last -> value;
    }

    void clear() {
        Node<T> *node = head;
        while (node != nullptr) { 
            Node<T> *temp = node -> child;
            delete node;
            node = temp;
        }

        head = nullptr;
        size = 0;
    }

    int get_size() {
        return size;
    }

    void print() {
        Node<T> *node = head;
        while (node != nullptr) {
            cout << node -> value << endl;
            node = node -> child;
        }
    }
};