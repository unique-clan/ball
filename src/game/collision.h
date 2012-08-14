/* (c) Magnus Auvinen. See licence.txt in the root of the distribution for more information. */
/* If you are missing that file, acquire a complete release at teeworlds.com.                */
#ifndef GAME_COLLISION_H
#define GAME_COLLISION_H

#include <base/vmath.h>

class CCollision
{
	friend class CBall;
	class CTile *m_pTiles;
	int m_Width;
	int m_Height;
	class CLayers *m_pLayers;

	bool IsTileSolid(int x, int y);
	bool IsTileBallEvent(int x, int y);
	int GetTile(int x, int y);
	vec2 NextTile(vec2 Pos, vec2 Dir);

public:
	enum
	{
		COLFLAG_SOLID=1,
		COLFLAG_DEATH=2,
		COLFLAG_NOHOOK=4,
		COLFLAG_BALL_SOLID=8,

		SFLAG_GOAL_TEAM_0=16,
		SFLAG_GOAL_TEAM_1=32,
		SFLAG_LIMIT_TEAM_0=48,
		SFLAG_LIMIT_TEAM_1=64,
		SFLAG_GOALIE_LIMIT_0=80,
		SFLAG_GOALIE_LIMIT_1=96
	};

	CCollision();
	void Init(class CLayers *pLayers);
	bool CheckPoint(float x, float y) { return IsTileSolid(round(x), round(y)); }
	bool CheckPoint(vec2 Pos) { return CheckPoint(Pos.x, Pos.y); }
	bool BallCheckPoint(float x, float y) { return IsTileBallEvent(round(x), round(y)); }
	bool BallCheckPoint(vec2 Pos) { return IsTileBallEvent(round(Pos.x), round(Pos.y)); }
	int GetCollisionAt(float x, float y) { return GetTile(round(x), round(y)); }
	int GetWidth() { return m_Width; };
	int GetHeight() { return m_Height; };
	int IntersectLine(vec2 Pos0, vec2 Pos1, vec2 *pOutCollision, vec2 *pOutBeforeCollision, bool ball=false);
	void MovePoint(vec2 *pInoutPos, vec2 *pInoutVel, float Elasticity, int *pBounces);
	void MoveBox(vec2 *pInoutPos, vec2 *pInoutVel, vec2 Size, float Elasticity);
	bool TestBox(vec2 Pos, vec2 Size);
};

#endif
