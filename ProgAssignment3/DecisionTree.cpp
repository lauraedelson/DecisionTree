#include "DecisionTree.h"
#include "DecisionNode.h"
#include "ChanceNode.h"
#include "LeafNode.h"

DecisionTree::DecisionTree(float sucessVal, float failureVal, float successProb, float failureProb, const vector<Reviewer>& reviewers)
{
	root = shared_ptr<Node>(new DecisionNode("root"));
	
	addReviewerChildren(root, sucessVal, failureVal, successProb, failureProb, 0, reviewers);
}

void DecisionTree::addReviewerChildren(shared_ptr<Node> root, float successVal, float failureVal, float successProb, float failureProb, float rejectValue, vector<Reviewer> reviewers)
{
	while (!reviewers.empty()) {
		Reviewer currReviewer = reviewers.back();
		reviewers.pop_back();
		float currSuccessVal = successVal - currReviewer.cost;
		float currFailureVal = failureVal - currReviewer.cost;
		float approveProbability = (currReviewer.successOdds * successProb) + (currReviewer.failureOdds * failureProb);
		float rejectProbability = 1 - approveProbability;
		float currSuccessProbIfApproved = (currReviewer.successOdds * successProb) / approveProbability;
		float currFailureProbIfApproved = 1 - currSuccessProbIfApproved;
		float currSuccessProbIfRejected = ((1 - currReviewer.successOdds) * successProb) / rejectProbability;
		float currFailureProbIfRejected = 1 - currSuccessProbIfRejected;
		float currRejectValue = rejectValue - currReviewer.cost;

		//add node representing this reviewer
		shared_ptr<Node> reviewerNode = shared_ptr<Node>(new ChanceNode(currReviewer.name));
		root->addChild(reviewerNode);

		//add accept child
		shared_ptr<Node> acceptChild = shared_ptr<Node>(new DecisionNode("Accepted by " + currReviewer.name));
		reviewerNode->addChild(approveProbability, acceptChild);

		//add children to accept child
		addReviewerChildren(acceptChild, currSuccessVal, currFailureVal, currSuccessProbIfApproved, currFailureProbIfApproved, currRejectValue, reviewers);

		//add reject child
		shared_ptr<Node> rejectChild = shared_ptr<Node>(new DecisionNode("Rejected by " + currReviewer.name));
		reviewerNode->addChild(rejectProbability, rejectChild);

		//add children to reject child
		addReviewerChildren(rejectChild, currSuccessVal, currFailureVal, currSuccessProbIfRejected, currFailureProbIfRejected, currRejectValue, reviewers);
	}
	shared_ptr<Node> publish = shared_ptr<Node>(new ChanceNode("Publish"));
	publish->addChild(successProb, shared_ptr<Node>(new LeafNode("Success", successVal)));
	publish->addChild(failureProb, shared_ptr<Node>(new LeafNode("Failure", failureVal)));
	root->addChild(publish);
	shared_ptr<Node> reject = shared_ptr<Node>(new LeafNode("Reject", rejectValue));
	root->addChild(reject);
}
