# Flappy Bird
(1)Tên: Trần Nhật Hưng. MSSV: 23020543</br>
(2) Game Flappy Bird : Chú chim sẽ phải di chuyển qua phần hở giữa 2 ống nước ở trên và dưới, không được chạm ống, nóc của màn hình hay phần base bên dưới </br>
(3) Ngưỡng điểm em mong muốn là 8-9</br>
<strong> Lý do bảo vệ ngưỡng điểm:</strong></br>
- Tính năng đã thực hiện (tự học và tự làm):</br>
 Sử dụng thư viện SDL2 để xây dựng game từ đầu</br>

 Thiết kế game theo kiến trúc nhiều file (main.cpp, gameloop.cpp, player.cpp, obstacle.cpp, texturemanager.cpp,…)</br>

 Tạo các trạng thái của game: màn hình bắt đầu, đang chơi, kết thúc, menu chọn điểm</br>

 Tạo button bằng text với hiệu ứng đổi màu khi hover, có thể click</br>

 Giao diện chọn Start, xem điểm (Points), hiển thị danh sách điểm từ score.txt</br>

 Hiển thị nút âm thanh, điểm số trong lúc chơi</br>

 Hiệu ứng vật lý cho chim: trọng lực, độ cao nhảy, gia tốc rơi</br>

 Animation cho chim với 3 khung ảnh thay đổi theo thời gian</br>

 Hệ thống ống cống sinh ngẫu nhiên và di chuyển theo tốc độ cố định</br>

 Kiểm tra va chạm với ống và mặt đất</br>

 Hiển thị "Game Over" và cho phép Restart</br>

 Code được tổ chức tốt, dễ mở rộng (tách class, dùng reset(), update()…)</br>

(3.2) Thuật toán & kỹ thuật đã sử dụng:  </br>

### Thuật toán để chim bay:
- reset()</br>
**Chức năng:**</br>
Đặt lại toàn bộ trạng thái chim khi bắt đầu game hoặc chơi lại.</br>
**Thiết lập:**</br>
Gán lại vị trí bắt đầu: Ypos = HEIGHT / 3.</br>
Đặt tốc độ bay jumpHeight = -6.</br>
Gia tốc ban đầu accelerator1 = 0, accelerator2 = 0.</br>
Tắt trạng thái bay inJump = false.</br>
Vị trí hiển thị setDest(...) được đặt lại tương ứng.</br>

- Gravity()</br>
**Chức năng:**</br>
Cập nhật vị trí Y của chim, xử lý rơi hoặc bay theo vật lý đơn giản.</br>
**Khi chim đang bay (inJump == true):**</br>
jumpHeight += gravity;</br>
Ypos += gravity + accelerator1 + accelerator2 + jumpHeight;</br>
gravity (ví dụ = 0.4) luôn đẩy chim xuống.</br>
jumpHeight ban đầu là âm (-6), tạo lực đẩy lên (nhảy).</br>
Mỗi frame, jumpHeight tăng dần về 0 → chim chậm lại rồi bắt đầu rơi.</br>
Khi jumpHeight > 0, chim hết lực nhảy → chuyển sang rơi (inJump = false).</br>
Khi chim không bay:</br>
Ypos += gravity + accelerator1 + accelerator2;</br>
Rơi nhanh dần do tích lũy gia tốc (accelerator1, accelerator2), tạo cảm giác chim nặng dần.</br>

- Jump()</br>
**Chức năng:**</br>
Xử lý nhảy khi người chơi nhấn phím.</br>
**Chi tiết**</br>
if (jumpTimer - lastJump > 180) </br>
Mỗi lần nhảy cách nhau ít nhất 180ms.</br>
Nếu đủ thời gian:</br>
Đặt lại gia tốc về 0.</br>
Bật inJump = true.</br>
Lưu thời điểm nhảy (lastJump).</br>
Nếu không đủ thời gian → tiếp tục rơi theo Gravity(). </br>

### Thuật toán các cột chạy
- Các cột độ dài từ 0 tới 260.
- Chạy với tốc độ 3px/frame.

### Thuật toán va chạm
- Xử lý trường hợp chim bay lên nóc, chạm base, chạm các cột bằng cách so sánh tọa độ chim với tọa độ các thành phần khác như cột trên, cột dưới. Với base và top, so sánh đơn thuần tọa độ chứ ko dùng hàm SDL_HasIntersection().

# Nguồn tham khảo: https://www.youtube.com/@askarihassan2632/playlists, https://github.com/Zyb0rg/SDL-Tutorial.git.</br>
# Link video demo: https://youtu.be/zXc9lygLH8A </br>
