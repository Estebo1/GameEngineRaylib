#pragma once
namespace estebo {
	class Scene
	{
    public:
        virtual ~Scene() = default;
        virtual void OnEnter() = 0;
        virtual void OnExit() = 0;
        virtual void Update() = 0;
        virtual void Draw() = 0;
    };
}
