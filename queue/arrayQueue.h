#pragma once
#ifndef H_queAsArr
#define H_queAsArr
#include <iostream>
#include <cassert>
#include "queueADT.h"

using namespace std;

template <class queT>
class queType : public queueADT<queT>
{
public:
	const queType<queT>& operator=(const queType<queT>&);				//Operator(=) ovverloading

	bool isEmptyQue() const;
	bool isFullQue() const;
	void initializeQue();
	queT front() const;
	queT back() const;
	void addQue(const queT& queElem);
	void deleteQue();
	void moveNthFront(int n);

	queType(int queSize = 100);											//Constructor
	queType(const queType<queT>& otherQue);								//Copy constructor
	~queType();															//destructor

private:
	int maxQueSize;
	int count;
	int queFront;
	int queRear;
	queT* list;
};

template<class queT>
bool queType<queT>::isEmptyQue() const
{
	return (count == 0);
}

template<class queT>
bool queType<queT>::isFullQue() const
{
	return (count == maxQueSize);
}

template<class queT>
void queType<queT>::initializeQue()
{
	queFront = 0;								//[qFront][][][][][][][][qRear]
	queRear = maxQueSize - 1;
	count = 0;
}

template<class queT>
queT queType<queT>::front() const
{
	assert(!isEmptyQue());
	return list[queFront];
}

template<class queT>
queT queType<queT>::back() const
{
	assert(!isEmptyQue());
	return list[queRear];
}

template <class queT>
void queType<queT>::addQue(const queT& newElem)
{
	if (!isFullQue())
	{
		queRear = (queRear + 1) % maxQueSize;				//Using mode opr. because que is circular
		count++;
		list[queRear] = newElem;
	}
	else
	{
		cerr << "Que is full cant add!" << endl;
	}
}

template <class queT>
void queType<queT>::deleteQue()
{
	if (!isEmptyQue())
	{
		count--;
		queFront = (queFront + 1) % maxQueSize;
	}
	else
	{
		cerr << "Que is empty delete is finished!" << endl;
	}
}

template<class queT>
queType<queT>::queType(int queSize)										//Constructor
{
	if (queSize <= 0)
	{
		cerr << "Size of the array to hold the queue must "
			<< "be positive." << endl;
		cerr << "Creating an array of size 100." << endl;
		maxQueSize = 100;
	}
	else
	{
		maxQueSize = queSize;
	}
	queFront = 0;														//[qFront][][][][][qRear]
	queRear = maxQueSize - 1;
	count = 0;
	list = new queT[maxQueSize];										//Creating array hold que elements
}

template <class queT>
queType<queT>::~queType()												//Destructor
{
	delete[] list;
}

template <class queT>
const queType<queT>& queType<queT>::operator=(const queType<queT>& otherQue)
{
	int j;
	if (this != &otherQue)												//avoid self-copy
	{
		maxQueSize = otherQue.maxQueSize;
		queFront = otherQue.queFront;
		queRear = otherQue.queRear;
		count = otherQue.count;

		delete[] list;
		list = new queT[maxQueSize];

		if (count != 0)													//Copy otherQue in this que
		{
			for (j = queFront; j <= queRear; j = (j + 1) % maxQueSize)
				list[j] = otherQue.list[j];
		}
		return *this;
	}
}

template <class queT>
queType<queT>::queType(const queType<queT>& otherQue)					//Copy constructor
{
	maxQueueSize = otherQueue.maxQueueSize;
	queueFront = otherQueue.queueFront;
	queueRear = otherQueue.queueRear;
	count = otherQueue.count;
	list = new queT[maxQueueSize];

	for (j = queFront; j <= queRear; j = (j + 1) % maxQueSize)
		list[j] = otherQue.list[j];
}

template <class queT>
void queType<queT>::moveNthFront(int n)
{
	if (n <= 0 || n > count)
	{
		cout<<"The value of n is out of range." << endl;
	}
	else
	{
		if (count == 0)
		{
			cout << "The queue is empty." << endl;
		}
		else
		{
			int ind = (queFront + n - 1) % maxQueSize;
			queT temp = list[ind];

			if (queFront<=ind)
			{
				for (int j = ind; j > queFront; j--)
					list[j] = list[j - 1];
			}
			else
			{
				while (ind != maxQueSize - 1)
				{
					if (ind == 0)
					{
						list[ind] = list[maxQueSize - 1];
						ind = maxQueSize - 1;
					}
					else
					{
						list[ind] = list[ind - 1];
						ind--;
					}
				}
				for (int j = ind; j > queFront; j--)
				{
					list[j] = list[j - 1];
				}
			}
			list[queFront] = temp;
		}
	}
}
#endif