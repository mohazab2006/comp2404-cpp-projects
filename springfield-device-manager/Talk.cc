#include "Talk.h"

Talk::Talk(const string& title, const string& speaker,
           const string& keywords, const string& audio,
           const string& videoFile)
    : title(title), speaker(speaker), keywords(keywords),
      audio(audio), videoFile(videoFile) {
}

const string& Talk::getTitle() const {
    return title;
}

const string& Talk::getSpeaker() const {
    return speaker;
}

const string& Talk::getKeywords() const {
    return keywords;
}

const string& Talk::getAudio() const {
    return audio;
}

const string& Talk::getVideoFile() const {
    return videoFile;
}

bool Talk::contains(const string& keyword) const {
    return keywords.find(keyword) != string::npos;
}

void Talk::print(ostream& ost) const {
    ost << "Speaker: " << speaker << endl;
    ost << "Title: " << title << endl;
    ost << "Keywords: " << keywords << endl;
}

ostream& operator<<(ostream& ost, const Talk& talk) {
    talk.print(ost);
    return ost;
}