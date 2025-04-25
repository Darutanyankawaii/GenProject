#pragma once
# include "./Basic.hpp"
# include "./SelectPanel.hpp"

//enum ActMode {
//	MODE_NORMAL,
//	MODE_PAUSE
//};

//Gameシーン
class Home : public App::Scene
{
private:
	int actMode_ = 0;

	PanelCtrl selectPanel_;
public:
	Home(const InitData& init);
	~Home();


	void update() override;
	void draw() const override;

	void updateModeNormal();
	void drawModeNormal() const;
};
