#pragma once
#include "doa.h"

using namespace doa;
class Enemy : public scene::GameObject {
private:
	//doa::animation::Animation e_anim_idle;
	//doa::animation::Animation e_anim_move;
	const int speed_value = 10;
	bool charging;
public:
	glm::vec3* m_vel;
	glm::vec3* start_pos;
	glm::vec3* player_pos;
	float m_gravity;
	int dir;

	Enemy(glm::vec3* velocity = new glm::vec3(0, 0, 0), glm::vec3* player_pos = new glm::vec3(0, 0, 0),float gravity = 0.8);
	virtual ~Enemy();

	void move(int deviation);
	void charge(int speed_multiply, float range);

	void update(const scene::Scene& parent, const std::vector<GameObject*>& objects, const std::vector<scene::Light*>& lights) override;
	void render(const scene::Scene& parent, const std::vector<GameObject*>& objects, const std::vector<scene::Light*>& lights) const override;
};
