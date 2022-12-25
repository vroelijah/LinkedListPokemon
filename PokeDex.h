#pragma once
#include "C:\Users\jumpy\source\repos\224Lab8Redo\PokeNode.h"
#include <string>
using namespace std;

template <class T>
T larger(T poke1, T poke2) {
	return (poke1 > poke2 ? poke1 : poke2);
}

//template <typename Ty>
//Ty larger(Ty Pokemon, Ty Pokemon2) {
//	return()
//}
class PokeDex {
private:
	typedef PokeNode* pokeNodePtr;
	pokeNodePtr head, tail, current;
	bool flag = true;
public:
	PokeDex() {
		head = NULL;
		current = head;
		tail = NULL;
	};
	void addPokemon(PokeNode* pokemon) {
		if (!head) {
			head = pokemon;
			tail=current = head;
		}
		else {
			tail->setNext(pokemon);
			tail->getNext()->setPrev(tail) ;
			tail = tail->getNext();
		}
	};
	void compare() {
		if (current == head) {
			cout << "cannot compare these tow pokemon as they are the same." << endl;
		}
		else {
			int Lbase = larger(head->getTotalBaseStat(), current->getTotalBaseStat());
			double Lweight = larger(head->getWeight(), current->getWeight());
			cout << "Comparing BaseStat..." << endl;
			if (head->getTotalBaseStat() == Lbase) {
				cout << head->getName() << " is greater" << endl;
			}
			else {
				cout << current->getName() << " is greater" << endl;
			}

			cout << "Comparing Weight..." << endl;
			if (head->getWeight() == Lweight) {
				cout << head->getName() << " is greater" << endl;
			}
			else {
				cout << current->getName() << " is greater" << endl;
			}

		}
		
		
	};
	void moveToNext() {
		if (current->getNext()) {
			current = current->getNext();
		}
	};
	void moveToPrev() {
		if (current->getPrev()) {
			current = current->getPrev();
		}
	};
	void moveToHead() {
		current = head;
	};
	void moveToTail() {
		current = tail;
	};
	void printAll() {
		PokeNode* temp = head;
		while (temp) {
			if (temp == current) {
				cout << "*";
			}
			temp->print();
			temp = temp->getNext();
		}
	};
	void loadAll() {
		if (flag) {
			addPokemon(new PokeNode("Pikachu", "Electric", 430, 6.0));
			addPokemon(new PokeNode("Lucario", "Steel", 520, 7.8));
			addPokemon(new PokeNode("Netwoe", "Fire", 345, 4.2));
			addPokemon(new PokeNode("Greeny", "Water", 209, 10.2));
		}
	};
	void setTail(PokeNode* tail) {
		this->tail = tail;
	};
	void savePokeInCenter(string pokename) {
		PokeNode* temp = head;
		if (head->getName() == pokename) {
			if (head->getNext()) {
				head = head->getNext();
				head->getNext()->setPrev(NULL);
				current = head;
			}
			else {
				head = NULL;
			}
		}
		else {
			while (temp->getName()!=pokename) {
				temp = temp->getNext();
			}
			if (temp->getNext()) {
				temp->getPrev()->setNext(temp->getNext());
				temp->getNext()->setPrev(temp->getPrev());
			}
			else {
				temp = NULL;
			}

		}
	};
	PokeNode* getCurrent() {
		return current;
	};
};