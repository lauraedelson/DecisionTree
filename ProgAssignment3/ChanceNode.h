#include "DecisionNode.h"
#include <limits>
#include <map>
#include <boost/shared_ptr.hpp>

static string CHANCE = "chance";

class ChanceNode :
	public Node
{
public:
	ChanceNode(string inName) : Node(inName) { value = -1 * numeric_limits<float>::max(); }

	string getType() {return CHANCE;}
	boost::shared_ptr<Node> getChild(string childName);
	float getValue();
	boost::shared_ptr<Node> getNextChild();
	void addChild(boost::shared_ptr<Node> child) {}
	void addChild(float prob, boost::shared_ptr<Node> child) { children[prob] = child; }

private:
	map<float, boost::shared_ptr<Node> > children;
};

