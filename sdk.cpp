#include <palworld/sdk.h>
#include <palworld/hooks.h>

palworld::Sdk::Sdk(ConfigFile* config)
{
	LOG("Initializing SDK Offsets");
	// Set the module base address
	ue::offsets::UeAddress::set_module(
		reinterpret_cast<std::uintptr_t>(LI_FN(GetModuleHandleA)(nullptr))
	);
	LOG(_("Module: 0x%llX"),
	    ue::offsets::UeAddress::get_module());

	// Set the process event index
	ue::offsets::UeAddress::set_process_event_index(0x4C);

	// Get the global name pool
	ue::offsets::UeAddress::set_gname(
		_("48 8D 0D ? ? ? ? E8 ? ? ? ? 4C 8B C0 C6 05 ? ? ? ? 01 8B D3 0F B7 C3 89 44 24 ?")
	);
	LOG(_("GName: 0x%llX"),
	    ue::offsets::UeAddress::get_gname());

	// Get the global world
	ue::offsets::UeAddress::set_gworld(
		_("48 8B 05 ? ? ? ? 4C 8D 44 24 ? 48 8D 54 24 ? 48 89 44 24 ?")
	);
	LOG(_("GWorld: 0x%llX"),
	    ue::offsets::UeAddress::get_gworld());

	// Get the global object
	ue::offsets::UeAddress::set_gobject(
		_("48 8B 05 ? ? ? ? 48 8B 14 C8 49 63 C0 48 8D 0C 40 48 39 34 CA")
	);
	LOG(_("GObject: 0x%llX"),
	    ue::offsets::UeAddress::get_gobject());

	// Get the static construct object
	ue::offsets::UeAddress::set_static_construct_object(
		_("48 89 5C 24 10 48 89 74 24 18 55 57 41 54 41 56 41 57 48 8D AC 24 30 FE")
	);
	LOG(_("StaticConstructObjectInternal: 0x%llX"),
	    ue::offsets::UeAddress::get_static_construct_object());

	hooks::broadcast_msg_addr = ue::utils::pattern_scan(
		ue::memory::module,
		"40 55 56 41 57 48 8D 6C 24 B9 48 81 EC D0 00 00 00 48 8B F2");
	LOG(_("BroadcastMsg: 0x%llX"),
	    hooks::broadcast_msg_addr);
}

