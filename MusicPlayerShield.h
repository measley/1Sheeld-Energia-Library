#ifndef MusicPlayerShield_h
#define MusicPlayerShield_h

#define STOP 0x01
#define PLAY 0x02
#define PAUSE 0x03
#define PREVIOUS 0x04
#define NEXT 0x05
#define SEEK_FORWARD 0x06
#define SEEK_BACKWARD 0x07
#define VOLUME 		  0x08

class MusicPlayerShieldClass 
{
private:

public:
	void stop();
	void play();
	void pause();
	void previous();
	void next();
	void seekForward(byte );
	void seekBackward(byte );
	void setVolume(byte );
};

extern MusicPlayerShieldClass MusicPlayer;
#endif