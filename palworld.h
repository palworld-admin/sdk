#pragma once
#include "hooks.h"

namespace palworld
{
	class Sdk
	{
	public:
		explicit Sdk(ConfigFile* config);

		~Sdk()
		{
			// Delete all callbacks
			for (const auto callback : hooks::process_event::callbacks)
			{
				delete callback;
			}

			for (const auto callback : hooks::broadcast_chat_message::callbacks)
			{
				delete callback;
			}

			for (const auto callback : hooks::static_construct_object::pre_callbacks)
			{
				delete callback;
			}

			for (const auto callback : hooks::static_construct_object::post_callbacks)
			{
				delete callback;
			}

			hooks::process_event::callbacks.clear();
			hooks::broadcast_chat_message::callbacks.clear();
			hooks::static_construct_object::pre_callbacks.clear();
			hooks::static_construct_object::post_callbacks.clear();
		}

		static void add_chat_callback(HookCallback* callback)
		{
			hooks::broadcast_chat_message::callbacks.push_back(callback);
		}

		static void add_process_event_callback(HookCallback* callback)
		{
			hooks::process_event::callbacks.push_back(callback);
		}

		static void add_pre_static_construct_object_callback(HookCallback* callback)
		{
			hooks::static_construct_object::pre_callbacks.push_back(callback);
		}

		static void add_post_static_construct_object_callback(HookCallback* callback)
		{
			hooks::static_construct_object::post_callbacks.push_back(callback);
		}
	};
}
