#include <iostream>
using namespace std;

//node data type for re-use in SLL
struct node
{
	int data; //element
	node *next; //link
};

//singly linked list for reuse
struct SLL
{
	node *head;

	SLL()
	{
		head = nullptr;
	}

	//#########################################################################

	~SLL()
	{
		while (head != NULL)
		{
			node *temp = head;
			head = head->next;
			temp->next = nullptr;
			delete temp;
			temp = nullptr;
		}
	}
	//#########################################################################

	bool isEmpty()
	{
		if (head == nullptr) 
		{
			cout << "List is empty" << std::endl;
			return true;
		} 
		return false;
	}
	//#########################################################################
	
	void Traverse()
	{
		if (isEmpty())
			return;
		node *temp = head;
		while (temp != nullptr)
		{
			cout << temp->data << " ";
			temp = temp -> next;
		}
		cout << std::endl;
	}
	//#########################################################################

	void InsertAtStart(int value)
	{
		node *curr = new node;
		curr->data = value;
		curr->next = head;
		head = curr;
	}
	//#########################################################################

	void InsertAtEnd(int value)
	{
		node *prev = head; //finding location
		node* n = new node;
		n->data = value;
		if (!isEmpty())
		{
			while (prev->next != nullptr)
			{
				prev = prev->next;
			}
			prev->next = n;
		}
		else
		{
			head = n;
		}
		n->next = nullptr;
	}
	//#########################################################################

	void InsertAtAnyPosition(int value, uint64_t pos)
	{
		node* curr = head;   //created three pointers for list traversal and reference record
		node* prev = nullptr;
		uint64_t count = 1; // first node is position 1

		while (curr != nullptr)
		{
			if (count != pos)
			{
				//node not found
				count += 1;
				prev = curr;
				curr = curr->next;
			}
			else
			{   //node found
				if (prev == nullptr)
				{
					InsertAtStart(value);
					return;
				}
				else
				{
					node *n = new node;
					n->data = value;
					prev->next = n;
					n->next = curr;
					return;
				}
			}
		}
		if (count == pos) //position just after last node or inserts a node (i.e:start) when list is empty
		{
			InsertAtEnd(value);
			return;
		}
		cout << "Invalid position for insertion." << std::endl;
	}
	//############################################################################

	void DeleteAtStart()
	{
		if (!isEmpty())
		{
			node* curr = head;
			head = head->next;
			curr->next = nullptr;

			delete curr;
			curr = nullptr;
		}
	}
	//#########################################################################

	void DeleteAtEnd()
	{
		if (!isEmpty())
		{
			node *prev = nullptr;
			node *temp = head;
			while( temp->next != nullptr ) //find last node
			{
				prev = temp;
				temp = temp->next;
			}

			//delete node
			if (prev == nullptr) //if last node is first node
			{
				delete temp;
				temp = nullptr;
				head = nullptr;
				return;
			}
			prev->next = nullptr; //else
			delete temp;
			temp = nullptr;
		}
	}
	//#########################################################################

	// match pos
	// [prev]->[curr]->[nextt]->
	
	void DeleteAtAnyPosition(uint64_t pos)
	{
		if ( !isEmpty() )
		{
			node *curr = head;   //created three pointers for list traversal and reference record
			node *prev = nullptr;
			node *nextt = head->next;
			uint64_t count = 1; // first node is position 1

			while (curr != nullptr)
			{
				if (count != pos)
				{
					//node not found
					count += 1;
					prev = curr;
					curr = curr->next;
					if (curr == nullptr)
						continue;
					nextt = curr->next;
				}
				else
				{   //node found
					if (prev == nullptr)
					{
						DeleteAtStart();
						return;
					}
					else if (nextt == nullptr)
					{
						DeleteAtEnd();
						return;
					}
					else
					{
						prev->next = nextt;
						curr->next = nullptr;
						delete curr;
						curr = nullptr;
						return;
					}
				}
			}
			cout << "Invalid position for deletion." << std::endl;
		}
	}
	//#########################################################################

	void SearchData(int value)
	{
		node *temp = head;
		uint64_t count = 1;
		while (temp != nullptr)
		{
			if (value == temp->data)
			{
				cout << "Element " << value << " is at position " << count << std::endl;
				return;
			}
			else
			{
				temp = temp->next;
				count += 1;
			}
		}
		cout << "Element not found." << std::endl;
	}
	//#########################################################################
};

int main()
{
	SLL var;

	//testing maximum usecases
	var.SearchData(3);
	var.Traverse();
	var.DeleteAtEnd();
	var.DeleteAtStart();
	var.DeleteAtAnyPosition(5);

	var.InsertAtStart(10);
	var.SearchData(10);
	var.DeleteAtStart();
	var.Traverse();
	var.SearchData(10);
	var.SearchData(1);

	var.InsertAtEnd(2);
	var.InsertAtEnd(1);
	var.SearchData(1);
	var.SearchData(2);
	var.Traverse();
	var.DeleteAtEnd();
	var.Traverse();

	var.InsertAtAnyPosition(2, 4);
	var.Traverse();
	var.InsertAtAnyPosition(3, 1);
	var.Traverse();
	var.InsertAtAnyPosition(4, 1);
	var.Traverse();
	var.InsertAtAnyPosition(22, 4);
	var.Traverse();
	var.InsertAtAnyPosition(33, 5);
	var.Traverse();
	var.InsertAtAnyPosition(5, 5);
	var.Traverse();
	var.InsertAtAnyPosition(8, 5);
	var.Traverse();
	var.InsertAtAnyPosition(7, 3);
	var.Traverse();

	var.DeleteAtAnyPosition(1);
	var.Traverse();
	var.DeleteAtAnyPosition(1);
	var.Traverse();
	var.DeleteAtAnyPosition(6);
	var.Traverse();
	var.DeleteAtAnyPosition(6);
	var.Traverse();
	var.DeleteAtAnyPosition(3);
	var.Traverse();

	return 0;
}