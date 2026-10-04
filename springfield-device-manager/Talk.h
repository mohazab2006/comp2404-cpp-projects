#ifndef TALK_H
#define TALK_H

#include <iostream>
#include <string>

using namespace std;

class Talk {
    public:
        Talk(const string& title, const string& speaker,
             const string& keywords, const string& audio,
             const string& videoFile);

        const string& getTitle() const;
        const string& getSpeaker() const;
        const string& getKeywords() const;
        const string& getAudio() const;
        const string& getVideoFile() const;

        bool contains(const string& keyword) const;
        void print(ostream& ost) const;

    private:
        string title;
        string speaker;
        string keywords;
        string audio;
        string videoFile;
};

ostream& operator<<(ostream& ost, const Talk& talk);

#endif