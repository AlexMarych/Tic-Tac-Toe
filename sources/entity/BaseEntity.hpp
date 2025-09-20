#include "raylib.h"
#include "../core/coreObject/GameObject.hpp"
#include "../core/animation/Animatable.hpp"
#include <map>


class BaseEntity : public GameObject, public Animatable
{	
public:
		BaseEntity() = default;
		BaseEntity(const Texture2D& texture, const std::string& name, const Rectangle& destRect, int maxFrame)
			: GameObject(texture, name, destRect), Animatable(texture, destRect, maxFrame){}

		virtual ~BaseEntity() = default;
		
}