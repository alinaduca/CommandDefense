#include <iostream>

using namespace std;

class Compare
{
public:
	virtual int CompareElements(void* e1, void* e2) {
		int* e1_int = static_cast<int*>(e1);
		int* e2_int = static_cast<int*>(e2);
		return *e1_int - *e2_int;
	}
};

template <class T>
class ArrayIterator {
private:
	int Current; // mai adaugati si alte date si functii necesare pentru iterator
	T* Element;
public:
    ArrayIterator() {
		this->Current = 0;
	}
	ArrayIterator(int Value) {
		this->Current = Value;
	}
	ArrayIterator& operator++ () {
		this->Current++;
	}
	ArrayIterator& operator-- () {
		this->Current--;
	}
	bool operator= (ArrayIterator<T>& ArrIt) {
		this->Current = ArrIt.Current;
		return true;
	}
	bool operator!=(ArrayIterator<T>& ArrIt) {
		if(this->Current != ArrIt.Current)
            return true;
		return false;
	}
	T* GetElement() {
		return this->Element;
	}
};

template <class T>
class Array {
private:
	T** List; // lista cu pointeri la obiecte de tipul T*
	int Capacity; // dimensiunea listei de pointeri
	int Size; // cate elemente sunt in lista

public:
	Array() {
		this->Capacity = 0;
		this->Size = 0;
		this->List = nullptr;
	}

	~Array() {
		delete[] this->List;
	}

	Array(int capacity) {
		if(capacity < 0)
			throw "Error: Capacity cannot be smaller then 0. [Array(int capacity) constructor]";
		this->Capacity = capacity;
		this->Size = 0;
		this->List = new T * [capacity];
		for(int i = 0; i < this->Capacity; i++)
			this->List[i] = new T;
	}

	Array(const Array<T>& otherArray) {
		this->Capacity = otherArray.Capacity;
		this->Size = otherArray.Size;
		this->List = new T * [Capacity];
		for(int i = 0; i < otherArray.Capacity; i++) {
			this->List[i] = new T;
			*this->List[i] = otherArray[i];
		}
	}

	// arunca exceptie daca index este out of range
	T& operator[] (int index) {
		if(index < 0 || index > this->Size)
			throw "Error: index is out of range. [operator[]]";
		return *(this->List[index]);
	}

	// adauga un element de tipul T la sfarsitul listei si returneaza this
	const Array<T>& operator+=(const T& newElem) {
		if(this->Size == this->Capacity)
			this->Capacity = this->Capacity * 2;
		*(this->List[this->Size++]) = newElem;
		return *this;
	}

	// adauga un element pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie
	const Array<T>& Insert(int index, const T& newElem) {
		if(index < 0 || index > this->Size)
			throw "Error: index is out of range. [Insert(int index, const T& newElem) method]";
		for(int i = this->Capacity - 1; i > index; i--)
			*this->List[i] = *this->List[i - 1];
		*this->List[index] = newElem;
		if(this->Size == this->Capacity)
			this->Capacity = this->Capacity * 2;
	}

	// adauga o lista pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie
	const Array<T>& Insert(int index, const Array<T> otherArray) {
		if(index < 0 || index > this->Size)
			throw "Error: index out of bounds. [3]";
	}

	// sterge un element de pe pozitia index, returneaza this. Daca index e invalid arunca o exceptie
	const Array<T>& Delete(int index) {
		if(index < 0 || index > this->Size)
			throw "Error: index is out of range. [Delete(int index) method]";
		for(int i = index; i < this->Size - 1; i++)
			*this->List[i] = *this->List[i + 1];
		this->Size--;
	}

	bool operator=(const Array<T>& otherArray) {
		this->Capacity = otherArray.Capacity;
		this->Size = otherArray.Size;
		for(int i = 0; i < this->Capacity; i++)
			*this->List[i] = *otherArray.List[i];
		return true;
	}

	// sorteaza folosind comparatia intre elementele din T
	void Sort() {
		T aux;
		for(int i = 0; i < this->Size - 1; i++)
			for(int j = 0; j < this->Size - i - 1; j++)
				if(*this->List[j] > *this->List[j + 1]) {
					aux = *this->List[j];
					*this->List[j] = *this->List[j + 1];
					*this->List[j + 1] = aux;
				}
	}

