#pragma once

#include <stack>
#include <memory>
#include "ICommand.hpp"

namespace Command
{
    class CommandInvoker
    {

    private:
        std::stack<std::unique_ptr<ICommand>> _undoStack;
        std::stack<std::unique_ptr<ICommand>> _redoStack;

        size_t maxHistory_{ 256 };

    public:
		CommandInvoker() noexcept = default;
		~CommandInvoker() noexcept = default;

        CommandInvoker(const CommandInvoker&) = delete;
        CommandInvoker& operator=(const CommandInvoker&) = delete;
        CommandInvoker(CommandInvoker&&) = delete;
        CommandInvoker& operator=(CommandInvoker&&) = delete;

        void executeCommand(std::unique_ptr<ICommand> command) 
        {
            if (!command) return;
            
            if (command->Execute()) {
                _undoStack.push(std::move(command));
                redoStack_.clear();
                if (undoStack_.size() > maxHistory) 
                {
                    undoStack_.erase(undoStack_.begin());
                }
            }
        }

        void undoCommand() {
            if (_undoStack.empty()) return;

            auto& command = _undoStack.top();
            command->Undo();
            _redoStack.push(std::move(_undoStack.top()));
            _undoStack.pop();
        }

        void redoCommand() {
            if (_redoStack.empty()) return;
            auto& command = _redoStack.top();
            command->Execute();
            _undoStack.push(std::move(_redoStack.top()));
            _redoStack.pop();
        }

        void setMaxHistory(size_t maxHistory) noexcept { maxHistory_ = (maxHistory == 0u) ? 1u : maxHistory; }
        size_t getMaxHistory() const noexcept { return maxHistory_; }
    };
}