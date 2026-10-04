#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include "Talk.h"

using namespace std;

class Player {
	public:
		virtual ~Player() {}
		virtual void play(const Talk& talk, ostream& ost) const = 0;
};

class AudioPlayer : public Player {
	public:
		virtual void play(const Talk& talk, ostream& ost) const;
};

class VideoPlayer : public AudioPlayer {
	public:
		virtual void play(const Talk& talk, ostream& ost) const;
};

#endif