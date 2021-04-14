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
		Node* pPrev;
		T data;

		Node(T data = T(), Node* pNext = nullptr, Node* pPrev = nullptr)
		{
			this->data = data;
			this->pNext = pNext;
			this->pPrev = pPrev;
		}
	};
	int Size;
	Node<T>* head;
	Node<T>* tail;
};


template<typename T>
List<T>::List()
{
	Size = 0;
	head = nullptr;
	tail = nullptr;
}


template<typename T>
List<T>::~List()
{
	//clear();
}


template<typename T>
void List<T>::pop_front()
{
	if (!head)
		cout << "Empty" << endl;
	else
	{
		Node<T>* temp = head;
		head = head->pNext;
		delete temp;
		if (head)
			head->pPrev = nullptr;
		Size--;
	}

}
template<typename T>
void List<T>::pop_back()
{
	if (!tail)
		cout << "Empty" << endl;
	else
	{
		Node<T>* temp = tail;
		tail = tail->pPrev;
		delete temp;
		if (tail)
			tail->pNext = nullptr;
		Size--;
	}
}

template<typename T>
void List<T>::push_back(T data)
{
	Node<T>* temp = new Node<T>(data);
	temp->pNext = nullptr;
	temp->pPrev = nullptr;

	if (tail == nullptr)
	{
		head = temp;
		tail = temp;
		head->pNext = tail;
		tail->pPrev = head;
	}
	else
	{
		temp->pPrev = tail;
		tail->pNext = temp;
		tail = temp;
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
	Node<T>* temp = new Node<T>(data);
	temp->pNext = nullptr;
	temp->pPrev = nullptr;

	if (head == nullptr)
	{
		head = temp;
		tail = temp;
		head->pNext = tail;
		tail->pPrev = head;
	}
	else
	{
		temp->pNext = head;
		head->pPrev = temp;
		head = temp;
	}
	Size++;
}

template<typename T>
void List<T>::insert(T data, int index)
{

	if (!head || Size + 1 < index)
		return;

	if (index == 0)
	{
		push_front(data);
	}
	else if (index == Size + 1)
	{
		push_back(data);
	}
	else
	{
		Node<T>* previous = this->head;

		for (int i = 0; i < index; i++)
		{
			previous = previous->pNext;
		}

		Node<T>* temp = new Node<T>(data);

		temp->pNext = previous->pNext;
		temp->pPrev = previous;
		previous->pNext = temp;
		Size++;
	}
}

template<typename T>
void List<T>::removeAt(int index)
{
	if (!head || index > Size - 1)
		return;
	if (index == 0)
	{
		pop_front();
	}
	else if (index == Size - 1)
	{
		pop_back();
	}
	else
	{
		Node<T>* previous = this->head;
		for (int i = 0; i < index; i++)
		{
			previous = previous->pNext;
		}

		Node<T>* toDelete = previous->pNext;
		previous->pNext = toDelete->pNext;
		toDelete->pNext->pPrev = previous;

		delete toDelete;
		Size--;
	}

}

void func1(List<string> lst)
{
	auto cout_a = 0;
	for (auto i = 0; i < lst.GetSize(); i++)
	{
		auto& word1 = lst[i];
		if (word1[0] == word1[word1.length() - 1])
		{
			cout_a++;
		}

	}
	cout << "����������� � ����������� ���� � �� � ������: " << cout_a << endl;
}
void func2(List<string> lst)
{
	auto cout_b = 0;
	for (auto i = 1; i < lst.GetSize() - 1; i++)
	{

		auto& word1 = lst[i - 1];

		auto& word2 = lst[i];
		if (word2[0] == word1[word1.length() - 1])
		{
			cout_b++;
		}

	}
	cout << "����������� � 򳺿 � �����, �� ��� ���������� �������� �����: " << cout_b << endl;
}
void func3(List<string> lst)
{
	auto cout_c = 0;
	for (auto i = 0; i < lst.GetSize() - 1; i++)
	{
		if (lst[i] == lst[lst.GetSize() - 1])
		{
			cout_c++;
		}
	}
	cout << "��������� � ������� ������: " << cout_c << endl;
}

int main()
{
	/*�������� �������, ��� �������� ������� ��� ������ �, ����:
	�. ����������� � ����������� ���� � �� � ������;
	�. ����������� � 򳺿 � �����, �� ��� ���������� �������� �����;
	�. ��������� � ������� ������.
*/
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);


	List<string> lst;
	lst.push_back("����");
	lst.push_back("������");
	lst.push_back("���");
	lst.push_back("������");
	lst.push_back("������");
	lst.push_back("�������");
	lst.push_back("����");
	lst.push_back("������");
	lst.push_back("��������");
	lst.push_back("���������");
	lst.push_back("����");
	lst.push_back("��������");
	lst.push_back("����");
	lst.push_back("���");
	lst.push_back("�������");

	
	for (auto i = 0; i < lst.GetSize(); i++)
	{
		cout << lst[i] << endl;
	}
	func1(lst);
	func2(lst);
	func3(lst);
	return 0;
}