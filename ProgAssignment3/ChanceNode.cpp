#include "ChanceNode.h"
#include <iterator>
#include <stdlib.h>  

boost::shared_ptr<Node> ChanceNode::getChild(string childName)
{
	for (map<float, boost::shared_ptr<Node>>::iterator map_it = children.begin(); map_it != children.end(); map_it++) {
		if (map_it->second->getName() == childName) {
			return map_it->second;
		}
	}
	return boost::shared_ptr<Node>();
}

float ChanceNode::getValue()
{
	if (value == (-1 * numeric_limits<float>::max())) {
		value = 0;
		for (map<float, boost::shared_ptr<Node>>::iterator map_it = children.begin(); map_it != children.end(); map_it++) {
			value += map_it->first * map_it->second->getValue();
		}
	}

	return value;
}

boost::shared_ptr<Node> ChanceNode::getNextChild()
{
	int r_val = rand() % 10;
	float child_prob = children.begin()->first;
	if (r_val < child_prob * 10) {
		return children.begin()->second;
	}
	map<float, boost::shared_ptr<Node>>::iterator map_it = children.begin();
	map_it++;
	return map_it->second;
}
