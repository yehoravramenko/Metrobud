#include "Metrobud.hpp"

Metrobud::Metrobud() : Client()
{
}

void Metrobud::OnStart()
{
	this->window.SetSize({ 1280, 720 });
	this->window.SetTitle("Metrobud");
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
