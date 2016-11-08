#include "LeafNode.h"
#include <vector>
#include "Reviewer.h"
#include <boost/shared_ptr.hpp>

class DecisionTree
{
public:
	DecisionTree(float sucessVal, float failureVal, float successProb, float failureProb, const vector<Reviewer>& reviewers);


	boost::shared_ptr<Node> getRoot() { return root; }

private:
	void addReviewerChildren(boost::shared_ptr<Node> root, float sucessVal, float failureVal, float successProb, float failureProb, float rejectValue, vector<Reviewer> reviewers);
	boost::shared_ptr<Node> root;
};

