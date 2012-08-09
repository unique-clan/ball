#include <engine/shared/config.h>

#include <game/server/entities/character.h>
#include <game/server/gamecontext.h>
#include <game/server/player.h>
#include "ball.h"

CGameControllerBALL::CGameControllerBALL(class CGameContext *pGameServer) : IGameController(pGameServer)
{
	m_pGameType = "BALL";
	m_GameFlags = GAMEFLAG_TEAMS;
	ball_game_state = IGameController::BALL_GAME_RESPAWN;
}

// event
int CGameControllerBALL::OnCharacterDeath(class CCharacter *pVictim, class CPlayer *pKiller, int Weapon)
{
	while (pVictim->m_aWeapons[WEAPON_SHOTGUN].m_Ammo) {
		pVictim->FireWeapon(true);
	}

	pVictim->GetPlayer()->m_RespawnTick = max(pVictim->GetPlayer()->m_RespawnTick, Server()->Tick()+Server()->TickSpeed()*g_Config.m_SvRespawnDelayTDM);

	return 0;
}
