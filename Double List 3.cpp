/*Bài này bao gồm
- Các hàm thêm một nút vào danh sách
- Các hàm xóa một nút trong danh sách
*/

//Thêm một nút mang giá trị element vào đầu danh sách
template <class data>
void DList<data>::addhead(data element)
{
  Tnode<data>* p = new Tnode<data>(element);
  
  if(head == NULL)
  {
    head = tail = p;
    len = 1;
    return;
  }
  
  p->right = head;
  head->left = p;
  head = p;
  len++;
}

//Thêm một nút element vào đầu danh sách
template <class data>
void DList<data>::addhead(Tnode<data>* element)
{
  if(element == NULL)
    return;
  
  if(head == NULL)
  {
    head = tail = element;
    element->left = element->right = NULL;
    len = 1;
    return;
  }
  
  element->left = NULL;
  element->right = head;
  head->left = p;
  head = p;
  len++;
}

//Thêm một nút mang giá trị element vào cuối danh sách
template <class data>
void DList<data>::addtail(data element)
{
  Tnode<data>* p = new Tnode<data>(element);
  
  if(head == NULL)
  {
    head = tail = p;
    len = 1;
    return;
  }
  
  tail->right = p;
  p->left = tail;
  tail = p;
  len++;
}

//Thêm một nút element vào cuối danh sách
template <class data>
void DList<data>::addtail(Tnode<data>* element)
{
  if(element == NULL)
    return;
  
  if(head == NULL)
  {
    head = tail = element;
    element->left = element->right = NULL;
    len = 1;
    return;
  }
  
  element->right = NULL;
  tail->right = p;
  p->left = tail;
  tail = p;
  len++;
}

//Thêm một nút mang giá trị element vào kế nút p : before = true thêm vào trước p - before - false thêm vào sau p
template <class data>
void DList<data>::addbet(Tnode<data>* p, data element, bool before = true)
{
  if(p == NULL || head == NULL)
    return;
  
  Tnode<data>* k = new Tnode<data>(element);
  
  k->right = p->right;
  if(p->right)
    p->right->left = k;
  p->right = k;
  k->left = p;
  
  if(before)
    swap(p->info, k->info);
  
  if(tail == p)
    tail = k;
  len++;
}

//Thêm một nút element vào kế nút p : before = true thêm vào trước p - before - false thêm vào sau p
template <class data>
void DList<data>::addbet(Tnode<data>* p, Tnode<data>* element, bool before = true)
{
  if(p == NULL || head == NULL || element == NULL)
    return;
  
  element->right = p->right;
  if(p->right)
    p->right->left = element;
  p->right = element;
  element->left = p;
  
  if(before)
    swap(p->info, element->info);
  
  if(tail == p)
    tail = element;
  len++;
}

//Xóa nút đầu
template <class data>
void DList<data>::delhead()
{
  if(head == NULL)
    return;
  
  Tnode<data>* p = head;
  
  if(len == 1)
  {
    head = tail = NULL;
    len = 0;
    delete p;
    return;
  }
  
  head = head->right;
  head->left = NULL;
  delete p;
  len--;
}

//Xóa nút cuối
template <class data>
void DList<data>::deltail()
{
  if(head == NULL)
    return;
  
  Tnode<data>* p = tail;
  
  if(len == 1)
  {
    head = tail = NULL;
    len = 0;
    delete p;
    return;
  }
  
  tail = tail->left;
  tail->right = NULL;
  delete p;
  len--;
}

//Xóa nút element
template <class data>
void DList<data>::delnode(Tnode<data>* element)
{
  if(head == NULL || element == NULL)
    return;
  
  if(len == 1)
  {
    if(head != element)
      return;
    
    delete element;
    head = tail = NULL;
    len = 0;
    return;
  }
  
  if(head == element)
  {
    head = head->right;
    head->left = NULL;
    delete element;
    len--;
    return;
  }
  
  Tnode<data>* p = element->left;
  
  p->right = element->right;
  if(p->right)
    p->right->left = p;
    
  if(tail == element)
    tail = p;
  
  delete element;
  len--;
}
     
//Xóa nút mang giá trị element
template <class data>
void DList<data>::delnode(data element)
{
  if(head == NULL)
    return;
  
  for(Tnode<data>* i = head; i; i = i->right)
    if(i->info == element)
    {
      delnode(i);
      break;
    }
}
