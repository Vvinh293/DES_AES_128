# DES_AES_128
1. Thuật toán DES
1.1. Mô tả chung
   Thuật toán DES được sử dụng để mã hóa và giải mã các block dữ liệu 64 bit dựa trên một key 64 bit
1.1. Lưu đồ thuật toán mã hóa
   <img width="1126" height="1298" alt="image" src="https://github.com/user-attachments/assets/2fe07878-3043-48cb-a0c6-26363bd53b4d" />
1.2. Chi tiết thuật toán
   1.2.1. Hoán vị khởi tạo
   64 bits đầu vào sẽ được hoán vị theo bảng mô tả sau đây
   <img width="1200" height="646" alt="image" src="https://github.com/user-attachments/assets/000af5be-fe69-41a2-b4d1-5b4eb6c7e8f0" />
   1.2.2. Phân chia chuỗi bit
   Sau hoán vị, chuỗi bit mới được phân ra làm 2 đoạn mỗi đoạn 32 bits. Đoạn bên trái (L) gồm từ bit số 1 đến bit số 32, đoạn bên phải (R) gồm các bit từ số 33 đến số 64.
   1.2.3. Tính toán các đoạn L, R
   Đoạn L của lần tính toán sau sẽ chính là đoạn R của lần tính toán trước, đoạn R của lần tính toán sau sẽ được tính từ đoạn R trước đó qua công thức :
   <img width="1076" height="272" alt="image" src="https://github.com/user-attachments/assets/4a811871-d34a-47fd-8807-4458f793fbe4" />
   Hàm mã hóa f(R,K)
   <img width="1224" height="1218" alt="image" src="https://github.com/user-attachments/assets/d5a3c64d-ca4a-4b6f-a84e-58d665872856" />
   32 bits của đoạn R được đánh số từ 1 đến 32 theo thứ tự từ trái qua phải, sử dụng bảng E để tạo thành một giá trị 48 bit.
   Bảng E :
   <img width="1196" height="854" alt="image" src="https://github.com/user-attachments/assets/d06d20e6-b16c-4878-a036-73b5496969b1" />
   Sau khi được kết quả 48 bits lấy kết quả đó XOR với 48 bits của khóa vòng. Kết quả được chia thành 8 block , mỗi block 6 bits rồi dựa vào các hàm biến đổi riêng biệt để chuyển đổi
   <img width="1174" height="652" alt="image" src="https://github.com/user-attachments/assets/6bf2c62d-afd4-470e-9f14-ac8e4df1e651" />
   Việc chuyển đổi giá trị của các hàm S1, S2, ..., S8 được thực hiện bằng cách tách block 6 bit thành hai phần. Phần thứ nhất là tổ hợp của bit đầu tiên và bit cuối cùng của block để tạo thành 2 bit chọn hàng của bảng S, bảng S có 4 hàng được đánh số từ 0 đến 3 theo thứ tự từ trên xuống. Phần thứ 2 là 4 bit còn lại dùng để chọn cột của bảng S, bảng S có 16 cột được đánh số từ 0 đến 15 theo thứ tự từ trái qua phải. Như vậy, với mỗi block 8 bit ta chọn được 1 giá trị trong bảng S. Giá trị này nằm trong khoảng từ 0 đến 15 sẽ được quy đổi thành chuỗi nhị phân 4 bit tương ứng. Các chuỗi nhị phân có được sau khi chuyển đổi từ S1 đến S8 sẽ được ghép lại theo thứ tự từ trái qua phải để tạo thành một giá trị 32 bit.
   Giá trị này được đưa qua một hàm hoán vị P để tạo ra giá trị hàm f.
   <img width="540" height="444" alt="image" src="https://github.com/user-attachments/assets/a1c783cb-9202-4514-b862-a4bb7050e427" />
   Sau đó sử dụng bảng E để chuyển R thành 48 bits
   Kết quả của hàm f :
   <img width="698" height="168" alt="image" src="https://github.com/user-attachments/assets/24871459-b0d1-43ea-a797-fb07f415953c" />
   1.2.4. Tính toán khóa K
   <img width="1218" height="1278" alt="image" src="https://github.com/user-attachments/assets/61381314-cd25-4243-a3f1-f3527e615caa" />
   

   







