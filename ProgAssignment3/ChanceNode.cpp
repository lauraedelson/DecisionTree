#include "ChanceNode.h"
#include <iterator>
#include <stdlib.h>  

shared_ptr<Node> ChanceNode::getChild(string childName)
{
	for (map<float, shared_ptr<Node>>::iterator map_it = children.begin(); map_it != children.end(); map_it++) {
		if (map_it->second->getName() == childName) {
			return map_it->second;
		}
	}
	return nullptr;
}

float ChanceNode::getValue()
{
	if (value == numeric_limits<float>::lowest()) {
		value = 0;
		for (map<float, shared_ptr<Node>>::iterator map_it = children.begin(); map_it != children.end(); map_it++) {
			value += map_it->first * map_it->second->getValue();
		}
	}

	return value;
}

shared_ptr<Node> ChanceNode::getNextChild()
{
	int r_val = rand() % 10;
	float child_prob = children.begin()->first;
	if (r_val < child_prob * 10) {
		return children.begin()->second;
	}
	map<float, shared_ptr<Node>>::iterator map_it = children.begin();
	map_it++;
	return map_it->second;
}
