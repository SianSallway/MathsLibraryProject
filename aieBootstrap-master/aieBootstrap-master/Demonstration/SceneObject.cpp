#include "SceneObject.h"
#include<assert.h>
#include <iostream>

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