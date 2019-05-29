#pragma once
#include <iostream>
#include <vector>
#include "Renderer2D.h"
#include"Font.h"

using namespace std;

class SceneObject
{
public:
	SceneObject();
	virtual ~SceneObject();

	virtual void OnUpdate(float deltaTime) { }

	void Update(float deltaTime);

	virtual void OnDraw(aie::Renderer2D* renderer) { }

	void Draw(aie::Renderer2D* renderer);

	SceneObject* GetParent() const { return parent; }

	size_t childCount() const { return children.size(); }

	SceneObject* GetChild(unsigned int index) const { return children[index]; }

	void AddChild(SceneObject* child);
	
	void RemoveChild(SceneObject* child);

protected:

	SceneObject* parent = nullptr;
	vector<SceneObject*> children;

};

