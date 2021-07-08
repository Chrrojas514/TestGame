#pragma once

#include "HunterCentralUtility.h"

namespace Hunter
{
	enum class EventType
	{
		PressKey,
		ReleaseKey,
		CloseWindow,
		ResizeWindow,
		MinimizeWindow,
		MaximizeWindow
	};

	class HUNTER_API Event
	{
	public:
		EventType GetEventType() const;

	private:
		EventType type;
	};
}