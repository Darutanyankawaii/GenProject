# include "./Basic.hpp"
# include "./Home.hpp"
# include "./Asset.hpp"


void Main()
{
	Window::Resize(600, 800); // ウィンドウサイズの変更

	//シーンの追加方法
	//1,テンプレ文をもとにテンプレに追加したいシーンの名前を書きmanagerに加える
	//2,Basic.hppにある「enum class SceneName」の中に1で作成したシーンの名前を書き込む
	//3,作りたいシーンの.hppファcイルと.cppファイルを作成する。
	//4,作りたいシーンの.hppファイルを#includeする。

	RegistTextureAsset();

	App manager;
	manager
		.add<Home>(SceneName::Home)
		;

	const int FPS = 60; // FPSの設定
	Stopwatch sw;
	sw.start();

	while (System::Update())
	{

		if (manager.update() == false)
		{
			break;
		}

		while (sw.msF() < 1000.0 / FPS); // FPSの調整
		sw.restart(); // ストップウォッチをリセット
	}
}

//
// - Debug ビルド: プログラムの最適化を減らす代わりに、エラーやクラッシュ時に詳細な情報を得られます。
//
// - Release ビルド: 最大限の最適化でビルドします。
//
// - [デバッグ] メニュー → [デバッグの開始] でプログラムを実行すると、[出力] ウィンドウに詳細なログが表示され、エラーの原因を探せます。
//
// - Visual Studio を更新した直後は、プログラムのリビルド（[ビルド]メニュー → [ソリューションのリビルド]）が必要な場合があります。
//
