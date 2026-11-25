# DES_AES_128
1. Thuật toán DES
1.1. Mô tả chung
   Thuật toán DES được sử dụng để mã hóa và giải mã các block dữ liệu 64 bit dựa trên một key 64 bit
1.1. Lưu đồ thuật toán mã hóa
  <img width="1126" height="1330" alt="image" src="https://github.com/user-attachments/assets/87910993-5419-4eae-a6d2-5e98c1622752" />
1.2. Chi tiết thuật toán
   1.2.1. Hoán vị khởi tạo
   64 bits đầu vào sẽ được hoán vị theo bảng mô tả sau đây
  <img width="1140" height="632" alt="image" src="https://github.com/user-attachments/assets/49079ce0-a3d5-4545-a4aa-a963eebbe075" />
   1.2.2. Phân chia chuỗi bit
   Sau hoán vị, chuỗi bit mới được phân ra làm 2 đoạn mỗi đoạn 32 bits. Đoạn bên trái (L) gồm từ bit số 1 đến bit số 32, đoạn bên phải (R) gồm các bit từ số 33 đến số 64.
   1.2.3. Tính toán các đoạn L, R
   Đoạn L của lần tính toán sau sẽ chính là đoạn R của lần tính toán trước, đoạn R của lần tính toán sau sẽ được tính từ đoạn R trước đó qua công thức :
   <img width="784" height="236" alt="image" src="https://github.com/user-attachments/assets/eca7836c-97ce-4427-ad8b-574485a3b223" />
   Hàm mã hóa f(R,K)
  <img width="1152" height="1244" alt="image" src="https://github.com/user-attachments/assets/f1ad8c09-665d-453d-954a-e016cd82ae68" />
   32 bits của đoạn R được đánh số từ 1 đến 32 theo thứ tự từ trái qua phải, sử dụng bảng E để tạo thành một giá trị 48 bit.
   Bảng E :
   <img width="1140" height="846" alt="image" src="https://github.com/user-attachments/assets/261f977a-d0fa-47bd-a762-09c6814115c0" />
   Sau khi được kết quả 48 bits lấy kết quả đó XOR với 48 bits của khóa vòng. Kết quả được chia thành 8 block , mỗi block 6 bits rồi dựa vào các hàm biến đổi riêng biệt để chuyển đổi
   <img width="1152" height="654" alt="image" src="https://github.com/user-attachments/assets/479ce6f8-6bf4-492e-bf96-bbfc808dfc81" />
   Việc chuyển đổi giá trị của các hàm S1, S2, ..., S8 được thực hiện bằng cách tách block 6 bit thành hai phần. Phần thứ nhất là tổ hợp của bit đầu tiên và bit cuối cùng của block để tạo thành 2 bit chọn hàng của bảng S, bảng S có 4 hàng được đánh số từ 0 đến 3 theo thứ tự từ trên xuống. Phần thứ 2 là 4 bit còn lại dùng để chọn cột của bảng S, bảng S có 16 cột được đánh số từ 0 đến 15 theo thứ tự từ trái qua phải. Như vậy, với mỗi block 8 bit ta chọn được 1 giá trị trong bảng S. Giá trị này nằm trong khoảng từ 0 đến 15 sẽ được quy đổi thành chuỗi nhị phân 4 bit tương ứng. Các chuỗi nhị phân có được sau khi chuyển đổi từ S1 đến S8 sẽ được ghép lại theo thứ tự từ trái qua phải để tạo thành một giá trị 32 bit.
   Giá trị này được đưa qua một hàm hoán vị P để tạo ra giá trị hàm f.
  <img width="440" height="432" alt="image" src="https://github.com/user-attachments/assets/b53a895d-a5a2-4360-bcd1-3c3498210eff" />
   Sau đó sử dụng bảng E để chuyển R thành 48 bits
   Kết quả của hàm f :
   <img width="730" height="210" alt="image" src="https://github.com/user-attachments/assets/c85b7932-19a7-4a2c-8327-59452b9b7645" />
   1.2.4. Tính toán khóa K
   <img width="1138" height="1300" alt="image" src="https://github.com/user-attachments/assets/b4041e73-1e5b-4e0e-9933-83442a7a1412" />
   Bảng hoán vị lựa chọn PC-1 có hai phần. Phần đầu dùng để xác định giá trị C0 và phần sau dùng để xác định giá trị D0. Theo bảng trên thì C0 là chuỗi bit có thứ tự là 57, 49, 41, ..., 36 lấy từ key gốc, D0 là chuỗi bit có thứ tự là 63, 55, 47, ..., 4 lấy từ key gốc.
Sau khi xác định được giá trị ban đầu để tính key là C0 và D0 thì các khóa vòng Kn (với n từ 1 đến 16) sẽ được tính theo nguyên tắc giá trị của khóa vòng thứ n sẽ được tính từ giá trị khóa vòng thứ n-1.
<img width="1144" height="858" alt="image" src="https://github.com/user-attachments/assets/23fe930b-bf03-45ab-9179-17f11c4a7700" />
   Sau khi tính được Cn và Dn thì chuỗi CnDn sẽ được đánh số từ 1 đến 56 theo thứ tự từ trái sang phải và được hoán vị lựa chọn lần 2 theo bảng hoán vị PC-2
   <img width="976" height="598" alt="image" src="https://github.com/user-attachments/assets/a5ccec4a-fd5e-4ca8-8306-7550392e1a09" />
   Bước cuối cùng, Giá trị của lần lặp mã hóa cuối cùng sẽ được hoán vị khởi tạo đảo IP-1 và tạo ra giá trị mã hóa plaintext.
   <img width="1118" height="638" alt="image" src="https://github.com/user-attachments/assets/df416dc4-d7fa-4e38-b43b-f8e8438c2708" />

Test:
[INPUT]
Plaintext (M) : 00123456789ABCDE
Key       (K) : 0133457799BBCDFF

[OUTPUT]

Plaintext  : 00123456789ABCDE
Key        : 0133457799BBCDFF
Ciphertext : 1ABFF69D5A93E80B






   







