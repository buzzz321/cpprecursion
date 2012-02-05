//============================================================================
// Name        : clooper.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

#include "Layout.h"

using namespace std;

void removeVectorItem(vector<Layout> & data)
{
    //Find new end iterator
    std::vector<Layout>::iterator newEnd = std::remove(data.begin(), data.end(), data[0]);
    //Erase the "removed" elements.
    data.erase(newEnd, data.end());
}

void indent(vector<Layout> data, vector<pair<int,int> > *flattenedData, int indenLevel){
	if (data.empty()){
		return;
	}

	cout << data[0].getId() << " parent: " << indenLevel << endl;
	flattenedData->push_back(pair<int,int>(data[0].getId(), indenLevel));

	indent(data[0].getChilds(), flattenedData, indenLevel + 1);

	//Find new end iterator
    removeVectorItem(data);
	indent(data, flattenedData, indenLevel);
}

int main() {
	Layout X(0,0);

	Layout A(1,0);
	Layout Ac(2,1);
	Layout Acc(4,2);

	Layout B(3,0);
	Layout Bc(5,3);

	Ac.addChild(Acc);
	A.addChild(Ac);

	B.addChild(Bc);

	X.addChild(A);
	X.addChild(B);

	vector<Layout> data;
	vector<pair<int,int> > flatter;

	data.push_back(X);

	indent(data, &flatter, 0);

	for(vector<pair<int,int> >::iterator iter = flatter.begin(); iter < flatter.end(); ++iter) {
		cout<<"id["<<iter->first<<"]="<<iter->second<<endl;
	}

	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	return 0;
}
