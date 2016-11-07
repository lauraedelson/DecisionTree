#pragma once
#include "Node.h"
#include <vector>
#include "Reviewer.h"

class DecisionTree
{
public:
	DecisionTree(float sucessVal, float failureVal, float successProb, float failureProb, const vector<Reviewer>& reviewers);


	shared_ptr<Node> getRoot() { return root; }

private:
	void addReviewerChildren(shared_ptr<Node> root, float sucessVal, float failureVal, float successProb, float failureProb, float rejectValue, vector<Reviewer> reviewers);
	shared_ptr<Node> root;
};

