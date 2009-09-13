

ll:ll(void* inEle, type inType)
{
   e = inEle;
   t = inType;
}

void ll::~ll()
{
   prev.next = next;
   next.prev = prev;
   free(e);
}

//adds supplied node to end of this node
void add(ll* newnode)
{
   next = newnode;
   newnode.prev = this;
}
