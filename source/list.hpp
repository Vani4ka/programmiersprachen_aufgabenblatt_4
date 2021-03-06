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
	typedef ListIterator<T> Self;

	typedef T value_type;
	typedef T* pointer;
	typedef T& reference;
	typedef ptrdiff_t difference_type;
	typedef std::forward_iterator_tag iterator_category;

	friend class List<T>;

	ListIterator():
	m_node{nullptr}
	{}

	ListIterator(ListNode<T>* n):
	m_node{n}
	{}

	reference operator*() const {
		return m_node->m_value;
	}

	// pointer operator->() const {
	// 	return 
	// }


	Self& operator++() {
		m_node = m_node->m_next;
		return *this;
	}

	// ?
	Self& operator+(int n) {
		for (int i = 0; i < n; ++i)
		{
			if (m_node->m_next==nullptr)
			{
				break;
			}
			m_node = m_node->m_next;
		}
		return *this;
	}

	bool operator==(const Self& x) const {
		return m_node==x.m_node;
	}

	bool operator!=(const Self& x) const {
		return m_node!=x.m_node;
	}

	Self next() const {
		if(m_node) {
			return ListIterator(m_node->m_next);
		}
		else {
			return ListIterator(nullptr);
		}
	}

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

	List():
	m_size{0},
	m_first{nullptr},
	m_last{nullptr}
	{}

	~List() {
		clear();
	}

	// copy-c-tor
	List(List<T> const& l) {
		for(auto it=l.begin(); it!=l.end(); ++it) {
			push_back(*it);
		}
	}

	//move c-tor
	List(List&& m):
	m_first(m.m_first),
	m_last(m.m_last),
	m_size(m.m_size)
	{
		m.m_first=nullptr;
		m.m_last=nullptr;
		m.m_size=0;
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

	ListIterator<T> begin() const {
		return ListIterator<T> {m_first};
	}

	ListIterator<T> end() const {
		//return ListIterator<T> {nullptr};
		ListIterator<T> e{m_last};
		return e.next();
	}

	//insert funktioniert nicht

	// void insert(ListIterator<T> pos, T const& node) {
	// 	ListNode<T>* n = new ListNode<T>{node, pos.m_node->m_prev, pos.m_node->m_next};
		
	// 	if(pos==begin()) {
	// 		m_first=n;
	// 		pos.m_node->m_next->m_prev= n;
	// 		std::cout<<"if"<<std::endl;
	// 	}
	// 	else if (pos==end()) {
	// 		pos.m_node->m_prev->m_next= n;
	// 		m_last=n;
	// 		std::cout<<"else if"<<std::endl;
	// 	}
	// 	else {
	// 		pos.m_node->m_prev->m_next= n;
	// 		pos.m_node->m_next->m_prev= n;
	// 		std::cout<<"else"<<std::endl;
	// 	}
	// 	m_size+=1;
	// 	std::cout<<"ende"<<std::endl;
	// }


	// void reverse() {
	// 	auto it=begin()+1;
	// 	while(it!=end()) {
	// 		//std::cout<<1<<std::endl;
	// 		auto node = it.m_node->m_prev;
	// 		auto temp = node->m_prev;
	// 		//std::cout<<2<<std::endl;
	// 		node->m_prev = node->m_next;
	// 		node->m_next = temp;
	// 		//std::cout<<3<<std::endl;
	// 		++it;
	// 	}
	// 	//std::cout<<4<<std::endl;
	// 	auto temp = it.m_node->m_prev;
	// 	//std::cout<<4.5<<std::endl;
	// 	it.m_node->m_prev = it.m_node->m_next;
	// 	//std::cout<<5<<std::endl;
	// 	it.m_node->m_next = temp;

	// 	auto temp1=m_first;
	// 	//std::cout<<6<<std::endl;
	// 	m_first=m_last;
	// 	m_last=temp1;
	// 	//std::cout<<7<<std::endl;
	// }

private:
	//Warum sind sie initialisiert? 
	std::size_t m_size = 0;
	ListNode<T>* m_first = nullptr;
	ListNode<T>* m_last = nullptr;
};

template <typename T>
bool operator==(List<T> const& xs, List<T> const& ys) {
	if(xs.size()==ys.size()) {
		auto i=xs.begin();
		for(auto j=ys.begin(); j!=ys.end();++j) {
			if (*j!=*i)
			{
				return false; 
			}
			++i;
		}
		return true;
	}
	else return false;
}

template <typename T>
bool operator!=(List<T> const& xs, List<T> const& ys) {
	if(xs.size()==ys.size()) {
		auto i=xs.begin();
		for(auto j=ys.begin(); j!=ys.end();++j) {
			if (*j!=*i)
			{
				return true; 
			}
			++i;
		}
		return false;
	}
	else return true;
}

#endif