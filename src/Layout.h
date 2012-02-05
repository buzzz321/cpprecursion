/*
 * Layout.h
 *
 *  Created on: 4 feb 2012
 *      Author: anders
 */

#ifndef LAYOUT_H_
#define LAYOUT_H_
#include <vector>

class Layout {
public:
	Layout();
	Layout(int id, int parentId);
	void addChild(Layout layout);
	std::vector<Layout> getChilds() const;

	bool hasChilds() {
		return childs.size() > 0;
	}

	int getId() const;
    int getParentId() const;
    void setId(int id);
    void setParentId(int parentId);
private:
    std::vector<Layout> childs;
    int id;
    int parentId;
};

const bool operator==(const Layout& lhs, const Layout& rhs);

#endif /* LAYOUT_H_ */
