#include "Player.h";
using namespace doa::keyboard;

Player::Player(glm::vec3* velocity, float gravity, bool airborne) : m_vel{ velocity }, m_gravity{ gravity }
{
	doa::texture::CreateTexture("pencil", "Textures\\pencil.png");
}
Player::~Player() {delete m_vel;}

void Player::move(bool right, bool left)
{
	m_vel->x = (right - left) * speed_value;
}

void Player::jump()
{
	if (!airborne)
		m_vel->y = speed_value;
}

void Player::update(const scene::Scene& parent, const std::vector<GameObject*>& objects, const std::vector<scene::Light*>& lights)
{
	move(IsKeyHold(E), IsKeyHold(Q));
	m_position->x += m_vel->x;
	m_vel->y += m_gravity;
	m_position->y += m_vel->y;
	if (IsKeyHold(SPACE))
		jump();

	if (m_position->y < 100)
	{
		m_position->y = 100;
		airborne = false;
	}

	if (m_position->x > 400)
		m_position->x = 400;
	if (m_position->x < -400)
		m_position->x = -400;
	//TODO: Add collision check for "airborne"
}


void Player::render(const scene::Scene& parent, const std::vector<GameObject*>& objects, const std::vector<scene::Light*>& lights) const
{
	using namespace ezrender;
	Texture(doa::texture::Get("pencil"));
	Scale(50, 50);
	TranslateX(m_position->x);
	TranslateY(m_position->y);
	Render(parent,objects,lights);
}