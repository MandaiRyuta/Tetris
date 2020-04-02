#pragma once
#include <vector>

class Scene
{
public:
	Scene() {}
	void Init();
	void Update();
	void Draw();
	void Release();
	void Create(std::vector<int> obj);
	void Delete();
private:
	std::vector<int> obj_;
};