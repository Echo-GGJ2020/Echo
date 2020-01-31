#include "Enemy.h"
Enemy::Enemy(glm::vec3* velocity, glm::vec3* player_pos, float gravity) : m_vel{ velocity }, m_gravity{ gravity }, player_pos{ player_pos }
{
	*start_pos = *m_position;
	dir = 1;
	charging = false;
}
Enemy::~Enemy(){ delete m_vel; }

void Enemy::move(int deviation)
{
	if (!charging)
	{
		if ((m_position->x - start_pos->x) >= deviation || (m_position->x - start_pos->x) <= -deviation)
			dir = !dir;
	}
}
void Enemy::charge(int speed_multiply, float range)
{
	float len = glm::length(*player_pos - *m_position);

	if (len < range)
	{
		charging = true;
		if ((m_position - player_pos) < 0)
			dir = 1 * speed_multiply;
		if ((m_position - player_pos) > 0)
			dir = -1 * speed_multiply;
	}
	else if (charging)
	{
		dir = dir / speed_multiply;
		charging = false;
	}
}

void Enemy::update(const scene::Scene& parent, const std::vector<GameObject*>& objects, const std::vector<scene::Light*>& lights)
{
	m_vel->x = dir * speed_value;
	m_position->x = m_vel->x;
	move(200);
	charge(2,100);
}
void Enemy::render(const scene::Scene& parent, const std::vector<GameObject*>& objects, const std::vector<scene::Light*>& lights) const
{
	using namespace ezrender;
	Color(1, 0, 0);
	Scale(30, 30);
	TranslateX(m_position->x);
	TranslateY(m_position->y);
}