	// sorteaza folosind o functie de comparatie
	void Sort(int(*compare)(const T&, const T&)) {
		if(compare == nullptr)
			throw "Error: Invalid compare function. [Sort(int(*compare)(const T&, const T&)) method]";
		T aux;
		for(int i = 0; i < this->Size - 1; i++)
			for(int j = 0; j < this->Size - i - 1; j++)
				if(compare(*this->List[j], *this->List[j + 1]) > 0) {
					aux = *this->List[j];
					*this->List[j] = *this->List[j + 1];
					*this->List[j + 1] = aux;
				}
	}

	// sorteaza folosind un obiect de comparatie
	void Sort(Compare* comparator) {
		if(comparator == nullptr)
			throw "Error: Invalid compare function. [Sort(Compare* comparator) method]";
		T aux;
		for(int i = 0; i < this->Size - 1; i++)
			for(int j = 0; j < this->Size - i - 1; j++)
				if(comparator->CompareElements(static_cast<void*>(this->List[i]), static_cast<void*>(this->List[i + 1])) > 0) {
					aux = *this->List[j];
					*this->List[j] = *this->List[j + 1];
					*this->List[j + 1] = aux;
				}
	}

	// functii de cautare - returneaza pozitia elementului sau -1 daca nu exista
	int BinarySearch(const T& elem) {
		if(this->Size == 0 || this->Capacity == 0)
			throw "Error: array is empty. [BinarySearch(const T& elem) method]";
		int st = 0, dr = this->Size - 1, mij;
		while(st <= dr) {
			mij = (st + dr) / 2;
			if(*this->List[mij] == elem)
				return mij;
			if(*this->List[mij] < elem)
				st = mij + 1;
			else
				dr = mij - 1;
		}
		return -1;
	}

	int BinarySearch(const T& elem, int(*compare)(const T&, const T&)) {
		if(this->Size == 0 || this->Capacity == 0)
			throw "Error: array is empty. [BinarySearch(const T& elem, int(*compare)(const T&, const T&)) method]";
		int st = 0, dr = this->Size - 1, mij;
		while(st <= dr) {
			mij = (st + dr) / 2;
			if(compare(*this->List[mij], elem) == 0)
				return mij;
			if(compare(*this->List[mij], elem) < 0)
				st = mij + 1;
			else
				dr = mij - 1;
		}
		return -1;
	}

	int BinarySearch(const T& elem, Compare* comparator) {
		if(this->Size == 0 || this->Capacity == 0)
			throw "Error: array is empty. [BinarySearch(const T& elem, Compare* comparator) method]";
		int st = 0, dr = this->Size - 1, mij;
		while(st <= dr) {
			mij = (st + dr) / 2;
			if(compare(*this->List[mij], elem) == 0)
				return mij;
			if(compare(*this->List[mij], elem) < 0)
				st = mij + 1;
			else
				dr = mij - 1;
		}
		return -1;
	}

	int Find(const T& elem) { // cauta un element in Array
        if(this->Size == 0 || this->Capacity == 0)
			throw "Error: array is empty. [Find(const T& elem) method]";
        for(int i = 0; i < this->Size; i++)
            if(*this->List[i] == elem)
                return i;
		return -1;
	}
	int Find(const T& elem, int(*compare)(const T&, const T&)) { //  cauta un element folosind o functie de comparatie
        if(this->Size == 0 || this->Capacity == 0)
			throw "Error: array is empty. [Find(const T& elem, int(*compare)(const T&, const T&)) method]";
        for(int i = 0; i < this->Size; i++)
            if(compare(*this->List[i], elem) == 0)
                return i;
		return -1;
	}
	int Find(const T& elem, Compare* comparator) { //  cauta un element folosind un comparator
        if(this->Size == 0 || this->Capacity == 0)
			throw "Error: array is empty. [BinarySearch(const T& elem, Compare* comparator) method]";
		for(int i = 0; i < this->Size; i++)
			if(compare(*this->List[i], elem) == 0)
				return i;
		return -1;
	}

	int GetSize() {
        return this->Size;
	}
	int GetCapacity() {
        return this->Capacity;
	}

	ArrayIterator<T> GetBeginIterator(){
        return 0;
	}
	ArrayIterator<T> GetEndIterator() {
        return this->Size;
	}
};
