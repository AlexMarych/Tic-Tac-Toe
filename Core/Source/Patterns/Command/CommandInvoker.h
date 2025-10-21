#pragma once

#include <stack>
#include <memory>
#include "ICommand.h"

namespace Command
{
    class CommandInvoker
    {
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
            
            if (command->execute()) {
                if (m_undoStack.size() <= m_maxHistory) 
                {
                    m_undoStack.push(std::move(command));
                    m_redoStack = {};
                }
            }
        }

        void undoCommand() {
            if (m_undoStack.empty()) return;

            auto& command = m_undoStack.top();
            command->undo();
            m_redoStack.push(std::move(m_undoStack.top()));
            m_undoStack.pop();
        }

        void redoCommand() {
            if (m_redoStack.empty()) return;
            auto& command = m_redoStack.top();
            command->execute();
            m_undoStack.push(std::move(m_redoStack.top()));
            m_redoStack.pop();
        }

        void setMaxHistory(const size_t& maxHistory) noexcept { m_maxHistory = (maxHistory == 0u) ? 1u : maxHistory; }
        size_t getMaxHistory() const noexcept { return m_maxHistory; }

    private:
        std::stack<std::unique_ptr<ICommand>> m_undoStack{};
        std::stack<std::unique_ptr<ICommand>> m_redoStack{};

        size_t m_maxHistory{ 256 };
    };
}