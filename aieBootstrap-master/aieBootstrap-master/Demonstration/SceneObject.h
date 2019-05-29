#pragma once
#include <iostream>
#include <vector>
#include "Renderer2D.h"
#include"Font.h"
#include "Matrix3.h"

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

	const Matrix3& GetLocalTransform() const;

	const Matrix3& GetGobalTransform() const;

protected:

	SceneObject* parent = nullptr;
	vector<SceneObject*> children;

	Matrix3 localTransform = Matrix3::identity;
	Matrix3 globalTransform = Matrix3::identity;

};

