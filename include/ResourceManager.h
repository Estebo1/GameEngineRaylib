#pragma once
#include <unordered_map>
#include <raylib.h>
#include <string>

namespace estebo {
	class ResourceManager
	{
	public:
		static ResourceManager& get() {
			static ResourceManager rm;
			return rm;
		}

		ResourceManager();
		~ResourceManager();

		Texture2D& GetTexture(std::string name);
		Font& GetFont(std::string name);
		Sound& GetSound(std::string name);
		Music& GetMusic(std::string name);

	private:
		std::unordered_map<std::string, Texture2D> textureDiccionary;
		std::unordered_map<std::string, Font> fontDiccionary;
		std::unordered_map<std::string, Sound> soundDiccionary;
		std::unordered_map<std::string, Music> musicDiccionary;
		std::string texturePath{ "textures/" };
		std::string soundPath{ "sounds/" };
		std::string musicPath{ "music/" };
	};
}