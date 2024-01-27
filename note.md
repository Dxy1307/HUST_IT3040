- Trình dịch (Compiler): chương trình thực hiện biên dịch toàn bộ chương trình nguồn thành mã máy trước khi thực hiện
- Thông dịch (interpreter): chương trình dịch và thực hiện từng dòng lệnh của chương trình cùng lúc. Dịch từ ngôn ngữ này sang ngôn ngữ khác, không tạo ra chương trình dạng mã máy say assembly

- Chu trình phát triển phần mềm: 6 bước
   + Analyze Requirements
   + Design solution
   + Validate design
   + Implement design
   + Test solution
   + Document solution

- Các phép toán trên con trỏ
   + Cộng hoặc trừ con trỏ với 1 số nguyên n trả về 1 con trỏ cùng kiểu, là địa chỉ mới trỏ tới 1 đối tượng khác nằm cách đối tượng đang bị trỏ n phần tử
   + Trừ 2 con trỏ cho ta khoảng cách (sô phần tử) giữa 2 con trỏ
   + Không có phép cộng, nhân, chia 2 con trỏ
   + Có thể dùng các phép gán, so sánh các con trỏ (chú ý đến sự tương thích về kiểu)

- Chú ý: **++** và **--** có độ ưu tiên cao hơn * nên *p++ tương đương với *(p++) tức là tăng địa chỉ mà nó trỏ tới chứ không phải tăng giá trị mà nó chứa
   Ex:   *p++ = *q++ tương ứng với
         *p = *q;
         p = p + 1;
         q = q + 1;

- Con trỏ trỏ tới con trỏ
   + <kiểu dữ liệu> ** <Tên biến trỏ>;
   + có thể mô tả một mảng 2 chiều qua con trỏ của con trỏ theo công thức:
      M[i][k] = *(*(M + i) + k);
      Trong đó: M + i là địa chỉ của phần tử thứ i trong mảng
                *(M + i) cho nội dung phần tử trên
                *(M + i) + j là địa chỉ phần tử [i][j]
# Cấp phát bộ nhớ động
## Sử dụng hàm malloc()
- Từ malloc là đại diện cho cụm từ memory allocation
- thực hiện cấp phát bộ nhớ bằng cách chỉ định số byte cần cấp phát. Hàm này trả về con trỏ kiểu **void** cho phép chúng ta có thể ép kiểu về bất cứ kiểu dữ liệu nào.
- Vùng nhớ cấp phát không được khởi tạo giá trị ban đầu
- Syntax:
   ```c
   ptr = (castType*)malloc(size);

   ptr = (int *)malloc(100* sizeof(int));
   ```
- Trong trường hợp không thể cấp phát bộ nhớ, nó sẽ trả về một con trỏ **NULL**

## Sử dụng hàm calloc()
- Đại diện cho cụm từ contiguous allocation
- Thực hiện cấp phát bộ nhớ và khởi tạo tất cả các ô nhớ có giá trị bằng 0
- Syntax: nhận vào 2 tham số là **số ô nhớ** muốn khởi tạo và **kích thước của một ô nhớ**
   ```c
   ptr = (castType*)calloc(n, size);

   ptr = (int *)calloc(100, sizeof(int));
   ```

## Sử dụng hàm free()
- Việc cấp phát bộ nhớ động trong C dù sử dụng cách nào trong 2 cách trên đều không thể tự giải phóng bộ nhớ nên sử dùng hàm **free()** để giải phóng vùng nhớ.
- Syntax:
   ```c
   free(ptr); // ptr là con trỏ
   ```

## Sử dụng hàm realloc()
- Nếu việc cấp phát bộ nhớ động không đủ hoặc cần nhiều hơn mức đã cấp phát, bạn có thể thay đổi kích thước của bộ nhớ đã được cấp phát trước đó bằng cách sử dụng hàm **realloc()**
- Syntax:
   ```c
   ptr = realloc(ptr, n);
   ```
   Hàm này thực hiện cấp phát vùng nhớ mới cho con trỏ **ptr**, vùng nhớ mới đó sẽ có kích thước mới là **n** bytes
- Hàm này sẽ cố gắng mở rộng số ô nhớ ra phía sau nếu có thể để giữ nguyên giá trị của con trỏ ban đầu. Trong TH phải đối sang một vùng nhớ khác, hàm **realloc()** cũng sẽ mang theo giá trị đã có ở vùng nhớ cũ sang vùng nhớ mới và giải phóng luôn vùng nhớ cũ.

