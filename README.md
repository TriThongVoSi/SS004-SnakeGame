# Snake - Game Rắn Săn Mồi (C++)

## Giới thiệu
Đây là trò chơi **Rắn săn mồi** (Snake) được lập trình bằng ngôn ngữ C++ trên nền tảng Console, sử dụng các hàm đồ họa cơ bản của Windows. Game cho phép bạn điều khiển rắn di chuyển, ăn mồi để tăng điểm và chiều dài, với nhiều mức tốc độ và màu sắc khác nhau.

## Tính năng nổi bật
- Giao diện console đơn giản, dễ chơi.
- Chọn tốc độ di chuyển của rắn (6 mức).
- Chọn màu sắc cho rắn.
- Có mồi thường và mồi to (xuất hiện mỗi 5 lần ăn mồi thường).
- Hiển thị điểm số trực tiếp.
- Kết thúc khi rắn chạm tường hoặc tự cắn vào thân.

## Điều khiển
- **Mũi tên** hoặc các phím **W/A/S/D** để di chuyển rắn:
  - Lên: Mũi tên lên hoặc W
  - Xuống: Mũi tên xuống hoặc S
  - Trái: Mũi tên trái hoặc A
  - Phải: Mũi tên phải hoặc D
- Chọn tốc độ, màu sắc và bắt đầu chơi bằng các phím số tương ứng trong menu.

## Yêu cầu hệ thống
- Windows 10/11
- Visual Studio 2022 (hoặc mới hơn)
- Đã cài đặt Desktop development with C++

## Hướng dẫn cài đặt và chạy game bằng Visual Studio 2022
1. **Tải mã nguồn** về máy tính của bạn.
2. Mở Visual Studio 2022.
3. Chọn `File` > `Open` > `Project/Solution...`.
4. Dẫn đến file `snake-master/snake.sln` và mở.
5. Chọn cấu hình `Debug` hoặc `Release`, nền tảng `x86` hoặc `x64` tùy hệ điều hành.
6. Nhấn **F5** (hoặc nút Start) để biên dịch và chạy game.

## Cấu trúc thư mục
```
snake-master/
  ├── snake/
  │   ├── code.cpp         # File mã nguồn chính
  │   ├── mySnake.h        # Định nghĩa class và logic game
  │   ├── myGraphic.h      # Các hàm đồ họa console
  │   ├── snake.vcxproj    # File project Visual Studio
  │   └── snake.vcxproj.filters
  └── snake.sln            # File solution Visual Studio
```

## Lưu ý
- Game chỉ chạy trên Windows do sử dụng các hàm đồ họa đặc trưng của Windows Console.
- Khi chơi, hãy chọn tốc độ và màu sắc phù hợp để có trải nghiệm tốt nhất.

---
Tác giả: [Từ Minh Khoa - Võ Sĩ Trí Thông] 