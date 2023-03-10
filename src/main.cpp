#include <GameServer.hpp>

// Automatically called when the compiled binary is loaded.
COMPONENT_ENTRY_POINT()
{
	return new GameServer();
}