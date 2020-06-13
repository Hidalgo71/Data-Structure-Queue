#pragma once
#ifndef H_queAsArr
#define H_queAsArr
#include <iostream>
#include <cassert>
#include "queueADT.h"

using namespace std;

template<class queT>
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
#endif
