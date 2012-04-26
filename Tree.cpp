#include "Tree.hpp"

Tree::Tree()
{
	left = NULL;
	right = NULL;
}

Tree::Tree(T value)
{
	info = value;
	left = NULL;
	right = NULL;
}

Tree::Tree(T value, const Tree &left, const Tree &right)
{
	info = value;
	this->left = &left;
	this->right = &right;
}

T get_root() const
{
	return info;
}

int get_depth() const
{
	return depth;
}

bool has_children() const
{
	return left == NULL and right == NULL;
}

bool has_right() const
{
	return right == NULL;
}

Tree get_left()
{
	return *(this->left);
}

Tree get_right()
{
	return *(this->right);
}