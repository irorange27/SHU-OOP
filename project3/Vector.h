#ifndef VECTOR_H
#define VECTOR_H

#include <cstddef>
#include <stdexcept>
#include <initializer_list>

template <typename T>
class Vector {
public:
Vector() : data_(nullptr), size_(0), capacity_(0) {}

Vector(size_t size) : data_(new T[size]), size_(size), capacity_(size) {}

Vector(size_t size, const T& value) : Vector(size) {
    for (size_t i = 0; i < size; ++i) {
        data_[i] = value;
    }
}

Vector(std::initializer_list<T> init) : Vector(init.size()) {
    size_ = init.size();
    for (size_t i = 0; i < size_; ++i) {
        data_[i] = *(init.begin() + i);
    }
}

Vector(const Vector& other) : Vector(other.size_) {
    for (size_t i = 0; i < size_; ++i) {
        data_[i] = other.data_[i];
    }
}

Vector(Vector&& other) : data_(other.data_), size_(other.size_), capacity_(other.capacity_) {
    other.data_ = nullptr;
    other.size_ = 0;
    other.capacity_ = 0;
}

~Vector() {
    delete[] data_;
}

Vector<T>& operator=(const Vector& other) {
    if (this != &other) {
        delete[] data_;
        size_ = other.size_;
        capacity_ = other.capacity_;
        data_ = new T[capacity_];
        for (size_t i = 0; i < size_; ++i) {
            data_[i] = other.data_[i];
        }
    }
    return *this;
}

Vector<T>& operator=(std::initializer_list<T> init) {
    delete[] data_;
    size_ = init.size();
    capacity_ = init.size();
    data_ = new T[capacity_];
    for (size_t i = 0; i < size_; ++i) {
        data_[i] = *(init.begin() + i);
    }
    return *this;
}

Vector<T>& operator=(Vector&& other) {
    if (this != &other) {
        delete[] data_;
        data_ = other.data_;
        size_ = other.size_;
        capacity_ = other.capacity_;
        other.data_ = nullptr;
        other.size_ = 0;
        other.capacity_ = 0;
    }
    return *this;
}

void assign(size_t count, const T& value) {
    resize(count);
    for (size_t i = 0; i < size_; ++i) {
        data_[i] = value;
    }
}

T& at(size_t pos) {
    if (pos >= size_) {
        throw std::out_of_range("Vector::at() - index out of range");
    }
    return data_[pos];
}

const T& at(size_t pos) const {
    if (pos >= size_) {
        throw std::out_of_range("Vector::at() - index out of range");
    }
    return data_[pos];
}

T& operator[](size_t pos) {
    return data_[pos];
}

const T& operator[](size_t pos) const {
    return data_[pos];
}

T& front() {
    return data_[0];
}

const T& front() const {
    return data_[0];
}

T& back() {
    return data_[size_ - 1];
}

const T& back() const {
    return data_[size_ - 1];
}

T* data() {
    return data_;
}

const T* data() const {
    return data_;
}

bool empty() const {
    return size_ == 0;
}

size_t size() const {
    return size_;
}

size_t capacity() const {
    return capacity_;
}

size_t max_size() const {
    return size_t(-1) / sizeof(T);
}

void reserve(size_t new_capacity) {
    if (new_capacity > capacity_) {
        reallocate(new_capacity);
    }
}

void clear() {
    delete[] data_;
    data_ = nullptr;
    size_ = 0;
    capacity_ = 0;
}

void insert(size_t pos, const T& value) {
    if (pos > size_) {
        throw std::out_of_range("Vector::insert() - index out of range");
    }

    if (size_ == capacity_) {
        reallocate(capacity_ == 0 ? 1 : 2 * capacity_);
    }

    for (size_t i = size_; i > pos; --i) {
        data_[i] = data_[i - 1];
    }
    data_[pos] = value;
    ++size_;
}

void erase(size_t pos) {
    if (pos >= size_) {
        throw std::out_of_range("Vector::erase() - index out of range");
    }

    for (size_t i = pos; i < size_ - 1; ++i) {
        data_[i] = data_[i + 1];
    }
    --size_;
}

void resize(size_t new_size) {
    if (new_size > capacity_) {
        reallocate(new_size);
    }

    if (new_size > size_) {
        for (size_t i = size_; i < new_size; ++i) {
            data_[i] = T(); // 默认构造新元素
        }
    }

    size_ = new_size;
}

void swap(Vector& other) {
    std::swap(data_, other.data_);
    std::swap(size_, other.size_);
    std::swap(capacity_, other.capacity_);
}

//向量加法运算
Vector<T> operator+(const Vector<T>& other) {
    if (size_ != other.size_) {
        throw std::invalid_argument("Vector::operator+() - size mismatch");
    }
    Vector<T> result(size_);
    for (size_t i = 0; i < size_; ++i) {
        result[i] = data_[i] + other[i];
    }
    return result;
}
Vector<T> operator+(const T& value) {
    Vector<T> result(size_);
    for (size_t i = 0; i < size_; ++i) {
        result[i] = data_[i] + value;
    }
    return result;
}
Vector<T>& operator+=(const Vector<T>& other) {
    if (size_ != other.size_) {
        throw std::invalid_argument("Vector::operator+=() - size mismatch");
    }
    for (size_t i = 0; i < size_; ++i) {
        data_[i] += other[i];
    }
    return *this;
}
Vector<T>& operator+=(const T& value) {
    for (size_t i = 0; i < size_; ++i) {
        data_[i] += value;
    }
    return *this;
}
//向量减法运算
Vector<T> operator-(const Vector<T>& other) {
    if (size_ != other.size_) {
        throw std::invalid_argument("Vector::operator-() - size mismatch");
    }
    Vector<T> result(size_);
    for (size_t i = 0; i < size_; ++i) {
        result[i] = data_[i] - other[i];
    }
    return result;
}
Vector<T> operator-(const T& value) {
    Vector<T> result(size_);
    for (size_t i = 0; i < size_; ++i) {
        result[i] = data_[i] - value;
    }
    return result;
}
Vector<T>& operator-=(const Vector<T>& other) {
    if (size_ != other.size_) {
        throw std::invalid_argument("Vector::operator-=() - size mismatch");
    }
    for (size_t i = 0; i < size_; ++i) {
        data_[i] -= other[i];
    }
    return *this;
}
Vector<T>& operator-=(const T& value) {
    for (size_t i = 0; i < size_; ++i) {
        data_[i] -= value;
    }
    return *this;
}

//向量数乘
Vector<T> operator*(const T& value) {
    Vector<T> result(size_);
    for (size_t i = 0; i < size_; ++i) {
        result[i] = data_[i] * value;
    }
    return result;
}
Vector<T>& operator*=(const T& value) {
    for (size_t i = 0; i < size_; ++i) {
        data_[i] *= value;
    }
    return *this;
}

//向量内积
T operator*(const Vector<T>& other) {
    if (size_ != other.size_) {
        throw std::invalid_argument("Vector::operator*() - size mismatch");
    }
    T result = 0;
    for (size_t i = 0; i < size_; ++i) {
        result += data_[i] * other[i];
    }
    return result;
}

private:
    T* data_;
    size_t size_;
    size_t capacity_;

