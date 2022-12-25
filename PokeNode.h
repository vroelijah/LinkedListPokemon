#pragma once
#include <iostream>
#include <string>
using namespace std;

class PokeNode
{
private:
	string name, type;
	int totalBaseStat;
	double weight;
	PokeNode* next;
	PokeNode* prev;
public:
	PokeNode(string name, string type, int totalBaseStat, double weight) {
		this->name = name;
		this->type = type;
		this->totalBaseStat = totalBaseStat;
		this->weight = weight;
		next = NULL;
		prev = NULL;
	};
	void setNext(PokeNode* next) {
		this->next = next;
	};
	void setPrev(PokeNode* prev) {
		this->prev = prev;
	};
	PokeNode* getNext() {
		return next;
	};
	PokeNode* getPrev() {
		return prev;
	};
	string getName() {
		return name;
	};
	int getTotalBaseStat() {
		return totalBaseStat;
	};
	double getWeight() {
		return weight;
	};
	void print() {
		cout << name << " " << type << " " << totalBaseStat << " " << weight << endl;
	};
};
