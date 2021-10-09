/*Danh sách liên kết đôi : Double List
Danh sách liên kết đôi gồm một dãy các nút, mỗi nút gồm 2 con trỏ nối với nút phía trước và nút phía sau nó
Vì thế ta có thể duyệt xuôi hay ngược danh sách này

So với 'danh sách liên kết đơn' Single List :
  - Ưu điểm
    + Danh sách liên kết đơn có một vài thao tác thêm, xóa có độ phức tạp O(n), chỉ có thể duyệt một chiều, khó thao tác
    + Danh sách liên kết đôi : các thao tác thêm, xóa luôn có độ phức tạp O(1), có thể duyệt hai chiều, dễ dàng cài đặt các thuật toán như trên mảng một chiều
    
  - Nhược điểm : cần thêm một con trỏ để nối với phần tử trước nó, tốn thêm bộ nhớ

Vì các nút của danh sách liên kết đôi đều có 2 con trỏ, giống với các nút của một cây nhị phân nên mình sẽ dùng nút của cây nhị phân luôn để khỏi phải tạo lại
Như vậy ta sẽ dùng nút có hai con trỏ : left ( trỏ tới phần tử trước nó ), right ( trỏ tới phần tử sau nó )
*/

#include<iostream>

//====================================================================================================
template <class data>
class Tnode{
  public:
    data info;
    Tnode* left, * right;           //LEFT : TRỎ TỚI NÚT TRƯỚC NÓ - RIGHT : TRỎ TỚI NÚT SAU NÓ
    
  //HÀM KHỞI TẠO
  Tnode(data element = 0);
  
  //HÀM BỔ TRỢ
  void change(data element);        //Thay đổi lại giá trị của nút
};

template <class data>
Tnode<data>::Tnode(data element)
{
  info = element;
  left = right = NULL;
}

template <class data>
void Tnode<data>::change(data element)
{
  info = element;
}
//====================================================================================================
template <class data>
class DList{
  public:
    Tnode<data>* head, * tail;
    unsigned int len;
    
  //HÀM KHỞI TẠO
  DList();                            //Khởi tạo một danh sách rỗng
  //NÂNG CAO
  DList(unsigned int length, ...);             //Khởi tạo một danh sách có số nút được chỉ định
  
  //HÀM BỔ TRỢ : sẽ được viết ở các bài sau
  bool isEmpty();                     //Trả về true nếu danh sách rỗng
  void del();                         //Giải phóng toàn bộ danh sách
  void show();                        //In danh sách theo chiều xuôi
  void showrev();                     //In danh sách theo chiều ngược
  void reverse();                     //Đảo danh sách O(n)
  bool isSymmetry();                  //Trả về true nếu danh sách đối xứng  O(n)
  
  void addhead(data element);         //Thêm một nút vào đầu danh sách
  void addhead(Tnode<data>* element); //Thêm một nút vào đầu danh sách
  void addtail(data element);         //Thêm một nút vào cuối danh sách
  void addtail(Tnode<data>* element); //Thêm một nút vào cuối danh sách
  void addbet(Tnode<data>* p, data element, bool before = true);          //true : thêm một nút vào trước nút p - false : thêm một nút vào sau nút p
  void addbet(Tnode<data>* p, Tnode<data>* element, bool before = true);  //true : thêm một nút vào trước nút p - false : thêm một nút vào sau nút p
  
  void delhead();                     //Xóa nút đầu danh sách
  void deltail();                     //Xóa nút cuối danh sách
  void delnode(data element);         //Xóa nút đầu tiên mang giá trị element
  void delnode(Tnode<data>* element); //Xóa nút element
  
  Tnode<data>* max();                 //Trả về nút mang giá trị lớn nhất
  Tnode<data>* min();                 //Trả về nút mang giá trị nhỏ nhất
  Tnode<data>* find(data element);    //Trả về nút mang giá trị element được chỉ định
  
  void sort_interchange(bool ascending = true);       //Sắp xếp danh sách : O(n^2)
  void sort_shaker(bool ascending = true);            //Sắp xếp danh sách : O(n^2) hoặc O(n)
  void sort_insertion(bool ascending = true);         //Sắp xếp danh sách : O(n^2) hoặc O(n)
  void sort_selection(bool ascending = true);         //Sắp xếp danh sách : O(n^2)
  void sort_quick(bool ascending = true);             //Sắp xếp danh sách : O(n^2) hoặc O(n logn)
};
  
//Khởi tạo DList rỗng
template <class data>
DList<data>::DList()
{
  head = tail = NULL;
  len = 0;
}
  
//Khai báo thư viện stdarg.h
#include<stdarg.h>

//Khởi tạo DList có sẵn các nút
template <class data>
DList<data>::DList(unsigned int length, ...)
{
  if(length == 0)
  {
    head = tail = NULL;
    len = 0;
    return;
  }
  
  va_list list;
  va_start(list, length);
  
  head = tail = new Tnode<data>(va_arg(list, data));      //Tạo nút đầu tiên
  len = length;
  
  for(int i = 1; i < length; i++, tail = tail->right)
  {
    tail->right = new Tnode<data>(va_arg(list, data));    //Tạo các nút kế tiếp
    tail->right->left = tail;
  }
  
  va_end(list);
}

/*Hoặc ta có thể sử dụng đệ quy để tạo n nút, sau đó mới gán giá trị vào
Hàm sau đây không thuộc lớp DList*/

/*//Tạo n nút được chỉ định
template <class data>
Tnode<data>* new_nTnode(int n)
{
  if(n <= 0)
  return NULL;
  
  Tnode<data>* p = new Tnode<data>();
  p->right = new_nTnode<data>(n - 1);
  
  if(p->right)
    p->right->left = p;
  
  return p;
}

//Khởi tạo DList có sẵn các nút
template <class data>
DList<data>::DList(unsigned int length, ...)
{
  if(length == 0)
  {
    head = tail = NULL;
    len = 0;
    return;
  }
  
  va_list list;
  va_start(list, length);
  head = tail = new_nTnode<data>(length);
  len = length;
  
  for(;; tail = tail->right)
  {
    tail->info = va_arg(list, data);
    if(tail->right == NULL)
      break;
  }
    
  va_end(list);
}
*/
