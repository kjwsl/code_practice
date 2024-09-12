#include <cmath>
#include <cstddef>
#include <new>

template <typename T>
class LList {
public:
    struct Node {
        size_t idx {};
        T val {};
        Node* next {};
        Node* prev {};
    };

    LList()
        : m_head(new Node)
        , m_tail(m_head)
    {
        m_head->idx = 0;
    }
    virtual ~LList()
    {
        Node* cur { m_head };
        while (cur->next) {
            cur = cur->next;
            delete cur->prev;
        }
        if (cur) {
            delete cur;
        }
    }

    void push(const T& val)
    {
        m_tail->val = val;
        try {
            m_tail->next = new Node;
        } catch (std::bad_alloc& e) {
            throw;
        }

        m_tail->next->prev
            = m_tail;
        m_tail = m_tail->next;

        m_size++;
    }

private:
    static constexpr size_t s_kInitSize { 1 };

    size_t m_size {};
    Node* m_head {};
    Node* m_tail {};
};

template <typename T>
class Array {
public:
    Array();
    virtual ~Array();

    Array& operator=(const Array& lhs) = delete;
    Array(const Array& other) = delete;

    Array& operator=(const Array&& lhs) noexcept;
    Array(const Array&& other) noexcept;

    void push(const T& val)
    {
        if (m_size == m_capacity) {
            m_capacity = m_capacity == 0 ? s_kInitSize : m_capacity * 2;
            T* newElements { new T[m_capacity] };
            for (size_t i = 0; i < m_size; i++) {
                newElements[i] = m_elements[i];
            }
            delete[] m_elements;
            m_elements = newElements;
        }

        m_elements[m_size++] = val;
    }

    T& operator[](size_t idx)
    {
        return m_elements[idx];
    }

private:
    static constexpr size_t s_kInitSize { 1 };

    LList<T*> m_elements {};
    size_t m_size { 0 };
    size_t m_capacity { 0 };
};

size_t reqIdx { 13 };
size_t realIdx { static_cast<size_t>(std::log2(reqIdx + 1)) };