# Hàm
- Trong C, tên hàm là duy nhất, C chỉ có duy nhất 1 cách truyền tham số: tham trị (kể cả dùng địa chỉ cũng vậy)
- Khi một hàm trả về một tham chiếu, chúng ta có thể gọi hàm ở phía bên trái của một phép gán (C++)
## Tham số ngầm định
- Một hàm có thể có nhiều tham số có giá trị mặc định. Các tham số có giá trị mặc định cần phải được nhóm lại vào các tham số cuối cùng (hoặc duy nhất) của một hàm.
- Khi gọi hàm có nhiều tham số có giá trị mặc định, chúng ta chỉ có thể bỏ bớt các tham số theo thứ tự từ phải sang trái và phải bỏ liên tiếp nhau.
Ex:
```C
   int myFunc(int a = 1, int b, int c = 3, int d = 4); // sai
   int myFunc(int a, int b = 2, int c = 3, int d = 4); // đúng
```
## Đa năng hóa hàm (Overloading) - Chỉ có trong C++
- Cung cấp nhiều hơn một định nghĩa cho tên hàm đã cho trong cùng một phạm vi
- Trình biên dịch sẽ lựa chọn phiên bản thích hợp của hàm hay toán tử dựa trên các tham số mà nó được gọi.
## Đa năng hóa toán tử
- Định nghĩa lại chức năng của các toán tử đã có sẵn (Thể hiện các phép toán một cách tự nhiên hơn).
- Syntax:
   data_type **operator** operator_symbol (parameters) {
      ......
   }
- Không thể định nghĩa các toán tử mới
- Hầu hết các toán từ của C++ đều có thể được đa năng hóa, trừ các toán tử sau
      :: Toán tử định phạm vi
      .* Truy cập đến con trỏ là trường của struct hay class
      . Truy cập đến trường của struct hay class
      ?: Toán tử điều kiện
- Không thể thay đổi thứ tự ưu tiên, không thể thay đổi ý nghĩa, không thể có các tham số có giá trị mặc định.

# Con trỏ hàm
- Syntax: <return_type> (*<name_of_ptr>) (<data_type_of_parameters>);

# Khái quát hóa hàm
- Syntax: template <parameter-list> function-declaration
- Ex:
```C++
   template <typename T> 
   T maxval(T x, T y) {
      return (x > y) ? x : y;
   }
```

# Hàm nặc danh - cú pháp lambda
- Syntax: [=] () mutable throw() -> int {...}
Gồm 6 phần:
   + []: mệnh đề bắt giữ (capture clause)
      /[&]: ký hiệu biến được truy cập bằng tham chiếu
      /bỏ & hoặc dùng [=]: truy cập giá trị
      /[]: không truy cập biến nào trong khối lệnh chứa nó
   + (): danh sách tham số
      /ngoài khả năng bắt giữ các biến bên ngoài, lambda còn có thể nhận đối số bằng cách khai báo danh sách tham số
   + mutable: tính bền vững của lambda
      /nếu thêm từ khóa này vào một lambda, nó cho phép lambda thay đổi giá trị những biến được bắt giữ theo giá trị
   + throw(): ngoại lệ có thể xảy ra trong lambda
   + int: kiểu trả về của lambda
      /thêm vào giúp việc đọc hiểu lambda dễ dàng hơn
   + {...}: phần thân của lambda
      /sử dụng những biến được bắt giữ trong mệnh đề bắt giữ 
      /sử dụng các tham số 
      /sử dụng các biến được khai báo bên trong struct/class chứa nó thông qua con trỏ this (OOP)
      /sử dụng các biến toàn cục, biến static

# std::function in C++11
- Syntax:
   std::fucntion < <return_type>([list of parameters]) > varName;
   std::function < bool(int, int)> comparisonFunc;

# inline functions
- Là một loại hàm trong C++. Từ khóa **inline** được sử dụng để đề nghị (không phải là bắt buộc) compiler thực hiện **inline expansion(khai triển nội tuyến)** với hàm đó hay nói cách khác là chèn code của hàm đó tại địa chỉ mà nó được gọi.
   Ex: **inline** double myFunc(int a, int b) {
      return a + b;
   }
- Trình biên dịch có thể không thực hiện nội tuyến trong các trường hợp như:
   + Hàm chứa vòng lặp (for, while, do-while)
   + Hàm chứa các biến tĩnh
   + Hàm đệ quy
   + Hàm chứa câu lệnh switch hoặc goto

