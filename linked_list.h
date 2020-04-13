#include <iostream>
#include <string>
using namespace std;

namespace utec
{
	struct CNode
	{
		int value_ = 0;
		CNode *next_ = nullptr;
	};

	inline namespace first
	{
		class CLinkedList
		{
			private:
				CNode* head_ = nullptr;
				CNode* tail_ = nullptr;
				size_t size_ = 0;
			public:
				//Constructores
				CLinkedList() = default;
				CLinkedList(const CLinkedList& other);
				CLinkedList(CLinkedList&& other) noexcept;
				CLinkedList& operator=(const CLinkedList& other);
				CLinkedList&operator=(CLinkedList&& other) noexcept;
				
				//Destructor
				virtual ~CLinkedList();

				//add operations
				void push_front(int value);
				void push_back(int value);
				void insert(size_t index, int value);

				//remove operations
				void pop_front();
				void pop_back();
				void erase(size_t index);

				//traversal operations
				int item(size_t index) const;
				CNode* p_item(size_t index) const;
				string imprimir_list();
				size_t size() const;
		};
	}
}