#include <palworld/sdk.h>
#include <palworld/hooks.h>

void palworld::hooks::process_event::hook(ue::UObject* object, ue::UObject* function, void* params)
{
	for (const auto callback : callbacks)
	{
		callback->call(object, function, params);
	}
	original(object, function, params);
}
