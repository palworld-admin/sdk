#include <palworld/sdk.h>
#include <palworld/hooks.h>

void palworld::hooks::broadcast_chat_message::hook(__int64 a1, FPalChatMessage* chat_message)
{
	for (const auto callback : callbacks)
	{
		callback->call(a1, chat_message);
	}
	original(a1, chat_message);
}
