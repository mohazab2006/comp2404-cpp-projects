#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <iostream>
#include <string>
#include "SummitStream.h"
#include "View.h"
#include "SearchFactory.h"

using namespace std;

class Controller {
		
	public:
				
		void launch();
	
	private:
		void initWithTalks();
		void showAllConferences();
		void showSingleConference();
		void getTalkBySpeaker(); 
		void getTalkByKeyword(); 
		void getTalkBySpeakerAndKeyword(); 
		void printCurrentTalks(); 
		void playCurrentTalks(); 
		void toggleVideo(); 
		View view;
		SummitStream summitstream;
		SearchFactory pf;
		List<Talk*> playlist;

		const vector<string> conferences = {
								"CPP Summit", "AI Overlords", "Garbage Collection Con", "Symposium of Self-Driving", "Ruby is Still a Thing Con"
							};
		const vector<string> descriptions = {
								"Memory management and other sadisms", "Pre-emptively kowtowing!", "The computer one - IRL garbage collection is down the street",
								"No valets needed", "Seriously, it's still a thing"
							};
	
};
#endif