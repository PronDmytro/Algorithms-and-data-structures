#include <iostream>
#include<Windows.h>
#include <algorithm>
#include <cctype>
#include <string>
using namespace std;


template<typename T>
class List
{
public:
	List();
	~List();

	void pop_front();

	void push_back(T data);

	void clear();

	int GetSize() { return Size; }

	T& operator[](const int index);

	void push_front(T data);

	void insert(T data, int index);

	void removeAt(int index);


	void pop_back();

private:


	template<typename T>
	class Node
	{
	public:
		Node* pNext;
		T data;

		Node(T data = T(), Node* pNext = nullptr)
		{
			this->data = data;
			this->pNext = pNext;
		}
	};
	int Size;
	Node<T>* head;
};


template<typename T>
List<T>::List()
{
	Size = 0;
	head = nullptr;
}


template<typename T>
List<T>::~List()
{
	//clear();
}


template<typename T>
void List<T>::pop_front()
{
	Node<T>* temp = head;

	head = head->pNext;

	delete temp;

	Size--;

}

template<typename T>
void List<T>::push_back(T data)
{
	if (head == nullptr)
	{
		head = new Node<T>(data);
	}
	else
	{
		Node<T>* current = this->head;

		while (current->pNext != nullptr)
		{
			current = current->pNext;
		}
		current->pNext = new Node<T>(data);

	}

	Size++;
}

template<typename T>
void List<T>::clear()
{
	while (Size)
	{
		pop_front();
	}
}


template<typename T>
T& List<T>::operator[](const int index)
{
	int counter = 0;

	Node<T>* current = this->head;

	while (current != nullptr)
	{
		if (counter == index)
		{
			return current->data;
		}
		current = current->pNext;
		counter++;
	}
}

template<typename T>
void List<T>::push_front(T data)
{
	head = new Node<T>(data, head);
	Size++;
}

template<typename T>
void List<T>::insert(T data, int index)
{

	if (index == 0)
	{
		push_front(data);
	}
	else
	{
		Node<T>* previous = this->head;

		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}

		Node<T>* newNode = new Node<T>(data, previous->pNext);

		previous->pNext = newNode;

		Size++;
	}





}

template<typename T>
void List<T>::removeAt(int index)
{
	if (index == 0)
	{
		pop_front();
	}
	else
	{
		Node<T>* previous = this->head;
		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}


		Node<T>* toDelete = previous->pNext;

		previous->pNext = toDelete->pNext;

		delete toDelete;

		Size--;
	}

}

template<typename T>
void List<T>::pop_back()
{
	removeAt(Size - 1);
}

void func1(List<int> lst)
{
	/*підраховує кількість входжень елемента Е в список Р*/
	int num, count = 0;
	cout << "Введіть Е: ";
	cin >> num;
	for (auto i = 0; i< lst.GetSize();i++)
	{
		if (num == lst[i])
		{
			count++;
		}
	}
	if(count !=0)
	{
		cout << "В список входить " << count << " елемнтів " << num << endl;
	}
	else
	{
		cout << "Даних елементів не існує" << endl;
	}
	
}
void func2(List<int> lst)
{
	if (lst.GetSize()==0)
	{
		cout << "Список порожній";
	}
	else
	{
		cout << "Список не порожній";
	}
	
}

int main()
{
	/*Написати функцію, яка підраховує кількість слів списку Р, якщо:
	а. починаються і закінчуються однією і тією ж літерою;
	б. починаються з тієї ж літери, на яку закінчується попереднє слово;
	в. збігаються з останнім словом.
*/
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);


	List<int> lst;
	cout <<" lst" << endl;
	for (auto i = 0; i < 9; i++)
	{
		lst.push_back( 1);
		cout << lst[i] << endl;
	}
	

	func1(lst);
	func2(lst);
	

	return 0;
}

