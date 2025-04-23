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
Sử dụng SDL_GetTicks() để xử lý cooldown nhảy</br>

Tạo animation thủ công với animationTimer</br>

Sử dụng 2 cấp độ gia tốc để mô phỏng trọng lực thực tế</br>

Kết hợp rand() để tạo khoảng cách ngẫu nhiên giữa các ống</br>

Cập nhật UI theo trạng thái (gameStarted, isGameOver, showPointsScreen)</br>

Đọc file score.txt và render text bằng TTF</br>
- Mức độ sử dụng AI:
 Em tìm hiểu và viết các hàm các chức năng. Những phần em viết chưa đúng em có sử dụng AI để sửa và hiểu phần đó. 
# Nguồn tham khảo: https://www.youtube.com/@askarihassan2632/playlists, https://github.com/Zyb0rg/SDL-Tutorial.git.</br>
# Link video demo: https://youtu.be/zXc9lygLH8A </br>
