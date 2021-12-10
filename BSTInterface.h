//YOU MAY NOT MODIFY THIS DOCUMENT

#pragma once

#include "NodeTreeInterface.h"

using namespace std;

class BSTInterface {
public:
	BSTInterface() = default;
	virtual ~BSTInterface() = default;

	//Please note that the class that implements this interface must be made
	//of objects which implement the NodeInterface

	/*
	* Returns the root node for this tree
	*
	* @return the root node for this tree.
	*/
    [[maybe_unused]] [[nodiscard]] virtual NodeTreeInterface * getRootNode() const = 0;

	/*
	* Attempts to add the given int to the BST tree
	*
	* @return true if added
	* @return false if unsuccessful (i.e. the int is already in tree)
	*/
    [[maybe_unused]] virtual bool add(int data) = 0;

	/*
	* Attempts to remove the given int from the BST tree
	*
	* @return true if successfully removed
	* @return false if remove is unsuccessful(i.e. the int is not in the tree)
	*/
    [[maybe_unused]] virtual bool remove(int data) = 0;

	/*
	* Removes all nodes from the tree, resulting in an empty tree.
	*/
    [[maybe_unused]] virtual void clear() = 0;
};
