#include <palworld/sdk.h>

// MinHook
#include <MinHook.h>

/**
 * \brief Palworld SDK Hooking Function
 */
bool palworld::hooks::init()
{
	if (MH_Initialize() != MH_OK)
	{
		LOG(_("failed to initialize min_hook"));
		return false;
	}

	if (MH_CreateHook(reinterpret_cast<void*>(
		                  ue::offsets::UeAddress::get_static_construct_object()),
	                  &static_construct_object::hook,
	                  reinterpret_cast<void**>(&static_construct_object::original)) != MH_OK)
	{
		LOG("failed to hooks StaticConstructObject_Internal");
		return false;
	}

	if (MH_CreateHook(reinterpret_cast<void*>(broadcast_msg_addr),
	                  &broadcast_chat_message::hook,
	                  reinterpret_cast<void**>(&broadcast_chat_message::original)) != MH_OK)
	{
		LOG(_("failed to hook message_broadcast"));
		return false;
	}

	if (MH_EnableHook(nullptr) != MH_OK)
	{
		LOG(_("failed to hooks enable hooks"));
		return false;
	}

	return true;
}

bool palworld::hooks::remove()
{
	if (MH_DisableHook(nullptr) != MH_OK)
	{
		LOG(_("failed to disable hooks"));
		return false;
	}

	if (MH_RemoveHook(reinterpret_cast<void*>(broadcast_msg_addr)) != MH_OK)
	{
		LOG(_("failed to remove message_broadcast hook"));
		return false;
	}

	if (MH_RemoveHook(reinterpret_cast<void*>(
		ue::offsets::UeAddress::get_static_construct_object())) != MH_OK)
	{
		LOG(_("failed to remove StaticConstructObject_Internal hook"));
		return false;
	}

	if (MH_Uninitialize() != MH_OK)
	{
		LOG(_("failed to uninitialize min_hook"));
		return false;
	}

	return true;
}
