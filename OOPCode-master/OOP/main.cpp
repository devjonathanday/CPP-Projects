#include<iostream>
#include "Television.h"
#include "PiggyBank.h"
#include "ServerBrowserService.h"

using namespace std;

int main()
{
	bool gameLoop = false;
	int userInput = 0;
	/*
	Television telly;
	// ^ This is the only time the variables are accessed. The variables are set indirectly through the functions below.

	//Television game loop
	while (!gameLoop)
	{
		system("cls");
		int userInput;
		cout << "What do you want to do?\n" << endl;
		cout << "Volume: " << telly.volume() << endl;
		cout << "Channel: " << telly.channel() << "\n" << endl;
		cout << "[1] Increase Volume\n[2] Decrease Volume\n[3] Increase Channel\n[4] Decrease Channel\n\n[5] Turn TV off" << endl;
		cin >> userInput;
		switch (userInput)
		{
		case 1:
			telly.increaseVolume();
			break;
		case 2:
			telly.decreaseVolume();
			break;
		case 3:
			telly.increaseChannel();
			break;
		case 4:
			telly.decreaseChannel();
			break;
		case 5:
			gameLoop = true;
			break;
		}
	}
	cout << "The screen fades away and you see your sad reflection. Awkward." << endl;
	system("pause");

	system("cls");
	gameLoop = false;
	//Piggy bank game loop
	int userInput;
	DigitalPiggyBank piggy;
	cout << "You now have a digital piggy bank!" << endl;
	system("pause");
	while (!gameLoop)
	{
		system("cls");
		cout << "Balance: $" << piggy.balance() << endl;
		cout << "[1] Deposit a dollar\n[2] Break piggy bank (withdraw)\n[3] Leave" << endl;
		cin >> userInput;
		switch (userInput)
		{
		case 1:
			piggy.deposit(1);
			break;
		case 2:
			system("cls");
			cout << "You took $" << piggy.balance() << " out of the piggy bank!" << endl;
			piggy.withdraw();
			system("pause");
			break;
		case 3:
			gameLoop = true;
			break;
		}
	}
	system("cls");
	*/
	gameLoop = false;
	//Servers loop
	ServerBrowserService network;

	while (!gameLoop)
	{
		bool end = false;
		int maxServers = 50;
		int pingLimit = 100;
		int regionSpecifier = 1;
		bool allowEmpty = true;
		bool allowFull = true;
		userInput = 0;
		ServerInfo newServer;
		ServerInfo dstArray[50];
		while (!end)
		{
			system("cls");
			//cout << "Servers available: " << 50 - network.getServers << endl;
			cout << "[1] New Server\n[2] Print the current servers with these parameters\n\nSearch Filters:" << endl;
			cout << "[3] Max Servers: " << maxServers << endl;
			cout << "[4] Ping Limit: " << pingLimit << endl;
			cout << "[5] Region Specifier: " << regionSpecifier << endl;
			if (allowEmpty)
			{
				cout << "[6] Allow Empty: [Allow] Block" << endl;
			}
			else
			{
				cout << "[6] Allow Empty:  Allow [Block]" << endl;
			}
			if (allowFull)
			{
				cout << "[7] Allow Full: [Allow] Block" << endl;
			}
			else
			{
				cout << "[7] Allow Full:  Allow [Block]" << endl;
			}
			cin >> userInput;
			switch (userInput)
			{
			case 1:
				cout << "Enter the region ID for the new server. ";
				cin >> newServer.regionID;
				cout << "Enter the player count for the new server. ";
				cin >> newServer.currentPlayerCount;
				cout << "Enter the maximum number of players. ";
				cin >> newServer.maxPlayers;
				cout << "Enter the ping for the new server. ";
				cin >> newServer.ping;
				network.registerServer(newServer);
				break;
			case 2:
				network.getServers(dstArray, 50, maxServers, pingLimit, regionSpecifier, allowEmpty, allowFull);
				system("pause");
				//network.printServers(dstArray);
				break;
			case 3:
				cout << "Enter the limit for how many servers to look for." << endl;
				cin >> maxServers;
				break;
			case 4:
				cout << "Enter the ping limit for the search." << endl;
				cin >> pingLimit;
				break;
			case 5:
				cout << "Enter the region to search for." << endl;
				cin >> regionSpecifier;
				break;
			case 6:
				allowEmpty = !allowEmpty;
				break;
			case 7:
				allowFull = !allowFull;
				break;
			}
		}
	}
}