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

		// Reference:
		// https://stackoverflow.com/a/3999597
		static std::string to_utf8(const std::wstring& wide_string)
		{
			if (wide_string.empty()) return std::string();

			const int size_needed = WideCharToMultiByte(CP_UTF8,
			                                            0, &wide_string[0], (int)wide_string.size(),
			                                            nullptr,
			                                            0, nullptr, nullptr);
			std::string strTo(size_needed, 0);
			WideCharToMultiByte(CP_UTF8, 0, &wide_string[0],
			                    (int)wide_string.size(), &strTo[0],
			                    size_needed, nullptr,
			                    nullptr);

			return strTo;
		}
	};
}
