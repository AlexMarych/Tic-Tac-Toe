#pragma once

#include <stack>
#include <memory>
#include "ICommand.hpp"

namespace Command
{
    class CommandInvoker
    {

    private:
        static std::stack<std::unique_ptr<ICommand>> _undoStack;
        static std::stack<std::unique_ptr<ICommand>> _redoStack;

    public:
        static void ExecuteCommand(std::unique_ptr<ICommand> command) {
            if (command->Execute()) {
                _undoStack.push(std::move(command));
                while (!_redoStack.empty()) _redoStack.pop();
            }
        }

        static void UndoCommand() {
            if (_undoStack.empty()) return;
            auto& command = _undoStack.top();
            command->Undo();
            _redoStack.push(std::move(_undoStack.top()));
            _undoStack.pop();
        }

        static void RedoCommand() {
            if (_redoStack.empty()) return;
            auto& command = _redoStack.top();
            command->Execute();
            _undoStack.push(std::move(_redoStack.top()));
            _redoStack.pop();
        }
    };
}