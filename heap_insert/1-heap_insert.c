#include "binary_trees.h"

/**
 * tree_size - measures the size of a binary tree
 * @tree: pointer to the root node of the tree
 *
 * Return: size of the tree, or 0 if tree is NULL
 */
size_t tree_size(const heap_t *tree)
{
	if (!tree)
		return (0);

	return (1 + tree_size(tree->left) + tree_size(tree->right));
}

/**
 * find_parent - finds the parent node for insertion
 * @root: pointer to the root node
 * @index: index where to insert (1-based)
 *
 * Return: pointer to the parent node
 */
heap_t *find_parent(heap_t *root, size_t index)
{
	heap_t *left, *right;

	if (!root)
		return (NULL);

	if (index == 1)
		return (root);

	left = find_parent(root->left, index / 2);
	right = find_parent(root->right, index / 2);

	if (index % 2 == 0)
		return (left ? left : right);
	else
		return (right ? right : left);
}

/**
 * insert_at_position - inserts node at the correct position
 * @root: double pointer to the root node
 * @value: value to insert
 * @size: current size of the tree
 *
 * Return: pointer to the inserted node
 */
heap_t *insert_at_position(heap_t **root, int value, size_t size)
{
	heap_t *parent, *new_node;
	size_t parent_index;

	parent_index = (size + 1) / 2;
	parent = find_parent(*root, parent_index);

	new_node = binary_tree_node(parent, value);
	if (!new_node)
		return (NULL);

	if ((size + 1) % 2 == 0)
		parent->left = new_node;
	else
		parent->right = new_node;

	return (new_node);
}

/**
 * heapify_up - maintains max heap property by moving node up
 * @node: pointer to the inserted node
 *
 * Return: pointer to the final position of the node
 */
heap_t *heapify_up(heap_t *node)
{
	int temp;

	while (node->parent && node->n > node->parent->n)
	{
		temp = node->n;
		node->n = node->parent->n;
		node->parent->n = temp;
		node = node->parent;
	}

	return (node);
}

/**
 * heap_insert - inserts a value into a Max Binary Heap
 * @root: double pointer to the root node of the Heap
 * @value: value to store in the node to be inserted
 *
 * Return: pointer to the inserted node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node;
	size_t size;

	if (!root)
		return (NULL);

	if (!*root)
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}

	size = tree_size(*root);
	new_node = insert_at_position(root, value, size);
	if (!new_node)
		return (NULL);

	return (heapify_up(new_node));
}