# Macros
Ex:
```C++
   #define max(a, b) (a > b ? a : b)
   #define for(i, a, b) for(int i = a; i <= b; i++)
   #define expr 2 + 5
```

# data segment
Khi thực hiện, vùng dữ liệu data segment của một chương trình được chia làm 3 phần: **static**, **stack**, **heap** data
   + static: global hay static variables
   + stack data: các biến cục bộ của chương trình con
   + heap data: dữ liệu được cấp phát động, dữ liệu này sẽ còn cho đến khi ta giải phóng hoặc khi kết thúc chương trình

# Đệ quy: 2 loại đệ quy
- Đệ quy trực tiếp
   + Đệ quy tuyến tính
   + Đệ quy nhị phân
   + Đệ quy phi tuyến
- Đệ quy gián tiếp
   + Đệ quy tương hỗ

**Đệ quy tuyến tính (linear recursion)**
Syntax:
```C++
   P() {
      if(B) thực hiện S;
      else {thực hiện S*, gọi P}
   }
   với S, S* là các thao tác không đệ quy

Ex:
   int fact(int n) {
      if(n == 0) return 1;
      else return n * fact(n - 1);
   }
```

**Đệ quy nhị phân (binary recursion)**
Syntax:
```C++
   P() {
      if(B) thực hiện S;
      else {
         thực hiện S*;
         gọi P; gọi P;
      }
   }
   với S, S* là các thao tác không đệ quy.

Ex:
   int fibo(int n) {
      if(n < 2) return 1;
      else return fibo(n - 1) + fibo(n - 2);
   }
```

**Đệ quy phi tuyến (nonlinear recursion)**
- Là đệ quy mà lời gọi đệ quy được thực hiện bên trong vòng lặp
Syntax:
```C++
   P() {
      for(<giá trị đầu> to <giá trị cuối>) {
         thực hiện S;
         if(điều kiện dừng) then thực hiện S*;
         else gọi P;
      }
   }
   với S, S* là các thao tác không đệ quy
Ex: Cho dãy {An} xác định theo công thức truy hồi:
                  A0 = 1;
      An = n^2.A0 + (n - 1)^2.A1 + ... + 2^2.A(n-2) + 1^2.A(n-1)
   int A(int n) {
      if(n == 0) return 1;
      else {
         int temp = 0;
         for(int i = 0; i < n; i++) {
            temp = temp + (n - i) * (n - i) * A(i);
         }
         return temp;
      }
   }
```

**Đệ quy tương hỗ (mutual recursion)**
- Trong đệ quy tương hỗ có 2 hàm, và trong thân của hàm này có lời gọi của hàm kia, điều kiện dừng và giá trị trả về của cả 2 hàm có thể giống hoặc khác nhau
Syntax:
   KieuDuLieu TenHamX(ThamSo) {
      if(Dieu Kien Dung) {
         ...;
         return Giá trị trả về;
      }
      ...;
      return TenHamX(ThamSo) <Liên kết hai hàm> TenHamY(Thamso);
   }

   KieuDuLieu TenHamY(ThamSo) {
      if(Dieu Kien Dung) {
         ...;
         return Giá trị trả về;
      }
      ...;
      return TenHamY(ThamSo) <Liên kết hai hàm> TenHamX(ThamSo);
   }
Ex: X(n) = 1, 2, 3, 5, 11, 41, ...
    Y(n) = 1, 1, 2, 6, 30, 330, ...
```C++
   long Y(int n);
   long X(int n) {
      if(n == 0) return 1;
      else return X(n - 1) + Y(n - 1);
   }
   long Y(int n) {
      if(n == 0) return 1;
      else return X(n - 1) * Y(n - 1);
   }
```

**Đệ quy có nhớ (memorization)**
**Đệ quy quay lui**
- Giải quyết vấn đề từ lời giải rỗng và xây dựng lời giải bộ phận để ngày càng tiến gần tới lời giải bài toán.
   + Nếu một lời giải bộ phận không thể tiếp tục phát triển, ta sẽ bỏ nó
   + Và quay sang xét tiếp các ứng cử viên khác
- Syntax:
```C++
   void Try(int i) {
      foreach(ứng viên được chấp nhận C) {
         <update các biến trạng thái>
         <ghi nhận x[i] mới theo C>
         if(i == n) <ghi nhận một lời giải>
         else Try(i + 1);
         <trả các biến về trạng thái cũ>
      }
   }
```

