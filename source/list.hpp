#ifndef BUW_LIST_HPP
#define BUW_LIST_HPP

#include <cstddef>
#include <iostream>

template <typename T>
struct List;

template <typename T>
struct ListNode {
	ListNode():
	m_value(),
	m_prev(nullptr),
	m_next(nullptr)
	{}

	ListNode(T const& v, ListNode* prev, ListNode* next):
	m_value(v),
	m_prev(prev),
	m_next(next)
	{}

	T m_value;
	ListNode* m_prev;
	ListNode* m_next;
};

template <typename T>
struct ListIterator
{
	friend class List<T>;
public:

	//to implement

private:
	ListNode<T>* m_node = nullptr;
};

template <typename T>
class List {
public:
	typedef T value_type;
	typedef T* pointer;
	typedef const T* const_pointer;
	typedef T& reference;
	typedef const T& const_reference;
	typedef ListIterator<T> iterator;
	//typedef ListConstIterator<T> const_iterator;

	friend class ListIterator<T>;
	//friend class ListConstIterator<T>;

	//to implement

	List():
	m_size(0),
	m_first(nullptr),
	m_last(nullptr)
	{}

	~List() {
		clear();
	}

	bool empty() const {
		if (size()==0)
		{
			return true;
		}
		else return false;
	}

	std::size_t size() const {
		return m_size;
	}

	T front() const {
		return m_first->m_value;
	}

	T back() const {
		return m_last->m_value;
	}

	void push_front(T const& t) {
		ListNode<T>* n = new ListNode<T>{t, nullptr, m_first};
		
		m_size+=1;
		m_first = n;
		if (size()==1)
		{
			m_last = n;
		}
		else {
			m_first->m_next->m_prev = n;
		}

	}
	void push_back(T const& t) {
		ListNode<T>* n = new ListNode<T>{t, m_last, nullptr};

		m_size+=1;
		m_last = n;
		if (size()==1)
		{
			m_first = n;
		}
		else {
			m_last->m_prev->m_next = n;
		}
	}

	void pop_front() {
		if(!empty()) {
			auto temp = m_first;
			if(size()>1) {
				m_first->m_next->m_prev = nullptr;
				m_first = m_first->m_next;
			}
			else {
				m_first->m_next=nullptr;
			}
			delete temp;
			temp = nullptr;
			m_size-=1;
		}
		else std::cout<<"List is empty!"<<std::endl;
	}

	void pop_back() {
		if(!empty()) {
			auto temp = m_last;
			if(size()>1){
				m_last->m_prev->m_next = nullptr;
				m_last = m_last->m_prev;
			}
			else {
				m_last->m_prev=nullptr;
			}
			delete temp;
			temp = nullptr;
			m_size-=1;
		}
		else std::cout<<"List is empty!"<<std::endl;
	}

	void clear() {
		while(!empty())
		{
			pop_back();
		}
	}

private:
	//Warum sind sie initialisiert? 
	std::size_t m_size = 0;
	ListNode<T>* m_first = nullptr;
	ListNode<T>* m_last = nullptr;
};

#endif