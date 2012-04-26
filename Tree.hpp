#ifndef TREE_HPP
#define TREE_HPP

template T class Tree
{
	private:
		T info;
		int depth;
		Tree* left;
		Tree* right;

	public:
		Tree();
		Tree(T value);
		Tree(T value, int depth);

		T get_root() const;
		int get_depth() const;

		void children(Tree &left, Tree &right) const;

};

#endif