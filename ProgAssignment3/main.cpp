#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip>
#include <iterator>
#include "DecisionTree.h"



using namespace std;

static string YES = "Yes";
static string NO = "No";

//given a space delimited string, return a vector of the parts
vector<string> tokenize(string input) {
	stringstream ss(input);
	istream_iterator<string> begin(ss);
	istream_iterator<string> end;
	vector<string> vstrings(begin, end);
	return vstrings;
}

int main(int argc, char* argv[]) {
	if (argc < 2) {
		cout << "usage: progassignment3 inputfile.txt" << endl;
		exit(EXIT_FAILURE);
	}

	ifstream inputFile(argv[1]);
	size_t reviewer_count;
	float success_value;
	float failure_value;
	float sucess_probability;
	float failure_probability;
	vector<Reviewer> reviewers;
	if (inputFile.is_open())
	{
		string line;
		getline(inputFile, line);
		vector<string> parts = tokenize(line);
		reviewer_count = atof(parts[0].c_str());
		success_value = atof(parts[1].c_str());
		failure_value = atof(parts[2].c_str());
		sucess_probability = atof(parts[3].c_str());
		failure_probability = 1 - sucess_probability;
		int reviewerCount = 1;
		while (getline(inputFile, line))
		{
			vector<string> subparts = tokenize(line);
			string reviewerName = "Consult Reviewer " + to_string(reviewerCount);
			reviewers.push_back(Reviewer(reviewerName, atof(subparts[0].c_str()), atof(subparts[1].c_str()), atof(subparts[2].c_str())));
			reviewerCount++;
		}
		inputFile.close();
	}
	else {
		cout << "Unable to open file" << argv[1] << endl;
		exit(EXIT_FAILURE);
	}

	DecisionTree tree(success_value, failure_value, sucess_probability, failure_probability, reviewers);
	shared_ptr<Node> currNode = tree.getRoot();
	stringstream stream;
	stream << fixed << setprecision(2) << currNode->getValue();
	string s = stream.str();
	cout << "Expected Value:" << s << endl;

	do {
		if (currNode != nullptr) {
			if (currNode->getType() == decision) {
				currNode = currNode->getNextChild();
			}
			else if (currNode->getType() == chance) {
				cout << currNode->getName() << endl;
				if (currNode->getName() == "Publish" ){
					currNode = currNode->getNextChild();
				}
				else {
					string answer;
					cin >> answer;
					if (answer == YES) {
						currNode = currNode->getChild("Accepted by " + currNode->getName());
						currNode = currNode->getNextChild();
					}
					else {
						currNode = currNode->getChild("Rejected by " + currNode->getName());
						currNode = currNode->getNextChild();
					}
				}
			}
		}
	} while (currNode != nullptr && currNode->getType() != leaf);
	if (currNode->getName() == "Reject") {
		cout << currNode->getName();
	}
}