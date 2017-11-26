void l_merge(slistEl * & h1, slistEl * & h2, slistEl * & h)
{
  slistEl * p;
  l_push_front(h,0);
  p = h;
  while(h1 && h2)
  {
    if(h1->data > h2->data)
    {
      p->next = h2;
      h2 = h2->next;
    }
    else
    {
      p->next = h1;
      h1 = h1->next;
    }
    p = p->next;
  }
  while(h1)
  {
    p->next = h1;
    h1 = h1->next;
    p  = p->next;
  }
  while(h2)
  {
    p->next = h2;
    h2 = h2->next;
    p  = p->next;
  }
  l_pop_front(h);
} 
//komentarz 2