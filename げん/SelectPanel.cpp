#include "SelectPanel.hpp"

PanelCtrl::PanelCtrl() {
	buttonPanels_.push_back(std::make_shared<AddTodoPanel>());
	buttonPanels_.push_back(std::make_shared<EditPanel>());

	//記録したTodoListを追加
}

void PanelCtrl::update() {

	switch (actMode_) {
	case MODE_HOME: //通常プレイ
		updateHome();
		break;
	case MODE_ADD: //追加
		updateInput();
		break;
	default:
		throw cereal::Exception("登録されてないModeです。");
	}
}

void PanelCtrl::draw() const {
	Scene::SetBackground(Palette::White);
	TextureAsset(U"Girl2" + U"{}"_fmt(GirlCounter)).resized(210, 315).draw(195, 82);
	TextureAsset(U"Main").draw( 90, 82);
	TextureAsset(U"Icon").draw( 100, 10);

	for (const auto& panel_ : buttonPanels_) {
		panel_->draw();
	}

	for (const auto& panel_ : panels_) {
		panel_->draw();
	}

}

void PanelCtrl::updateHome() {
	mouseTouchPanel();
	panels_.remove_if([](const std::shared_ptr <BasePanel>& panel) { return panel->deleteFlag_; });

	int i = 0;
	for (auto& panel_ : panels_) {
		panel_->rePos(panelManager_->calculatePanelRePos(i));
		i++;
	}

	if (addPanelFlag == true) {
		panels_.push_back(std::make_shared<TodoPanel>(panelManager_->calculatePanelPos(), tmp));
		//tmp.isEmpty();
		addPanelFlag = false;
	}
}

void PanelCtrl::updateInput() {
	// キーボードからテキストを入力する
	TextInput::UpdateText(tmp);
	//const String editingText = TextInput::GetEditingText();
	Print << tmp;
	if (KeyEnter.down()) {
		if (!tmp.isEmpty()) {
			addPanelFlag = true;
		}
		actMode_ = MODE_HOME;
	}
}

void PanelCtrl::mouseTouchPanel() {
	for (auto& panel_ : buttonPanels_) {
		if (panel_->intersects(Cursor::Pos()) && MouseL.down()) {
			switch (panel_->clickAction()) {
				case 1: //AddPanel Todoバー追加
					if(panelManager_->panelCount_ < panelManager_->LIMIT_PANEL_COUNT)
					actMode_ = MODE_ADD;
					break;
			}
		}
	}

	for (auto& panel_ : panels_) {
		if (panel_->intersects(Cursor::Pos()) && MouseL.down()) {
			switch (panel_->clickAction()) {
			case 0:	//TodoPanel 自身のTodoバー削除
				panel_->deleteFlag_ = true;
				panelManager_->panelCount_--;
				if (panel_->checkOn_ == true && GirlCounter > 1) {
					GirlCounter--;
				}
				else if(panel_->checkOn_ == false && GirlCounter < 4){
					GirlCounter++;
				}
				break;
			}
		}
		if (panel_->intersects2(Cursor::Pos()) && MouseL.down()) {
			panel_->clickAction2();
		}
	}
}



//void PanelCtrl::mouseTouchPanel() {
//	for (int i = 0; i < PANEL_NUM; i++) {
//		if (panel_[i].mainPanelRegion_.intersects(Cursor::Pos())) {
//			attentionPanel_ = i;
//		}
//	}
//}

//void PanelCtrl::initText(const Array<String> quizText) {
//	for (int i = 0; i < quizText.size(); i++) {
//		panel_[i].text_ = quizText[i];
//	}
//}

//int32 PanelCtrl::returnChoicePanel() {
//	return attentionPanel_ + 1;
//}

//void PanelCtrl::debug() {
//	Print << U"SelectPanelクラス実行中";
//	Print << U"マウスカーソルまたはスペースキーでパネルを選択";
//	Print << U"エンターキーでパネルを選択";
//	Print << attentionPanel_;
//	Print << previousMousePos_;
//	Print << Cursor::Pos();
//}
