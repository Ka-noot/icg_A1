#include "Gameplay/Components/Movement.h"
#include <GLFW/glfw3.h>
#include "Gameplay/GameObject.h"
#include "Gameplay/Scene.h"
#include "Utils/ImGuiHelper.h"
#include "Gameplay/InputEngine.h"
#include "Gameplay/Light.h" 

void Movement::Awake()
{

}

void Movement::RenderImGui() {
	LABEL_LEFT(ImGui::DragFloat, "test", &test.x);
}

nlohmann::json Movement::ToJson() const {
	return {
		{ "test", test }
	};
}

Movement::Movement() :
	IComponent()
{ }

Movement::~Movement() = default;

Movement::Sptr Movement::FromJson(const nlohmann::json & blob) {
	Movement::Sptr result = std::make_shared<Movement>();
	result->test = blob["test"];
	return result;
}

void Movement::Update(float deltaTime)
{
	if (InputEngine::GetKeyState(GLFW_KEY_1) == ButtonState::Pressed)
	{
		for (int i = 0; i < GetGameObject()->GetScene()->Lights.size(); i++)
		{
			GetGameObject()->GetScene()->Lights[i].Range = 0.f;
		}
		GetGameObject()->GetScene()->SetupShaderAndLights();//turning off the lights

	}
	if (InputEngine::GetKeyState(GLFW_KEY_2) == ButtonState::Pressed)
	{
		for (int i = 0; i < GetGameObject()->GetScene()->Lights.size(); i++)
		{
			GetGameObject()->GetScene()->Lights[i].Range = 30.f;
		}
		GetGameObject()->GetScene()->SetAmbientLight(glm::vec3(0.5f));

	}
	
	if (InputEngine::GetKeyState(GLFW_KEY_8) == ButtonState::Pressed)
	{
		for (int i = 0; i < GetGameObject()->GetScene()->Lights.size(); i++)
		{
			GetGameObject()->GetScene()->Lights[i].Range = 30.f;
		}
		GetGameObject()->GetScene()->SetupShaderAndLights();

		GetGameObject()->GetScene()->SetColorLUT(warmLut);//calling LUT for color grading warm

	}

	if (InputEngine::GetKeyState(GLFW_KEY_9) == ButtonState::Pressed)
	{
		for (int i = 0; i < GetGameObject()->GetScene()->Lights.size(); i++)
		{
			GetGameObject()->GetScene()->Lights[i].Range = 30.f;
		}
		GetGameObject()->GetScene()->SetupShaderAndLights();

		GetGameObject()->GetScene()->SetColorLUT(coldLut);//calling LUT for color grading cold
	}

	if (InputEngine::GetKeyState(GLFW_KEY_0) == ButtonState::Pressed)
	{
		for (int i = 0; i < GetGameObject()->GetScene()->Lights.size(); i++)
		{
			GetGameObject()->GetScene()->Lights[i].Range = 30.f;
		}
		GetGameObject()->GetScene()->SetupShaderAndLights();

		GetGameObject()->GetScene()->SetColorLUT(customLut); //calling LUT for color grading custom lava lamp look
	}
	if (InputEngine::GetKeyState(GLFW_KEY_SPACE) == ButtonState::Pressed)
	{
		for (int i = 0; i < GetGameObject()->GetScene()->Lights.size(); i++)
		{
			GetGameObject()->GetScene()->Lights[i].Range = 30.f;
		}
		GetGameObject()->GetScene()->SetupShaderAndLights();

		GetGameObject()->GetScene()->SetColorLUT(defaultLut);// this allows the user to go back to original state after each key press
	}

}

