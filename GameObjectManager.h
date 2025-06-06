#pragma once
#include <d3d11.h>
#include <unordered_map>
#include "AGameObject.h"
#include "ARenderer.h"

// Should only contain base game objects (one's with no parents)
class GameObjectManager
{
public:
	static GameObjectManager* GetInstance();
	GameObjectManager(const GameObjectManager&) = delete;
	GameObjectManager& operator=(const GameObjectManager&) = delete;

	// Game-related methods
	//void ProcessInput(sf::Event event);
	void Update(float dt);
	void Draw();

	// Object-related methods
	void AddObject(AGameObject* gameObject);
	void BindRendererToShader(ARenderer* rendererComponent);
	AGameObject* FindObjectByName(std::string name);
	void DeleteObject(AGameObject* gameObject);
	void DeleteObjectByName(std::string name);
	std::vector<AGameObject*> GetAllObjects(); 
	int GetActiveObjectsCount();


private:
	GameObjectManager() {};
	static GameObjectManager* sharedInstance;

	std::unordered_map<std::string, AGameObject*> gameObjectMap;
	std::vector<AGameObject*> gameObjectList;

	std::unordered_map<LPCWSTR, std::vector<AGameObject*>> shaderToObjectsMap;
};

