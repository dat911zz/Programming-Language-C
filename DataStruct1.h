/* Danh sách liên kết đơn : Single List
- Sử dụng "template <class ...>" : cho phép bạn cài đặt, sử dụng với mọi kiểu dữ liệu : int, double, char, ...
- Sử dụng "class" thay vì "struct" : nếu bạn chưa học HƯỚNG ĐỐI TƯỢNG thì không cần lo, cách cài đặt sẽ không khác mấy với "struct"
- Cài đặt một số hàm cơ bản về danh sách liên kết đơn : khởi tạo, thêm nút, xóa nút, tìm kiếm nút, ...
*/

#include<iostream>

//Khai báo prototype ở đầu chương trình
template <class data> class node;        //Lớp nút đơn
template <class data> class SList;       //Lớp danh sách liên kết đơn

//====================================================================================================
template <class data>       //data : là một kiểu dữ liệu mà bạn muốn sử dụng : int, double, char, ...
class node {
public:       //Cho phép truy cập từ bên ngoài lớp
    data info;      //Kiểu dữ liệu của nút
    node* next;     //Thành phần truy cập đến nút tiếp theo

  //Dưới đây : mỗi hàm sẽ được cài đặt ở các bài riêng theo thứ tự  

  //HÀM KHỞI TẠO : không có kiểu trả về, tên hàm trùng với tên lớp
    node(data value = 0);         //Mặc định là 0 nếu không thêm tham số

    /*Cách khai báo
    node<int> a;                    //Hoặc node<int> a(5);
    node<char> a;                   //Hoặc node<char> a('a');
    node<int>* p = new node<int>;   //Hoặc node<int>* p = new node<int>(5);

    Khi sử dụng "struct", khai báo một biến node : node a;
    - Bạn phải làm thêm một việc đó là gán giá trị cho nút và gán con trỏ next của nút đó bằng NULL

    Đối với sử dụng "class", khai báo một biến node : node a(5);
    - Nút a đã có giá trị là 5 và con trỏ next của nó đã bằng NULL
    - Bạn sẽ không cần phải lăn tăn việc đã gán giá trị cho nó chưa, giảm bớt nhiều thao tác, tránh lỗi khi sử dụng*/

    //HÀM BỔ TRỢ : có kiểu trả về
    void change(data value);        //Thay đổi lại giá trị của nút
};

template <class data>             //Khởi tạo nút
node<data>::node(data value)
{
    info = value;
    next = NULL;
}

template <class data>             //Thay đổi lại giá trị của nút
void node<data>::change(data value)
{
    info = value;
}
//====================================================================================================
template <class data>
class SList {
public:
    node<data>* head, * tail;           //Con trỏ đầu và con trỏ cuối của danh sách
    int len;                            //Độ dài của Single List

  //HÀM KHỞI TẠO
    SList();                              //Khởi tạo danh sách rỗng
    //NÂNG CAO
    SList(int length, ...);               //Khởi tạo danh sách có sẵn các nút

    //PHƯƠNG THỨC : được viết ở các bài sau
    void operator=(SList<data> list);

    //HÀM BỔ TRỢ : được viết ở các bài sau
    bool isEmpty();                       //Trả về true nếu danh sách rỗng
    void show();                          //Xuất toàn bộ danh sách để xem
    void showrev();                       //Xuất danh sách theo chiều ngược
    void del();                           //Giải phóng toàn bộ danh sách
    void reverse();                       //Đảo danh sách             O(n)
    bool isSymmetry();                    //Trả về true nếu danh sách đối xứng  O(n)

    void addhead(data element);           //Thêm vào đầu danh sách    O(1)
    void addhead(node<data>* element);    //Thêm vào đầu danh sách    O(1)
    void addtail(data element);           //Thêm vào cuối danh sách   O(1)
    void addtail(node<data>* element);    //Thêm vào cuối danh sách   O(1)
    void addbet(node<data>* p, data element, bool before = true);            //before = true : thêm vào trước p - before = false : thêm vào sau p   O(1)
    void addbet(node<data>* p, node<data>* element, bool before = true);     //before = true : thêm vào trước p - before = false : thêm vào sau p   O(1)

    void delhead();                       //Xóa phần tử đầu           O(1)
    void deltail();                       //Xóa phần tử cuối          O(n)
    void delnode(node<data>* element);     //Xóa nút element           O(1) hoặc O(n)

