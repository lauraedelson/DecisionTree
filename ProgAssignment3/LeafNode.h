#pragma once
#include "Node.h"
class LeafNode :
	public Node
{
public:
	LeafNode(string inName, float inValue) : Node(inName) { value = inValue; };

	shared_ptr<Node> getNextChild() { return nullptr; };
	shared_ptr<Node> getChild(string childName) { return nullptr; }
	float getValue() { return value; };
	node_t getType() { return leaf; };
	void addChild(shared_ptr<Node> child) {}
	void addChild(float prob, shared_ptr<Node> child) {}
};

