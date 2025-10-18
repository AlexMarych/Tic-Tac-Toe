#pragma once

namespace Command
{
    class ICommand {
    public:
        virtual ~ICommand() noexcept = default;
        virtual bool Execute() = 0;
        virtual void Undo() = 0;
    };
}