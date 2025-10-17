#pragma once

namespace Command
{
    class ICommand {
    public:
        virtual ~ICommand() = default;
        virtual bool Execute() = 0;
        virtual void Undo() = 0;
    };
}