#include "GameObject.h"

namespace Core {

    GameObject::GameObject(const Texture2D& texture, const std::string& name, const Rectangle& destRect)
        : Renderable(texture, destRect),
        m_active(true),
        m_name(name)
    {
    }

    void GameObject::update(float deltatime)
    {

    }

    void GameObject::setPosition(const Rectangle& rect)
    {
        Renderable::setPosition(rect.x, rect.y);
    }

} 