    node<data>* max();                    //Trả về nút lớn nhất - danh sách rỗng thì trả về NULL                                  O(n)
    node<data>* min();                    //Trả về nút nhỏ nhất - danh sách rỗng thì trả về NULL                                  O(n)
    node<data>* find(data element);       //Tìm nút mang giá trị element - danh sách rỗng hoặc không tìm thấy thì trả về NULL     O(n)

    void sort_interchange(bool ascending = true);              //Sắp xếp danh sách : dùng Interchange Sort     O(n^2)
    void sort_buble(bool ascending = true);                    //Sắp xếp danh sách : dùng Buble Sort           O(n^2)
    void sort_insertion(bool ascending = true);                //Sắp xếp danh sách : dùng Insertion Sort       O(n^2) hoặc O(n)
    void sort_selection(bool ascending = true);                //Sắp xếp danh sách : dùng Selection Sort       O(n^2)
};

//Khởi tạo danh sách rỗng
template <class data>
SList<data>::SList()
{
    head = tail = NULL;
    len = 0;
}

/*NÂNG CAO : thêm thư viện stdarg.h
Tiện lợi cho việc thử nghiệm : khai báo một danh sách có sẵn các nút
Ví dụ : SList<int> list(5, 9, 8, 7, 6, 5);
- Lúc này danh sách liên kết gồm 5 nút : 9 8 7 6 5

Hãy sử dụng hàm này đúng mục đích để tránh các lỗi
Ví dụ sau đây là sử dụng sai mục đích của hàm : SList<int> list(5, 1, 2, 3, 4);
Khai báo số phần tử là 5 nhưng chỉ bỏ vào 4 phần tử, sẽ gây ra giá trị rác

Trường hợp khai báo dư số phần tử sẽ không gây ra lỗi : SList<int> list(3, 1, 2, 3, 4, 5);
*/

#include<stdarg.h>
//Khởi tạo danh sách có sẵn các nút
template <class data>
SList<data>::SList(int length, ...)
{
    if (length <= 0)
    {
        head = tail = NULL;
        len = 0;
        return;
    }

    len = length;           //Gán độ dài của danh sách

    va_list list;           //Sử dụng biến va_list trong thư viện stdarg.h để di chuyển qua các biến thuộc dấu '...'
    va_start(list, length); //Trỏ vào biến trước dấu '...'

    head = tail = new node<data>(va_arg(list, data));     //Tạo nút đầu tiên mang giá trị của biến đầu tiên trong dấu '...'

    for (int i = 1; i < length; i++, tail = tail->next)    //Tạo length - 1 nút còn lại
        tail->next = new node<data>(va_arg(list, data));    //Tạo các node liên tiếp

    tail->next = NULL;             //Đặt điểm dừng cho tail
}


/*Ta cũng có thể dùng một hàm phụ tạo ra n nút trước, sau đó mới duyệt và gán giá trị cho chúng
Các hàm sau đây sẽ được đóng dấu //
*/

/*Hàm trả về nút đầu của n nút liên kết nhau, hàm này không thuộc lớp SList

template <class data>
node<data>* new_nNode(int n)
{
  if(n <= 0)
    return NULL;

  node<data>* p = new node<data>;
    p->next = new_nNode<data>(n - 1);

    return p;
}

//Khởi tạo danh sách có sẵn các nút
template <class data>
SList<data>::SList(int length, ...)
{
  if(length <= 0)
  {
    head = tail = NULL;
    len = 0;
    return;
  }

  len = length;           //Gán độ dài của danh sách

  va_list list;           //Sử dụng biến va_list trong thư viện stdarg.h để di chuyển qua các biến thuộc dấu '...'
  va_start(list, length); //Trỏ vào biến trước dấu '...'

  head = tail = new_nNode<data>(length);      //Tạo length nút
  for(;; tail = tail->next)
  {
    tail->info = va_arg(list, data);          //Gán giá trị cho từng nút
    if(tail->next == NULL)
      break;
  }
}
*/

//====================================================================================================
//Bài 2     ==========================================================================================
//====================================================================================================

/*Bài này bao gồm các hàm sau
- Thêm một nút vào head : có thể gọi giá trị hoặc một nút có sẵn
- Thêm một nút vào tail : có thể gọi giá trị hoặc một nút có sẵn
- Thêm một nút vào trước, sau nút chỉ định*/

