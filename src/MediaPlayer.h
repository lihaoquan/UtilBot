#pragma once

#include <windows.h>
#include <mmsystem.h>
#include <string>

namespace Media {

	const LPCWSTR NOTIFICATION_SOUND = L"D://assets/notification.wav";

	class MediaPlayer
	{
	private:
		MediaPlayer();
	public:
		static void PlayMedia(LPCWSTR media);
	};
}