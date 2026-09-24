#pragma once
#include "Scene.h"
#include <string>
#include <unordered_map>

namespace estebo {
    class SceneManager
    {
        std::unordered_map<std::string, Scene*> scenes;
        Scene *current = nullptr;
        Scene *next = nullptr;

        SceneManager() = default;
        ~SceneManager()
        {
            if (current)
                current->OnExit();
            for (auto& [name, scene] : scenes)
                delete scene;

        }

    public:
        static SceneManager& Get()
        {
            static SceneManager instance;
            return instance;
        }

        SceneManager(const SceneManager&) = delete;
        void operator=(const SceneManager&) = delete;

        void AddScene(const std::string& name, Scene* scene)
        {
            scenes[name] = scene;
        }

        void ChangeScene(const std::string& name)
        {
            auto it = scenes.find(name);
            if (it == scenes.end())
                return;
            next = it->second;
        }

        void Update()
        {
            if (current)
            {
                current->Update();
            }
            ProcessChange();
        }

        void Draw()
        {
            if (current)
                current->Draw();
        }
        void Shutdown()
        {
            if (current)
                current->OnExit();
            for (auto& [name, scene] : scenes)
                delete scene;
            scenes.clear();

            current = nullptr;
            next = nullptr;
        }   
    private:
        void ProcessChange()
        {
            if (!next)
                return;
            if (current)
                current->OnExit();
            current = next;
            next = nullptr;
            current->OnEnter();
        }
    };
}
