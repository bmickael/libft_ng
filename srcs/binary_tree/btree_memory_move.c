
#include "btree_internal_header.h"

typedef unsigned int u32;

static void	*btree_aligned_memcpy_four(
	void *restrict dst,
	const void *restrict src,
	size_t n)
{
	u32 *src1;
	u32 *dst1;

	if (src == dst)
		return ((void *)src);
	src1 = (u32 *)src;
	dst1 = (u32 *)dst;
	n >>= 2;
	while (n--)
		*dst1++ = *src1++;
	return (dst);
}

int		btree_memory_move(void *dest, struct s_node *src_node)
{
	struct s_node	*dest_node;
	int		parent_position;

	if (src_node == NULL || dest == NULL)
		return (-EINVAL);
	if (src_node->parent)
		parent_position = (src_node->parent->left == src_node) ? -1 : 1;
	else
		parent_position = 0;
	btree_aligned_memcpy_four(dest, src_node, sizeof(struct s_node));
	dest_node = (struct s_node *)dest;
	if (dest_node->left)
		dest_node->left->parent = dest_node;
	if (dest_node->right)
		dest_node->right->parent = dest_node;
	if (parent_position == -1)
		dest_node->parent->left = dest_node;
	else if (parent_position == 1)
		dest_node->parent->right = dest_node;
	return (0);
}
