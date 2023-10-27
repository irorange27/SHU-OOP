// LINKLIST_H_INCLUDED
#ifndef LINKLIST_H_INCLUDED
#define LINKLIST_H_INCLUDED


using namespace std;

template <typename T> class LinkList;

template <typename T> class Node
{
private:
    T _data;
    Node* _prev;
    Node* _next;
    friend class LinkList<T>;
public:
    Node() : _prev(nullptr), _next(nullptr) {}
    Node(T data) : _data(data), _prev(nullptr), _next(nullptr) {}
    Node(T data, Node* prev, Node* next) : _data(data), _prev(prev), _next(next) {}
    // This is the destructor for the Node class
    virtual ~Node() {
        // Set the previous and next pointers to nullptr
        _prev = nullptr;
        _next = nullptr;
    }
    T data() const { return _data; }
    Node* prev() const { return _prev; }
    Node* next() const { return _next; }
    void setPrev(Node* prev) { _prev = prev; }
    void setNext(Node* next) { _next = next; }
    void setData(T data) { _data = data; }


};

template <typename T> class LinkList
{
private:
    Node<T>* _head;
    Node<T>* _cur_node;
    size_t _size;
public:
    LinkList() : _head(nullptr), _cur_node(nullptr), _size(0) {}
    LinkList(T data) : _head(new Node<T>(data)), _cur_node(_head), _size(1) {}
    
   
    /**
     * Copy constructor for the LinkList class.
     * Initializes a new LinkList object with a copy of the data from the given LinkList object.
     *
     * @param other The LinkList object to copy from.
     */
    LinkList(const LinkList<T>& other) : _head(nullptr), _cur_node(nullptr), _size(0) {
        Node<T>* cur_node = other._head;
        while (cur_node != nullptr) {
            append(cur_node->data());
            cur_node = cur_node->next();
        }
    }
    ~LinkList() {
        Node<T>* cur_node = _head;
        while (cur_node != nullptr) {
            Node<T>* next_node = cur_node->next();
            delete cur_node;
            cur_node = next_node;
        }
    }
    size_t size() const { return _size; }
    void show() const;
    Node<T>* head() const { return _head; }
    Node<T>* tail() const { return _cur_node; } 
    Node<T>* curNode() const { return _cur_node; }
    void setCurNode(Node<T>* cur_node) { _cur_node = cur_node; }
    LinkList<T>* next() const { return _cur_node->next(); }
    LinkList<T>* prev() const { return _cur_node->prev(); }
    void setNext(LinkList<T>* next) { _cur_node->setNext(next); }
    void setPrev(LinkList<T>* prev) { _cur_node->setPrev(prev); }
    void setData(T data) { _cur_node->setData(data); }
    LinkList<T>& append(T data);
    LinkList<T>& extend(const LinkList<T>& other);
    LinkList<T>& pop();
    LinkList<T>& popleft();
    
};


template <typename T>
void LinkList<T>::show() const {
    Node<T>* cur_node = _head;
    std::cout << "[";
    if (cur_node != nullptr) {
        std::cout << cur_node->data();
        cur_node = cur_node->next();
        while (cur_node != nullptr) {
            std::cout << ", " << cur_node->data();
            cur_node = cur_node->next();
        }
    }
    std::cout << "]\n";
}

template <>
void LinkList<char>::show() const {
    Node<char>* cur_node = _head;
    if (cur_node != nullptr) {
        std::cout << cur_node->data(); 
    }
    std::cout << std::endl;
}


template <typename T>
LinkList<T>& LinkList<T>::append(T data) {
    if (_cur_node == nullptr) {
        _head = new Node<T>(data);
        _cur_node = _head;
    } else {
        _cur_node->setNext(new Node<T>(data));
        _cur_node = _cur_node->next();
    }
    _size++;
    return *this;
}

template <typename T>
LinkList<T>& LinkList<T>::extend(const LinkList<T>& other) {
    Node<T>* cur_node = other._head;
    while (cur_node != nullptr) {
        append(cur_node->data());
        cur_node = cur_node->next();
    }
    return *this;
}

template <typename T>
LinkList<T>& LinkList<T>::pop() {
    if (_cur_node == nullptr) {
        throw std::runtime_error("List is empty");
    }
    Node<T>* prev_node = _cur_node->prev();
    prev_node->setNext(_cur_node->next());
    delete _cur_node;
    _cur_node = prev_node;
    _size--;
    return *this;
}

template <typename T>
LinkList<T>& LinkList<T>::popleft() {
    if (_cur_node == nullptr) {
        throw std::runtime_error("List is empty");
    }
    Node<T>* _new_head = _head->next();
    delete _head;
    _head = _new_head;
    _size--;
    return *this;
}


#endif // END LINKLIST_H_INCLUED
