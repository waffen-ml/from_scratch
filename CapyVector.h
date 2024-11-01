#pragma once
#include <cassert>

template<typename T>
class CapyVector {
private:
    const double GROW_FACTOR = 1.4;
    T std_element_;
    T* data_;
    size_t size_ = 0;
    size_t cap_ = 0;

    void set_capacity(size_t new_capacity) {
        T* new_data = new T[new_capacity];
        size_t new_size = std::min(size_, new_capacity);

        //for (int i = 0; i < new_size; i++)
        //    new_data[i] = data_[i];

        memcpy(new_data, data_, new_size * sizeof(T));

        delete[] data_;
        data_ = new_data;
        cap_ = new_capacity;
        size_ = new_size;
    }

    void grow_naturally() {
        size_t new_capacity = std::max((int)ceil(GROW_FACTOR * cap_), 2);
        set_capacity(new_capacity);
    }

public:
    CapyVector() = default;


    CapyVector(size_t size) {
        resize(size);
    }


    CapyVector(size_t size, T std_element) {
        std_element_ = std_element;
        resize(size);
    }

    ~CapyVector() {
        delete[] data_;
    }


    void push_back(T value) {
        if (cap_ == size_)
            grow_naturally();

        data_[size_] = value;
        size_++;
    }


    T pop_back() {
        assert(size_ > 0);
        size_--;
        return data_[size_];
    }


    void shrink_to_fit() {
        set_capacity(size_);
    }


    void resize(size_t new_size) {
        if (new_size > cap_)
            set_capacity(new_size);

        for (int i = size_; i < new_size; i++)
            data_[i] = std_element_;

        size_ = new_size;
    }


    void reserve(size_t new_capacity) {
        assert(new_capacity >= cap_);
        set_capacity(new_capacity);
    }


    void fill(T value) {
        for (int i = 0; i < size_; i++)
            data_[i] = value;
    }


    T back() const {
        assert(size_ > 0);
        return data_[size_ - 1];
    }


    T& back() {
        assert(size_ > 0);
        return data_[size_ - 1];
    }


    T front() const {
        assert(size_ > 0);
        return data_[0];
    }


    T& front() {
        assert(size_ > 0);
        return data_[0];
    }


    bool empty() const {
        return size_ == 0;
    }


    void clear() {
        size_ = 0;
    }

    T operator [](int i) const {
        return data_[i];
    }


    T& operator [](int i) {
        return data_[i];
    }

    size_t size() const {
        return size_;
    }

    size_t capacity() const {
        return cap_;
    }
};

template<typename T>
std::ostream& operator<<(std::ostream& ss, CapyVector<T>& vec) {
    ss << "vector(size=" << vec.size() << ", cap=" << vec.capacity() << ", items=[";

    for (int i = 0; i < vec.size() - 1; i++)
        ss << vec[i] << ", ";

    if (vec.size() > 0)
        ss << vec.back() << "])";

    return ss;
}