    void reallocate(size_t new_capacity) {
        if (new_capacity <= capacity_) {
            return;
        }

        T* new_data = new T[new_capacity];
        for (size_t i = 0; i < size_; ++i) {
            new_data[i] = data_[i];
        }

        delete[] data_;
        data_ = new_data;
        capacity_ = new_capacity;
    }
};

// 非成员函数
template <typename T>
bool operator==(const Vector<T>& lhs, const Vector<T>& rhs) {
    if (lhs.size() != rhs.size()) {
        return false;
    }

    for (size_t i = 0; i < lhs.size(); ++i) {
        if (lhs[i] != rhs[i]) {
            return false;
        }
    }

    return true;
}

template <typename T>
bool operator!=(const Vector<T>& lhs, const Vector<T>& rhs) {
    return !(lhs == rhs);
}

template <typename T>
bool operator<(const Vector<T>& lhs, const Vector<T>& rhs) {
    for (size_t i = 0; i < std::min(lhs.size(), rhs.size()); ++i) {
        if (lhs[i] < rhs[i]) {
            return true;
        }
        if (lhs[i] > rhs[i]) {
            return false;
        }
    }
    return lhs.size() < rhs.size();
}

template <typename T>
bool operator<=(const Vector<T>& lhs, const Vector<T>& rhs) {
    return !(rhs < lhs);
}

template <typename T>
bool operator>(const Vector<T>& lhs, const Vector<T>& rhs) {
    return rhs < lhs;
}

template <typename T>
bool operator>=(const Vector<T>& lhs, const Vector<T>& rhs) {
    return !(lhs < rhs);
}

#endif