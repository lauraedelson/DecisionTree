#pragma once
#include "Node.h"
#include <map>


class ChanceNode :
	public Node
{
public:
	ChanceNode(string inName) : Node(inName) { value = numeric_limits<float>::lowest(); }

	node_t getType() {return chance;}
	shared_ptr<Node> getChild(string childName);
	float getValue();
	shared_ptr<Node> getNextChild();
	void addChild(shared_ptr<Node> child) {}
	void addChild(float prob, shared_ptr<Node> child) { children[prob] = child; }

private:
	map<float, shared_ptr<Node>> children;
};

