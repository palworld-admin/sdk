#pragma once

namespace palworld::hooks
{
	bool init();
	bool remove();

	inline uintptr_t broadcast_msg_addr;

	namespace process_event
	{
		inline std::vector<HookCallback*> callbacks = std::vector<HookCallback*>();

		using fn = void(__thiscall*)(ue::UObject*, ue::UObject*, void*);
		inline fn original;
		void __stdcall hook(ue::UObject* object, ue::UObject* function, void* params);
	}


	namespace broadcast_chat_message
	{
		inline std::vector<HookCallback*> callbacks = std::vector<HookCallback*>();

		using fn = void(__thiscall*)(__int64, FPalChatMessage*);
		inline fn original;
		void __stdcall hook(__int64 a1, FPalChatMessage* chat_message);
	}

	namespace static_construct_object
	{
		inline std::vector<HookCallback*> pre_callbacks  = std::vector<HookCallback*>();
		inline std::vector<HookCallback*> post_callbacks = std::vector<HookCallback*>();

		using fn = void(__thiscall*)(ue::engine::FStaticConstructObjectParameters);
		inline fn original;
		void __stdcall hook(const ue::engine::FStaticConstructObjectParameters& params);
	}
}
