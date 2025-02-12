#pragma once
#include "../ExportAPI.hpp"

namespace AuraEngine
{
    class Client;

    class AE_API EventHandler
    {
    public:
        explicit EventHandler(Client* client);
        void PollEvents() const;

        ~EventHandler();

    private:
        Client* client = nullptr;
    };
} // namespace AuraEngine
