#include "Metrobud.hpp"

using namespace AuraEngine;

float speed = 5.0f;
glm::vec3 forward{0.0f, 0.0f, 1.0f};
glm::vec3 right{1.0f, 0.0f, 0.0f};

void Metrobud::OnStart()
{
}

void Metrobud::OnUpdate()
{
    if (Input->GetKey(Keycode::W))
        this->Renderer->GetCamera()->Translate(forward * speed * GetDeltaTime());
    if (Input->GetKey(Keycode::S))
        this->Renderer->GetCamera()->Translate(-forward * speed * GetDeltaTime());
    if (Input->GetKey(Keycode::D))
        this->Renderer->GetCamera()->Translate(right * speed * GetDeltaTime());
    if (Input->GetKey(Keycode::A))
        this->Renderer->GetCamera()->Translate(-right * speed * GetDeltaTime());
}

void Metrobud::OnRender()
{
}

void Metrobud::OnExit()
{
}
