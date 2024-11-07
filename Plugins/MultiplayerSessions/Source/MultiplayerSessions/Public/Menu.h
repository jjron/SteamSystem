// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Interfaces/OnlineSessionInterface.h"
#include "Menu.generated.h"

/**
 * 
 */
UCLASS()
class MULTIPLAYERSESSIONS_API UMenu : public UUserWidget
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable)
	void MenuSetup(int32 NumberOfPublicConnections = 4, FString TypeOfMatch = FString(TEXT("FreeForAll")), FString LobbyPath = FString(TEXT("/Game/ThirdPerson/Maps/Lobby")));

	UFUNCTION(BlueprintCallable)
	void MenuLobby(FString MatchMapPath = FString(TEXT("/Game/ThirdPerson/Maps/MatchLevel")));
	
protected:

	virtual bool Initialize() override;
	virtual void NativeDestruct() override;

	// Callbacks for custom delegates on MultiplayerSessionsSubsystem
	UFUNCTION()
	void OnCreateSession(bool bWasSuccessful);
	void OnFindSessions(const TArray<FOnlineSessionSearchResult>& SessionResults, bool bWasSuccessful);
	void OnJoinSession(EOnJoinSessionCompleteResult::Type Result);
	UFUNCTION()
	void OnDestroySession(bool bWasSuccessful);
	UFUNCTION()
	void OnStartSession(bool bWasSuccessful);
	
private:
	UPROPERTY(meta=(BindWidget))
	class UButton* HostButton;

	UPROPERTY(meta=(BindWidget))
	UButton* JoinButton;

	UPROPERTY(meta=(BindWidget))
	UButton* StartButton;
	
	UFUNCTION()
	void HostButtonClicked();

	UFUNCTION()
	void JoinButtonClicked();

	UFUNCTION()
	void StartButtonClicked();
	
	void MenuTeardown();
	
	class UMultiplayerSessionsSubsystem* MultiplayerSessionsSubsystem;

	int32 NumPublicConnections{4};
	FString MatchType{TEXT("FreeForAll")};
	FString PathToLobby{TEXT("")};
	FString PathToMatchMap{TEXT("")};
};
