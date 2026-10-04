#include "Player.h"
#include <fstream>
#include <string>

void AudioPlayer::play(const Talk& talk, ostream& ost) const {
	ost << talk.getAudio() << endl;
}

void VideoPlayer::play(const Talk& talk, ostream& ost) const {
	AudioPlayer::play(talk, ost);

	ifstream inFile(talk.getVideoFile().c_str());
	if (!inFile.is_open()) {
		ost << "Error opening video file: " << talk.getVideoFile() << endl;
		return;
	}

	string line;
	while (getline(inFile, line)) {
		ost << line << endl;
	}
	inFile.close();
}