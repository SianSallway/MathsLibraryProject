#include "SceneObject.h"
#include <assert.h>
#include <iostream>
//current
using namespace std;

SceneObject::SceneObject()
{
}

SceneObject::~SceneObject()
{
	//detach from parent 
	if (parent != nullptr)
	{
		parent->RemoveChild(this);

		//remove all children 
		for (auto child : children)
		{
			child->parent = nullptr;
		}
	}
}

void SceneObject::AddChild(SceneObject* child)
{
	//make sure it doesn't have a parent already
	assert(child->parent == nullptr);

	//assign "this" as parent
	child->parent = this;

	//add new child to collection
	children.push_back(child);
}

void SceneObject::RemoveChild(SceneObject* child)
{
	//find the child in the collection
	auto iter = find(children.begin(), children.end(), child);

	//if found, remove it 
	if (iter != children.end())
	{
		children.erase(iter);
		//also unassign parent
		child->parent = nullptr;
	}
}

void SceneObject::Update(float deltaTime)
{
	//run OnUpdate behaviour 
	OnUpdate(deltaTime);

	//update children
	for (auto child : children)
	{
		child->Update(deltaTime);
	}
}

void SceneObject::UpdateTransform()
{
	if (parent != nullptr)
	{
		globalTransform = parent->globalTransform * localTransform;
	}
	else
	{
		globalTransform = localTransform;
	}

	for (auto child : children)
	{
		child->UpdateTransform();
	}
}

void SceneObject::Draw(aie::Renderer2D* renderer)
{
	//run OnDraw behaviour
	OnDraw(renderer);

	//draw children
	for (auto child : children)
	{
		child->Draw(renderer);
	}
}

const Matrix3& SceneObject::GetLocalTransform() const
{
	return localTransform;
}

const Matrix3& SceneObject::GetGobalTransform() const
{
	return globalTransform;
}

void SceneObject::SetPosition(float x, float y)
{
	localTransform[2] = {x, y, 1};
	UpdateTransform();
}

void SceneObject::SetRotate(float radians)
{
	localTransform.SetRotateZ(radians);
	UpdateTransform();
}

void SceneObject::Rotate(float radians)
{
	std::cout << radians << std::endl;

	localTransform.RotateZ(radians);
	UpdateTransform();
}

void SceneObject::SetScale(float width, float height)
{
	localTransform.SetScaled(width, height, 1);
	UpdateTransform();
}

void SceneObject::Scale(float width, float height)
{
	localTransform.Scale(width, height, 1);
	UpdateTransform();
}

void SceneObject::Translate(float x, float y)
{
	localTransform.Translate(x, y);
	UpdateTransform();
}