
#include "btree_internal_header.h"

struct s_node	*btree_new(void)
{
	return (NULL);
}

/*
** Delete Constructor use suffix method.
*/

int		btree_delete(struct s_node *root, int (*deallocator)(void *))
{
	if (root) {
		if (deallocator == NULL)
			return (-EINVAL);
		if (root->left)
			btree_delete(root->left, deallocator);
		if (root->right)
			btree_delete(root->right, deallocator);
		deallocator(root);
	}
	return (0);
}

size_t		btree_get_node_size(void)
{
	return (sizeof(struct s_node));
}
