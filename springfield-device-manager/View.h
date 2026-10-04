#ifndef VIEW_H
#define VIEW_H

#include <iostream>
#include <string>
#include <vector>
#include "Conference.h"
#include "Player.h"

using namespace std;

class View {

	public:
		// constructors
		View();

		void menu(vector<string>&, int& choice);
		void printAllConferences(const List<Conference*>& conferences);
		void conferenceMenu(const List<Conference*>& conferences, int& choice);
		void printConference(const Conference*);
		void promptSpeaker(string& speaker);
		void promptKeyword(string& keyword);
		void printPlaylist(List<Talk*>&);
		void playPlaylist(List<Talk*>&);

		void promptVideo();
		void toggleVideo(bool);

	private:
		AudioPlayer audioPlayer;
		VideoPlayer videoPlayer;
		Player* player;
};

#endif