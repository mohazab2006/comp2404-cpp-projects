#include "View.h"
#include <limits>
#include <vector>

View::View() {
	player = &audioPlayer;
}

void View::menu(vector<string>& menu, int& choice)
{
	cout << endl;
	cout << "Please make a selection:" << endl << endl;
	for (int i = 0; i < menu.size(); ++i) {
		cout << "  (" << i + 1 << ") " << menu[i] << endl;
	}
	cout << "  (0) Exit" << endl << endl;

	cout << "Enter your selection: ";
	cin >> choice;
	if (choice == 0)
		return;

	while (choice < 0 || choice > menu.size()) {
		cout << "Enter your selection: ";
		cin >> choice;
	}
}

void View::printAllConferences(const List<Conference*>& conferences) {
	for (int i = 0; i < conferences.getSize(); ++i) {
		cout << i + 1 << ": " << *conferences[i] << endl;
	}
}

void View::printConference(const Conference* conference) {
	conference->printWithTalks(cout);
}

void View::conferenceMenu(const List<Conference*>& conferences, int& choice) {
	int numOptions = conferences.getSize();

	printAllConferences(conferences);

	cout << endl;
	cout << "Choose an conference" << endl;
	cout << "or select (0) to exit" << endl;

	cout << "Enter your selection: ";
	cin >> choice;
	if (choice == 0)
		return;

	while (choice < 0 || choice > numOptions) {
		cout << "Enter your selection: ";
		cin >> choice;
	}
	--choice;
}

void View::promptSpeaker(string& speaker) {
	cout << "Select number of speaker:  " << endl;
	vector<string> allSpeakers = {"Joe Smith", "Jane Doe", "Bruce Wayne", "Darth Vader", "Ada Lovelace"};
	for (int i = 0; i < allSpeakers.size(); ++i) {
		cout << "  (" << i + 1 << ") " << allSpeakers[i] << endl;
	}
	cout << "Enter your selection: ";
	int choice;
	cin >> choice;
	while (choice < 1 || choice > allSpeakers.size()) {
		cout << "Enter your selection: ";
		cin >> choice;
	}
	speaker = allSpeakers[choice - 1];
}

void View::promptKeyword(string& keyword) {
	cout << "Select number of keyword:  " << endl;
	vector<string> allKeywords = {
		"C++",
		"memory management",
		"allocators",
		"templates",
		"generic programming",
		"concurrency",
		"profiling",
		"performance optimization",
		"AI",
		"machine learning",
		"deep learning",
		"neural networks",
		"systems",
		"garbage collection",
		"robotics"
	};

	for (int i = 0; i < allKeywords.size(); ++i) {
		cout << "  (" << i + 1 << ") " << allKeywords[i] << endl;
	}
	cout << "Enter your selection: ";
	int choice;
	cin >> choice;
	while (choice < 1 || choice > allKeywords.size()) {
		cout << "Enter your selection: ";
		cin >> choice;
	}
	keyword = allKeywords[choice - 1];
}

void View::printPlaylist(List<Talk*>& talk) {
	for (int i = 0; i < talk.getSize(); ++i) {
		cout << *talk[i] << endl;
	}
}

void View::playPlaylist(List<Talk*>& talk) {
	cout << "Playing playlist size " << talk.getSize() << endl;
	for (int i = 0; i < talk.getSize(); ++i) {
		cout << endl << *talk[i] << endl;
		player->play(*talk[i], cout);
		cout << endl;
	}
}

void View::promptVideo() {
	int numOptions = 2;
	int choice = -1;

	cout << endl;
	cout << "  (0) Exit (no change)" << endl;
	cout << "  (1) Audio player only" << endl;
	cout << "  (2) Audio and Video player" << endl << endl;

	while (choice < 0 || choice > numOptions) {
		cout << "Enter your selection: ";
		cin >> choice;
	}

	if (choice == 0) {
		return;
	}

	toggleVideo(choice == 2);
}

void View::toggleVideo(bool video) {
	if (video) {
		player = &videoPlayer;
	} else {
		player = &audioPlayer;
	}
}