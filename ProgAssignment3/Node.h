#include <memory>
#include <string>
#include <boost/shared_ptr.hpp>


using namespace std;


class Node
{
public:
	Node(string inName) :name(inName) {};

	string getName() { return name; };

	virtual string getType() = 0;
	virtual boost::shared_ptr<Node> getNextChild() = 0;
	virtual float getValue() = 0;
	virtual boost::shared_ptr<Node> getChild(string childName) = 0;
	virtual void addChild(boost::shared_ptr<Node> child) = 0;
	virtual void addChild(float prob, boost::shared_ptr<Node> child) = 0;

protected:
	const string name;
	float value;
};
