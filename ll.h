enum type
{
   charp,
   doublep
};

struct ll
{
   void* x;
   type t;

   ll *next;
   ll *prev;

   ll(void*, type);
   ~ll();

   add(ll*);
}  
   