//Tên hàm trùng nhau nhưng khi sử dụng bạn đưa vào giá trị hay một nút thì nó sẽ hiểu

//Thêm một nút vào đầu danh sách : tham số là một giá trị
template <class data>
void SList<data>::addhead(data element)
{
    node<data>* p = new node<data>(element);      //p->next đã bằng NULL

    if (head == NULL)
        head = tail = p;
    else {
        p->next = head;
        head = p;
    }

    len++;
}

//Thêm một nút vào đầu danh sách : tham số là nút có sẵn
template <class data>
void SList<data>::addhead(node<data>* element)
{
    if (element == NULL)
        return;

    if (head == NULL)
    {
        head = tail = element;
        element->next = NULL;
    }
    else {
        element->next = head;
        head = element;
    }

    len++;
}

//Thêm một nút vào cuối danh sách : tham số là một giá trị
template <class data>
void SList<data>::addtail(data element)
{
    node<data>* p = new node<data>(element);      //p->next đã bằng NULL

    if (head == NULL)
        head = tail = p;
    else {
        tail->next = p;
        tail = p;
    }
    len++;
}

//Thêm một nút vào cuối danh sách : tham số là một nút có sẵn
template <class data>
void SList<data>::addtail(node<data>* element)   //element->next chưa chắc đã bằng NULL
{
    if (element == NULL)
        return;

    if (head == NULL)
        head = tail = element;
    else {
        tail->next = element;
        tail = element;
    }

    element->next = NULL;
    len++;
}

//Hàm hoán vị
template <class data>
void swap(data& a, data& b)
{
    data temp = a;
    a = b;
    b = temp;
}

/*Quay lại bài Single List 1 : khai báo prototype hai hàm addbet thì đã gán giá trị bool before = true
Nên khi gọi lại hàm này, ta không cần gán lại giá trị này nữa

Nhắc lại kiến thức : before = true thì thêm một nút vào trước nút p, before = false thì thêm một nút vào sau nút p

Cách gọi hàm : ta có sẵn một SList<int> list;
- Nếu thêm một nút vào trước nút p thì : list.addhead(p, 10);         //Thêm một nút mang giá trị 10 vào trước nút p
- Nếu thêm một nút vào sau nút p thì   : list.addhead(p, 10, false);  //Thêm một nút mang giá trị 10 vào sau nút p

GIẢI THUẬT :
* Thêm một nút vào trước nút p
  - Ta có một danh sách list gồm các nút : 5 2 3 7 NULL

  Nút p mang giá trị 2, ta cần thêm một nút k mang giá trị 1 vào trước p
  Bước 1 : thêm nút k vào sau nút p, ta được danh sách mới           : 5 2 1 3 7 NULL
  Bước 2 : hoán vị giá trị của hai nút p và k, ta được danh sách mới : 5 1 2 3 7 NULL

  TRƯỜNG HỢP p = NULL : bạn có thể không thêm nút vào và đóng hàm đi, nhưng ở đây mình sẽ thêm vào cuối danh sách. Việc này do người viết tự định nghĩa
  => Độ phức tạp của việc thêm một nút vào trước nút p luôn là O(1)

* Thêm một nút vào sau nút p
  - Ta có một danh sách list gồm các nút : 5 2 3 7 NULL
  Nút p mang giá trị 2, ta cần thêm một nút k mang giá trị 1 vào sau p
  Bước 1 : thêm nút k vào sau nút p, ta được danh sách mới           : 5 2 1 3 7 NULL

  TRƯỜNG HỢP p = NULL : mình sẽ không thêm nút vào và đóng hàm lại
  => Độ phức tạp của việc thêm một nút vào sau nút p luôn là O(1)

Vì vậy hàm addbet luôn là thêm vào sau nút p, chỉ hoán vị khi before = true*/

//Thêm một nút mang giá trị element vào kế nút p
template <class data>
void SList<data>::addbet(node<data>* p, data element, bool before)
{
    if (head == NULL || p == NULL && !before)
        return;

    //Nút p = NULL thì sẽ thêm một nút vào cuối
    if (p == NULL)
    {
        addtail(element);
        return;
    }

    node<data>* k = new node<data>(element);

    //Thêm nút k vào sau p
    k->next = p->next;
    p->next = k;

    //Hoán vị hai nút p, k khi before = true
    if (before && p->info != k->info)
        swap(p->info, k->info);

    //Gán lại tail nếu tail trùng p
    if (tail == p)
        tail = k;
    len++;
}

