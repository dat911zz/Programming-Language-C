/*Bài này bao gồm
- Hàm kiểm tra danh sách rỗng
- Hàm giải phóng toàn bộ danh sách
- Hàm xuất danh sách
- Hàm xuất danh sách theo chiều ngược
- Hàm đảo danh sách
- Hàm kiểm tra danh sách đối xứng
- Hàm trả về nút mang giá trị lớn nhất
- Hàm trả về nút mang giá trị nhỏ nhất
- Hàm tìm nút mang giá trị được chỉ định
*/

//Kiểm tra danh sách rỗng
template <class data>
bool DList<data>::isEmpty()
{
  return head == NULL;
}

//Giải phóng toàn bộ danh sách
template <class data>
void DList<data>::del()
{
  if(head == NULL)
    return;
  
  Tnode<data>* p = head;
  
  for(; head;)
  {
    head = head->right;
    delete p;
    p = head;
  }
  
  tail = NULL;
  len = 0;
}

/*Ta có thể sử dụng kỹ thuật đệ quy để giải phóng theo chiều ngược lại, 
Hàm sau đây không thuộc lớp DList
*/

/*//Hàm giải phóng danh sách
template <class data>
void DList_del(Tnode<data>* head)     //Nhận vào một nút đầu danh sách
{
  if(head == NULL)
    return;
  
  DList_del(head->right);
  delete head;
}

//Giải phóng toàn bộ danh sách
template <class data>
void DList<data>::del()
{
  if(head == NULL)
    return;
  
  DList_del(head);
  head = tail = NULL;
  len = 0;
}
*/

//Xuất danh sách
template <class data>
void DList<data>::show()
{
  for(Tnode<data>* i = head; i; i = i->right)
    std::cout << i->info << " ";
  std::cout << "NULL\n";
}

//Xuất danh sách theo chiều ngược
template <class data>
void DList<data>::showrev()
{
  std::cout << "NULL";
  for(Tnode<data>* i = tail; i; i = i->left)
    std::cout  << " " << i->info;
  std::cout << '\n';
}

//Hàm hoán vị
template <class data>
void swap(data &a, data& b)
{
  data temp = a;
  a = b;
  b = temp;
}

//Đảo danh sách
template <class data>
void DList<data>::reverse()
{
  if(len <= 1)
    return;
  
  for(Tnode<data>* i = head, * j = tail; i != j && i != j->right; i = i->right, j = j->left)
    swap(i->info, j->info);
}

//Kiểm tra danh sách đối xứng
template <class data>
bool DList<data>::isSymmetry()
{
  if(head == NULL)
    return false;
  
  for(Tnode<data>* i = head, * j = tail; i != j && i != j->right; i = i->right, j = j->left)
    if(i->info != j->info)
      return false;
  return true;
}

//Trả về nút mang giá trị lớn nhất
template <class data>
Tnode<data>* DList<data>::max()
{
  if(head == NULL)
    return NULL;
  
  Tnode<data>* max = head;
  for(Tnode<data>* i = head->right; i; i = i->right)
    if(max->info < i->info)
      max = i;
  return max;
}

//Trả về nút mang giá trị nhỏ nhất
template <class data>
Tnode<data>* DList<data>::min()
{
  if(head == NULL)
    return NULL;
  
  Tnode<data>* min = head;
  for(Tnode<data>* i = head->right; i; i = i->right)
    if(min->info > i->info)
      min = i;
  return min;
}

//Tìm nút mang giá trị được chỉ định
template <class data>
Tnode<data>* DList<data>::find(data element)
{
  if(head == NULL)
    return NULL;
  
  for(Tnode<data>* i = head; i; i = i->right)
    if(i->info == element)
      return i;
  return NULL;
}
