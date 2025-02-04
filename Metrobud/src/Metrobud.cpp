#include "Metrobud.hpp"

using namespace AuraEngine;

Metrobud::Metrobud() : Client("Metrobud") {}

void Metrobud::OnStart()
{
}

void Metrobud::OnUpdate()
{
  if (Input->GetKey(Keycode::W))
    Debug.Log("W pressed");
}

void Metrobud::OnRender()
{
}

void Metrobud::OnExit()
{
}
