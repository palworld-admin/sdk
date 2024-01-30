#pragma once

namespace palworld
{
	// 0x48 (0x48 - 0x0)
	// ScriptStruct Pal.PalChatMessage
	struct FPalChatMessage
	{
		uint8 Category;
		ue::FString Sender;
		ue::FGuid SenderPlayerUId;
		ue::FString Message;
		ue::FGuid ReceiverPlayerUId;
	};

	static_assert(sizeof(FPalChatMessage) == 0x48);
}
