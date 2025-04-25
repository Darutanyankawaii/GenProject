# pragma once
# include <Siv3D.hpp>

enum class SceneName {
	Debug,
	Home
};

struct GameData
{
public:
};

using App = SceneManager<SceneName, GameData>; // 型エイリアス宣言
