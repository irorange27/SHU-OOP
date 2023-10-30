// LINKLIST_H_INCLUDED
#ifndef LINKLIST_H_INCLUDED
#define LINKLIST_H_INCLUDED

#include <iostream>
#include <fstream>

template <typename T> class LinkList;

template <typename T> class Node
{
private:
    T _data;
    Node* _prev;
    Node* _next;
    void setPrev(Node* prev) { _prev = prev; }
    void setNext(Node* next) { _next = next; }
    void setData(T data) { _data = data; }
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

};

template <typename T> class LinkList
{
private:
    Node<T>* _head;
    Node<T>* _cur_node;
    size_t _size;
    void setNext(LinkList<T>* next) { _cur_node->setNext(next); }
    void setPrev(LinkList<T>* prev) { _cur_node->setPrev(prev); }
    void setCurNode(Node<T>* cur_node) { _cur_node = cur_node; }

public:
    LinkList() : _head(nullptr), _cur_node(nullptr), _size(0) {}
    LinkList(T data) : _head(new Node<T>(data)), _cur_node(_head), _size(1) {}
    LinkList(const LinkList<T>& other) : _head(nullptr), _cur_node(nullptr), _size(0) {
        Node<T>* cur_node = other._head;
        while (cur_node != nullptr) {
            append(cur_node->data());
            cur_node = cur_node->next();
        }
    }
    ~LinkList() {
        clear();
    }

    
    int save(const std::string& filename);
    int load(const std::string& filename);
    
    // Get data for the LinkList class
    T data() const { return _cur_node->data(); }    // Get data for the LinkList class
    void show() const;  // Displays the data in the LinkList.
    LinkList<T>& operator=(const LinkList<T>& other);   // Assigns a LinkList object to another LinkList object.
    size_t size() const { return _size; }
    Node<T>* head() const { return _head; }
    Node<T>* tail() const { return _cur_node; } 
    Node<T>* curNode() const { return _cur_node; }
    LinkList<T>* next() const { return _cur_node->next(); }
    LinkList<T>* prev() const { return _cur_node->prev(); }
    Node<T>* getIndex(const T& data) const {
        Node<T>* cur_node = _head;
        while (cur_node != nullptr && cur_node->data() != data) {
            cur_node = cur_node->next();
        }
        return cur_node;
    }
    T& locate(const T& data) {
        Node<T>* cur_node = _head;
        while (cur_node != nullptr && cur_node->data() != data) {
            cur_node = cur_node->next();
        }
        return cur_node->data();
    }
    T& index(size_t index) const{
        Node<T>* cur_node = _head;
        for (size_t i = 0; i < index; i++) {
            cur_node = cur_node->next();
        }
        return cur_node->data();
    }
    
    // Add data for the LinkList class
    LinkList<T> copy() const;       // Creates a copy of the LinkList.
    LinkList<T>& append(T data);        // Appends data to the end of the LinkList.
    LinkList<T>& extend(const LinkList<T>& other); // Extends the LinkList with another LinkList.
    
    // delete the data
    void clear();       // Deletes all the data in the LinkList.
    LinkList<T>& Remove(T& data);        // Removes the last element from the LinkList.
    LinkList<T>& pop(); // Removes the last element from the LinkList.
    LinkList<T>& popleft(); // Removes the first element from the LinkList.

    // Change data
    void setData(T data) { _cur_node->setData(data); }      // Sets the data of the current node.
    LinkList<T>& reverse(); // Reverses the LinkList in place.

    
    // file operate
    // void save(const char* filename, ios_base::openmode mode = ios_base::out) const {
    //     std::ofstream ofs(filename, mode);
    //     Node<T>* cur_node = _head;
    //     while (cur_node != nullptr) {
    //         ofs << cur_node->data() << std::endl;
    //         cur_node = cur_node->next();
    //     }
    // }
    // void load(const char* filename, ios_base::openmode mode = ios_base::in) {
    //     std::ifstream ifs(filename, mode);
    //     T data;
    //     while (ifs >> data) {
    //         append(data);
    //     }
    //     ifs.close();
    // }

    // operators
    friend std::istream& operator>>(std::istream& is, LinkList<T>& list) {
        T data;
        while (is >> data and data != -1) {
            list.append(data);
        }
        return is;
    }

    friend std::ostream& operator<<(std::ostream& os, const LinkList<T>& list) {
        Node<T>* cur_node = list._head;
        os << "[";
        if (cur_node != nullptr) {
            os << cur_node->data();
            cur_node = cur_node->next();
            while (cur_node != nullptr) {
                os << ", " << cur_node->data();
                cur_node = cur_node->next();
            }
        }
        os << "]";
        return os;
    }
    
};

template <typename T>
LinkList<T>& LinkList<T>::operator=(const LinkList<T>& other) {
    if (this != &other) {
        clear();
        Node<T>* cur_node = other._head;
        while (cur_node != nullptr) {
            append(cur_node->data());
            cur_node = cur_node->next();
        }
    }
    return *this;
}

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
int LinkList<T>::save(const std::string& filename) {
    std::ofstream ofs(filename);
    Node<T>* cur_node = _head;
    while (cur_node != nullptr) {
        ofs << cur_node->data() << std::endl;
        cur_node = cur_node->next();
    }
    return 0;
}

template <typename T>
LinkList<T> LinkList<T>::copy() const {
    LinkList<T> copyList;
    for (Node<T>* cur_node = _head; cur_node != nullptr; cur_node = cur_node->next())
        copyList.append(cur_node->data());
    
    return copyList;
}

template <typename T>
LinkList<T>& LinkList<T>::append(T data) {
    if (_cur_node == nullptr) {
        _head = new Node<T>(data);
        _cur_node = _head;
    } else {
        _cur_node->setNext(new Node<T>(data, _cur_node, nullptr));
        _cur_node = _cur_node->next();
    }
    _size++;
    return *this;
}

template <typename T>
LinkList<T>& LinkList<T>::extend(const LinkList<T>& other) {
    LinkList<T> copyList = other.copy();
    Node<T>* cur_node = copyList._head;
    while (cur_node != nullptr) {
        append(cur_node->data());
        cur_node = cur_node->next();
    }
    return *this;
}

template <typename T>
void LinkList<T>::clear() {
    Node<T>* cur_node = _head;
    while (cur_node != nullptr) {
        Node<T>* next_node = cur_node->next();
        delete cur_node;
        cur_node = next_node;
    }
    _head = nullptr;
    _cur_node = nullptr;
    _size = 0;
}

template <typename T>
LinkList<T>& LinkList<T>::Remove(T& data) {
    if (_cur_node == nullptr) {
        throw std::runtime_error("List is empty");
    } 
    Node<T>* cur_node = _head;
    while (cur_node != nullptr) {
        if (cur_node->data() == data) {
            Node<T>* prev_node = cur_node->prev();
            prev_node->setNext(cur_node->next());
            delete cur_node;
            _size--;
            return *this;
        }
        cur_node = cur_node->next();
    }
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

template <typename T>
LinkList<T>& LinkList<T>::reverse() {
    Node<T>* cur_node = _head;
    Node<T>* prev_node = nullptr;
    Node<T>* next_node = nullptr;
    while (cur_node != nullptr) {
        next_node = cur_node->next();
        cur_node->setNext(prev_node);
        prev_node = cur_node;
        cur_node = next_node;
    }
    _head = prev_node;
    return *this;
}

#endif // END LINKLIST_H_INCLUED
