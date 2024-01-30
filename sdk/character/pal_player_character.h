#pragma once


namespace palworld
{
	// 0x1D8 (0x9D0 - 0x7F8)
	// Class Pal.PalPlayerCharacter
	class APalPlayerCharacter : public APalCharacter
	{
		bool IsIdle();
		bool IsGuildMaster();
		bool IsGliding();

		void CallReviveDelegate();
		void CallRespawnDelegate();
		void CallMoveToRespawnLocationDelegate(ue::FVector& Location);
	};
}
