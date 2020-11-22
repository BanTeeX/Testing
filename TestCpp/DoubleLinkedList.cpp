#include <iostream>

using namespace std;

template<typename T>
class DoubleLinkedList
{
	struct Node //element listy
	{
	public:
		mutable Node* previousNode = nullptr; //wskaŸnik do poprzedniego elementu listy
		mutable Node* nextNode = nullptr; //wska¿nik do nastêpnego elementu listy
		T value; //przechowywana wartoœæ

		Node(T value) : value(value) {}
	};

private:
	mutable size_t currentIndex = NULL; //numer aktualnie wskazanego indeksu
	mutable Node* currentNode = nullptr; //wskaŸnik do aktualnie wskazywanego elementu
	size_t length = 0; //d³ugoœæ tablicy


	bool TryMoveCurrentIndex(const size_t newIndex) const noexcept //przesuwa wskaŸnik na podany indeks
	{
		if (newIndex < length)
		{
			if (newIndex == currentIndex)
			{
				return true;
			}
			else if (newIndex > currentIndex)
			{
				for (; currentIndex < newIndex; currentIndex++)
				{
					currentNode = currentNode->nextNode;
				}
			}
			else
			{
				for (; currentIndex > newIndex; currentIndex--)
				{
					currentNode = currentNode->previousNode;
				}
			}
			return true;
		}
		return false;
	}

public:
	~DoubleLinkedList() noexcept
	{
		Clear();
	}

	constexpr size_t GetLength() const noexcept
	{
		return length;
	}

	bool TryGetValueAtIndex(const size_t index, T& outValue) const noexcept //pobranie wartoœci pod indeksem, outIsSuccess true je¿eli operacja powiod³a siê, flase w przeciwnym wypadku
	{
		if (TryMoveCurrentIndex(index))
		{
			outValue = currentNode->value;
			return true;
		}
		outValue = NULL;
		return false;
	}

	bool TrySetValueAtIndex(const size_t index, const T value) noexcept //ustawienie wartoœci na indeksie zwraca true, gdy operacja siê powiedzie, lub false, w przeciwnym wypadku
	{
		if (TryMoveCurrentIndex(index))
		{
			currentNode->value = value;
			return true;
		}
		return false;
	}

	void AddValue(const T value) noexcept //dodanie elementu na koniec tablicy
	{
		Node* node = new Node(value);
		if (length == 0)
		{
			currentIndex = 0;
			currentNode = node;
		}
		else
		{
			TryMoveCurrentIndex(length - 1);
			currentNode->nextNode = node;
			node->previousNode = currentNode;
		}
		length++;
	}

	bool TryAddValueAtIndex(const size_t index, const T value) noexcept //wstawia nowy element na podany indeks (zwraca true, gdy operacja siê powiedzie, lub false, w przeciwnym wypadku)
	{
		if (TryMoveCurrentIndex(index))
		{
			Node* cell = new Node(value);
			if (currentNode->previousNode != nullptr)
			{
				currentNode->previousNode->nextNode = cell;
			}
			cell->previousNode = currentNode->previousNode;
			cell->nextNode = currentNode;
			currentNode->previousNode = cell;
			currentNode = cell;
			length++;
			return true;
		}
		return false;
	}

	void RemoveValue() noexcept //usuwa ostatni element z listy i zwraca go
	{
		if (length > 0)
		{
			TryMoveCurrentIndex(length - 1);
			if (currentNode->previousNode != nullptr)
			{
				currentNode->previousNode->nextNode = currentNode->nextNode;
			}
			currentIndex--;
			Node* temp = currentNode->previousNode;
			delete currentNode;
			currentNode = temp;
			length--;
			if (length == 0)
			{
				currentIndex = NULL;
			}
		}
	}

	bool TryRemoveValueAtIndex(const size_t index) noexcept //usuwa element na podanym indeksie (zwraca true, gdy operacja siê powiedzie, lub false, w przeciwnym wypadku)
	{
		if (TryMoveCurrentIndex(index))
		{
			Node* temp;
			if (currentNode->previousNode != nullptr)
			{
				currentNode->previousNode->nextNode = currentNode->nextNode;
			}
			if (currentNode->nextNode != nullptr)
			{
				currentNode->nextNode->previousNode = currentNode->previousNode;
				temp = currentNode->nextNode;
			}
			else
			{
				currentIndex--;
				temp = currentNode->previousNode;
			}
			delete currentNode;
			currentNode = temp;
			length--;
			if (length == 0)
			{
				currentIndex = NULL;
			}
			return true;
		}
		return false;
	}

	void Clear() noexcept //czyœci listê
	{
		if (TryMoveCurrentIndex(0))
		{
			Node* temp;
			for (; currentIndex < length; currentIndex++)
			{
				temp = currentNode->nextNode;
				delete currentNode;
				currentNode = temp;
			}
			length = 0;
			currentIndex = NULL;
		}
	}
};

template<typename T>
void PrintArray(const DoubleLinkedList<T>& list) noexcept //wyœwietla listê
{
	int value;
	for (size_t i = 0; i < list.GetLength(); i++)
	{
		list.TryGetValueAtIndex(i, value);
		cout << "[" << i << "] : " << value << endl;
	}
}

void DoubleLinkedListProgram()
{
	DoubleLinkedList<int> list;

	list.AddValue(1);
	list.AddValue(3);
	list.AddValue(4);
	list.TryAddValueAtIndex(1, 2);
	PrintArray(list);

	cout << endl;

	list.TrySetValueAtIndex(0, 5);
	list.TryRemoveValueAtIndex(1);
	list.TryRemoveValueAtIndex(2);
	list.TrySetValueAtIndex(1, 6);
	PrintArray(list);

	cout << endl;

	list.RemoveValue();
	PrintArray(list);

	cout << endl;

	list.Clear();
	PrintArray(list);
}