**Khử đệ quy**
- Khử đệ quy bằng vòng lặp:
   Ex: f(n) = C nếu n = n0
       f(n) = g(n, f(n - 1)) nếu n > n0
   Giải thuật:
      K = n0; F = C;
      F = f(n0);
      while(k < n) {
         k++;
         f = g(k, F);
      }
      return F;

- Khử đệ quy đuôi:
   if B(X) then D(X)             X là tập biến (một hoặc một bộ nhiều biến)
   else {                        P(X) là thủ tục đệ quy phụ thuộc X
      A(X);                      A(X), D(X) là các thao tác không đệ quy
      P(F(X));                   f(X) là hàm biến đổi X
   }
   Giải thuât:
   while(!B(X)) {
      A(X);
      X = f(X);
   }   
   D(X);

- Khử đệ quy tuyến tính bằng stack:
   if C(X) then D(X)             X là một biến đơn hoặc nhiều biến
   else {                        C(X) là một biểu thức boolean của X
      A(X);                      A(X), B(X), D(X) không đệ quy
      P(F(X));                   f(X) là hàm của X
      B(X);
   }
   Giải thuật:
   {
      create_stack(S); // tạo stack S
      while(not C(X)) {
         A(X);
         push(S, X); // cất giá trị X vào stack S
         X = f(X);
      }
      D(X);
      while(not empty(S)) {
         pop(S, X); // lấy dữ liệu từ S
         B(X)
      }
   }

- Khử đệ quy nhị phân bằng stack:
   if C(X) then D(X)             X là một biến đơn hoặc nhiều biến
   else {                        C(X) là một biểu thức boolean
      A(X); P(f(X));             A(X), B(X), D(X) không đệ quy
      B(X); P(g(X));             f(X), g(X) là các hàm của X
   }
   Giải thuật:
   {
      create_stack(S);
      push(S, (X, 1));
      while(k != 1) {
         while(not C(X)) {
            A(X);
            push(S, (X, 2));
            X = f(X);
         }
         D(X);
         pop(S, (X, k));
         if(k != 1) {
            B(X);
            X = g(X);
         }
      }
   }

# Data structures
## STL Containers
**Vector<T>**
- Vector là mảng động, hỗ trợ kiểm tra biên khi truy xuất phần tử
- Các phần tử vector được lưu liên tiếp trong bộ nhớ, do vậy các phép toán số học với con trỏ hoạt động trên vector và đảm bảo truy xuất ngẫu nhiên trong O(1)
- Không có cơ chế thêm/xóa phần tử đầu
- Thực hiện push_back() khi vector đã đầy sẽ dẫn tới việc cấp phát mới (reallocation)

**deque<T>**
- Hàng đợi 2 đầu "Double - Ended Queue", tương tự như vector nhưng cho phép chèn/xóa nhanh phần tử đầu
- Truy xuất ngẫu nhiên nhanh, nhưng không đảm bảo các phần tử được lưu giữ kế tiếp nhau trong bộ nhớ
   + Do đó phép toán số học với con trỏ không hoạt động
   + Toán tử [] và at() được đa năng hóa để làm việc đúng

**Array**
- là một lớp bao(wrapper) của mảng C++, có thể xem như một vector kích thước cố định
- không tự động chuyển thành pointer
- thường được lưu trong bộ nhớ stack hơn là bộ nhớ heap
- nhanh hơn và hiệu quả về mặt bộ nhớ hơn vector

**List<T>**
- Cài đặt như danh sách liên kết kép doubly-linked list, cho phép chèn và xóa nhanh phần tử
- Chỉ hỗ trợ truy xuất tuần tự thông quá iterators, không truy xuất ngẫu nhiên qua chỉ số bằng toán tử [] hoặc at()

**forward_list**
- Về cơ bản là danh sách liên kết đơn
- Không truy xuất ngay lập tức tới cuối danh sách được, nghĩa là không có push_back(), back()
- Không thể duyệt ngược danh sách
- Không có phương thức size()

## STL Container Adapters
**Các thao tác với stack**
empty(): kiểm tra stack rỗng hay không
size(): trả về kích thước stack
top(): trả về tham chiếu tới phần tử trên cùng của stack
push(g): thêm phần tử 'g' lên đỉnh của stack
emplace(): khởi tạo và chèn phần tử lên đỉnh stack, hiệu quả hơn hàm push do không mất thời gian copy đối tượng
pop(): xóa phần tử trên cùng của đỉnh stack

