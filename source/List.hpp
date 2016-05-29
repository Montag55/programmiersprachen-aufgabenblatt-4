#ifndef BUW_LIST_HPP
#define BUW_LIST_HPP

#include <cstddef>



template <typename T>
struct List;

template <typename T>
struct ListNode{
	ListNode(): m_value(), m_prev(nullptr), m_next(nullptr) {}
	ListNode(T const& v, ListNode*prev, ListNode*next): m_value(v), m_prev(prev), m_next(next){}
	T m_value;
	ListNode*m_prev;
	ListNode*m_next;
};

template <typename T>
struct ListConstIterator{
	friend class List <T>;
	public:
	// not implemented yet
	private:
	ListNode <T>*m_node = nullptr;
	};

template <typename T>
struct ListIterator{
	typedef ListIterator<T>Self;
	typedef T value_type;
	typedef T* pointer;
	typedef T& reference;
	typedef ptrdiff_t difference_type;
	typedef std::forward_iterator_tag iterator_category;

	friend class List <T>;

	ListIterator():
		m_node(nullptr) {}

	ListIterator(ListNode <T>*n): 
		m_node(n) {}

	reference operator*() const{
		return m_node->m_value;
	} 

	pointer operator->() const{
		return *m_node;
	}

	Self& operator++(){
		m_node = m_node->m_next;
		return *this;
	}

	Self operator++(int){	//http://www.cs.rpi.edu/~musser/gp/List/lists2.html
		Self tmp = *this;
		++(*this);
		return tmp;
	}

	bool operator==(const Self& x) const{
		return m_node == x.m_node;
	}

	bool operator!=(const Self& x) const {
		return m_node != x.m_node;
	}

	Self next () const{
		if (m_node)
			return ListIterator(m_node->m_next);
		else
			return ListIterator(nullptr);
	}
	private :
		// The Node the iterator is pointing to
		ListNode <T>*m_node = nullptr;
};


template <typename T>
class List{
public:
	typedef T value_type;
	typedef T * pointer;
	typedef const T * const_pointer;
	typedef T & reference;
	typedef const T & const_reference;
	typedef ListIterator <T> iterator;
	typedef ListConstIterator <T> const_iterator;
	friend class ListIterator <T>;
	friend class ListConstIterator <T>;

	List():
		m_size{0},
		m_first{nullptr},
		m_last{nullptr} {}

	~List(){clear();} //destructor?

	std::size_t size() const{
		return m_size;
	}

	bool empty() const{
		return m_size==0;
	}

	void push_front(T const& a){
		if (empty()){
			ListNode<T>* l1 = new ListNode<T>(a, nullptr, nullptr);
			m_first = l1;
			m_last = l1;
		}

		else {
			ListNode<T>* l1 = new ListNode<T>(a, nullptr, m_first);
			m_first->m_prev=l1;
			m_first = l1;		
		}
		m_size +=1;
	}

	void push_back(T const& a){
		if (empty()){
			ListNode<T>* l1 = new ListNode<T>(a, nullptr, nullptr);
			m_first = l1;
			m_last = l1;
		}

		else {
			ListNode<T>* l3 = new ListNode<T>(a, m_last, nullptr);
			m_last->m_next=l3;
			m_last = l3;		
		}
		m_size +=1;
	}

	void pop_front(){
		if (m_size>1){
			auto tmp = m_first->m_next;
			delete m_first;
			tmp->m_prev = nullptr;
			m_first=tmp;
			m_size= m_size -1;
		}
		if(m_size == 1){
			delete m_first;
			m_first=nullptr;
			m_last=nullptr;
			m_size = m_size - 1;
		}
	}

	void pop_back(){
		if (m_size>1){
			auto tmp = m_last->m_prev;
			delete m_last;
			tmp->m_next = nullptr;
			m_last=tmp;
			m_size= m_size -1;
		}
		if(m_size == 1){
			delete m_first;
			m_first=nullptr;
			m_last=nullptr;
			m_size = m_size - 1;
		}
	}

	T& front() const{
		return m_first->m_value;
	}

	T& back() const{
		return m_last->m_value;
	}

	void clear(){
		while (m_size != 0){
			pop_front();
		}
	}

	iterator begin() const{
		if (empty())
			return nullptr;
		return m_first;
	}

	iterator end() const{
		if (empty())
			return nullptr;
		return m_last;
	}

	
		
private:
std::size_t m_size = 0;
ListNode <T>* m_first = nullptr;
ListNode <T>* m_last = nullptr;
};

#endif