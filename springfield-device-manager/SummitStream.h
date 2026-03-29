#ifndef SUMMITSTREAM_H
#define SUMMITSTREAM_H
#include <iostream>
#include <string>
#include "List.h"
#include "Conference.h"
#include "Search.h"

using namespace std;

class SummitStream {
	public:
		SummitStream();
		~SummitStream();

		void addConference(Conference* conference);
		bool addTalk(Talk* talk, const string& conferenceName);

		const List<Conference*>& getConferences() const;

		Conference* getConference(int index) const;
		Conference* getConference(const string& name) const;

		void getTalks(const Search& search, List<Talk*>& talks) const;

	private:
		List<Conference*> conferences;
};

#endif