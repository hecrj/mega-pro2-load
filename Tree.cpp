#include "Tree.hpp"

Tree::Tree()
{
	depth = 0;
	left = NULL;
	right = NULL;
}

Tree::Tree(T value)
{
	info = value;
	depth = 0;
	left = NULL;
	right = NULL;
}

Tree::Tree(T value, int depth)
{
	info = value;
	depth = depth;
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

void children(Tree &left, Tree &right)
{
	left = *(this->left);
	right = *(this->right);
}