#include "ChanceNode.h"
#include <boost/shared_ptr.hpp>

static string LEAF = "leaf";

class LeafNode :
	public Node
{
public:
	LeafNode(string inName, float inValue) : Node(inName) { value = inValue; };

	boost::shared_ptr<Node> getNextChild() { return boost::shared_ptr<Node>(); };
	boost::shared_ptr<Node> getChild(string childName) { return boost::shared_ptr<Node>(); }
	float getValue() { return value; };
	string getType() { return LEAF; };
	void addChild(boost::shared_ptr<Node> child) {}
	void addChild(float prob, boost::shared_ptr<Node> child) {}
};

