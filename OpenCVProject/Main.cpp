#include "ATCVideoEngine/ATCVideoEngine.h"
#define Main main





int Main()
{
	string VideoFileName("Video\\LOVE.mp4");
	
	ATA->PlayMusics(VideoFileName);

	ATV->LoadVideo(VideoFileName);
	ATV->PlayVideo(VideoFileName);

	system("pause");
	return 0;
}