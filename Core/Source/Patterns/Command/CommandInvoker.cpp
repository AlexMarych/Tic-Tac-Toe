#include "CommandInvoker.h"

namespace Command
{
    void CommandInvoker::executeCommand(std::unique_ptr<ICommand> command)
    {
        if (!command) return;

        if (command->execute()) {
            if (m_undoStack.size() <= m_maxHistory) {
                m_undoStack.push(std::move(command));
                m_redoStack = {};
            }
        }
    }

    void CommandInvoker::undoCommand()
    {
        if (m_undoStack.empty()) return;

        auto command = std::move(m_undoStack.top());
        command->undo();
        m_redoStack.push(std::move(m_undoStack.top()));
        m_undoStack.pop();
    }

    void CommandInvoker::redoCommand()
    {
        if (m_redoStack.empty()) return;

        auto command = std::move( m_redoStack.top());
        command->execute();
        m_undoStack.push(std::move(m_redoStack.top()));
        m_redoStack.pop();
    }

}