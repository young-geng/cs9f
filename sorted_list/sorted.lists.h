#ifndef SORTEDLIST_H
#define SORTEDLIST_H

#include <iostream>
#include <cassert>

template <class NODETYPE> class SortedList;
template <class NODETYPE> class SortedListIterator;

template <class NODETYPE>
class ListNode {
	friend class SortedList<NODETYPE>;
	friend class SortedListIterator<NODETYPE>;
public:
	ListNode (const NODETYPE &);
	NODETYPE Info ();
private:
	NODETYPE myInfo;
	ListNode* myNext;
};

template <class NODETYPE>
ListNode<NODETYPE>::ListNode (const NODETYPE &value) {
	myInfo = value;
	myNext = nullptr;
}

template <class NODETYPE>
NODETYPE ListNode<NODETYPE>::Info () {
	return myInfo;
}

template <class NODETYPE>
class SortedList {
	friend class SortedListIterator<NODETYPE>;
public:
	SortedList ();
	~SortedList ();
	SortedList (const SortedList <NODETYPE> &);
	void Insert (const NODETYPE &);
	bool IsEmpty ();
	SortedList<NODETYPE>& operator=(const SortedList<NODETYPE>&);
private:
	ListNode <NODETYPE>* myFirst;
};

template <class NODETYPE>
class SortedListIterator {
 public:
 	SortedListIterator (const SortedList<NODETYPE> &);
 	bool MoreRemain ();
 	NODETYPE Next();
 private:
 	ListNode<NODETYPE> *current;
};



template <class NODETYPE>
SortedList<NODETYPE>::SortedList() {	// constructor
	myFirst = nullptr;
}

template <class NODETYPE>
SortedList<NODETYPE>::~SortedList() {	// destructor
	if (!IsEmpty ()) {
		std::cerr << "*** in destructor, destroying: ";
		ListNode <NODETYPE>* current = myFirst;
		ListNode <NODETYPE>* temp;
		while (current != nullptr) {
			std::cerr << " " << current->myInfo;
			temp = current;
			current = current->myNext;
			delete temp;
		}
		std::cerr << std::endl;
	}
}

template <class NODETYPE>
SortedList<NODETYPE>::SortedList(const SortedList<NODETYPE>& list) {	// copy constructor
	std::cerr << "*** in copy constructor" << std::endl;
	ListNode <NODETYPE>* listCurrent = list.myFirst;
	ListNode <NODETYPE>* newCurrent = nullptr;
	while (listCurrent != nullptr) {
		ListNode <NODETYPE> *temp 
		  = new ListNode <NODETYPE> (listCurrent->Info ());
		if (newCurrent == nullptr) {
			myFirst = temp;
			newCurrent = myFirst;
		} else {
			newCurrent->myNext = temp;
			newCurrent = temp;
		}
		listCurrent = listCurrent->myNext;
	}
}


template <class NODETYPE>
void SortedList<NODETYPE>::Insert(const NODETYPE& value) {	// Insert
	ListNode <NODETYPE> *toInsert 
	  = new ListNode <NODETYPE> (value);
	if (IsEmpty ()) {
		myFirst = toInsert;
	} else if (value < myFirst->Info ()) {
		toInsert->myNext = myFirst;
		myFirst = toInsert;
	} else {
		ListNode <NODETYPE> *temp = myFirst;
		for (temp = myFirst; 
			  temp->myNext != nullptr && temp->myNext->Info () < value; 
			  temp = temp->myNext) {
		}
		toInsert->myNext = temp->myNext;
		temp->myNext = toInsert;
	}
}

template <class NODETYPE>
bool SortedList<NODETYPE>::IsEmpty() {	// IsEmpty
	return myFirst == nullptr;
}


template <class NODETYPE>
SortedList<NODETYPE>& SortedList<NODETYPE>::operator=(const SortedList<NODETYPE>& target) {
	if (&target == this) {
		std::cerr << "*** Assigning a list to itself." << std::endl;
		return *this;
	}
	if (!IsEmpty ()) {
		std::cerr << "*** in operator=, destroying: ";
		ListNode <NODETYPE>* current = myFirst;
		ListNode <NODETYPE>* temp;
		while (current != nullptr) {
			std::cerr << " " << current->myInfo;
			temp = current;
			current = current->myNext;
			delete temp;
		}
		std::cerr << std::endl;
	}
	myFirst = nullptr;
	SortedListIterator<NODETYPE> iter(target);
	while (iter.MoreRemain()) {
		Insert(iter.Next());
	}
	return *this;
}


template <class NODETYPE>
SortedListIterator<NODETYPE>::SortedListIterator(const SortedList<NODETYPE>& list) {
	current = list.myFirst;
}

template <class NODETYPE>
bool SortedListIterator<NODETYPE>::MoreRemain() {
	return current != nullptr;
}

template <class NODETYPE>
NODETYPE SortedListIterator<NODETYPE>::Next() {
	NODETYPE elem = current->Info();
	current = current->myNext;
	return elem;
}





#endif
