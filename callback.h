#pragma once
#include "sdk/ue.h"

namespace palworld
{
	class HookCallback
	{
	public:
		virtual ~HookCallback() = default;
		virtual void call(ue::UObject* object, ue::UObject* function, void* params) {};
		virtual void call(__int64 a1, FPalChatMessage* chat_message) {};
		virtual void call(ue::engine::FStaticConstructObjectParameters params) {};
		virtual void call(ue::UObject* result) {};
		virtual void call(void* result) {};
	};
}
