#include "Tree.hpp"

template <class T>
Tree::Tree()
{
	first = NULL;
}

template <class T>
Tree::Tree(const Tree &original)
{
	first = copy_node(original.first);
}

template <class T>
~Tree::Tree()
{
	delete_node(first);
}

template <class T>
Tree& Tree::operator=(const Tree &original)
{
	if(this != &original)
	{
		delete_node(first);
		first = copy_node(original.first);
	}

	return *this;
}

template <class T>
T get_root() const
{
	return first->value;
}

template <class T>
bool is_empty() const
{
	return (first == NULL);
}

template <class T>
void Tree::clear()
{
	delete_node(first);
	first = NULL;
}

template <class T>
void Tree::plant(T &value, Tree& t_left, Tree &t_right)
{
	Node* node;
	node = new Node;
	node->value = value;
	node->left = t_left.first;

	if(t_right.first != t_left.first or t_right.first == NULL)
		node->right = t_right.first;
	else
		node->right = copy_node(t_right.first);

	first = node;
	t_left.first = NULL;
	t_right.first = NULL;
}

template <class T>
void Tree::children(Tree &t_left, Tree &t_right) const
{
	//Node* node;
	//node = first;

	t_left.first = first->left;
	t_right.first = first->right;

	//first = NULL;
	//delete node;
}

template <class T>
static Node* Tree::copy_node(Node* node)
{
	if(node == NULL)
		return NULL;

	Node *node_copy = new Node;
	
	node_copy->value = node->value;
	node_copy->left = copy_node(node->left);
	node_copy->right = copy_node(node->right);

	return node_copy;
}

template <class T>
static void Tree::delete_node(Node* node)
{
	if(node == NULL)
		return;

	delete_node(node->left);
	delete_node(node->right);
	delete node;
}