//Thêm một nút element vào kế nút p
template <class data>
void SList<data>::addbet(node<data>* p, node<data>* element, bool before)
{
    if (head == NULL || element == NULL || p == NULL && !before)
        return;

    //Nút p = NULL thì sẽ thêm một nút vào cuối
    if (p == NULL)
    {
        addtail(element);
        return;
    }

    element->next = p->next;
    p->next = element;

    //Hoán vị hai nút p, element khi before = true
    if (before && p->info != element->info)
        swap(p->info, element->info);

    //Gán lại tail nếu tail trùng p
    if (tail == p)
        tail = element;
    len++;
}

//====================================================================================================
//Bài 3     ==========================================================================================
//====================================================================================================

/*Bài này bao gồm các hàm
- Xóa nút đầu của danh sách
- Xóa nút cuối của danh sách
- Xóa một nút được chỉ định
- Tìm nút mang giá trị lớn nhất
- Tìm nút mang giá trị nhỏ nhất
- Tìm nút mang giá trị được chỉ định
*/

//Lưu ý : hãy chắc chắn rằng bạn không làm sai giá trị của biến len so với độ dài của danh sách, nếu không sẽ dễ gây ra lỗi

//Xóa nút đầu
template <class data>
void SList<data>::delhead()
{
    if (head == NULL)
        return;

    if (len == 1)
    {
        delete head;
        head = tail = NULL;
        len = 0;
        return;
    }

    node<data>* p = head;
    head = head->next;
    delete p;
    len--;
}

//Xóa nút cuối
template <class data>
void SList<data>::deltail()
{
    if (head == NULL)
        return;

    if (len == 1)
    {
        delete tail;
        head = tail = NULL;
        len = 0;
        return;
    }

    //Tìm đến nút trước tail
    for (node<data>* i = head; i->next; i = i->next)
        if (i->next == tail)
        {
            i->next = NULL;
            delete tail;
            tail = i;
            break;
        }
    len--;
}

/*GIẢI THUẬT : xóa một nút element trong danh sách
Ta có danh sách list gồm các nút : 5 2 7 8 NULL

Xóa nút element mang giá trị bằng 2
  Bước 1 : gán giá trị nút sau nút element vào chính nó, ta được danh sách mới : 5 7 7 8 NULL
  Bước 2 : xóa một nút sau nút element, ta được danh sách mới                  : 5 7 8 NULL

TRƯỜNG HỢP nút element là nút cuối : độ phức tạp O(n)
=> Độ phức tạp của việc xóa một nút element là O(1) hoặc O(n)
*/

//Xóa nút được chỉ định
template <class data>
void SList<data>::delnode(node<data>* element)
{
    if (head == NULL || element == NULL)
        return;

    if (len == 1)
    {
        delete head;
        head = tail = NULL;
        len = 0;
        return;
    }

    if (element != tail)
    {
        node<data>* p = element->next;      //p là nút sau nút element
        if (tail == p)
            tail == element;

        element->info = p->info;            //Đưa giá trị của nút p lên nút element
        element->next = p->next;            //Loại nút p khỏi danh sách
        delete p;                           //Giải phóng nút p
        len--;
        return;
    }

    //Trường hợp element == tail
    for (node<data>* i = head; i->next; i = i->next)
        if (i->next == tail)
        {
            i->next = NULL;
            delete tail;
            tail = i;
            break;
        }
    len--;
}

//Tìm nút mang giá trị lớn nhất
template <class data>
node<data>* SList<data>::max()
{
    if (head == NULL)
        return NULL;

    node<data>* node_max = head;

    for (node<data>* i = head->next; i; i = i->next)
        if (node_max->info < i->info)
            node_max = i;
    return node_max;
}

//Tìm nút mang giá trị nhỏ nhất
template <class data>
node<data>* SList<data>::min()
{
    if (head == NULL)
        return NULL;

    node<data>* node_min = head;

    for (node<data>* i = head->next; i; i = i->next)
        if (node_min->info > i->info)
            node_min = i;
    return node_min;
}

