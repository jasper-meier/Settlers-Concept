#ifndef WORLD_H
#define WORLD_H

#include <vector>
#include "Grid.h"

class World {
public:
	static World* Instance();
	Grid* grid;

	void init();
	void update();

	Settler* createNewSettler(EnumSettlerType type, Profession prof, Vector3 worldPos, Tool* tool = nullptr, ResourceGroup* rg = nullptr);

private:
	static World* instance;

	SettlerType** types;
	std::vector<Settler> settlers;

	void createResourceGroups();
	void sendUpdateDataToServer();
	void receiveUpdateDataFromServer();

	World();
	~World();
};

#endif