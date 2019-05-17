#pragma once

class Television
{
private:
	int currentChannel = 5;
	int currentVolume = 30;

public:
	void increaseVolume();
	void decreaseVolume();    // decreases the volume by one

	int volume();             // returns the current volume

	void increaseChannel();   // increases the channel num by one
	void decreaseChannel();   // decreases the channel num by one

	int channel();            // returns the current channel
};