**Các thao tác với queue**
empty(): trả về queue rỗng hay không
size(): trả về kích thước của queue
front(): trả về tham chiếu tới phần tử đầu tiên trong queue
back(): trả về tham chiếu tới phần tử cuối cùng trong queue
push(g): thêm phần tử 'g' vào cuối queue
emplace(): khởi tạo và chèn phần tử mới vào cuối queue
pop(): xóa phần tử đầu tiên trong queue

**Các thao tác với priority_queu**
- Cấu trúc hàng đợi ưu tiên đảm bảo phần tử được ưu tiên nhất luôn ở đầu hàng đợi
- Các thao tác giống với queue

## STL Associative Containers
- Container liên kết có thứ tự
   + [multi]map, [multi]set
   + thứ tự các phần tử dựa trên giá trị *key*, không phải theo giá trị chèn vào
   + cài đặt sử dụng kiến trúc tương tự **binary search tree** => time tìm kiếm O(log N)
   + Có thể duyệt các phần tử theo "thứ tự"
- Container liên kết không có thứ tự
   + unordered_[multi]map, unordered_[multi]set
   + không có thứ tự giữa các phần tử
   + cài đặt sử dụng **hash tables** => time tìm kiếm O(1)
   + có thể duyệt các phần tử nhưng không theo một thứ tự cụ thể nào

**set<T>**
- tập hợp các giá trị duy nhất, không cho phép các phần tử trùng nhau
   + nếu cố insert một phần tử đã có trong set, thì set không thay đổi
   + kết quả trả về là một cặp <iterator, bool>
      /phần tử thứ 2 thể hiện phép chèn thành công hay không
      /phần tử đầu tiên là vị trí của phần tử mới được chèn (hoặc phần tử đã tồn tại sẵn)

**map<T>**
- Tập hợp các cặp giá trị phân biệt
   + map<T1, T2> m;
   + T1 là kiểu khóa
   + T2 là kiểu giá trị
- Truy vấn map tìm kiếm phần tử
   + tìm kiếm theo index sẽ chèn key mới nếu nó chưa tồn tại trong map
      if(works["bach"] == 0)
         // back not present
   + phương pháp khác là dùng phương pháp find() trả về con trỏ iterator tới cặp key/value cần truy vấn
      map<string, int>::iterator it;
      it = words.find("bach);
      if(it == words.end())
         // back not present

## STL Unsorted Associative Containers
- unordered_[multi]set và unordered_[multi]map
- tương tự như các cấu trúc container liên kết có thứ tự, ngoại trừ:
   + các phần tử không được sắp xếp
   + được cài đặt bằng bảng băm (hash tables), độ phức tạp O(1) với các thao tác insert/lookup/remove
   + có iterators để duyệt các phần tử trong container nhưng không theo thứ tự đặc biệt nào cả

## pair
- template<class T1, class T2> struct pair;
   + pair chứa 2 phần tử có thể thuộc 2 kiểu khác nhau
   + truy cập phần tử thứ nhất bằng first
   + truy cập phần tử thứ hai bằng second
## make_pair
- template<class T1, class T2> pair<T1, T2> make_pair(T1 x, T2 y);
- tạo ra một đối tượng pair

# Bẫy lỗi
- try: đặt phần code có thể xảy ra exception trong khối try
- throw: khi có bất thường xảy ra trong chương trình, sử dụng keyword throw để ném ra một ngoại lệ
- catch: nếu muốn bắt bất kỳ exception nào, cần phải đặt câu lệnh catch sau câu lệnh try, lệnh catch chỉ bắt những exception tương thích với kiểu đã được chỉ định, nếu muốn lệnh catch bắt exception thuộc bất kỳ kiểu dữ liệu nào, sử dụng dấu "..."

# Gỡ rối, kiểm thử và tinh chỉnh
- Các phương pháp đo:
   + Statement Coverage: đảm bảo rằng tất cả các dòng lệnh trong mã nguồn đã được kiểm tra ít nhất một lần
   + Branch Coverage: đảm bảo rằng tất cả các nhánh chương trình trong mã nguồn đã được kiểm tra ít nhất một lần
   + Path Coverage: đảm bảo rằng tất cả các đường chạy (là tổ hợp của các nhánh) chương trình trong mã nguồn đã được kiểm tra ít nhất một lần