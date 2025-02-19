#pragma once
#include <AuraEngine.hpp>

class Metrobud : public AuraEngine::Client
{
public:
    Metrobud() : Client("Metrobud") {};
    void OnStart() override;
    void OnUpdate() override;
    void OnRender() override;
    void OnExit() override;
};
