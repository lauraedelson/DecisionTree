#pragma once
#include <memory>
#include <vector>
#include <limits>


#include "Node.h"

class DecisionNode :
	public Node
{
public:
	DecisionNode(string inName) : Node(inName) { value = numeric_limits<float>::lowest(); }

	node_t getType() {return decision;}
	shared_ptr<Node> getChild(string childName);
	shared_ptr<Node> getNextChild();
	float getValue();
	void addChild(shared_ptr<Node> child) { children.push_back(child); }
	void addChild(float prob, shared_ptr<Node> child) {}

private:
	vector<shared_ptr<Node>> children;
};