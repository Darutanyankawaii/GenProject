# include "./Home.hpp"

Home::Home(const InitData& init) : IScene{ init }
{
}

Home::~Home()
{

}

void Home::update()
{
	ClearPrint();

	updateModeNormal();

	//switch (actMode_) {
	//case MODE_NORMAL: //通常プレイ
	//	updateModeNormal();
	//	break;
	//case MODE_PAUSE: //一時停止
	//	//updateModePause();
	//	break;
	//default:
	//	throw cereal::Exception("登録されてないModeです。");
	//}
}

void Home::updateModeNormal()
{
	selectPanel_.update();
}

void Home::draw() const
{
	drawModeNormal();

	//switch (actMode_) {
	//case MODE_NORMAL: //通常プレイ
	//	drawModeNormal();
	//	break;
	//case MODE_PAUSE: //一時停止
	//	//drawModePause();
	//	break;
	//default:
	//	throw cereal::Exception("登録されてないModeです。");
	//}
}

void Home::drawModeNormal() const
{
	selectPanel_.draw();
}
