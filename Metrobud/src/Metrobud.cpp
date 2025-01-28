#include "Metrobud.hpp"

Metrobud::Metrobud() : Client() {}

void Metrobud::OnStart()
{
  this->renderer->GetWindow()->SetSize({ 1280, 720 });
  this->renderer->GetWindow()->SetTitle("Metrobud");
}

void Metrobud::OnUpdate()
{
}

void Metrobud::OnRender()
{
}

void Metrobud::OnExit()
{
}
