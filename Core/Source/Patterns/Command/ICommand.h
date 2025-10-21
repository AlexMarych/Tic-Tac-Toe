#pragma once

namespace Command
{
    class ICommand {
    public:
        virtual ~ICommand() noexcept = default;
        virtual bool execute() = 0;
        virtual void undo() = 0;
    };
}