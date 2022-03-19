#pragma once
#include "IComponent.h"
#include "Gameplay/Physics/RigidBody.h"
#include "Gameplay/Components/RenderComponent.h"
#include "Graphics/Textures/Texture3D.h"

class Movement : public Gameplay::IComponent {
public:
	typedef std::shared_ptr<Movement> Sptr;

	std::weak_ptr<Gameplay::IComponent> Panel;

	Movement();
	virtual ~Movement();
	glm::vec3 test;
	virtual void Awake() override;
	virtual void Update(float deltaTime) override;

public:
	virtual void RenderImGui() override;
	MAKE_TYPENAME(Movement);
	virtual nlohmann::json ToJson() const override;
	static Movement::Sptr FromJson(const nlohmann::json& blob);

protected:

	RenderComponent::Sptr _renderer;
	Texture3D::Sptr warmLut = ResourceManager::CreateAsset<Texture3D>("luts/hot.CUBE");
	Texture3D::Sptr coldLut = ResourceManager::CreateAsset<Texture3D>("luts/superCold.CUBE");
	Texture3D::Sptr customLut = ResourceManager::CreateAsset<Texture3D>("luts/lightParty.CUBE");
	Texture3D::Sptr defaultLut = ResourceManager::CreateAsset<Texture3D>("luts/cool.CUBE");
};
