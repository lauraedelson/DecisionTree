#include "DecisionNode.h"



shared_ptr<Node> DecisionNode::getChild(string childName)
{
	for (size_t i = 0; i < children.size(); i++) {
		if (children[i]->getName() == childName) {
			return children[i];
		}
	}
	return nullptr;
}

shared_ptr<Node> DecisionNode::getNextChild()
{
	shared_ptr<Node> bestChild = nullptr;
	for (size_t i = 0; i < children.size(); i++) {
		if (bestChild == nullptr || children[i]->getValue() > bestChild->getValue()) {
			bestChild = children[i];
		}
	}
	return bestChild;
}

float DecisionNode::getValue()
{
	if (value == numeric_limits<float>::lowest()) {
		value =  getNextChild()->getValue();
	}

	return value;
}
