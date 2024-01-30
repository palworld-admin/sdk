#pragma once


namespace palworld
{
	class UPalUtility : public ue::UObject
	{
		void SendSystemToPlayerChat(UObject* WorldContextObject, const ue::FString& Message,
		                            struct FGuid& ReceiverPlayerUId);

		bool LotteryInt(int32 ProbabilityPercentage);

		bool LotteryFloat(float ProbabilityPercentage);

		void SendSystemAnnounce(UObject* WorldContextObject, const ue::FString& Message);

		bool IsPalMonster(ue::engine::AActor* Actor);

		bool IsPalCharacter(ue::engine::AActor* Actor);

		bool IsEnemy(ue::engine::AActor* ActorA, ue::engine::AActor* ActorB);

		APalPlayerCharacter* GetTrainerPlayer(class AActor* Monster);

		int32 GetPlayerEquipmentHP(UObject* WorldContextObject, const FGuid& PlayerUId);

		int32 GetPlayerEquipmentDefense(UObject* WorldContextObject, const FGuid& PlayerUId);

		void SetPassword(UObject* WorldContextObject, const ue::FString& Password);

		void PalCaptureSuccess(APalPlayerCharacter* AttackerPlayer, APalCharacter* Monster);

		void GiveExpToAroundPlayerCharacter(UObject* WorldContextObject, ue::FVector& Center, float Radius,
		                                    float Exp, bool bCallDelegate);

		void GiveExpToAroundCharacter(UObject* WorldContextObject, ue::FVector& Center, float Radius,
		                              float Exp, ue::TSubclassOf<APalCharacter> CharacterClass, bool bCallDelegate);

		ue::FString GetServerWorldDisplayName(UObject* WorldContextObject);

		void Alert(UObject* WorldContextObject, ue::FText Message);

		void KillCharacter_NotDamageToEquipItem(class APalCharacter* Character);
	};
}
