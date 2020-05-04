#include "MediaPlayer.h"

namespace Media {
	void MediaPlayer::PlayMedia(LPCWSTR media)
	{
		PlaySound(media, NULL, SND_FILENAME | SND_ASYNC);
		getchar();
	}
}