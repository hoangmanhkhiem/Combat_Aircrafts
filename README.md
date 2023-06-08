# Banmaybay_C
Cơ chế hoạt động của code game bắn máy bay:

1. Các hàm cần xây dựng
a. Hàm di chuyển con trỏ

b. Hàm vẽ khung game

c. Hàm tạo ra máy bay địch

d. Hàm di chuyển của máy bay người chơi

e. Hàm tính điểm khi tiêu diệt

f. Hàm xét khả năng sống sót

g. Hàm ẩn con trỏ

2. Quy ước

Vì nhận diện các phím nhập vào bàn phím được hiển thị bằng các số nên #Define các số ấy theo quy ước lên, xuống, trái, phải.

Gọi 4 máy bay địch có tọa độ lần lượt là (d,r),(d1,r1),(d2,r2),(d3,r3)

Gọi tọa độ máy bay người chơi là (x,y)

Gọi giá trị t=1 để xét game đã kết thúc hay chưa

Gọi giá trị f = 0: Tính điểm tiêu diệt máy bay

Gọi giá trị m = 4 : Giá trị số máy bay địch

Gọi giá trị j = 0: Giá trị tiêu diệt được máy bay

3. Cách thức hoạt động của code chính

Đầu tiên, vào game chọn bắt đầu, hàm run() chạy, sau đó chạy hàm Title() để hiển thị tiêu đề của game
, Gọi hàm ẩn con trỏ để cho nhìn đẹp hơn, sau đó dùng hàm setup_background để vẽ ra khung trò chơi.

Di chuyển con trỏ đến vị trí x = 26, y =2 để hiển thị điểm của trò chơi.

Di chuyển con trỏ đến vị trí x =26,y=3 để hiển thị máu có máy bay 

Di chuyển con trỏ đén vị trí x,y được quy ước ban đầu là x=10,y-18 là vị trí xuất phát của máy bay,
sau đó vẽ ("<^>")

Tiếp tục di chuyển con trỏ đến vị trí x=22,y=2 để chuẩn bị spawn ra các máy bay địch

Nếu t=1 tức là game còn hoạt động (t=0 là game đã kết thúc): Dùng hàm remote để di chuyển nhân vật

Sau đó dùng while để kiểm tra xem game đã kết thúc chưa nếu chưa sẽ chạy hàm tạo ra máy bay địch.

4. Cách thức hoạt động của hàm di chuyển máy bay chính

dùng hàm kbhit() để xác định phím bấm từ bàn phím là phím nào

Sau đó ta xét đến các khả năng di chuyển của máy bay:

Giả sử máy bay tiến lên

Ban đầu máy bay có tọa độ 10,18 thì sẽ kiểm tra nếu y!=1 tức đỉnh của màn hình thì sẽ tiến lên được và giảm 1 giá trị của y. Khi đó tại giá trị x,y ban đầu print("   ") để xóa hình máy bay cũ và thay đổi giá trị x,y mới sau đó gotoxy và in ra máy bay tại đó. và break khỏi vòng lặp.

Trường hợp nhấn Backspace thì tọa độ của con trỏ sẽ là tọa độ khi đó của máy bay x= const và y là tọa độ động. Dùng for để xóa và in hình viên đạn lên. Sau đó dùng hàm Tính điểm để xét xem đạn đó có chạm vào máy bay địch hay không. Nếu tọa độ y của máy bay reset về 0 thì dừng tính điểm.
