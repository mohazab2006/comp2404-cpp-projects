#include "Search.h"

ostream& operator<<(ostream& ost, const Search& search) {
	search.print(ost);
	return ost;
}

S_Search::S_Search(const string& speaker)
	: speaker(speaker) {
}

bool S_Search::matches(const Talk* talk) const {
	return talk->getSpeaker() == speaker;
}

void S_Search::print(ostream& ost) const {
	ost << "Search matches talks by speaker: " << speaker;
}

K_Search::K_Search(const string& keyword)
	: keyword(keyword) {
}

bool K_Search::matches(const Talk* talk) const {
	return talk->contains(keyword);
}

void K_Search::print(ostream& ost) const {
	ost << "Search matches talks by keyword: " << keyword;
}

SK_Search::SK_Search(const string& speaker, const string& keyword)
	: Search(), S_Search(speaker), K_Search(keyword) {
}

bool SK_Search::matches(const Talk* talk) const {
	return S_Search::matches(talk) || K_Search::matches(talk);
}

void SK_Search::print(ostream& ost) const {
	ost << "Search matches talks by speaker: " << speaker
	    << " or keyword: " << keyword;
}