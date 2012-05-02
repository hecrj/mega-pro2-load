#ifndef TREE_HPP
#define TREE_HPP

template T class Tree
{
	private:
		struct Node
		{
			T value;
			Node* left;
			Node* right;
		};
		Node* first;

		static Node* copy_node(Node* node);
		static void delete_node(Node* node);

	public:
		Tree();
		Tree(const Tree& original);

		T get_root() const;
		bool is_empty() const;

		void clear();
		void plant(T value, Tree &t_left, Tree &t_right);
		void children(Tree &t_left, Tree &t_right) const;

};

#endif