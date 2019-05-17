#include "ServerBrowserService.h"
#include<iostream>
#include<algorithm>

using namespace std;

bool ServerBrowserService::registerServer(ServerInfo newServer)
{
	if (serverCount < 50)
	{
		servers[serverCount].regionID = newServer.regionID;
		servers[serverCount].currentPlayerCount = newServer.currentPlayerCount;
		servers[serverCount].maxPlayers = newServer.maxPlayers;
		servers[serverCount].ping = newServer.ping;
		serverCount++;
		return true;
	}
	else
	{
		cout << "Cannot create new server (limit reached)." << endl;
		return false;
	}
}
int ServerBrowserService::getServers(ServerInfo * dstArray, size_t dstSize, int maxServers, int pingLimit, int regionSpecifier, bool allowEmpty, bool allowFull)
{
	int count = 0;

	
	for (int i = 0; i < min(maxServers, serverCount); i++)
	{
		if (servers[i].ping < pingLimit && servers[i].regionID == regionSpecifier)
		{
			if ((!allowEmpty && servers[i].currentPlayerCount > 0) || (!allowFull && servers[i].currentPlayerCount < servers[i].maxPlayers) || allowEmpty || allowFull)
			{
				count++;
				dstArray[i].regionID = servers[i].regionID;
				dstArray[i].currentPlayerCount = servers[i].currentPlayerCount;
				dstArray[i].maxPlayers = servers[i].maxPlayers;
				dstArray[i].ping = servers[i].ping;

				cout << "\nServer " << i + 1 << ":" << endl;
				cout << "Region ID: " << dstArray[i].regionID << endl;
				cout << "Players: " << dstArray[i].currentPlayerCount << "/" << dstArray[i].maxPlayers << endl;
				cout << "Ping: " << dstArray[i].ping << endl;
			}
		}
	}
	return count;
}
void ServerBrowserService::printServers(ServerInfo serverArray[])
{
	/*for (int i = 0; i < serverCount; i++)
	{
		cout << "\nServer " << i+1 << ":" << endl;
		cout << "Region ID: " << serverArray[i].regionID << endl;
		cout << "Players: " << serverArray[i].currentPlayerCount << "/" << serverArray[i].maxPlayers << endl;
		cout << "Ping: " << serverArray[i].ping << endl;
	}*/
	system("pause");
}