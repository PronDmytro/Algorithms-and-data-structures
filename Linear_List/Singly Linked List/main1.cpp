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
	clear();
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


	auto cout_a = 0;
	auto cout_b = 0;
	auto cout_c = 0;
	for (auto i = 0; i < lst.GetSize(); i++)
	{
		cout << lst[i] << endl;
	}
	
	for (auto i = 0; i < lst.GetSize(); i++)
	{
		auto& word1 = lst[i];
		if(word1[0] == word1[word1.length()-1])
		{
			cout_a++;
		}

	}
	cout << "����������� � ����������� ���� � �� � ������: " << cout_a << endl;
	
	for (auto i = 1; i < lst.GetSize()-1; i++)
	{
		
		auto &word1 = lst[i-1];

		auto& word2 = lst[i];
			if (word2[0] == word1[word1.length() - 1])
			{
				cout_b++;
			}
		
	}
	cout << "����������� � 򳺿 � �����, �� ��� ���������� �������� �����: " << cout_b << endl;
	for (auto i = 0; i < lst.GetSize()-1; i++)
	{
		if (lst[i] == lst[lst.GetSize()-1])
		{
			cout_c++;
		}
	}
	cout << "��������� � ������� ������: " << cout_c << endl;
	return 0;
}

