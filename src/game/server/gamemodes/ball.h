#ifndef GAME_SERVER_GAMEMODES_BALL_H
#define GAME_SERVER_GAMEMODES_BALL_H
#include <game/server/gamecontroller.h>

class CGameControllerBALL : public IGameController
{
public:
	CGameControllerBALL(class CGameContext *pGameServer);

	// event
	virtual int OnCharacterDeath(class CCharacter *pVictim, class CPlayer *pKiller, int Weapon);
};

#endif
