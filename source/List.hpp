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
struct ListIterator{
	friend class List <T>;
	// not implemented yet
	private:
	ListNode <T>*m_node = nullptr;
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
class List{
public:
	List():
		m_size{0},
		m_first{nullptr},
		m_last{nullptr} {}

	/*List(List const& a):
		m_first{nullptr},
		m_last{nullptr},
		m_size{} {
		}
	*/	
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

	typedef T value_type;
	typedef T * pointer;
	typedef const T * const_pointer;
	typedef T & reference;
	typedef const T & const_reference;
	typedef ListIterator <T> iterator;
	typedef ListConstIterator <T> const_iterator;
	friend class ListIterator <T>;
	friend class ListConstIterator <T>;
		
private:
std::size_t m_size = 0;
ListNode <T>* m_first = nullptr;
ListNode <T>* m_last = nullptr;
};

#endif