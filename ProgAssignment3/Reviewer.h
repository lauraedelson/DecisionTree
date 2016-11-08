#include <string>

using namespace std;

struct Reviewer {
	Reviewer(string inName, size_t inCost, float inSuccessOdds, float inFailureOdds) :name(inName), cost(inCost), successOdds(inSuccessOdds), failureOdds(inFailureOdds) {}

	string name;
	size_t cost;
	float successOdds;
	float failureOdds;
};