//Tìm nút mang giá trị element được chỉ định
template <class data>
node<data>* SList<data>::find(data element)
{
    if (head == NULL)
        return NULL;

    for (node<data>* i = head; i; i = i->next)
        if (i->info == element)
            return i;
    return NULL;
}

//====================================================================================================
//Bài 4     ==========================================================================================
//====================================================================================================

/*Bài này bao gồm các hàm :
- Kiểm tra danh sách rỗng
- Xuât danh sách
- Xuất danh sách theo chiều ngược
- Giải phóng toàn bộ danh sách
- Đảo danh sách
- Kiểm tra danh sách có đối xứng
- Phương thức : gán hai SList
*/

//Kiểm tra danh sách rỗng
template <class data>
bool SList<data>::isEmpty()
{
    return head == NULL;
}

//Xuất danh sách
template <class data>
void SList<data>::show()
{
    for (node<data>* i = head; i; i = i->next)
        std::cout << i->info << " ";
    std::cout << "NULL\n";
}

/*Danh sách liên kết đơn không thể đi từ chiều ngược lại được
Vì vậy ta cần sử dụng kỹ thuật đệ quy để giải quyết bài toán xuất ngược danh sách
*/

//Hàm xuất ngược danh sách liên kết đơn như sau, hàm này không thuộc lớp SList

template <class data>
void SList_showrev(node<data>* head)      //Nhận vào một con trỏ head
{
    if (head == NULL)
        return;

    SList_showrev(head->next);        //Đệ quy
    std::cout << " " << head->info;
}

//Sử dụng hàm trên để in ngược danh sách
//Xuất ngược danh sách
template <class data>
void SList<data>::showrev()
{
    std::cout << "NULL";
    SList_showrev(head);
    std::cout << '\n';
}

//Giải phóng toàn bộ danh sách
template <class data>
void SList<data>::del()
{
    if (head == NULL)
        return;

    for (node<data>* i = head; i; i = head)
    {
        head = head->next;
        delete i;
    }
    tail = NULL;
    len = 0;
}

//Ta có thể dùng đệ quy để giải phóng các nút theo chiều ngược, hàm dưới đây sẽ được đóng lại bằng các dấu //

/*Cần sử dụng một hàm phụ, hàm này không thuộc lớp SList
template <class data>
void SList_del(node<data>* head)      //Nhận vào một nút head
{
  if(head == NULL)
    return;

  SList_del(head->next);        //Đệ quy
  delete head;                  //Giải phóng
}

//Hàm giải phóng toàn bộ danh sách
template <class data>
void SList<data>::del()
{
  SList_del(head);      //Gọi hàm giải phóng danh sách
  head = tail = NULL;
  len = 0;
}
*/

//Đảo danh sách
template <class data>
void SList<data>::reverse()
{
    if (len <= 1)
        return;

    node<data>* p = tail = head;
    head = head->next;
    tail->next = NULL;

    for (node<data>* i = head; i; i = head)
    {
        head = head->next;
        i->next = p;
        p = i;
    }

    head = p;
}

/*Tạo một SList cùng kiểu rỗng
Ta đẩy lần lượt giá trị của từng nút theo chiều xuôi vào đầu danh sách mới này
Sau đó duyệt qua từng nút của hai danh sách và so sánh chúng
*/

//Kiểm tra danh sách đối xứng
template <class data>
bool SList<data>::isSymmetry()
{
    SList<data> list;
    for (node<data>* i = head; i; i = i->next)     //Đẩy từng giá trị vào đầu danh sách mới
        list.addhead(i->info);

    for (node<data>* i = head, *j = list.head; i; i = i->next, j = j->next)
        if (i->info != j->info)
        {
            list.del();       //Giải phóng danh sách mới
            return false;     //Danh sách không đối xứng
        }

    list.del();           //Giải phóng danh sách mới
    return true;          //Danh sách đối xứng
}

/*Khi gán hai SList : list2 = list;
Lúc này chương trình sẽ thực thi hai dòng :
list2.head = list1.head;
list2.tail = list1.tail;

Như vậy list2 đang dùng chung các nút với list1, nếu thay đổi giá trị các nút trong list2 thì các nút trong list1 sẽ thay đổi theo
Vì thế ta sẽ viết hàm ( phương thức ) để list2 và list1 không dùng chung các nút

Cách gọi : list2 = list1;   //Gán như bình thường
*/

