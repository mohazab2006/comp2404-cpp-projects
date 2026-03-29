#ifndef SEARCH_H
#define SEARCH_H

#include <iostream>
#include <string>
#include "Talk.h"

using namespace std;

class Search {
	public:
		virtual ~Search() {}
		virtual bool matches(const Talk*) const = 0;
		virtual void print(ostream& ost) const = 0;
};

ostream& operator<<(ostream& ost, const Search& search);

class S_Search : public virtual Search {
	public:
		S_Search(const string& speaker);
		virtual bool matches(const Talk* talk) const;
		virtual void print(ostream& ost) const;

	protected:
		string speaker;
};

class K_Search : public virtual Search {
	public:
		K_Search(const string& keyword);
		virtual bool matches(const Talk* talk) const;
		virtual void print(ostream& ost) const;

	protected:
		string keyword;
};

class SK_Search : public S_Search, public K_Search {
	public:
		SK_Search(const string& speaker, const string& keyword);
		virtual bool matches(const Talk* talk) const;
		virtual void print(ostream& ost) const;
};

#endif