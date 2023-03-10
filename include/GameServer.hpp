#ifndef GAMESERVER_HPP
#define GAMESERVER_HPP

#include <sdk.hpp>
#include <Server/Components/Vehicles/vehicles.hpp>
#include <Server/Components/Actors/actors.hpp>
#include <Server/Components/Dialogs/dialogs.hpp>

class GameServer :
	public IComponent, 
	public CoreEventHandler,
	public PlayerSpawnEventHandler,
	public PlayerConnectEventHandler,
	public PlayerStreamEventHandler,
	public PlayerTextEventHandler,
	public PlayerShotEventHandler,
	public PlayerChangeEventHandler,
	public PlayerDamageEventHandler,
	public PlayerClickEventHandler,
	public PlayerCheckEventHandler,
	public PlayerUpdateEventHandler,
	public VehicleEventHandler,
	public ActorEventHandler,
	public PlayerDialogEventHandler
{
private:
	// Hold a reference to the main server core.
	ICore* core = nullptr;
	IVehiclesComponent* vehicles = nullptr;
	IActorsComponent* actors = nullptr;
	IDialogsComponent* dialogs = nullptr;

public:
	// Visit https://open.mp/uid to generate a new unique ID.
	PROVIDE_UID(0x8B5F17A995337F9B);

	// When this component is destroyed we need to tell any linked components this it is gone.
	~GameServer();

	// Implement the main component API.
    StringView componentName() const override
	{
		return "GameServer";
	}
    SemanticVersion componentVersion() const override
	{
		return SemanticVersion(1, 0, 0, 0);
	}
    void onLoad(ICore *c) override;
    void onInit(IComponentList *components) override;
    void onTick(Microseconds elapsed, TimePoint now) override;
    void onReady() override;
    void onFree(IComponent* component) override;
	void free() override;
	void reset() override;
	
	//Player callbacks
	bool onPlayerRequestSpawn(IPlayer& player) override; 
	void onPlayerSpawn(IPlayer& player) override; 
	void onIncomingConnection(IPlayer& player, StringView ipAddress, unsigned short port) override; 
	void onPlayerConnect(IPlayer& player) override; 
	void onPlayerDisconnect(IPlayer& player, PeerDisconnectReason reason) override; 
	void onPlayerClientInit(IPlayer& player) override; 
	void onPlayerStreamIn(IPlayer& player, IPlayer& forPlayer) override; 
	void onPlayerStreamOut(IPlayer& player, IPlayer& forPlayer) override; 
	bool onPlayerText(IPlayer& player, StringView message) override; 
	bool onPlayerCommandText(IPlayer& player, StringView message) override; 
	bool onPlayerShotMissed(IPlayer& player, const PlayerBulletData& bulletData) override; 
	bool onPlayerShotPlayer(IPlayer& player, IPlayer& target, const PlayerBulletData& bulletData) override; 
	bool onPlayerShotVehicle(IPlayer& player, IVehicle& target, const PlayerBulletData& bulletData) override; 
	bool onPlayerShotObject(IPlayer& player, IObject& target, const PlayerBulletData& bulletData) override; 
	bool onPlayerShotPlayerObject(IPlayer& player, IPlayerObject& target, const PlayerBulletData& bulletData) override; 
	void onPlayerScoreChange(IPlayer& player, int score) override; 
	void onPlayerNameChange(IPlayer& player, StringView oldName) override; 
	void onPlayerInteriorChange(IPlayer& player, unsigned newInterior, unsigned oldInterior) override; 
	void onPlayerStateChange(IPlayer& player, PlayerState newState, PlayerState oldState) override; 
	void onPlayerKeyStateChange(IPlayer& player, uint32_t newKeys, uint32_t oldKeys) override; 
	void onPlayerDeath(IPlayer& player, IPlayer* killer, int reason) override; 
	void onPlayerTakeDamage(IPlayer& player, IPlayer* from, float amount, unsigned weapon, BodyPart part) override; 
	void onPlayerGiveDamage(IPlayer& player, IPlayer& to, float amount, unsigned weapon, BodyPart part) override; 
	void onPlayerClickMap(IPlayer& player, Vector3 pos) override; 
	void onPlayerClickPlayer(IPlayer& player, IPlayer& clicked, PlayerClickSource source) override; 
	void onClientCheckResponse(IPlayer& player, int actionType, int address, int results) override; 
	bool onPlayerUpdate(IPlayer& player, TimePoint now) override;
	
	//Vehicle callbacks
	void onVehicleStreamIn(IVehicle& vehicle, IPlayer& player) override;
	void onVehicleStreamOut(IVehicle& vehicle, IPlayer& player) override;
	void onVehicleDeath(IVehicle& vehicle, IPlayer& player) override;
	void onPlayerEnterVehicle(IPlayer& player, IVehicle& vehicle, bool passenger) override;
	void onPlayerExitVehicle(IPlayer& player, IVehicle& vehicle) override;
	void onVehicleDamageStatusUpdate(IVehicle& vehicle, IPlayer& player) override;
	bool onVehiclePaintJob(IPlayer& player, IVehicle& vehicle, int paintJob) override;
	bool onVehicleMod(IPlayer& player, IVehicle& vehicle, int component) override;
	bool onVehicleRespray(IPlayer& player, IVehicle& vehicle, int colour1, int colour2) override;
	void onEnterExitModShop(IPlayer& player, bool enterexit, int interiorID) override;
	void onVehicleSpawn(IVehicle& vehicle) override;
	bool onUnoccupiedVehicleUpdate(IVehicle& vehicle, IPlayer& player, UnoccupiedVehicleUpdate const updateData) override;
	bool onTrailerUpdate(IPlayer& player, IVehicle& trailer) override;
	bool onVehicleSirenStateChange(IPlayer& player, IVehicle& vehicle, uint8_t sirenState) override;
	
	//Actor callbacks
	void onPlayerGiveDamageActor(IPlayer& player, IActor& actor, float amount, unsigned weapon, BodyPart part) override;
	void onActorStreamOut(IActor& actor, IPlayer& forPlayer) override;
	void onActorStreamIn(IActor& actor, IPlayer& forPlayer) override;

	//Dialog callbacks
	void onDialogResponse(IPlayer &player, int dialogId, DialogResponse response, int listItem, StringView inputText) override;
};

#endif