/**
 * A simple implementation for a Linked List.
 * Different variations of insert are available.
 */

#include<iostream>
using namespace std;

template <typename T>
class Node {

    private:
        T data;
        Node<T>* next;

    public:

        Node(T data) {
            this->data = data;
        }

        void setNext(Node<T>* next) {
            this->next = next;
        }

        T getData() {
            return this->data;
        }

        Node<T>* getNext() {
            return this->next;
        }
};

template <typename T>
class LinkedList {

    private:
        Node<T>* first;
        Node<T>* last;

        Node<T>* node(T data) {
            Node<T>* curr = this->first;
            while (curr != NULL && curr->getData() != data) {
                curr = curr->getNext();
            }
            return curr;
        }

    public:

        LinkedList() {
            this->first = this->last = NULL;
        }

        /**
         * Inserts the element at the beginning of the list
         */
        void pushFront(T data) {
            Node<T>* f = this->first;
            Node<T>* newNode = new Node<T>(data);
            this->first = newNode;
            if (f == NULL) {
                this->last = newNode;
            } else {
                newNode->setNext(f);
            }
        }

        /**
         * Inserts the element at the end of the list
         */
        void pushBack(T data) {
            Node<T>* l = this->last;
            Node<T>* newNode = new Node<T>(data);
            this->last = newNode;
            if (l == NULL) {
                this->first = newNode;
            } else {
                l->setNext(newNode);
            }
        }

        /**
         * Inserts the element @code(data) after the given element @code(after).
         * If the @code(after) element is not present, the insertion is not done.
         */
        void push(T data, T after) {
            Node<T>* pred = node(after);
            if (pred == NULL) {
                return;
            }
            Node<T>* succ = pred->getNext();
            Node<T>* newNode = new Node<T>(data);
            pred->setNext(newNode);
            if (succ == NULL) {
                this->last = newNode;
            } else {
                newNode->setNext(succ);
            }
        }

        /**
         * Prints the list from beginning to the end
         */
        void display() {
            Node<T>* curr = this->first;
            cout << "Linked List is: ";
            while (curr != NULL) {
                cout << curr->getData() << " ";
                curr = curr->getNext();
            }
            cout << "\n";
        }
};

int main() {
    LinkedList<int> linkedList;
    cout << "Initialising the linked list...\n";
    linkedList.pushFront(5);
    linkedList.pushFront(10);
    linkedList.pushBack(15);
    linkedList.push(7, 10);
    linkedList.push(13, 12); // 13 won't be added since 12 is not present
    linkedList.display();
    return 0;
}