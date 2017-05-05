/* MenyBuganim 302490610	BaruchRothkoff 311603252 */
#include<assert.h>
#include <iostream>
using namespace std;

#ifndef ArrayList_H
#define ArrayList_H

template <class T>
class ArrayList{
private:
	T *storage;
	int size;
public:
	ArrayList() : size(0){};
	void addElement(T toAdd);
	void addElement(T toAdd, int index);
	T popMin();
	T popMax();
	int getSize()const{ return size; };
	void print()const;
	ArrayList(const ArrayList&);
	~ArrayList();
};

template <class T>
void ArrayList<T>::addElement(T toAdd){					//add element.
	T *temp = new T[size + 1];			//making dynamic temp.
	assert(temp != 0);
	for (int i = 0; i < size; i++){		//make copy of storage.
		temp[i] = storage[i];
	}
	temp[size] = toAdd;
	delete[]storage;
	storage = temp;
	size++;
}

template <class T>
void ArrayList<T>::addElement(T toAdd, int index){				//add element at specific index.
	if (index > size || index < 0){
		cout << "index not in normal bound." << endl;
	}
	else{
		T *temp = new T[size + 1];			//making dynamic temp.
		assert(temp != 0);					//Check memory allocation.
		for (int i = 0; i < index; i++){		//make copy of storage.
			temp[i] = storage[i];
		}
		temp[index] = toAdd;
		for (int i = index; i < size; i++){
			temp[i + 1] = storage[i];
		}
		delete[]storage;
		storage = temp;
		size++;
	}
}

template <class T>
T ArrayList<T>::popMin(){
	int counter = 0;
	if (size <= 0){
		cout << "array is empty." << endl;
		return NULL;
	}
	else{
		T min = NULL;
		min = storage[0];
		T*temp = new T[size-1];						//copy our array to temp array.
		assert(temp != 0);							//Check memory allocation.
		for (int i = 1; i < size; i++){			//find our minimum element.
			if (storage[i] < min){
				min = storage[i];
				counter = i;
			}
		}
		for (int i = 0; i < counter; i++){
			temp[i] = storage[i];
		}
		for (int i = counter; i < size-1; i++){		//from one after min keep copy to original.
			temp[i] = storage[i + 1];
		}
		delete[]storage;
		storage = temp;
		size--;										//making our size smaler;
		return min;
	}
}

template<class T>
T ArrayList<T>::popMax(){
	int counter = 0;
	if (size <= 0){
		cout << "array is empty." << endl;
		return NULL;
	}
	else{
		T max = NULL;
		max = storage[0];
		T*temp = new T[size - 1];						//copy our array to temp array.
		assert(temp != 0);							//Check memory allocation.
		for (int i = 1; i < size; i++){				//find our maximum element.
			if (storage[i] > max){
				max = storage[i];
				counter = i;
			}
		}
		for (int i = 0; i < counter; i++){
			temp[i] = storage[i];
		}
		for (int i = counter; i < size-1; i++){		//from one after max keep copy to original.
			temp[i] = storage[i + 1];
		}
		delete[]storage;
		storage = temp;
		size--;										//making our size smaler;
		return max;
	}
}

template<class T>
void ArrayList<T>::print()const{
	for (int i = 0; i < size; i++){
		cout << "[ " << i << " ] = " << *(storage + i) << "." << endl;
	}
}

template <class T>
ArrayList<T>::ArrayList(const ArrayList& copy){	//copyConstructor.
	this->storage = new T[copy.size];
	size = copy.size;

	for (int i = 0; i < size; i++){
		storage[i] = copy.storage[i];
	}
}

template <class T>
ArrayList<T>::~ArrayList(){						//destructor & release dynamic memory.
	delete[] storage;
	cout << "Array at the size of " << size << " has been deleted." << endl;
	//cin.get(); you want to wait before the program close? this is the main's responsbilty!!
}
#endif