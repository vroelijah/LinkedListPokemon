#include <iostream>
#include <algorithm>
#include <string>
#include <list>
#include <iostream>
#include "C:\Users\jumpy\source\repos\224Lab8Redo\PokeDex.h"
#include <string.h>

using namespace std;


//template<typename Dtype>
//void swapT(Dtype& a, Dtype& b) {
//	Dtype temp = a;
//	a = b;
//	b = temp;
//}
//template <typename Type>
//struct Node
//{
//	Type value;
//	Node* next;
//	Node():next(nullptr){}
//	Node(Type x,Node* prt=nullptr):value(x),next(nullptr){}
//	~Node(){}
//};



int main() {
		PokeDex one;


		while (1) {
			cout << "(l) - load" << endl;
			cout << "(p) - print" << endl;
			cout << "(a) - add" << endl;
			cout << "(s) - save to pokecenter" << endl;
			cout << "(c) - compare to head" << endl;
			cout << "(n) - move to next node " << endl;
			cout << "(b) - move to previous node" << endl;
			cout << "(h) - move to head" << endl;
			cout << "(t) - move to tail" << endl;
			string place;
			string n, t;
			int stat;
			double weight;
			char k;
			cin >> k;
			switch (k) {
				case 'l':
					one.loadAll();
					break;
				case 'p':
					one.printAll();
					break;
			case'c':
				one.compare();
				break;
			case 's':
				cout << "enter the name of the pokemon to place in the center" << endl;
				//string place;
				cin >> place;
				one.savePokeInCenter(place);
				break;
			case'n':
				one.moveToNext();
				break;
			case 'b':
				one.moveToPrev();
				break;
			case 'h':
				one.moveToHead();
				break;
			case 't':
				one.moveToTail();
				break;
			case 'a':
				cout << "enter the name, type, base stat, and weight of the pokemon you want to add" << endl;

				cin >> n >> t >> stat >> weight;
				one.addPokemon(new PokeNode(n, t, stat, weight));
				cout << "n was added" << endl;
				break;



			}

		}


	}