//Phương thức : gán bằng hai SList
template <class data>
void SList<data>::operator=(SList<data> list)
{
    if (head != NULL)
        del();        //Giải phóng danh sách cũ

    for (node<data>* i = list.head; i; i = i->next)
        addtail(i->info);
}

//====================================================================================================
//Bài 5     ==========================================================================================
//====================================================================================================

/*Bài này bao gồm các hàm sắp xếp danh sách, sử dụng các thuật toán sau :
- Interchange Sort    O(n^2)
- Buble Sort          O(n^2)
- Selection Sort      O(n^2)
- Insertion Sort      O(n^2) hoặc O(n)
*/

/*Nếu bạn sắp xếp tăng dần, chỉ cần gọi :           list.sort_interchange();
Nếu là sắp xếp giảm dần, phải thêm tham số false :  list.sort_interchange(false);
*/

//Sắp xếp danh sách dùng Interchange Sort
template <class data>
void SList<data>::sort_interchange(bool ascending)
{
    if (len <= 1)
        return;

    if (ascending)   //Sắp xếp danh sách tăng
    {
        for (node<data>* i = head; i; i = i->next)
            for (node<data>* j = i->next; j; j = j->next)
                if (i->info > j->info)
                    swap(i->info, j->info);
    }
    else {
        for (node<data>* i = head; i; i = i->next)
            for (node<data>* j = i->next; j; j = j->next)
                if (i->info < j->info)
                    swap(i->info, j->info);
    }
}

//Sắp xếp danh sách dùng Buble Sort
template <class data>
void SList<data>::sort_buble(bool ascending)
{
    if (len <= 1)
        return;

    node<data>* p = NULL;

    if (ascending)   //Sắp xếp danh sách tăng
    {
        for (node<data>* i = head; i->next != p;)
            for (node<data>* j = i;; j = j->next)
            {
                if (j->next == p)
                {
                    p = j;
                    break;
                }

                if (j->info > j->next->info)
                    swap(j->info, j->next->info);
            }
    }
    else {
        for (node<data>* i = head; i->next != p;)
            for (node<data>* j = i;; j = j->next)
            {
                if (j->next == p)
                {
                    p = j;
                    break;
                }

                if (j->info < j->next->info)
                    swap(j->info, j->next->info);
            }
    }
}

//Sắp xếp danh sách dùng Selection Sort
template <class data>
void SList<data>::sort_selection(bool ascending)
{
    if (len <= 1)
        return;

    node<data>* p;

    if (ascending)   //Sắp xếp danh sách tăng
    {
        for (node<data>* i = head; i; i = i->next)
        {
            p = i;
            for (node<data>* j = i->next; j; j = j->next)
                if (p->info > j->info)
                    p = j;

            if (p != i)
                swap(p->info, i->info);
        }
    }
    else {
        for (node<data>* i = head; i; i = i->next)
        {
            p = i;
            for (node<data>* j = i->next; j; j = j->next)
                if (p->info < j->info)
                    p = j;

            if (p != i)
                swap(p->info, i->info);
        }
    }
}

/*Vì danh sách liên kết đơn chỉ có thể duyệt theo chiều xuôi, nên ta sẽ xử dụng kỹ thuật đệ quy cho bài toán Insertion Sort
Hàm này không phải là lớp của SList
*/

template <class data>
void SList_insertion(node<data>* head, bool ascending)    //Nhận vào một nút
{
    if (head == NULL || head->next == NULL)
        return;

    SList_insertion(head->next, ascending);     //Đệ quy

    data temp = head->info;       //Giữ giá trị nút đang xét
    node<data>* i = head;

    //Phần sắp xếp chèn
    if (ascending)   //Sắp xếp danh sách tăng
    {
        for (; i->next && i->next->info < temp; i = i->next)
            i->info = i->next->info;
        i->info = temp;
    }
    else {
        for (; i->next && i->next->info > temp; i = i->next)
            i->info = i->next->info;
        i->info = temp;
    }
}

//Sắp xếp danh sách dùng Insertion Sort
template <class data>
void SList<data>::sort_insertion(bool ascending)
{
    if (len <= 1)
        return;

    SList_insertion(head, ascending);
}
