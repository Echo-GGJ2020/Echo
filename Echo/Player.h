#pragma once
#include "doa.h"

using namespace doa;
class Player : public scene::GameObject {
private:
	/*	doa::animation::Animation* p_anim_idle;
	doa::animation::Animation* p_anim_run;
	doa::animation::Animation* p_anim_fall;*/
	doa::texture::Texture p_texture;
	const int speed_value = 10;
public:
	glm::vec3* m_vel;
	float m_gravity;
	bool airborne;

	Player(glm::vec3* velocity = new glm::vec3(0, 0, 0), float gravity = -0.5, bool airborne = false);
	virtual ~Player();

	void move(bool right, bool left);
	void jump();

	void update(const scene::Scene& parent, const std::vector<GameObject*>& objects, const std::vector<scene::Light*>& lights) override;
	void render(const scene::Scene& parent, const std::vector<GameObject*>& objects, const std::vector<scene::Light*>& lights) const override;
};
