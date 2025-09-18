# CP2102

## 1. Tạo thư mục robocon với thư mục con week1
```bash
mkdir -p robocon/week1
```

<img width="1600" height="900" alt="image" src="https://github.com/user-attachments/assets/e957992c-b65a-41f7-addb-9821e1a646fe" />


## 2. Thêm user vào group
 Group " dialout " đã được add vào user thien123. Đây là gói để đọc các thiết bị ngoại vi như CP2102
```bash
sudo usermod -a -G dialout thien123
groups thien123
```

<img width="1600" height="900" alt="image" src="https://github.com/user-attachments/assets/2af517a3-241d-4f5f-8fbc-fbcfd0237743" />

## 3. Nhận điện CP2102 trên ubuntu
Sau khi kết nối với CP2102 qua USB. Ta có thể xem module này đã được nhận với tên gì bằng cmd :
```bash
ls /dev/ 
```
Terminal sẽ hiện ra cac module đã đuợc ubuntu nhận ra. Ở đây nếu chỉ có CP2102 thì khả năng cao tên của module này được ubuntu nhận ra với tên "ttyUSB0".\
Trường hợp có nhiều module, ta có thể tháo và kết nối lại Cp2102 và quan sát tự thay đổi của thư mục dev để biết được tên của module này.\
Ta có thể dùng cmd:
```bash $lsusb ```
để quan sát kĩ hơn các thông số của module CP2102. Từ đó có thể tùy chỉnh tên mà ubuntu đọc CP2102 bằng cách thêm udev-rules mới.\
<img width="800" height="450" alt="image" src="https://github.com/user-attachments/assets/673fa149-18af-4bd0-8a65-abb98d282f3a" />

## 4. Gán tên cố định cho module
Ta sẽ gán tên cho module thành /dev/CP2102. Ta cần tạo udev rule mới.\
```bass
cd /etc/udev/rules.d
sudo touch 99-cp2102.rules
sudo nano 99-cp2102.rules                                                # chỉnh sửa file này
```
Thêm dòng sau (thay 10c4 và ea60 bằng VID và PID của CP2102 lấy từ lệnh lsusb):
```bash
SUBSYSTEM=="tty", ATTRS{idVendor}=="10c4", ATTRS{idProduct}=="ea60", SYMLINK+="cp2102"
```
Reload tại và áp dụng rule mới:
```bash
sudo udevadm control --reload-rules
sudo udevadm trigger 
```
Lúc này ta sẽ tìm thấy tên cp2102 khi dùng ``` ls /dev ```








