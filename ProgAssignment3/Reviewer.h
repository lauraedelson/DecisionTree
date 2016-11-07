#pragma once

struct Reviewer {
	Reviewer(string inName, size_t inCost, float inSuccessOdds, float inFailureOdds) :name(inName), cost(inCost), successOdds(inSuccessOdds), failureOdds(inFailureOdds) {}

	const string name;
	const size_t cost;
	const float successOdds;
	const float failureOdds;
};