#include <memory>
#include <vector>
#include <limits>
#include <boost/shared_ptr.hpp>

#include "Node.h"

static string DECISION = "decision";

class DecisionNode :
	public Node
{
public:
	DecisionNode(string inName) : Node(inName) { value = -1 * numeric_limits<float>::max(); }

	string getType() {return DECISION;}
	boost::shared_ptr<Node> getChild(string childName);
	boost::shared_ptr<Node> getNextChild();
	float getValue();
	void addChild(boost::shared_ptr<Node> child) { children.push_back(child); }
	void addChild(float prob, boost::shared_ptr<Node> child) {}

private:
	vector<boost::shared_ptr<Node> > children;
};
