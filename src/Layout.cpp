/*
 * Layout.cpp
 *
 *  Created on: 4 feb 2012
 *      Author: anders
 */

#include "Layout.h"

using namespace std;

Layout::Layout(): id(-1), parentId(-1) {
	// TODO Auto-generated constructor stub

}

int Layout::getId() const
{
    return id;
}

int Layout::getParentId() const
{
    return parentId;
}

void Layout::setId(int id)
{
    this->id = id;
}

Layout::Layout(int id, int parentId): id(id), parentId(parentId)
{
}

void Layout::addChild(Layout layout)
{
	childs.push_back(layout);
}

std::vector<Layout> Layout::getChilds() const
{
	return this->childs;
}

void Layout::setParentId(int parentId)
{
    this->parentId = parentId;
}

const bool operator ==(const Layout & lhs, const Layout & rhs)
{
	return lhs.getId() == rhs.getId() &&
			lhs.getParentId() == rhs.getParentId() &&
			lhs.getChilds() == rhs.getChilds();
}





