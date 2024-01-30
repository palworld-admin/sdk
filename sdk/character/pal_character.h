#pragma once

namespace palworld
{
	// 0x1E0 (0x7F8 - 0x618)
	// Class Pal.PalCharacter
	class APalCharacter : public ue::engine::ACharacter
	{
	public:
		uint8 pad_0000[0x10];                                                           // 0x618(0x10)
		UPalCharacterParameterComponent* CharacterParameterComponent;                   // 0x628(0x8)

		// TODO: implement the rest of component
		class UPalStaticCharacterParameterComponent* StaticCharacterParameterComponent; // 0x630(0x8)
		class UPalDamageReactionComponent* DamageReactionComponent;                     // 0x638(0x8)
		class UPalStatusComponent* StatusComponent;                                     //  0x640(0x8)
	};
}
