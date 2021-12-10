//YOU MAY NOT MODIFY THIS DOCUMENT

#pragma once

#include <iostream>

class NodeTreeInterface {

public:
    NodeTreeInterface() = default;
	virtual ~NodeTreeInterface() = default;

	/*
	* Returns the data that is stored in this node
	*
	* @return the data that is stored in this node.
	*/
    [[maybe_unused]] [[nodiscard]] virtual int getData() const = 0;

	/*
	* Returns the left child of this node or null if it doesn't have one.
	*
	* @return the left child of this node or null if it doesn't have one.
	*/
    [[maybe_unused]] [[nodiscard]] virtual NodeTreeInterface * getLeftChild() const = 0;

	/*
	* Returns the right child of this node or null if it doesn't have one.
	*
	* @return the right child of this node or null if it doesn't have one.
	*/
    [[maybe_unused]] [[nodiscard]] virtual NodeTreeInterface * getRightChild() const = 0;

};
