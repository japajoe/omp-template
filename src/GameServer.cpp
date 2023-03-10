#include <GameServer.hpp>

GameServer::~GameServer()
{
    core->getPlayers().getPlayerSpawnDispatcher().removeEventHandler(this);
    core->getPlayers().getPlayerConnectDispatcher().removeEventHandler(this);
    core->getPlayers().getPlayerStreamDispatcher().removeEventHandler(this);
    core->getPlayers().getPlayerTextDispatcher().removeEventHandler(this);
    core->getPlayers().getPlayerShotDispatcher().removeEventHandler(this);
    core->getPlayers().getPlayerChangeDispatcher().removeEventHandler(this);
    core->getPlayers().getPlayerDamageDispatcher().removeEventHandler(this);
    core->getPlayers().getPlayerClickDispatcher().removeEventHandler(this);
    core->getPlayers().getPlayerCheckDispatcher().removeEventHandler(this);
    core->getPlayers().getPlayerUpdateDispatcher().removeEventHandler(this);

    if (vehicles)
        vehicles->getEventDispatcher().removeEventHandler(this);

    if (actors)
        actors->getEventDispatcher().removeEventHandler(this);

    if (dialogs)
        dialogs->getEventDispatcher().removeEventHandler(this);

    core->getEventDispatcher().removeEventHandler(this);
}

void GameServer::onLoad(ICore *c)
{
    this->core = c;

    core->getPlayers().getPlayerSpawnDispatcher().addEventHandler(this);
    core->getPlayers().getPlayerConnectDispatcher().addEventHandler(this);
    core->getPlayers().getPlayerStreamDispatcher().addEventHandler(this);
    core->getPlayers().getPlayerTextDispatcher().addEventHandler(this);
    core->getPlayers().getPlayerShotDispatcher().addEventHandler(this);
    core->getPlayers().getPlayerChangeDispatcher().addEventHandler(this);
    core->getPlayers().getPlayerDamageDispatcher().addEventHandler(this);
    core->getPlayers().getPlayerClickDispatcher().addEventHandler(this);
    core->getPlayers().getPlayerCheckDispatcher().addEventHandler(this);
    core->getPlayers().getPlayerUpdateDispatcher().addEventHandler(this);

    core->getEventDispatcher().addEventHandler(this);

    core->printLn("GameServer component loaded");
}

void GameServer::onInit(IComponentList *components)
{
    vehicles = components->queryComponent<IVehiclesComponent>();
    actors = components->queryComponent<IActorsComponent>();
    dialogs = components->queryComponent<IDialogsComponent>();

    vehicles->getEventDispatcher().addEventHandler(this);
    actors->getEventDispatcher().addEventHandler(this);
    dialogs->getEventDispatcher().addEventHandler(this);
}

void GameServer::onTick(Microseconds elapsed, TimePoint now)
{
}

void GameServer::onReady()
{
}

void GameServer::onFree(IComponent *component)
{
}

void GameServer::free()
{
}

void GameServer::reset()
{
}

bool GameServer::onPlayerRequestSpawn(IPlayer &player)
{
    return true;
}

void GameServer::onPlayerSpawn(IPlayer &player)
{
}

void GameServer::onIncomingConnection(IPlayer &player, StringView ipAddress, unsigned short port)
{
}

void GameServer::onPlayerConnect(IPlayer &player)
{
    std::string text = std::string(player.getName()) + " (" + std::to_string(player.getID()) + ") has joined the server";
    core->getPlayers().sendClientMessageToAll(Colour::White(), text);
}

void GameServer::onPlayerDisconnect(IPlayer &player, PeerDisconnectReason reason)
{
    std::string text = std::string(player.getName()) + " (" + std::to_string(player.getID()) + ") has left the server";
    core->getPlayers().sendClientMessageToAll(Colour::White(), text);
}

void GameServer::onPlayerClientInit(IPlayer &player)
{
}

void GameServer::onPlayerStreamIn(IPlayer &player, IPlayer &forPlayer)
{
}

void GameServer::onPlayerStreamOut(IPlayer &player, IPlayer &forPlayer)
{
}

bool GameServer::onPlayerText(IPlayer &player, StringView message)
{
    return true;
}

bool GameServer::onPlayerCommandText(IPlayer &player, StringView message)
{
    return false;
}

