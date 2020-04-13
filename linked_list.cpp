#include "linked_list.h"

utec::CLinkedList::CLinkedList(const CLinkedList& other)
{
	size_ = 1;
	auto actual = other.head_;
	head_ = new CNode{ actual->value_, nullptr };
	tail_ = head_;

	while (actual->next_)
	{
		actual = actual->next_;
		this->push_back(actual->value_);
	}
}

utec::CLinkedList::CLinkedList(CLinkedList&& other) noexcept
{
	size_ = move(other.size_);
	head_ = move(other.head_);
	tail_ = move(other.tail_);

	other.size_  = 0;
	delete other.head_;
	delete other.tail_;
	other.head_ = nullptr;
	other.tail_ = nullptr;
}

utec::CLinkedList& utec::CLinkedList::operator=(const CLinkedList& other)
{
	if (other.size_ != 0)
	{
		size_ = 1;
		auto actual = other.head_;
		head_ = new CNode{ actual->value_, nullptr };
		tail_ = head_;

		size_t i = 1;
		while (i < other.size_)
		{
			actual = actual->next_;
			this->push_back(actual->value_);
			++i;
		}
	}

	else
	{
		head_ = nullptr;
		tail_ = nullptr;

	}

	return *this;
}

utec::CLinkedList& utec::CLinkedList::operator=(CLinkedList&& other) noexcept
{
	auto current = head_;
	
	while (current != nullptr)
	{
		auto next = current->next_;
		delete current;
		current = next;
	}

	size_ = move(other.size());
	head_ = move(other.head_);
	tail_ = move(other.tail_);

	other.size_ = 0;
	other.head_ = nullptr;
	other.tail_ = nullptr;

	return *this;
}

utec::CLinkedList::~CLinkedList()
{
	CNode* ptr;	for (ptr = head_; head_; ptr = head_)	{		head_ = head_->next_;		delete ptr;	}
}

void utec::CLinkedList::push_front(int value)
{
	head_ = new CNode{ value, head_};

	if (tail_ == nullptr)
	{
		tail_ = head_;
	}

	tail_->next_ = nullptr;
	++size_;
}

void utec::CLinkedList::push_back(int value)
{
	auto aux = new CNode{ value, nullptr };

	if (head_ == nullptr)
	{
		head_ = tail_ = aux;
	}

	else
	{
		tail_->next_ = aux;
		tail_ = aux;
	}

	++size_;
}

void utec::CLinkedList::insert(size_t index, int value) 
{
	if (head_ == tail_) 
	{
		head_ = new CNode{ value, tail_ };

		if (tail_ == nullptr)
			tail_ = head_;
	}
	else 
	{
		p_item(index - 1)->next_ = new CNode{ value, p_item(index) };
	}
	size_++;
}

void utec::CLinkedList::pop_front() {	if (head_ == tail_) 	{		delete head_;		head_ = tail_ = nullptr;		size_ = 0;	}	else 	{		auto aux = head_->next_;		delete head_;		head_->next_ = nullptr;		head_ = aux;		--size_;	}}

void utec::CLinkedList::pop_back()
{
	if (head_ == tail_)
	{
		delete tail_;
		head_ = tail_ = nullptr;
		size_ = 0;
	}

	else
	{
		delete tail_->next_;
		tail_->next_ = nullptr;
		--size_;
	}
}

size_t utec::CLinkedList::size() const
{
	return size_;
}

void utec::CLinkedList::erase(size_t index)
{
	if (head_ == tail_)
	{
		delete head_;
		head_ = tail_ = nullptr;
		size_ = 0;
	}

	else
	{
		if (index == 0)
		{
			pop_front();
		}

		else if (index == size_ - 1)
		{
			pop_back();
		}

		else
		{
			auto aux = p_item(index + 1);
			delete p_item(index);
			p_item(index - 1)->next_ = aux;
			--size_;
		}
	}
}

int utec::CLinkedList::item(size_t index) const
{
	auto actual = head_;

	while (index--)
	{
		actual = actual->next_;
	}

	return actual->value_;
}

utec::CNode* utec::CLinkedList::p_item(size_t index) const
{
	auto actual = head_;

	while (index--)
	{
		actual = actual->next_;
	}

	return actual;
}

string utec::CLinkedList::imprimir_list()
{
	string list;

	for (int j = 0; j < size_; j++)
	{
		list += " " + to_string(this->item(j));
	}

	return list;
}