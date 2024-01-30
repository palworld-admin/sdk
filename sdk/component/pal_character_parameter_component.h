#pragma once

namespace palworld
{
	class APalCharacter;

	class UPalCharacterParameterComponent : public ue::UObject
	{
	public:
		uint8 pad_0000[0xA0]; // 0x0000(0xA0)

		void sub_dying_hp(const float sub_hp)
		{
			static UObject* fn = nullptr;
			if (!fn)
				find<ue::UFunction>("Function Pal.PalCharacterParameterComponent.SubDyingHP");
			struct
			{
				float sub_hp{};
			} params;

			params.sub_hp = sub_hp;
			process_event(this, fn, &params);
		}

		void set_trainer(APalCharacter* in_trainer)
		{
			static UObject* fn = nullptr;
			if (!fn)
				find<ue::UFunction>("Function Pal.PalCharacterParameterComponent.SetTrainer");

			struct
			{
				APalCharacter* in_trainer{};
			} params;

			params.in_trainer = in_trainer;
			process_event(this, fn, &params);
		}

		void revive_from_dying()
		{
			static UObject* fn = nullptr;
			if (!fn)
				find<ue::UFunction>("Function Pal.PalCharacterParameterComponent.ReviveFromDying");
			process_event(this, fn, nullptr);
		}
	};
}
