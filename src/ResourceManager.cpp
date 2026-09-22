#include "ResourceManager.h"
namespace estebo {
	ResourceManager::ResourceManager()
	{}
	ResourceManager::~ResourceManager()
	{}
	Texture2D& ResourceManager::GetTexture(std::string name)
	{
		std::string path = texturePath + name;

		auto it = textureDiccionary.find(path);

		if (it != textureDiccionary.end()) {
			return it->second;
		}

		if (!FileExists(path.c_str())) {
			TraceLog(DEBUG, "no existe un archivo con esa direccion, babas");
			std::string wabbitPath = texturePath + "wabbit_alpha.png";
			Texture2D tex = LoadTexture(wabbitPath.c_str());
			return tex;
		}

		textureDiccionary[path] = LoadTexture(path.c_str());
		return textureDiccionary[path];
	}
	Sound& ResourceManager::GetSound(std::string name)
	{
		std::string path = soundPath + name;

		auto it = soundDiccionary.find(path);

		if (it != soundDiccionary.end()) {
			return it->second;
		}

		if (!FileExists(path.c_str())) {
			TraceLog(DEBUG, "no existe un archivo con esa direccion, babas");
			Sound s;
			return s;
		}

		soundDiccionary[path] = LoadSound(path.c_str());
		return soundDiccionary[path];
	}
	Music& ResourceManager::GetMusic(std::string name)
	{
		std::string path = musicPath + name;

		auto it = musicDiccionary.find(path);

		if (it != musicDiccionary.end()) {
			return it->second;
		}

		if (!FileExists(path.c_str())) {
			TraceLog(DEBUG, "no existe un archivo con esa direccion, babas");
			Music m;
			return m;
		}

		musicDiccionary[path] = LoadMusicStream(path.c_str());
		return musicDiccionary[path];
	}
}