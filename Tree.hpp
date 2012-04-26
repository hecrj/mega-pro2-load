#ifndef TREE_HPP
#define TREE_HPP

template T class Tree
{
	private:
		T info;
		Tree* left;
		Tree* right;

	public:
		Tree();
		Tree(T value);
		Tree(T value, const Tree &left, const Tree &right);

		T get_root() const;
		bool has_children() const;
		bool has_right() const;
		Tree get_left() const;
		Tree get_right() const;

};

#endif