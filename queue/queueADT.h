#pragma once
#ifndef H_queueADT
#define H_queueADT

template <class queT>
class queueADT
{
public:
	virtual bool isEmptyQue() const = 0;					//Que is empty
	virtual bool isFullQue() const = 0;						//Que is Full
	virtual void initializeQue() const = 0;					//initialize empty que
	virtual queT front() const = 0;							//Returnt 1st element
	virtual queT back() const = 0;							//Return last element
	virtual void addQue() const = 0;						//Add
	virtual void deleteQue() const = 0;						//delete 1st element ot the que

};
#endif