#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <DHT.h>

// Cấu hình màn hình OLED
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET    -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// Cấu hình cảm biến DHT22
#define DHTPIN 2       // Chân DATA nối vào GPIO 15
#define DHTTYPE DHT22   // Khai báo loại cảm biến là DHT22
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);

  // Khởi động cảm biến DHT22
  dht.begin();
  Wire.begin(19, 22);
  // Khởi động màn hình OLED
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("Loi: Khong tim thay man hinh OLED!"));
    for(;;); // Dừng chương trình nếu lỗi màn hình
  }

  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);
}

void loop() {
  // Đọc độ ẩm (%) và nhiệt độ (độ C)
  float doAm = dht.readHumidity();
  float nhietDo = dht.readTemperature();

  // Kiểm tra xem cảm biến có bị lỗi đọc hay không
  if (isnan(doAm) || isnan(nhietDo)) {
    Serial.println(F("Loi: Khong doc duoc du lieu tu DHT22!"));
    return; // Bỏ qua vòng lặp này và thử lại ở vòng sau
  }

  // In ra Serial Monitor để kiểm tra song song
  Serial.print("Nhiet do: "); Serial.print(nhietDo); Serial.print(" C | ");
  Serial.print("Do am: "); Serial.print(doAm); Serial.println(" %");

  // Hiển thị lên màn hình OLED
  display.clearDisplay();

  // Tiêu đề
  display.setTextSize(1);
  display.setCursor(15, 0);
  display.println("TRAM DO NHIET DO");
  display.drawLine(0, 12, 127, 12, SSD1306_WHITE);

  // Hiển thị Nhiệt độ
  display.setTextSize(1);
  display.setCursor(0, 20);
  display.print("Nhiet do: ");
  display.setTextSize(2);
  display.setCursor(0, 32);
  display.print(nhietDo, 1); // Lấy 1 chữ số thập phân
  display.print("C");

  // Hiển thị Độ ẩm
  display.setTextSize(1);
  display.setCursor(75, 20);
  display.print("Do am:");
  display.setTextSize(2);
  display.setCursor(75, 32);
  display.print( doAm, 0); // Làm tròn số nguyên
  display.print("%");

  // Đẩy dữ liệu ra màn hình
  display.display();

  // BẮT BUỘC: DHT22 cần thời gian nghỉ tối thiểu 2 giây giữa các lần đọc
  delay(2000);
}