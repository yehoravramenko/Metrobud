#include "UI.hpp"
#include <imgui.h>
#include <imgui_impl_sdl3.h>
#include <imgui_impl_opengl3.h>

namespace AuraEngine
{
  UI::UI(SDL_Window *window, void *sdl_gl_context)
    : rootFrame{ "root", {0.0f,0.0f}, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize |
      ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoScrollbar |
      ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoBackground }
  {
    ImGui::CreateContext();
    //ImGuiIO &io = ImGui::GetIO();
    ImGui_ImplSDL3_InitForOpenGL(window, sdl_gl_context);
    ImGui_ImplOpenGL3_Init();
  }

  void UI::ProcessSDLEvent(SDL_Event &event)
  {
    ImGui_ImplSDL3_ProcessEvent(&event);
  }

  void UI::Update()
  {
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplSDL3_NewFrame();
    ImGui::NewFrame();
  }

  void UI::Draw()
  {
    ImGui::SetNextWindowBgAlpha(0.0f); // Fully transparent background
    ImGui::SetNextWindowPos(ImVec2(0, 0), ImGuiCond_Always); // Fixed position
    ImGui::SetNextWindowSize(ImVec2(0, 0)); // Auto-size based on text

    this->rootFrame.Draw();

    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
  }

  UI::~UI()
  {
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplSDL3_Shutdown();
    ImGui::DestroyContext();
  }
}