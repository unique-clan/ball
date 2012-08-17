#ifndef GAME_SERVER_ENTITIES_BALL_H
#define GAME_SERVER_ENTITIES_BALL_H

class CBall : public CEntity
{
public:
	CBall(CGameWorld *pGameWorld, int Owner, vec2 Pos, vec2 Dir);

	vec2 GetPos(float Time);
	void FillInfo(CNetObj_Projectile *pProj);

	virtual void Reset();
	virtual void Tick();
	virtual void TickPaused();
	virtual void Snap(int SnappingClient);

private:
	vec2 m_Direction;
	int m_Owner;
	int m_Player;
	int m_Team;
	int m_Type;
	int m_Damage;
	int m_Weapon;
	int m_StartTick;
	int m_RespawnTick;
	int m_LastOwnerInterTick;
};

#endif
