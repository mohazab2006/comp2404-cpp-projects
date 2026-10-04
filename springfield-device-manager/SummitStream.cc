#include "SummitStream.h"
#include <cstdlib>

SummitStream::SummitStream() {
}

SummitStream::~SummitStream() {
	for (int i = 0; i < conferences.getSize(); ++i) {
		delete conferences[i];
	}
}

void SummitStream::addConference(Conference* conference) {
	conferences += conference;
}

bool SummitStream::addTalk(Talk* talk, const string& conferenceName) {
	for (int i = 0; i < conferences.getSize(); ++i) {
		if (*(conferences[i]) == conferenceName) {
			conferences[i]->add(talk);
			return true;
		}
	}
	cerr << "Conference not found: " << conferenceName << endl;
	return false;
}

const List<Conference*>& SummitStream::getConferences() const {
	return conferences;
}

Conference* SummitStream::getConference(int index) const {
	if (index < 0 || index >= conferences.getSize()) {
		cerr << "Conference index out of bounds" << endl;
		exit(1);
	}
	return conferences[index];
}

Conference* SummitStream::getConference(const string& name) const {
	for (int i = 0; i < conferences.getSize(); ++i) {
		if (*(conferences[i]) == name) {
			return conferences[i];
		}
	}
	cerr << "Conference not found: " << name << endl;
	exit(1);
}

void SummitStream::getTalks(const Search& search, List<Talk*>& talks) const {
	for (int i = 0; i < conferences.getSize(); ++i) {
		Conference* conf = conferences[i];
		for (int j = 0; j < conf->getSize(); ++j) {
			Talk* talk = conf->getTalk(j);
			if (search.matches(talk)) {
				talks += talk;
			}
		}
	}
}