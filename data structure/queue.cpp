#include "iostream"

using namespace std;
template<class T>
class SimpleQueue;

template<class T>
class QueueNode{
    private:
        QueueNode * next;
        T m_data;
    public:
        QueueNode(T data) : m_data(data), next(nullptr){

        }
        T getData(){
            return m_data;
        }
        friend class SimpleQueue<T>;
};

template<class T>
class SimpleQueue{
    private:
        QueueNode<T> * frontNode;
        QueueNode<T> * rearNode;
        int _size;
    public:
        SimpleQueue(): frontNode(nullptr), rearNode(nullptr), _size(0){

        }
        int getSize(){
            return _size;
        }

        bool isEmpty(){
            return _size == 0;
        }

        void push_back(T val){
            // create the new node
            QueueNode<T> * newNode = new QueueNode<T>(val);
            if(isEmpty()){
                frontNode = newNode;
                // frontNode->next = nullptr; // not need because newNode->next pointed to nullptr already
                rearNode = newNode;
            } else {
                rearNode->next = newNode;
                rearNode = newNode;
                // rearNode->next = nullptr; // not need because newNode->next pointed to nullptr already
            }
            _size++;
        }

        QueueNode<T> dequeue(){
            QueueNode<T> *returnNode = nullptr;
            if(isEmpty()){
                cout << "The queue is empty !";
            } else {
                returnNode = frontNode;
                frontNode = frontNode->next;
                _size--;
            }
            
            return *returnNode;
        }
};

int main(){
    cout << "Data structure for queue in C++" << endl;

    // create a empty SimpleQueue
    SimpleQueue<int> myQueue; 
    cout << "Queue size = " << myQueue.getSize() << endl;
    cout << "Add first element" << endl;
    myQueue.push_back(100);
    cout << "Queue size = " << myQueue.getSize() << endl;
    cout << "Add second element" << endl;
    myQueue.push_back(101);
    cout << "Queue size = " << myQueue.getSize() << endl;
    cout << "Add third element" << endl;
    myQueue.push_back(200);
    cout << "Queue size = " << myQueue.getSize() << endl;
    // loop through all element in the queue
    cout << "loop through all element in the queue" << endl;
    for(int i = myQueue.getSize(); i > 0 ; i--){
        QueueNode<int> node = myQueue.dequeue();
        cout << " node.getData() " << node.getData() << endl;
        cout << "remaining size of Queue = " << myQueue.getSize() << endl;
    }

    // check the size again, should be empty now
    cout << "The current size = " << myQueue.getSize() << endl;
    return 0;
}