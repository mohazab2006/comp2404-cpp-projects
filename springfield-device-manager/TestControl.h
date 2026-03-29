#ifndef TESTCONTROL_H
#define TESTCONTROL_H

#include <iostream>
#include <string>
#include <random>
#include <unordered_set>
#include <sstream>
#include "SummitStream.h"
#include "View.h"
#include "Tester.h"
#include "SearchFactory.h"

using namespace std;

class TestControl {
		
	public:
		void launch();
	
	private:
		void initConferences(SummitStream& summitstream);
		void initWithTalks(SummitStream& summitstream, vector<string>& titles, vector<string>& speakers, 
			vector<string>& keywords, vector<string>& audio);
		
		int testAddConferences();
		int testAddTalks();
		int testGetTalksBySpeaker();
		int testGetTalksByKeyword();
		int testGetTalksBySpeakerAndKeyword();
		int testPlayCurrentTalks();
		int testAllAndMark();

		

		View view;
		Tester tester;
		SearchFactory pf;	

		const vector<string> conferences = {
								"CPP Summit", "AI Overlords", "Garbage Collection Con", "Symposium of Self-Driving", "Ruby is Still a Thing Con"
							};
		const vector<string> descriptions = {
								"Memory management and other sadisms", "Pre-emptively kowtowing!", "The computer one - IRL garbage collection is down the street",
								"No valets needed", "Seriously, it's still a thing"
							};
		

		
	
};
#endif