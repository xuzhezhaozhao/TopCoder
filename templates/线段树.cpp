struct Node         // 线段树
{
	int left;
	int right;
	int counter;
}segTree[4*BORDER]; 

/* 构建线段树 根节点开始构建区间[lef,rig]的线段树*/
void construct(int index, int lef, int rig)
{
	segTree[index].left = lef;
	segTree[index].right = rig;
	if(lef == rig)   // 叶节点
	{
		segTree[index].counter = 0;
		return;
	}
	int mid = (lef+rig) >> 1;
	construct((index<<1)+1, lef, mid);
	construct((index<<1)+2, mid+1, rig);
	segTree[index].counter = 0;
}

/* 插入线段[start,end]到线段树, 同时计数区间次数 */
void insert(int index, int start, int end)
{
	if(segTree[index].left == start && segTree[index].right == end)
	{
		++segTree[index].counter;
		return;
	}
	int mid = (segTree[index].left + segTree[index].right) >> 1;
	if(end <= mid)//左子树 
	{
		insert((index<<1)+1, start, end);
	}else if(start > mid)//右子树 
	{
		insert((index<<1)+2, start, end);
	}else//分开来了 
	{
		insert((index<<1)+1, start, mid);
		insert((index<<1)+2, mid+1, end);
	}
}

/* 查询点x的出现次数 
 * 从根节点开始到[x,x]叶子的这条路径中所有点计数相加方为x出现次数
 */
int query(int index, int x)
{
	if(segTree[index].left == segTree[index].right) // 走到叶子，返回
	{
		return segTree[index].counter;
	}
	int mid = (segTree[index].left+segTree[index].right) >> 1;
	if(x <= mid)
	{
		return segTree[index].counter + query((index<<1)+1,x);
	}
	return segTree[index].counter + query((index<<1)+2,x);
}

void  delete_ (int c , int  d, int index)
{
       if(c <= segTree[index].left && d >= segTree[index].right) 
           segTree[index].counter--;
       else 
       {
          if(c < (segTree[index].left + segTree[index].right)/2 ) delete_( c,d, segTree[index].left);
          if(d > (segTree[index].left + segTree[index].right)/2 ) delete_( c,d, segTree[index].right);
       }
} 