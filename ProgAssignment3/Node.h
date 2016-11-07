#pragma once

#include <memory>
#include <string>


using namespace std;


enum node_t{decision, chance, leaf};

class Node
{
public:
	Node(string inName) :name(inName) {};

	string getName() { return name; };

	virtual node_t getType() = 0;
	virtual shared_ptr<Node> getNextChild() = 0;
	virtual float getValue() = 0;
	virtual shared_ptr<Node> getChild(string childName) = 0;
	virtual void addChild(shared_ptr<Node> child) = 0;
	virtual void addChild(float prob, shared_ptr<Node> child) = 0;

protected:
	const string name;
	float value;
};
