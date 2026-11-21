# Trạm đo nhiệt độ, độ ẩm mini với ESP32 (DHT22 + OLED)

Dự án mô phỏng trạm đo nhiệt độ và độ ẩm môi trường sử dụng vi điều khiển ESP32, cảm biến DHT22 và hiển thị trực tiếp lên màn hình OLED SSD1306 (I2C).


## Linh kiện sử dụng
* ESP32 DevKit V1
* Cảm biến nhiệt độ & độ ẩm DHT22
* Màn hình OLED SSD1306 128x64 (I2C)

## Sơ đồ nối dây
| Linh kiện | Chân linh kiện | Chân ESP32 |
| :--- | :--- | :--- |
| **OLED SSD1306** | VCC / GND | 3V3 / GND |
| **OLED SSD1306** | SDA / SCL | GPIO 19 / GPIO 22 |
| **DHT22** | VCC / GND | 3V3 / GND |
| **DHT22** | DATA (SDA) | GPIO 15 |

## Thư viện yêu cầu
* `Adafruit SSD1306`
* `Adafruit GFX Library`
* `DHT sensor library`

## Chạy mô phỏng trực tiếp
👉 [Mở dự án trên Wokwi](https://wokwi.com/projects/481200791059833857)
