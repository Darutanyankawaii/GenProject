# include "./Basic.hpp"

void RegistTextureAsset() {
	TextureAsset::Register(U"Main", U"./image/main.png");
	TextureAsset::Register(U"Icon", U"./image/icon.png");
	TextureAsset::Register(U"Todolist", U"./image/todoList.jpg");
	TextureAsset::Register(U"Edit", U"./image/Edit.png");
	TextureAsset::Register(U"Add", U"./image/Add.png");
	TextureAsset::Register(U"Check", U"./image/check.png");
	TextureAsset::Register(U"Todo", U"./image/todo.png");
	TextureAsset::Register(U"Delete", U"./image/delete.png");

	TextureAsset::Register(U"Girl11", U"./image/girl1/1.jpg");
	TextureAsset::Register(U"Girl12", U"./image/girl1/2.jpg");
	TextureAsset::Register(U"Girl13", U"./image/girl1/3.jpg");
	TextureAsset::Register(U"Girl14", U"./image/girl1/4.jpg");

	TextureAsset::Register(U"Girl21", U"./image/girl2/1.jpg");
	TextureAsset::Register(U"Girl22", U"./image/girl2/2.jpg");
	TextureAsset::Register(U"Girl23", U"./image/girl2/3.jpg");
	TextureAsset::Register(U"Girl24", U"./image/girl2/4.jpg");
}
