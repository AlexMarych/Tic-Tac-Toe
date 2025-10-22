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

        void executeCommand(std::unique_ptr<ICommand> command);
        void undoCommand();
        void redoCommand();

        inline void setMaxHistory(const size_t& maxHistory) noexcept { m_maxHistory = (maxHistory == 0u) ? 1u : maxHistory; }
        inline size_t getMaxHistory() const noexcept { return m_maxHistory; }

    private:
        std::stack<std::unique_ptr<ICommand>> m_undoStack{};
        std::stack<std::unique_ptr<ICommand>> m_redoStack{};

        size_t m_maxHistory{ 256 };
    };
}