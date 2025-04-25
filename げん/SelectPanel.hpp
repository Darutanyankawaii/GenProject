#pragma once
# include "./Basic.hpp"

enum ActMode {
	MODE_HOME,
	MODE_ADD,
	MODE_EDIT
};

class PanelManager {
public:
	PanelManager() {};

	int panelCount_ = 0;
	int LIMIT_PANEL_COUNT = 3;
	const double PANEL_X = 200;
	const double PANEL_Y = 450;
	const Vec2 PANEL_SIZE = { 400, 100 };
	const double PANEL_WIDE = 20;

	Vec2 calculatePanelPos() {
		Vec2 startPos;
		startPos = (Vec2{ 95, 480 } + Vec2{ 0, (PANEL_SIZE.y) * panelCount_});
		panelCount_++;
		return startPos;
	}

	Vec2 calculatePanelRePos(int i) {
		Vec2 startPos;
		startPos = (Vec2{ 95, 480 } + Vec2{ 0, (PANEL_SIZE.y)* i});
		return startPos;
	}
};

class BasePanel {
public:
	BasePanel(Vec2 pos):
		pos_(pos)
	{};

	bool hit_ = false;
	bool deleteFlag_ = false;
	Vec2 pos_;
	bool checkOn_ = false;
	const Font messageFont{ 24 };

	virtual void draw() const {};
	virtual bool intersects(Vec2) = 0;
	virtual bool intersects2(Vec2) { return false; };
	virtual int clickAction() = 0;
	virtual void clickAction2() {};

	virtual void rePos(Vec2 pos) {}

	Color ChoiceColor(bool colorFlag) const{
		return colorFlag ? Palette::Orange : Palette::Blue;
	}
};

class TodoPanel : public BasePanel {
public:
	TodoPanel(Vec2 pos) :
		BasePanel(pos),
		message_(U"AAA"),
		panelRegion_(RoundRect{ pos, PANEL_SIZE, 10 }),
		checkRegion_(RoundRect{ pos, CHECK_SIZE, 10 }),
		buttonRegion_(RoundRect{ pos_ + Vec2{ 350, -25 }, CHECK_SIZE, 10 })
	{};

	TodoPanel( Vec2 pos, String memo) :
		BasePanel(pos),
		message_(memo),
		panelRegion_(RoundRect{ pos, PANEL_SIZE, 10}),
		checkRegion_(RoundRect{ pos, CHECK_SIZE, 10 }),
		buttonRegion_(RoundRect{ pos_ + Vec2{ 350, -25 }, CHECK_SIZE, 10 })
	{};

	const Vec2 PANEL_SIZE = { 400, 100};
	const Vec2 CHECK_SIZE = { 70, 70};

	RoundRect panelRegion_;
	RoundRect checkRegion_;
	RoundRect buttonRegion_;
	String message_;
	bool hit2_ = false;

	void draw() const override {
		TextureAsset(U"Delete").resized(70, 70).draw(pos_ + Vec2{ 350, -25 });
		TextureAsset(U"Todo").draw(pos_);
		messageFont(message_).draw(pos_ + Vec2{ 100, 25}, ColorF{ 0.2 });

		//buttonRegion_.draw();

		if (checkOn_) {
			TextureAsset(U"Check").resized(70, 70).draw(pos_);
		}
	};

	bool intersects(Vec2 pos) override {
		hit2_ = panelRegion_.intersects(pos);
		hit_ = buttonRegion_.intersects(pos);

		//if (hit2_) Print << U"Hit TodoPanel";
		//if (hit_) Print << U"Hit ButtonPanel";

		return hit_;
	};

	bool intersects2(Vec2 pos) override {
		hit_ = checkRegion_.intersects(pos);

		//if (hit_) Print << U"Hit checkPanel";

		return hit_;
	};

	void rePos(Vec2 pos) override {
		pos_ = pos;
		panelRegion_ = RoundRect{ pos, PANEL_SIZE, 10 };
		buttonRegion_ = RoundRect{ pos_ + Vec2{ 350, -25 }, CHECK_SIZE, 10 };
		checkRegion_ = RoundRect{ pos, CHECK_SIZE, 10 };
	}

	int clickAction() override {
		return 0;
	};

	void clickAction2() override {
		checkOn_ = true;
	};
};

class AddTodoPanel : public BasePanel {
public:
	AddTodoPanel() :
		BasePanel(PANEL_POS)
	{};

	//メインデータ
	const Vec2 PANEL_POS = { 100, 400 };
	const Vec2 PANEL_SIZE = { 70, 70 };
	const RoundRect PANEL_REGION = { PANEL_POS , PANEL_SIZE, 10};

	void draw() const override {
		TextureAsset(U"Add").resized( 70, 70).draw(PANEL_POS);
	};
	bool intersects(Vec2 pos) override {
		hit_ = PANEL_REGION.intersects(pos);
		//if (hit_) Print << U"Hit AddTodoPanel";
		return hit_;
	};

	int clickAction() override {
		return 1;
	};
};

class EditPanel : public BasePanel {
public:
	EditPanel() :
		BasePanel(PANEL_POS)
	 {};

	//メインデータ
	const Vec2 PANEL_POS = { 180, 400 };
	const Vec2 PANEL_SIZE = { 70, 70 };
	const RoundRect PANEL_REGION = { PANEL_POS , PANEL_SIZE, 10 };

	void draw() const override {
		TextureAsset(U"Edit").resized(70, 70).draw(PANEL_POS);
	};

	bool intersects(Vec2 pos) override {
		hit_ = PANEL_REGION.intersects(pos);
		//if(hit_) Print << U"Hit EditPanel";
		return hit_;
	};

	int clickAction() override {
		return 2;
	};
};

class PanelCtrl {
private:
	std::shared_ptr <PanelManager> panelManager_ = std::make_shared<PanelManager>(); //パネル生成管理
	Array<std::shared_ptr<BasePanel>> buttonPanels_; //パネルら
	Array<std::shared_ptr<BasePanel>> panels_;
	Vec2 previousMousePos_ = { 0, 0}; //マウスの座標

	int32 actMode_ = MODE_HOME;
	bool addPanelFlag = false;


	String tmp;
	int GirlCounter = 4;

public:
	PanelCtrl();
	void update();
	void draw() const;

	void updateHome();
	void updateInput();

	//void drawHome() const;
	//void drawInput() const;

	void mouseTouchPanel();

	/*void initText(const Array<String> quizText);
	int32 returnChoicePanel();

	void debug();*/
};
