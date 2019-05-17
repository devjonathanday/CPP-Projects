#pragma once
struct ServerInfo
{
	int regionID;             // region
	int currentPlayerCount;   // current player count
	int maxPlayers;           // max player count
	int ping;                 // ping
};

class ServerBrowserService
{
private:
	// An array of all servers registered with the system.


	ServerInfo servers[50]; // note: this is hard-coded for 50 servers

							// A count of all servers currently registered.
	int serverCount = 0;
public:
	// Registers a server with the service
	bool registerServer(ServerInfo newServer);

	// Copies server entries into the given array.
	// Returns the total number of servers provided to the array.
	int getServers(ServerInfo * dstArray, size_t dstSize, int maxServers, int pingLimit, int regionSpecifier, bool allowEmpty, bool allowFull);
	void printServers(ServerInfo serverArray[]);
};