#include "DecisionNode.h"

boost::shared_ptr<Node> DecisionNode::getChild(string childName)
{
	for (size_t i = 0; i < children.size(); i++) {
		if (children[i]->getName() == childName) {
			return children[i];
		}
	}
	return boost::shared_ptr<Node>();
}

boost::shared_ptr<Node> DecisionNode::getNextChild()
{
	if (children.size() > 1) {
		
		boost::shared_ptr<Node> bestChild = children[0];
		for (size_t i = 1; i < children.size(); i++) {
			if (children[i]->getValue() > bestChild->getValue()) {
				bestChild = children[i];
			}
		}
		return bestChild;
	}
	return boost::shared_ptr<Node>();
}

float DecisionNode::getValue()
{
	if (value == (-1 * numeric_limits<float>::max())) {
		value =  getNextChild()->getValue();
	}

	return value;
}
