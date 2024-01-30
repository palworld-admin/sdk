#include <palworld/sdk.h>
#include <palworld/hooks.h>

void palworld::hooks::static_construct_object::hook(
	const ue::engine::FStaticConstructObjectParameters& params)
{
	for (const auto callback : pre_callbacks)
	{
		callback->call(params);
	}

	original(params);

	for (const auto callback : post_callbacks)
	{
		callback->call(params);
	}

}