bool GameServer::onPlayerShotMissed(IPlayer &player, const PlayerBulletData &bulletData)
{
    return true;
}

bool GameServer::onPlayerShotPlayer(IPlayer &player, IPlayer &target, const PlayerBulletData &bulletData)
{
    return true;
}

bool GameServer::onPlayerShotVehicle(IPlayer &player, IVehicle &target, const PlayerBulletData &bulletData)
{
    return true;
}

bool GameServer::onPlayerShotObject(IPlayer &player, IObject &target, const PlayerBulletData &bulletData)
{
    return true;
}

bool GameServer::onPlayerShotPlayerObject(IPlayer &player, IPlayerObject &target, const PlayerBulletData &bulletData)
{
    return true;
}

void GameServer::onPlayerScoreChange(IPlayer &player, int score)
{
}

void GameServer::onPlayerNameChange(IPlayer &player, StringView oldName)
{
}

void GameServer::onPlayerInteriorChange(IPlayer &player, unsigned newInterior, unsigned oldInterior)
{
}

void GameServer::onPlayerStateChange(IPlayer &player, PlayerState newState, PlayerState oldState)
{
}

void GameServer::onPlayerKeyStateChange(IPlayer &player, uint32_t newKeys, uint32_t oldKeys)
{
}

void GameServer::onPlayerDeath(IPlayer &player, IPlayer *killer, int reason)
{
}

void GameServer::onPlayerTakeDamage(IPlayer &player, IPlayer *from, float amount, unsigned weapon, BodyPart part)
{
}

void GameServer::onPlayerGiveDamage(IPlayer &player, IPlayer &to, float amount, unsigned weapon, BodyPart part)
{
}

void GameServer::onPlayerClickMap(IPlayer &player, Vector3 pos)
{
}

void GameServer::onPlayerClickPlayer(IPlayer &player, IPlayer &clicked, PlayerClickSource source)
{
}

void GameServer::onClientCheckResponse(IPlayer &player, int actionType, int address, int results)
{
}

bool GameServer::onPlayerUpdate(IPlayer &player, TimePoint now)
{
    return true;
}

void GameServer::onVehicleStreamIn(IVehicle &vehicle, IPlayer &player)
{
}

void GameServer::onVehicleStreamOut(IVehicle &vehicle, IPlayer &player)
{
}

void GameServer::onVehicleDeath(IVehicle &vehicle, IPlayer &player)
{
}

void GameServer::onPlayerEnterVehicle(IPlayer &player, IVehicle &vehicle, bool passenger)
{
}

void GameServer::onPlayerExitVehicle(IPlayer &player, IVehicle &vehicle)
{
}

void GameServer::onVehicleDamageStatusUpdate(IVehicle &vehicle, IPlayer &player)
{
}

bool GameServer::onVehiclePaintJob(IPlayer &player, IVehicle &vehicle, int paintJob)
{
    return true;
}

bool GameServer::onVehicleMod(IPlayer &player, IVehicle &vehicle, int component)
{
    return true;
}

bool GameServer::onVehicleRespray(IPlayer &player, IVehicle &vehicle, int colour1, int colour2)
{
    return true;
}

void GameServer::onEnterExitModShop(IPlayer &player, bool enterexit, int interiorID)
{
}

void GameServer::onVehicleSpawn(IVehicle &vehicle)
{
}

bool GameServer::onUnoccupiedVehicleUpdate(IVehicle &vehicle, IPlayer &player, UnoccupiedVehicleUpdate const updateData)
{
    return true;
}

bool GameServer::onTrailerUpdate(IPlayer &player, IVehicle &trailer)
{
    return true;
}

bool GameServer::onVehicleSirenStateChange(IPlayer &player, IVehicle &vehicle, uint8_t sirenState)
{
    return true;
}

void GameServer::onPlayerGiveDamageActor(IPlayer &player, IActor &actor, float amount, unsigned weapon, BodyPart part)
{
}

void GameServer::onActorStreamOut(IActor &actor, IPlayer &forPlayer)
{
}

void GameServer::onActorStreamIn(IActor &actor, IPlayer &forPlayer)
{
}

void GameServer::onDialogResponse(IPlayer &player, int dialogId, DialogResponse response, int listItem, StringView inputText)
{
}