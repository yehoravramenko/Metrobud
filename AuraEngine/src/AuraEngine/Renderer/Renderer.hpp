#pragma once
#include <SDL3/SDL.h>
#include "../ExportAPI.hpp"
#include "../UI/UI.hpp"
#include "../Window/Window.hpp"
#include "Buffer.hpp"
#include "Camera.hpp"
#include "Shader.hpp"
#include "Texture.hpp"
#include "VertexArray.hpp"

#include <memory>
#include <utility>

namespace AuraEngine
{
    class EventHandler;
    class Client;
    class Renderer
    {
    public:
        explicit Renderer(const Client* client);
        void Update() const;
        void Render() const;

        // void SetSize(const std::pair<int, int> &size) const;
        [[nodiscard]] float GetAspectRatio() const;
        [[nodiscard]] AE_API Camera* GetCamera() const;

        ~Renderer();

        friend EventHandler;

    private:
        const Client* client = nullptr;
        SDL_GLContext gl_context = nullptr;

        std::unique_ptr<UI> ui;
        std::unique_ptr<Window> window;

        std::unique_ptr<Buffer> VBO;
        std::unique_ptr<Buffer> EBO;
        std::unique_ptr<VertexArray> DummyVAO;
        std::unique_ptr<Shader> shader;
        std::unique_ptr<Texture> texture1;
        std::unique_ptr<Camera> camera;

        static void windowResizeCallback(const std::pair<int, int> newSize);
    };
} // namespace AuraEngine
